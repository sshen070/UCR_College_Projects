#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using std::cout;
using std::endl;

// Using clock() is pretty old school and does not take advantage
// of better precision timers.  But is fine for our purposes.  I'll
// show it both ways, but if one is causing problems, just use the other.
using std::clock_t;
const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000;  // clock per milliseconds

// This is the more modern way to do timings with the high resolution clock
// I'll provide an example.  If this is causing problems for you, just delete
// all these "chrono" lines
#include <chrono>
using std::chrono::steady_clock;
using std::chrono::microseconds;
using std::chrono::time_point;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;

// If using C++ 14, this is better as constexpr
const int NUMBERS_SIZE = 50000;

// Provided by zybooks
int genRandInt(int low, int high) {
  return low + std::rand() % (high - low + 1);
}

// Provided by zybooks
void fillArrays(int arr1[], int arr2[], int arr3[]) {
  for (int i = 0; i < NUMBERS_SIZE; ++i) {
    arr1[i] = genRandInt(0, NUMBERS_SIZE);
    arr2[i] = arr1[i];
    arr3[i] = arr1[i];
  }
}

// Used algorithm from Zybooks
// Helper function for the Quicksort_midpoint & Quicksort_medianOfThree functions -> splits up array into partions & swaps as necessary
int QPartition(int numbers[], int low, int high) {
  // Pick middle element as pivot
  int midpoint = low + (high - low) / 2;
  int pivot = numbers[midpoint];
  
  bool done = false;
  while (!done) {
    // Increment the low index while the elements prior to the pivot are less than the pivot
    while (numbers[low] < pivot) {
      low += 1;
    }
    
    // Decrement the high index while the elements after to the pivot are greater than the pivot
    while (pivot < numbers[high]) {
      high -= 1;
    }
    
    // If the low and high indexes point to the the same index -> all partions are made
    // Return high index
    if (low >= high) {
      done = true;  // Terminate the loop
    }

    else {
      // Swap the values stored in the low and high indexes as they belong on the wrong side of the the pivot
      std::swap(numbers[low], numbers[high]);
      
      // Update indexes
      low += 1;
      high -= 1;
    }
  }
  return high;  // Return high index for next partion
}

// Sorts the array using the Quicksort sorting algorithm -> uses the middle element in the array as the pivot
// Passes in the numbers array & high and low indexes then calls itself
void Quicksort_midpoint(int numbers[], int i, int k) {
  // If low index is >= high index -> sorting not possible
  if (i >= k) {
    return;
  }

  int newHighIndex = QPartition(numbers, i, k);  // Uses the new high index from helper function for next partions

  // Recursively calls itself to partion both sides of the array
  Quicksort_midpoint(numbers, i, newHighIndex);
  Quicksort_midpoint(numbers, newHighIndex + 1, k);
}

// Helper function for Quicksort_medianOfThree -> returns the median value of three inputs (leftMost, midPoint, and rightMost indexes)
int medianCalc(int leftMost, int midPoint, int rightMost) {
  // Check if median is the middle value 
  if ((leftMost < midPoint && midPoint < rightMost) || (rightMost < midPoint && midPoint < leftMost)) {
    return midPoint;
  }

  // Check if median is leftMost value
  else if ((midPoint < leftMost && leftMost < rightMost) || (rightMost < leftMost && leftMost < midPoint)) {
    return leftMost;
  }

  // Median must be rightMost
  else {
    return rightMost;
  }
}


// Same idea as the other Quicksort Algorithm but instead sorts using the median value rather than the midpoint of the array (location)
// Passes in the numbers array & high and low indexes then calls itself
void Quicksort_medianOfThree(int numbers[], int i, int k) { 
  // If low index is >= high index -> sorting not possible
  if (i >= k) {
    return;
  }

  // Find the median of three elements
  int medianVal = medianCalc(numbers[i], numbers[(i + k) / 2], numbers[k]);

  // Swap the median with the first element to use as a pivot -> Qpartion function globally useable for quicksort functions
  int lowIndex = i;
  int highIndex = k;
  for (int j = lowIndex; j <= highIndex; j++) {
    if (numbers[j] == medianVal) {
      std::swap(numbers[i], numbers[j]);
      break;  // Prevent swaping back to original locations
    }
  }

  int lowEndIndex = QPartition(numbers, i, k);

  // Recursively calls itself to partion both sides of the array
  Quicksort_medianOfThree(numbers, i, lowEndIndex);
  Quicksort_medianOfThree(numbers, lowEndIndex + 1, k);
}

// InsertionSort function uses the insertion sort algorithm to sort the array
void InsertionSort(int numbers[], int numbersSize) {
  int j = 0;

  // Traverses through the whole array and swaps when element on the right < element on the left
  for (int i = 1; i < numbersSize; i++) {
    j = i;
    // Continues to swap until the element is in the right position
    while (j > 0 && numbers[j] < numbers[j - 1]) {
      std::swap(numbers[j], numbers[j - 1]);
      j--;
    }
  }
}

// We can compare other sorts we've talked about
static void BubbleSort(int numbers[], int n);

static void MergeSort(int numbers[], int left, int right);

// A helper function that will let us know if we have sorted
// everything
static bool is_sorted(int numbers[], int numbersSize) {
  if (numbersSize <= 0) return true;
  int last = numbers[0];
  for (int i=0; i < numbersSize; ++i) {
    int curr = numbers[i];
    if (curr < last) return false;
    last = curr;
  }
  return true;
}

static void copy_vector_into_array(const std::vector<int>& source, int array[]) {
  for (int i=0; i<static_cast<int>(source.size()); ++i) {
    array[i] = source[i];
  }
}

static void RadixSort(int numbers[], int size);

int main() {
  // I'm going to use the same array every time for all the
  // functions.  This is different than the Zybooks suggestion
  // but will give us more consistent timings
  std::vector<int> sample;
  sample.reserve(NUMBERS_SIZE);
  for (int i = 0; i < NUMBERS_SIZE; ++i) {
    sample.push_back(std::rand() % (NUMBERS_SIZE + 1));
  }

  // We'll run our tests across a bunch of sizes
  // CODETURD: While testing, I can do a break at the end of the
  // CODETURD: loop so I can make faster progress
  int test_sizes[4] = { 10, 100, 1000, 50000 };
  int test_array[NUMBERS_SIZE];
  for (int i=0; i < 4; ++i) {
    int size = test_sizes[i];
    cout << endl;
    cout << "-------------------- size " << size << " --------------------" << endl;

    // // BUBBLE SORT
    // {
    //   copy_vector_into_array(sample, test_array);
    //   // CODETURD: Pick one timing scheme or the other and remove
    //   // CODETURD: the one you don't use
    //   time_point<high_resolution_clock> start = high_resolution_clock::now();
    //   // clock_t Start = clock();
    //   BubbleSort(test_array, size);
    //   // clock_t End = clock();
    //   // int elapsedTime = (End - Start)/CLOCKS_PER_MS;
    //   // cout << elapsedTime << " ms" << endl;

    //   time_point<high_resolution_clock> stop = high_resolution_clock::now();
    //   microseconds duration = duration_cast<microseconds>(stop - start);
    //   cout << duration.count() << " ms for bubble sort " << endl;
    //   cout << "Sort is " << ((is_sorted(test_array, size))?"GOOD":"BAD") << endl;
    // }

    // // MERGE SORT
    // {
    //   copy_vector_into_array(sample, test_array);
    //   // CODETURD: Pick one timing scheme or the other and remove
    //   // CODETURD: the one you don't use
    //   time_point<high_resolution_clock> start = high_resolution_clock::now();
    //   // clock_t Start = clock();
    //   MergeSort(test_array, 0, size-1);
    //   // clock_t End = clock();
    //   // int elapsedTime = (End - Start)/CLOCKS_PER_MS;
    //   // cout << elapsedTime << " ms" << endl;

    //   time_point<high_resolution_clock> stop = high_resolution_clock::now();
    //   microseconds duration = duration_cast<microseconds>(stop - start);
    //   cout << duration.count() << " ms for merge sort " << endl;
    //   cout << "Sort is " << ((is_sorted(test_array, size))?"GOOD":"BAD") << endl;
    // }

    // // RADIX SORT
    // {
    //   copy_vector_into_array(sample, test_array);
    //   // CODETURD: Pick one timing scheme or the other and remove
    //   // CODETURD: the one you don't use
    //   time_point<high_resolution_clock> start = high_resolution_clock::now();
    //   // clock_t Start = clock();
    //   RadixSort(test_array, size);
    //   // clock_t End = clock();
    //   // int elapsedTime = (End - Start)/CLOCKS_PER_MS;
    //   // cout << elapsedTime << " ms" << endl;

    //   time_point<high_resolution_clock> stop = high_resolution_clock::now();
    //   microseconds duration = duration_cast<microseconds>(stop - start);
    //   cout << duration.count() << " ms for radix sort " << endl;
    //   cout << "Sort is " << ((is_sorted(test_array, size))?"GOOD":"BAD") << endl;
    // }

    // QUICKSORT MIDPOINT
    {
      copy_vector_into_array(sample, test_array);
      // CODETURD: Pick one timing scheme or the other and remove
      // CODETURD: the one you don't use
      time_point<high_resolution_clock> start = high_resolution_clock::now();
      // clock_t Start = clock();
      Quicksort_midpoint(test_array, 0, size - 1);
      // clock_t End = clock();
      // int elapsedTime = (End - Start)/CLOCKS_PER_MS;
      // cout << elapsedTime << " ms" << endl;

      time_point<high_resolution_clock> stop = high_resolution_clock::now();
      microseconds duration = duration_cast<microseconds>(stop - start);
      cout << duration.count() << " ms for quicksort midpoint" << endl;
      cout << "Sort is " << ((is_sorted(test_array, size))?"GOOD":"BAD") << endl;
    }

    // QUICKSORT MEDIAN OF THREEE
    {
      copy_vector_into_array(sample, test_array);
      // CODETURD: Pick one timing scheme or the other and remove
      // CODETURD: the one you don't use
      time_point<high_resolution_clock> start = high_resolution_clock::now();
      // clock_t Start = clock();
      Quicksort_medianOfThree(test_array, 0, size - 1);
      // clock_t End = clock();
      // int elapsedTime = (End - Start)/CLOCKS_PER_MS;
      // cout << elapsedTime << " ms" << endl;

      time_point<high_resolution_clock> stop = high_resolution_clock::now();
      microseconds duration = duration_cast<microseconds>(stop - start);
      cout << duration.count() << " ms for quicksort median" << endl;
      cout << "Sort is " << ((is_sorted(test_array, size))?"GOOD":"BAD") << endl;
    }

    // INSERTION SORT
    {
      copy_vector_into_array(sample, test_array);
      // CODETURD: Pick one timing scheme or the other and remove
      // CODETURD: the one you don't use
      time_point<high_resolution_clock> start = high_resolution_clock::now();
      // clock_t Start = clock();
      InsertionSort(test_array, size);
      // clock_t End = clock();
      // int elapsedTime = (End - Start)/CLOCKS_PER_MS;
      // cout << elapsedTime << " ms" << endl;

      time_point<high_resolution_clock> stop = high_resolution_clock::now();
      microseconds duration = duration_cast<microseconds>(stop - start);
      cout << duration.count() << " ms for insertion sort " << endl;
      cout << "Sort is " << ((is_sorted(test_array, size))?"GOOD":"BAD") << endl;
    }
  }

  return 0;
}

static void BubbleSort(int numbers[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (numbers[j] > numbers[j + 1]) {
        std::swap(numbers[j], numbers[j + 1]);
      }
    }
  }
}

static void merge(int numbers[], int start, int mid, int end) {
  int start2 = mid + 1;

  // If the direct merge is already sorted
  if (numbers[mid] <= numbers[start2]) {
    return;
  }

  // Two pointers to maintain start of both sub-arrays to merge
  while (start <= mid && start2 <= end) {
    // If element 1 is in right place
    if (numbers[start] <= numbers[start2]) {
      start++;
    } else {
      int value = numbers[start2];
      int index = start2;

      // Shift all the elements between element 1
      // element 2, right by 1.
      while (index != start) {
        numbers[index] = numbers[index - 1];
        index--;
      }
      numbers[start] = value;

      // Update all the pointers
      start++;
      mid++;
      start2++;
    }
  }
}

static void MergeSort(int numbers[], int left, int right) {
  if (left < right) {
    int mid = (left + right)/2;
    MergeSort(numbers, left, mid);
    MergeSort(numbers, mid+1, right);
    merge(numbers, left, mid, right);
  }
}

static void RadixSort(int numbers[], int size) {
  // LOTS of assumptions here.  I assume all data are
  // postive integers;

  // I have to do passes based on the digits.  I stop
  // when I extract the largest digit
  int divisor = 1;
  bool more = true;
  for (int pass=0; more ; pass++) {
    // I need 10 buckets with a lot of room in them
    std::vector< std::vector<int> > buckets(10);
    for (int i=0; i < 10; ++i) buckets[i].reserve(NUMBERS_SIZE);

    // I pull off the pass'th digit and use it to put a number
    // into a bucket.  To get it, I divide by 1, 10, 100, 1000
    // and then do a modulo
    more = false;
    for (int i=0; i < size; ++i) {
      int digit = (numbers[i]/divisor)%10;
      if (numbers[i]/divisor/10 > 0) more = true;
      buckets[digit].push_back(numbers[i]);
    }
    divisor *= 10;

    // Copy the buckets back into numbers
    int index = 0;
    for (int i=0; i < 10; ++i) {
      const std::vector<int>& bucket = buckets[i];
      for (int j=0; j<static_cast<int>(bucket.size()); ++j) {
        numbers[index++] = bucket[j];
      }
    }
  }
}

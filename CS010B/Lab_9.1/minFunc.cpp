#include "minFunc.h"
const int * min(const int arr[], int arrSize){
    if (arrSize == 0){
        return nullptr;
    }
    else if (arrSize == 1){
        return arr;
    }
    const int* minPtr;
    minPtr = min(arr + 1, arrSize - 1); // sets minPtr to the last value of the arrray

    // Compares value of arr (arrSize - 2 -> 0) during every recursion
    // Stores min value in minPtr
    if (*arr < *minPtr){
        minPtr = arr;
    }
    return minPtr;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    fstream inFS;
    inFS.open("Decrypt.txt"); 

    if (!inFS.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    vector<int> decryptedNumbers;
    int decryptedNumber;
    
    while(inFS >> decryptedNumber){
        decryptedNumbers.push_back(decryptedNumber);
    }
    
    vector<char> plainTextValues;
    for (int i = 0; i < decryptedNumbers.size(); i++) {
        int x = decryptedNumbers.at(i);
        if (7 <= x && x <= 32) {
            plainTextValues.push_back(char('A' + (x - 7)));
        }
        else if (x == 33){
            plainTextValues.push_back(' ');
        }
        else if (x == 34){
            plainTextValues.push_back('"');
        }
        else if (x == 35){
            plainTextValues.push_back(',');

        }
        else if (x == 36){
            plainTextValues.push_back('.');

        }
        else if (x == 37){
            plainTextValues.push_back('\'');

        }
    }

    for (int i = 0; i < plainTextValues.size(); i++) {
        cout << plainTextValues.at(i);
    }
    cout << endl;
    
}

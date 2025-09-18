#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main(int argc, char *argv[]){

    if (argc != 2) {
      cout << "Usage ERROR" << endl;
      exit(EXIT_FAILURE);
    }

    string dataFile;
    vector <double> flightPathAngles;
    vector <double> coefficientsOfLift;
    
    dataFile = argv[1];
    
    readData(dataFile, flightPathAngles, coefficientsOfLift);
 
    if (!isOrdered(flightPathAngles)) {
        reorder(flightPathAngles, coefficientsOfLift);
        cout << "Data was reordered." << endl;
    }
    
    double userFlightPathAngle;
    cout << "Enter a flight-path angle: ";
    cin >> userFlightPathAngle;
    double coefficient = interpolation(userFlightPathAngle, flightPathAngles, coefficientsOfLift);

    cout << "Coefficient of lift for angle " << userFlightPathAngle << " is: " << coefficient << endl;

    cout << "Do you want to enter another flight-path angle? (Yes/No): ";
    string response;
    cin >> response;

    while (response == "Yes"){
    cout << "Enter a flight-path angle: ";
    cin >> userFlightPathAngle;
    coefficient = interpolation(userFlightPathAngle, flightPathAngles, coefficientsOfLift);
    cout << "Coefficient of lift for angle " << userFlightPathAngle << " is: " << coefficient << endl;

    cout << "Do you want to enter another flight-path angle? (Yes/No): ";
    cin >> response;
    }
}

void readData(const string &dataFile, vector<double> &flightPathAngles, vector<double> &coefficientsOfLift){
    ifstream inFS;
    double angle;
    double coefficient;

    inFS.open(dataFile);

    if (!inFS.is_open()){
        cout << "Error opening " << dataFile << endl;
        exit(EXIT_FAILURE);
    }

    while (inFS >> angle >> coefficient){
        flightPathAngles.push_back(angle);
        coefficientsOfLift.push_back(coefficient);
    }

    inFS.close();
}

bool isOrdered(const vector<double> &flightPathAngles){
    for (unsigned int i = 1; i < flightPathAngles.size(); i++){
        if (flightPathAngles.at(i - 1) > flightPathAngles.at(i))
        {
            return false;
        }
    }
    return true;
}

void reorder(vector<double> &flightPathAngles, vector<double> &coefficientsOfLift){
    if (flightPathAngles.size() == 0){
        cout << "Vectors are empty. No reordering necessary." << endl;
    }

    for (unsigned int i = 0; i < flightPathAngles.size() - 1; i++){   
    unsigned int indexSmallest = i;
        for (unsigned int j = i + 1; j < flightPathAngles.size(); j++){
            if (flightPathAngles.at(j) < flightPathAngles.at(indexSmallest)){
                indexSmallest = j;
            }
        }
        if (indexSmallest != i){
            swap(flightPathAngles.at(i), flightPathAngles.at(indexSmallest));
            swap(coefficientsOfLift.at(i), coefficientsOfLift.at(indexSmallest));
        }
    }
}

double interpolation(double userFlightPathAngle, const vector<double> &flightPathAngles, const vector<double> &coefficientsOfLift){
    for (unsigned int i = 0; i < flightPathAngles.size(); i++){ 
        if (flightPathAngles.at(i) == userFlightPathAngle)
        {
            return coefficientsOfLift.at(i);
        }
    }

    unsigned int i = 0;
    while (i < flightPathAngles.size() && !(userFlightPathAngle < flightPathAngles.at(i))){
        i++;
    }
    
    if (i == flightPathAngles.size()){
        cout << "Flight-path angle is out of range." << endl;
        exit(EXIT_FAILURE);
    }

    double a = flightPathAngles.at(i - 1);
    double b = userFlightPathAngle;
    double c = flightPathAngles.at(i);
    double f_a = coefficientsOfLift.at(i - 1);
    double f_c = coefficientsOfLift.at(i);

    return (f_a + ((b - a) / (c - a)) * (f_c - f_a));
}
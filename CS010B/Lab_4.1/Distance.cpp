#include <iostream>
using namespace std;
#include <stdlib.h>
#include "Distance.h"

const double inchesToMeters = 0.0254;
// Constructors
Distance::Distance(){
    _feet = 0;
    _inches = 0.0;
}

Distance::Distance(unsigned ft, double in){
    _feet = ft;
    _inches = in;
    init();
}

Distance::Distance(double in){
    _feet = 0;
    _inches = in;
    init();
}

// Acesssor Functions
unsigned Distance::getFeet() const{
    return _feet;
}

double Distance::getInches() const{
    return _inches;
}

double Distance::distanceInInches() const{
    double inches = ( _feet * 12) + _inches;
    return inches;
}

double Distance::distanceInFeet() const{
    double feet = (_inches / 12) + _feet;
    return feet;
}

double Distance::distanceInMeters() const{
    double meters = distanceInInches() * inchesToMeters;
    return meters;
}

// Overloading Operators
Distance Distance::operator+(const Distance &rhs) const{
    Distance addition;
    addition._inches = _inches + rhs._inches;
    addition._feet = _feet + rhs._feet;
    addition.init();
    return addition;

    // return Distance(_feet + _feet.rhs, _inches + _inches.rhs);
}

Distance Distance::operator-(const Distance &rhs) const{
    Distance subtraction;

//    double implicitInches = distanceInInches();
//    double explicitInches = rhs.distanceInInches();

//    if (implicitInches > explicitInches){
//     subtraction._inches = implicitInches - explicitInches; 
//    }

//    else{
//     subtraction._inches = explicitInches - implicitInches;
//    }

   subtraction._inches = distanceInInches() - rhs.distanceInInches();
   subtraction.init();
   return subtraction;
}

ostream & operator<<(ostream &out, const Distance &rhs){
    out << rhs.getFeet() << "\' " << rhs.getInches() << "\" " << endl;
    return out;
}

void Distance::init(){
    _inches = abs(_inches);

    while (_inches >= 12){
        _inches -= 12;
        _feet++;
    }
}

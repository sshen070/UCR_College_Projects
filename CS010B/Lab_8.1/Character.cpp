#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#include "Character.h"


Character::Character(HeroType _type, const string & _name, double _health, double _attackStrength): type(_type), name(_name), health(_health), attackStrength(_attackStrength){
}

HeroType Character::getType() const{
    return type;
}

const string & Character::getName() const{
    return name;
}

int Character::getHealth() const{
    return health;
}

void Character::damage(double d){
    health -= d;
}

bool Character::isAlive() const{
    return (health > 0);
}


#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#include "Character.h"
#include "Wizard.h"

Wizard::Wizard(const string & _name, double _health, double _attackStrength, int _rank): Character(WIZARD, _name, _health, _attackStrength), rank(_rank){
}

void Wizard::attack(Character & enemy){
    double attackDmg = attackStrength;
    if (enemy.getType() == WIZARD){
        Wizard &opp = dynamic_cast<Wizard &>(enemy);
        attackDmg *= (static_cast<double>(rank)/opp.getRank());
    }
    cout << "Wizard " << name << " attacks " << enemy.getName() << " --- POOF!!" << endl;
    enemy.damage(attackDmg);
    cout << enemy.getName() << " takes " << attackDmg << " damage." << endl;
}


int Wizard::getRank() const{
    return rank;
}
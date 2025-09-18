#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#include "Character.h"
#include "Elf.h"

Elf::Elf(const string & _name, double _health, double _attackStrength, string _familyName): Character(ELF, _name, _health, _attackStrength), familyName(_familyName){
}

void Elf::attack(Character & enemy){
    double attackDmg = (health / MAX_HEALTH) * attackStrength;
    if (enemy.getType() == ELF){
        Elf &opp = dynamic_cast<Elf &>(enemy);
        if (familyName == opp.getFamilyName()){
            cout << "Elf " << name << " does not attack Elf " << enemy.getName() << endl;
            cout << "They are both members of the " << familyName << " family." << endl;
            return;
        }
    }
    cout << "Elf " << name << " attacks " << enemy.getName() << " --- TWSNG!!" << endl;
    enemy.damage(attackDmg);
    cout << enemy.getName() << " takes " << attackDmg << " damage." << endl;
}

string Elf::getFamilyName() const{
    return familyName;
}

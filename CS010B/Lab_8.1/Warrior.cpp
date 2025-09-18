#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#include "Character.h"
#include "Warrior.h"

Warrior::Warrior(const string & _name, double _health, double _attackStrength, string _allegiance): Character(WARRIOR, _name, _health, _attackStrength), allegiance(_allegiance){
}

void Warrior::attack(Character & enemy){
    double attackDmg = (health / MAX_HEALTH) * attackStrength;
    if (enemy.getType() == WARRIOR){
        Warrior &opp = dynamic_cast<Warrior &>(enemy);
        if (allegiance == opp.getAllegiance()){
            cout << "Warrior " << name << "does not attack Warrior " << enemy.getName() << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
            return;
        }
    }
    cout << "Warrior " << name << "attacks " << enemy.getName() << " --- SLASH!!" << endl;
    enemy.damage(attackDmg);
    cout << enemy.getName() << " takes " << attackDmg << " damage." << endl;
}

string Warrior::getAllegiance() const{
    return allegiance;
}

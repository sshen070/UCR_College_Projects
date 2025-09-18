#include <string>

using namespace std;

#ifndef __Warrior_H__
#define __Warrior_H__

class Warrior: public Character {
 private:
    string allegiance;

 public:
    Warrior(const string &, double, double, string);
    void attack(Character &) override;
    string getAllegiance() const;
 };

#endif
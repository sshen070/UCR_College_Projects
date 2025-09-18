#include <string>

using namespace std;

#ifndef __Wizard_H__
#define __Wizard_H__

class Wizard: public Character {
 private:
    int rank;

 public:
    Wizard(const string &, double, double, int);
 	 void attack(Character &) override;
    int getRank() const;
 };

#endif
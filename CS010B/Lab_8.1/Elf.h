#include <string>

using namespace std;

#ifndef __Elf_H__
#define __Elf_H__

class Elf: public Character {
 private:
    string familyName;

 public:
    Elf(const string &, double, double, string);
 	void attack(Character &) override;
    string getFamilyName() const;
 };

#endif
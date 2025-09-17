#ifndef USERMENU_H
#define USERMENU_H

#include <string>
#include <vector>
#include "User.h"
#include "Library.h"

#include <iostream>

using namespace std;

class UserMenu{
 public:
    void displayMenu(Library&, User& user);
};

#endif
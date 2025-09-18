#pragma once

#include <string>
#include <list>
#include <iostream>
#include "WordEntry.h"

using namespace std;

class HashTable {

private:
  list<WordEntry> *hashTable;
  int size;

public:
  // Constructor
  HashTable(int size);

  // Rule of Three
  ~HashTable();
  HashTable(const HashTable&) = delete;
  HashTable& operator=(const HashTable&) = delete;

  bool contains(const string& word) const;
  double getAverage(const string& word) const;
  void put(const string& word , int score);
 
private:
  int computeHash(const string &) const;
};

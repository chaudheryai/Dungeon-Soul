#ifndef ACCESSORY_H
#define ACCESSORY_H

#include "Item.hpp"
#include <vector>
#include <string>
#include <utility>
using namespace std;

//accessories have a list of the specific characterStat members they modify along with the values they will modified with

class Accessory : public Item {
public:
    vector<pair<string, int>> statValuePairs;
    Accessory(vector<pair<string, int>> statValuePairs, string name, string description, int count);

};

#endif // ACCESSORY_H
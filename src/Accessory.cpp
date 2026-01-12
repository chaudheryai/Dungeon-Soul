#include "../header/Accessory.h"
#include "../header/Item.hpp"
#include <vector>
#include <string>
using namespace std;

Accessory::Accessory(vector<pair<string, int>> statValuePairs, string name, string description, int count) : Item(name, description, count) {
    this->statValuePairs = statValuePairs;
}
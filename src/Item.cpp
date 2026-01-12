#include "../header/Item.hpp"

Item::Item(string name, string description, int count) {
    this->name = name;
    this->description = description;
    if (count < 0) {
        this->count = 0;
    } else {
        this->count = count;
    }
}

bool Item::operator==(const Item& other) const { 
    if (this->name == other.name && this->count == other.count)
        return true;
    return false;
}


string Item::getName() const { return this->name; }
string Item::getDescription() const { return this->description; }
int Item::getCount() const { return this->count; }

void Item::setName(const string& name) { this->name = name; }
void Item::setDescription(const string& description) { this->description = description; }
void Item::setCount(int count) { this->count = count; }
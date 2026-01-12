#include "../header/Inventory.hpp"
#include "../header/Item.hpp"
#include "../header/Accessory.h"
#include "../header/Weapon.h"
#include "../header/Armor.h"
#include <iostream>
#include <iomanip>
using namespace std;

Inventory::Inventory() {
    this->itemsSize = 0;
    this->accessoriesSize = 0;
}
Inventory::Inventory(int itemsSize) {
    this->itemsSize = itemsSize;
    this->accessoriesSize = 0;
}
Inventory::Inventory(int itemsSize, int accessoriesSize) {
    this->itemsSize = itemsSize;
    this->accessoriesSize = accessoriesSize;
}

bool Inventory::itemsAreFull() const {
    return items.size() >= itemsSize;
}
bool Inventory::accessoriesAreFull() const {
    return accessories.size() >= accessoriesSize;
}

bool Inventory::addItem(Item* item) {
    //only non-equipment items can stack
    bool isWeapon = dynamic_cast<Weapon*>(item) != nullptr;
    bool isArmor  = dynamic_cast<Armor*>(item)  != nullptr;
    bool isAccessory = dynamic_cast<Accessory*>(item) != nullptr;

    // If item already exists and is stackable, increase the count
    if (this->hasItem(item->getName()) && !isWeapon && !isArmor && !isAccessory) {
        Item* existingItem = this->getItem(item->getName());
        existingItem->setCount(existingItem->getCount() + item->getCount());
        return true;
    }
    else if (itemsAreFull()) {
        return false;
    }
    else {
        items.push_back(item);
        return true;
    }
}
bool Inventory::addAccessory(Accessory* accessory) {
    if (accessoriesAreFull())
        return false;
    accessories.push_back(accessory);
    return true;
}

bool Inventory::removeItem(Item* item) {
    auto it = items.begin(); //iterator for the items vector
    for (; it != items.end(); it++) {
        if (item == *it) {
            items.erase(it);
            return true;
        }
    }
    return false;
}
bool Inventory::removeAccessory(Accessory* accessory) {
    auto it = accessories.begin(); //iterator for the accessories vector
    for (; it != accessories.end(); it++) {
        if (accessory == *it) {
            accessories.erase(it);
            return true;
        }
    }
    return false;
}

Item* Inventory::getItem(const std::string& name) {
    auto it = items.begin(); //iterator for the items vector
    for (; it != items.end(); it++) {
        if (name == (*it)->getName()) {
            return *it;
        }
    }
    return nullptr;
}
Accessory* Inventory::getAccessory(const std::string& name) {
    auto it = accessories.begin(); //iterator for the accessories vector
    for (; it != accessories.end(); it++) {
        if (name == (*it)->getName()) {
            return *it;
        }
    }
    return nullptr;
}

vector<Accessory*>& Inventory::getAccessories() {
    return this->accessories;
}


bool Inventory::hasItem(const std::string& name) const {
    auto it = items.begin(); //iterator for the items vector
    for (; it != items.end(); it++) {
        if (name == (*it)->getName())
            return true;
    }
    return false;
}
bool Inventory::hasAccessory(const std::string& name) const {
    auto it = accessories.begin(); //iterator for the accessories vector
    for (; it != accessories.end(); it++) {
        if (name == (*it)->getName())
            return true;
    }
    return false;
}

void Inventory::printInventory() const {
    cout << "\n ------------------------------------------------------\n";
    cout << " Inventory (" <<  items.size() << '/' << itemsSize << ")\n";
    cout << " Accessory(ies) (" << accessories.size() << '/' << accessoriesSize << ")\n";

    //armor
    cout << " Armor: Helm [" << (helm ? helm->getName() : "None") << "] ";
    cout <<  "Chest [" << (chest ? chest->getName() : "None") << "] ";
    cout << " Legs [" << (legs ? legs->getName() : "None") << "] ";
    cout << " Shoes [" << (shoes ? shoes->getName() : "None") << "]\n";

    cout << " Weapon(s): [" << (weapon ? weapon->getName() : "None") << "]\n";

    cout << " Accessories:\n";
    if (accessories.size() >= 1) {
        for (int i = 0; i < accessories.size(); i++) {
            cout << "  " << i + 1 << ") " << accessories[i]->getName() << '\n';
        }     
        cout << "\n";   
    }
    else {
        cout << "  NONE\n\n";
    }

    cout << " Items:\n";    
    if (items.size() >= 1) {
        for (int i = 0; i < items.size(); i++) {
            cout << "  " << i + 1 << ") " << items[i]->getName() << " (x" << items[i]->getCount() << ")\n";
        }     
        cout << "\n";   
    }
    else {
        cout << "  NONE\n\n";
    }
    
    cout << " Rules: Full inventory blocks pickups; accessory swaps not allowed.\n";
    cout << "------------------------------------------------------\n";
    cout << " a) Use item  b) Equip/Unequip armor c) Back\n";
    cout << "\n";
    cout << " Input: ";
    

};





int Inventory::getItemsSize() const { return this->itemsSize; }
int Inventory::getAccessoriesSize() const { return this->accessoriesSize; }
Armor* Inventory::getHelm() const { return const_cast<Armor*>(this->helm); }
Armor* Inventory::getChest() const { return const_cast<Armor*>(this->chest); }
Armor* Inventory::getLegs() const { return const_cast<Armor*>(this->legs); }
Armor* Inventory::getShoes() const { return const_cast<Armor*>(this->shoes); }
Weapon* Inventory::getWeapon() const { return const_cast<Weapon*>(this->weapon); }


void Inventory::setItemsSize(int size) { this->itemsSize = size; }
void Inventory::setAccessoriesSize(int size) { this->accessoriesSize = size; }
void Inventory::setHelm(Armor* helm) { this->helm = helm; }
void Inventory::setChest(Armor* chest) { this->chest = chest; }
void Inventory::setLegs(Armor* legs) { this->legs = legs; }
void Inventory::setShoes(Armor* shoes) { this->shoes = shoes; }
void Inventory::setWeapon(Weapon* weapon) { this->weapon = weapon; }
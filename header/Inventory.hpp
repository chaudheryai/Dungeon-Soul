    #ifndef INVENTORY_HPP
    #define INVENTORY_HPP

    #include <string>
    #include <vector>
    using namespace std;

    class Item; //forward declarations
    class Accessory;
    class Armor;
    class Weapon;

    class Inventory {
    private:
        vector<Item*> items;
        vector<Accessory*> accessories;
        Armor* helm = nullptr;
        Armor* chest = nullptr;
        Armor* legs = nullptr;
        Armor* shoes = nullptr;
        Weapon* weapon = nullptr;
        int itemsSize; //number of items the inventory can hold
        int accessoriesSize; //number of items the inventory can hold

    public:
        Inventory();
        Inventory(int sizeForItems);
        Inventory(int sizeForItems, int sizeForAccessories);

        bool itemsAreFull() const;
        bool accessoriesAreFull() const;
        bool addItem(Item* item);
        bool addAccessory(Accessory* accessory);
        bool removeItem(Item* item);
        bool removeAccessory(Accessory* accessory);
        void printInventory() const;
        Item* getItem(const string& name);
        Accessory* getAccessory(const string& name);
        bool hasItem(const string& name) const;
        bool hasAccessory(const string& name) const;

        int getItemsSize() const;
        int getAccessoriesSize() const;
        vector<Accessory*>& getAccessories();

        Armor* getHelm() const;
        Armor* getChest() const;
        Armor* getLegs() const;
        Armor* getShoes() const;
        Weapon* getWeapon() const;

        void setItemsSize(int size);
        void setAccessoriesSize(int size);
        void setHelm(Armor* helm);
        void setChest(Armor* chest);
        void setLegs(Armor* legs);
        void setShoes(Armor* shoes);
        void setWeapon(Weapon* weapon);
    };

    #endif // INVENTORY_HPP
#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
using namespace std;

class Item {
private:
    string name = "{name}";
    string description = "{description}";
    int count = 0;
public:
    virtual ~Item() = default;  // REQUIRED for dynamic_cast
    Item(string name, string description, int count);  
      
    string getName() const;
    string getDescription() const;
    int getCount() const;
    void setName(const string& name);
    void setDescription(const string& description);
    void setCount(int count);

    bool operator==(const Item& right) const;
};

#endif // ITEM_HPP
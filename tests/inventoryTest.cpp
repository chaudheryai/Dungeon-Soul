#include "gtest/gtest.h"
#include "../header/Inventory.hpp"
#include "../header/Item.hpp"
#include "../header/Armor.h"
#include "../header/player.h"
#include "../header/Accessory.h"
using namespace std;

TEST(InventoryFunctionsTests, AddItem) {

    Inventory inv(3);
    Item item("item", "description", 1);

    EXPECT_TRUE(inv.addItem(&item));
}

TEST(InventoryFunctionsTests, AddFailsWhenFull) {
    Inventory inv(0);
    Item item1("item1", "desc", 1);

    EXPECT_FALSE(inv.addItem(&item1));
}

TEST(InventoryFunctionsTests, RemoveItem) {
    Inventory inv(3);
    Item item("item", "desc", 1);

    inv.addItem(&item);

    EXPECT_TRUE(inv.removeItem(&item));
}

TEST(InventoryFunctionsTests, RemoveItemFailsWhenEmpty) {
    Inventory inv(1);
    Item item1("item1", "desc", 1);

    EXPECT_FALSE(inv.removeItem(&item1));
}

TEST(InventoryFunctionsTests, GetItem) {
    Inventory inv(3);
    Item item("item", "desc", 1);

    inv.addItem(&item);

    Item* fetched = inv.getItem("item");

    ASSERT_NE(fetched, nullptr);
    EXPECT_EQ(fetched->getName(), "item");
}

TEST(InventoryFunctionsTests, GetItemReturnsNullWhenMissing) {
    Inventory inv(3);

    EXPECT_EQ(inv.getItem("missing"), nullptr);
}

TEST(InventoryFunctionsTests, HasItem) {
    Inventory inv(3);
    Item item("apple", "fruit", 1);

    inv.addItem(&item);

    EXPECT_TRUE(inv.hasItem("apple"));
}

TEST(InventoryFunctionsTests, HasItemFalseWhenNotPresent) {
    Inventory inv(3);

    EXPECT_FALSE(inv.hasItem("nothing"));
}

TEST(InventoryFullCheckTests, NoItemsReturnsNotFull) {
    Inventory inv(2);

    EXPECT_FALSE(inv.itemsAreFull());
}
TEST(InventoryFullCheckTests, FullItemsReturnsFull) {
    Inventory inv(1);
    Item item("item", "desc", 1);

    inv.addItem(&item);

    EXPECT_TRUE(inv.itemsAreFull());
}

TEST(InventoryPrintTests, PrintNonEmptyInventoryUI) {
    Inventory inv(3, 5);
    Item a("Sword", "Sharp blade", 1);
    Item b("Apple", "Crunchy fruit", 2);
    Armor helm(Armor::ArmorType::HELM, {{"poisonResistance", 5}}, "Iron Helm", "Sturdy headgear", 1);
    Accessory accessory({}, "Silver Ring", "A shiny ring", 1);

    inv.addItem(&a);
    inv.addItem(&b);
    inv.addAccessory(&accessory);
    inv.setHelm(&helm);

    cout << "\n--- Print non-empty inventory 'printInventory' function below ---\n";

    inv.printInventory();

    cout << "------------------------------------\n";
}

TEST(InventoryPrintTests, PrintEmptyInventoryUI) {
    Inventory inv(3, 5);

    cout << "\n--- Print empty inventory 'printInventory' function below ---\n";

    inv.printInventory();

    cout << "------------------------------------\n";
}
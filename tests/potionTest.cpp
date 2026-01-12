#include "gtest/gtest.h"
#include "../header/Potion.h"
#include "../header/player.h"
using namespace std;

//Constructor
TEST(PotionConstructorTests, ConstructorHealAmount) {

    Potion potion(50, 1);

    EXPECT_EQ(potion.getHealAmount(), 50);
}

TEST(PotionConstructorTests, ConstructorCount) {
    Potion potion(50, 4);

    EXPECT_EQ(potion.getCount(), 4);
}

TEST(PotionUseTests, PotionIncreasesHealth) {
    Player player;
    player.getInventory().setItemsSize(1);
    player.getPlayerStats().maxHealth= 50;
    player.getPlayerStats().currHealth= 10;
    
    Potion potion(30, 1);
    player.getInventory().addItem(&potion);
    player.useItem(&potion);
    EXPECT_EQ(player.getPlayerStats().currHealth, 40);
}

TEST(PotionUseTests, PotionDoesNotOverheal) {
    Player player;
    player.getInventory().setItemsSize(1);
    player.getPlayerStats().maxHealth= 50;
    player.getPlayerStats().currHealth= 50;
    
    Potion potion(30, 1);
    player.getInventory().addItem(&potion);
    player.useItem(&potion);
    EXPECT_EQ(player.getPlayerStats().currHealth, 50);
}

TEST(PotionUseTests, PotionCountDecreasesAfterUse) {
    Player player;
    player.getInventory().setItemsSize(1);
    
    Potion potion(30, 1);
    player.getInventory().addItem(&potion);
    player.useItem(&potion);

    EXPECT_EQ(potion.getCount(), 0);
}

TEST(PotionPrintTests, PrintFromUseFunction) {
    cout << "\n--- Print from player 'useItem' function below ---\n";
    cout << "------------------------------------\n";
    
    Player player;
    player.getInventory().setItemsSize(1);
    
    Potion potion(24, 1);
    player.getInventory().addItem(&potion);
    player.useItem(&potion);

    cout << "------------------------------------\n";
}
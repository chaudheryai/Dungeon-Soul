#include "gtest/gtest.h"
#include "../header/Actor.h"
using namespace std;


TEST(ActorConstructorTests, DefaultConstructorActorPosition) {
    Actor a;

    EXPECT_TRUE(a.getX() == 0 && a.getY() == 0);
}

TEST(ActorConstructorTests, DefaultConstructorActorAlive) {
    Actor a;

    EXPECT_TRUE(a.getIsAlive());
}

TEST(ActorConstructorTests, ParameterizedConstructorActorPosition) {
    Actor b(2,3);

    EXPECT_TRUE(b.getX() == 2 && b.getY() == 3);
}

TEST(ActorKillTests, KillMakesIsAliveFalse) {
    Actor a;
    a.kill();

    EXPECT_FALSE(a.getIsAlive());
}
cmake_minimum_required(VERSION 3.0)
project(dungeon_soul)

add_subdirectory(external/googletest)

add_library(game_lib
    src/Accessory.cpp
    src/Actor.cpp
    src/Armor.cpp
    src/Character.cpp
    src/CharacterStats.cpp
    src/dungeon.cpp
    src/Enemy.cpp
    src/floor.cpp
    src/floorTIle.cpp
    src/Inventory.cpp
    src/Item.cpp
    src/player.cpp
    src/Potion.cpp
    src/Weapon.cpp
    src/CombatSystem.cpp
    src/AIController.cpp
)

target_include_directories(game_lib PUBLIC include)

add_executable(game_exec src/main.cpp)
target_link_libraries(game_exec PRIVATE game_lib)

add_executable(testing
    tests/accessoryTest.cpp
    tests/armorTest.cpp
    tests/weaponTest.cpp
    tests/inventoryTest.cpp
    tests/potionTest.cpp
    tests/actorTest.cpp
    tests/characterTest.cpp
    tests/enemyTest.cpp
    tests/playerTest.cpp
    tests/tileTest.cpp
    tests/enemyTileTest.cpp
    tests/combatTest.cpp
)

add_executable(enemyDropTester
    tests/enemyDropsTest.cpp
)
target_link_libraries(enemyDropTester PRIVATE game_lib)

target_link_libraries(testing
    PRIVATE
        game_lib
        gtest
        gtest_main
)

target_compile_definitions(testing PRIVATE gtest_disable_pthreads=ON)
[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/EvxoT0RF)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=21053996)

# Dungeon Soul
 
 Authors: \<[Joshua Schumperli](https://github.com/jschu051)\>\<[Imran Chaudhery](https://github.com/chaudheryai)\>\<[Adam Schumperli](https://github.com/aschu042)\>\<[Darreck Craiu](https://github.com/darreckcraiu)\>

## Project Description
  *  Imran C: I love playing RPG’s I have been playing them my whole life. So I find it really enticing to be able to code with a team an RPG project.
  *  Adam S: I have always loved video games and in particular I have always been a fan of fantasy RPGs. I thought it would be a lot of fun to make my own fantasy RPG.
  *  Joshua S: I am very interested in game design and have a little experience with it so to me making a text-based one would be an interesting challenge.
  *  Darreck C: I like playing and developing video games and have made a couple very small-scoped games of my own. When it comes to software development, game development is the most interesting to me.
  
  *  Tools used: C++, GDB, Valgrind, Visual Studio Code.

  *  Input from the user will be taken in via entry of strings into the terminal by keyboard. The game will respond in the terminal to the user's inputs. The user will respond to prompts (i.e. "Go left (1)", "Go right (2)", "Enter name: ") by inputting the required character or string. Anything and everything that the user will draw information from and give information to will take place via text on the terminal.
 
Game features (Original Plan):
  - Game is a rougelike, meaning player death is permanent and losing requires starting from the beginning
  - Play the game through text prompts (explore, fight enemies, interact with objects etc.)
  - Randomness in encounters, enemies, stats, rooms, damage, events etc.
  - AI system for the enemies the player fights to make the game have some challenge
  - Player inventory system
  - Saving of permanent progress per computer (optional)
  - Game world will consist of the "World" which will consist of 5 "floor" which will each have many "rooms". These will all be hand made and the player will move throughout it by responding to prompts
  - The game elements witin each room will be random while the layout itself is static
  - The first floor is called the cave and has 6 different paths to follow, made up of 10 different random encounters and 6 set encounters
  - The second floor is called the forest and has 4 different paths to follow, made up of 8 different random encounters and 4 set encounters
  - The third floor is called the mountain and has 2 different paths to follow, made up of 7 different random encounters and 3 set encounters
  - The fourth floor is called the ruined battlefield and has 4 different paths to follow, made up of 8 different random encounters and 4 set encounters
  - The fifth and final floor is called the castle and only has 1 main path to follow, however it is split into 5 different distinct sections with the final section containing the final boss, among the sections there are 3 different random encounters and 1 set encounter each to a total of 15 different random encounters and 5 set encounters total
  - 21 different enemies which are split into 4 different "families" and the final boss enemies can attack other enemies that are not from the same family
  - Humaniod enemies: goblin, orc, ogre, troll, giant
  - Beast enemies: dire wolf, flame bear, venomous tiger, scapegoat, divine sheep
  - Undead enemies: zombie, spewer, exploder, lich, banshee
  - Golem enemies: earth golem, mini golem, lava golem, water golem, spirit golem
  - Final boss: THE KING
  - 10+ different items
  - The player starts with a small inventory but it can be upgraded to hold more items. The player is always able to wear four pieces of armor (a helmet, chestplate, leggings, and boot) weild one or two weapons (depending on if they are one or two handed weapons) and one accessory that gives a special boost. With upgrades a player can hold up to 3 accessories. Without upgrades the player can hold up to 5 non-equipped unique items, which can be upgraded to 7, 10, and eventually 15 non-equipped unique items. These items can be backup weapons/armor/accessories, materials to make/upgrade weapons/armor/accessories, or consumables like health potions or status ailment cures. The inventory is shown as a list with item name followed by quantity. EX: Health Potion x4
  - 4+ different player classes (different abilities and stats)

Game features (Current/Updated):
  - Game is a rougelike, meaning player death is permanent and losing requires starting from the beginning
  - Play the game through text prompts (explore, fight enemies, interact with objects etc.)
  - Randomness in encounters, enemies, stats, rooms, damage, events etc.
  - AI system for the enemies the player fights to make the game have some challenge
  - Player inventory system, keeps track of number of items and number of individual items
  - Game world will consist of the "World" which will consist of 5 "floor" which will each have many "rooms". These will all be hand made and the player will move throughout it by responding to prompts
  - The game elements witin each room will be random while the layout itself is static
  - 4 different player classes with 3 schools each (total of 12 different player options)
 ## Phase II

## User Interface Specification

### Navigation Diagram
<img width="709" height="1061" alt="UserInterfaceSpecifacation drawio (1)" src="https://github.com/user-attachments/assets/c729cddc-e895-4e12-b89b-c16720c413fc" />

### Screen Layouts

Dungeon Soul — Each Screen (Prototype)

A terminal-style, turn-based dungeon crawler. This section documents the player-facing screens and the intended flow, plus brief notes on the purpose of each element.

## Table of Contents
- [Start / Overview](#start--overview)
- [How to Play (Detailed)](#how-to-play-detailed)
- [Choose Class](#choose-class)
- [Choose School](#choose-school)
- [Lore (Prologue)](#lore-prologue)
- [Confirm Entry](#confirm-entry)
- [Floor Navigation (Floor 1)](#floor-navigation-floor-1)
- [Encounter / Battle Prompt](#encounter--battle-prompt)
- [Battle](#battle)
- [Inventory](#inventory)
- [Character Sheet](#character-sheet)
- [Portal Guard (Boss Gate)](#portal-guard-boss-gate)
- [Game Over / Victory](#game-over--victory)

---

## Start / Overview

    ───────────────────────────────────────────────────────
     │Welcome to Dungeon Soul.
     │
     │Enter 0 to begin your journey.
     │
     │How to play (summary):
     │ • Turn-based battles; explore floors to reach the throne room.
     │ • Classes + Schools define your style (physical, magic, stealth…).
     │ • Manage stats, resistances, and items; prepare for bosses.
     │
     │Press [1] for full “How to Play” or choose another option below.
     ───────────────────────────────────────────────────────
     │ 0) Begin
     │ 1) How to Play (detailed)
     │ 2) Lore (prologue)
     │ 3) Quit
    ───────────────────────────────────────────────────────
     │ Input › _
    ───────────────────────────────────────────────────────

**Purpose of elements**
- **Begin (0):** Proceeds to Character Creation.  
- **How to Play (1):** Opens the detailed tutorial screen.  
- **Lore (2):** Opens the story prologue (can be skipped).  
- **Quit (3):** Exits the game.

---

## How to Play (Detailed)

    ──────────────────────────────────────────────────────
    │ How to Play (Detailed)
    │ • Stats: Health, Physical Def, Vigor, Magical Def, Magic Power,
    │   Immunity, Agility.
    │ • Specific stats feed main stats (e.g., Strength+Stamina = Vigor).
    │ • Damage = Base + Modifiers − Resistances.
    │ • Crits: chance from Dexterity; crit doubles post-calc damage.
    │ • Dodge: Full (Dex+Speed) small cap; Partial reduces damage by 20%.
    │ • Status (Poison/Paralysis/Sleep/Stat↓) and healing are fixed power.
    │ • Movement: choose directions; reach portals; fight bosses.
    │ • Inventory: limited slots; equip armor/weapons/accessory(ies).
    │
    │ Tip: Schools specialize your tools (e.g., fire/lightning vs water…).
    │ ───────────────────────────────────────────────────────
    │ 0) Back to Start
    │
    ───────────────────────────────────────────────────────
    │ Input › _
    └──────────────────────────────────────────────────────

**Purpose:** Gives players actionable rules tied to your stat system.

---

## Choose Class

    ───────────────────────────────────────────────────────
    | Choose Your Character
    |
    │ Select your Class:
    │ 1) Swordsman – Strong single hits; balanced gear.
    │ 2) Mage       – Elemental casting; varied resistances.
    │ 3) Assassin   – Speed, crits, and status focus.
    │ 4) Tank       – High defenses, frontline control.
    │
    │ (You will pick a School next.)
    │ ───────────────────────────────────────────────────────
    │ 0) Back
    │
    ├──────────────────────────────────────────────────────
    │ Input › _
    └──────────────────────────────────────────────────────

**Purpose of elements**
- **List of Classes:** Explains role identity before narrowing to School.  
- **Back (0):** Returns to Start.

---

## Choose School

    If Swordsman
    1) School of Strength – Big single-hit damage (high Vigor).
    2) School of Agility  – Multi-hit strings (high Agility).
    3) School of Balance  – Mix of power and speed.
    0) Back

    If Mage
    1) Red & Purple  – Fire + Lightning.
    2) Blue & Brown  – Water + Earth.
    3) Change        – Wind + status/healing.
    0) Back

    If Assassin
    1) Unseen   – Extreme speed, early turn order.
    2) Unwanted – Status application specialist.
    3) Hatred   – High Dex: crit and dodge focus.
    0) Back

    If Tank
    1) Wall       – Physical defense specialist.
    2) Mysteries  – Elemental defense specialist.
    3) Protector  – Balanced defenses.
    0) Back

**Purpose of elements**
- **School List:** Locks in playstyle modifiers and starting kit.  
- **Back (0):** Returns to Class selection without penalty.

---

## Lore (Prologue)

    ───────────────────────────────────────────────────────
    |Lore (Prologue)
    │ [Story text… paginated if long.]
    │
    │ “Five floors divide the path to the throne. Families rival, yet all
    │ will heed the King’s call…”
    │
    │ Press [Enter] to continue pages.
    │ ───────────────────────────────────────────────────────
    │ 0) Back
    │
    ├──────────────────────────────────────────────────────
    │ Input › _
    └──────────────────────────────────────────────────────

**Purpose:** Delivers narrative context; no choices besides Back.

---

## Confirm Entry

    ┌──────────────────────────────────────────────────────
    | Confirm Entry to the Dungeon
    | ─────────────────────────────────────────────────────
    │ You have chosen:
    │   Class: Assassin
    │   School: Hatred
    │
    │ Enter the dungeon?
    │ ───────────────────────────────────────────────────────
    │ Y) Yes, begin Floor 1
    │ N) No, change my choices
    ├──────────────────────────────────────────────────────
    │ Input ›
    └──────────────────────────────────────────────────────

**Purpose**
- **Summary:** Shows final selections before committing.  
- **Y/N:** Prevents accidental entry; enables revising choices.

---

## Floor Navigation (Floor 1)

    ┌──────────────────────────────────────────────────────
    ├ Floor 1: Cave
    │ Seen Exits: N (Main Path), E (Side Path A), W (Side Path B)
    │
    │ Mini-Map (9×13) — @=You, .=Battle, M=Mini-boss, B=Boss
    │ _=Empty, N=NPC, T=Trap, #=Wall
    │
    │   x→   0 1 2 3 4 5 6 7 8 9 10 11 12
    │ y=0   # # # # # # B # # # #  #  #
    │ y=1   # # # # # # # # # # #  #  #
    │ y=2   # # # # # # . . . . M  #  #
    │ y=3   # # # T # # . . _ N #  #  #
    │ y=4   # # # T T # . . . . .  #  #
    │ y=5   # # M . . . . # # # #  #  #
    │ y=6   # # # # # # . . . M #  #  #
    │ y=7   # # # # # # @ . . . #  #  #      (Start at S → render as @)
    │ y=8   # # # # # # # # # # #  #  #
    │
    │ Status: HP 100 | Vigor 12 | PhysDef 8 | MagDef 6 | Agility 9
    │         Immunity 7 | Magic 5 | Inventory: 3/5
    │ ───────────────────────────────────────────────────────
    │ Movement:
    │  w) Go North (Main Path)   d) Go East (Side Path A)   a) Go West
    │  s) Go South
    │  0) Open Inventory         2) View Character (Stats)  3) Pause/Save
    ├──────────────────────────────────────────────────────
    │ Input › _
    └──────────────────────────────────────────────────────

**Purpose of elements**
- **Location/Exits:** Communicates navigable options.  
- **Mini-Map:** Textual map cues for terminal play.  
- **Status Line:** Quick HUD using aggregated stats.  
- **Movement Options:** Numbered/lettered to avoid conflicts.  
- **Inventory/Character:** Fast access to loadout and detailed stats.  
- **Pause:** Access to save/quit without losing progress.

---

## Encounter / Battle Prompt

    ┌────────────────────────────────────────────────────── 
    │ Encounter!
    │ A Goblin ambushes you! (Humanoid family)
    │ Traits: High Agility; average defenses.
    │
    │ What will you do?
    │ ───────────────────────────────────────────────────────
    │ 1) Fight
    │ 2) Attempt to Flee (Agility check)
    │ 3) Use Item
    ├──────────────────────────────────────────────────────
    │ Input › _
    └─────────────────────────────────────────────────────

**Purpose:** Bridges exploration → combat; exposes family traits relevance.

---

## Battle

    ┌────────────────────────────────────────────────────── 
    │ Battle
    │ Enemy: Goblin (Lv 3)  HP: 42/42  Family: Humanoid
    │ You : Assassin/Hatred (Lv 3)  HP: 76/90  MP: 20/20
    │ Combat Log:
    │ • Goblin darts forward! (Speed check)
    │ • You partially dodge. Damage reduced by 20%.
    │ Actions:
    │ 1) Attack (Slash)     2) Skill (Backstab)     3) Items
    │ 4) Defend (+PhysDef)  5) Special (Crit Focus) 6) Flee
    │ Notes: Crit chance from Dex; damage = base + mods − resistances.
    ├──────────────────────────────────────────────────────
    │ Input › _
    └──────────────────────────────────────────────────────

**Purpose of elements**
- **Enemy/Player lines:** Snapshot of key stats and resources.  
- **Combat Log:** Turn resolution order (important for Speed).  
- **Actions:** Core commands; names vary by class/school/gear.  
- **Notes:** Short reminders that reinforce mechanics.

---

## Inventory

    ┌────────────────────────────────────────────────────── 
    │ Inventory (3/5)
    │ Armor: Helm [Iron] | Chest [Leather] | Legs [None] | Shoes [Cloth]
    │ Weapon(s): Dagger [Slash 10]
    │ Accessory(ies): 1/1 (Agility Charm +1)
    │ Items:
    │  1) Healing Potion (x2)
    │  2) Antidote (x1)
    │  3) Fire Shard (mat)
    │
    │ Rules: Full inventory blocks pickups; accessory swaps not allowed.
    │ ───────────────────────────────────────────────────────
    │ A) Use item   B) Equip/Unequip armor/weapon   0) Back
    ├──────────────────────────────────────────────────────
    │ Input › _
    └──────────────────────────────────────────────────────

**Purpose:** Enforces capacity rules; exposes equip slots and items.

---

## Character Sheet

    ┌────────────────────────────────────────────────────── 
    │ Character Sheet
    │ Class/School: Assassin / Hatred     Level: 3
    │ Main Stats:
    │  • Health 90
    │  • Physical Def 8  (Pierce 5 | Blunt 6 | Slash 8)
    │  • Vigor 12        (Strength 7 | Stamina 17)
    │  • Magical Def 6   (Fire 4 | Water 5 | Earth 6 | Wind 5 | Lightning 4)
    │  • Magic Power 5   (FireAff 1 | WaterAff 1 | EarthAff 1 | WindAff 2 | LightningAff 0)
    │  • Immunity 7      (Poison 5 | Paralysis 4 | Sleep 5 | StatRes 4)
    │  • Agility 9       (Dex 8 | Speed 10)
    │
    │ Crit chance = ceil(Dex/10)%;
    │ Full Dodge = ceil((Dex+Speed)/100)%
    │ Partial Dodge = ceil((Dex + Speed/2)/10)%
    ───────────────────────────────────────────────────────
    │ 0) Back
    ├──────────────────────────────────────────────────────
    │ Input › _
    └──────────────────────────────────────────────────────

**Purpose:** Displays aggregated + specific stats exactly as per your system.

---

## Portal Guard (Boss Gate)

    ┌────────────────────────────────────────────────────── 
    | Portal to Floor 2
    │ A Boss blocks the portal.
    │
    │ Prepare?
    │ ───────────────────────────────────────────────────────
    │ 1) Fight Boss
    │ 2) Review Inventory
    │ 3) Review Character
    │ 0) Retreat
    ├──────────────────────────────────────────────────────
    │ Input › _
    └──────────────────────────────────────────────────────

**Purpose:** Gives a last prep checkpoint before boss fights.

---

## Game Over / Victory

    ┌────────────────────────────────────────────────────── 
    │Game Over
    │ You fall in the depths of the Dungeon.
    │ ───────────────────────────────────────────────────────
    │ 0) Return to Main Menu
    │ 1) Load Last Save
    ├──────────────────────────────────────────────────────
    │ Input › _
    └──────────────────────────────────────────────────────

    ┌────────────────────────────────────────────────────── 
    | Victory!
    │ THE KING is defeated. Peace returns—for now.
    │ ───────────────────────────────────────────────────────
    │ 0) Return to Main Menu
    │ 1) New Game+
    ├──────────────────────────────────────────────────────
    │ Input › _
    └──────────────────────────────────────────────────────

**Purpose:** Clear endpoints with sensible next steps.

---

## Class Diagram (OLD)
> <img width="725" height="762" alt="image" src="https://github.com/user-attachments/assets/ca9a32c4-5782-48e7-b12f-f45122bad679" />
## Class Diagram (NEW)
> ![CS100 Project Class UML Diagram](https://github.com/user-attachments/assets/a8210eac-e9d6-4408-984e-3215f9907520)


**Description:** Dungeon Soul is a game that can be split into many different parts which are made up of classes. These classes can be split into different catagories: Game Systems, Game Items, Non-player Characters, Game Board Set-up, and Player Characrters. The game itself is made using the Dungeon class which is made up of Floor classes, which is made up of FloorTie classes. The FloorTile class hold information about what is on every tile, the Floor class holds information about the location of every tile as well as ensureing that placement of certain key things like the portal to the next floor and the player spawn location, and the Dungeon class holds all of the floors and works to move players between said floors. The Item class is split into four subclasses Weapon, Armor, Accessory, and HealthPotion which are all self-describing (the weapon class deals with ingame weapons, armor class with ingame armor, etc.) with the Item class itself holding information that is universal between all the items in the game. The CombatSystem class works to detmerine what happens during combat working together with player input and the AIController class to do so. The AIController class works to determine what enemies do during battle. The Inventory Class works as the Inventory system for both players and NPCs. The Actor Class works to hold informaiton about where and what non-player entitites are doing. The Character subclass works to determine information baout all non-player characters and has 2 subclasses of its own. The Enemy subclass determines what Enemies the player will fight as well as what they will give the player. The NPC subclass determines what friendly NPCs the player will interact with in the dungeon as well as what items they can trade with the player. Finally the Player class holds all the information important for the player character allowing for a smooth playing experience. The Player class is dependent on both the Inventory and Weapon/Armor/Accessory classes to hold information on teh player's equiped and stored items. The CombatSystem Class is dependent on the Player, Character, and AIController classes to determine what happens during combat. The AIController class is dependent on the Enemy class to determine what the enemy will do. The Inventory class is dependent on the Item class to store in-game items. Finally, the FloorTile class is dependent on the Item, Enemy, and NPC classes in order to place all the enemies, NPCs, and treasure in each floor. NOTE: Beyond just the aforementioned classes, there is also a struct called CharacterStats which as the name implies holds all of the stat information for all player and non-player characters in the game. it was made because there are many stats in Dungeon Soul and many of these stats are shared entirely between player and non-player characters (EX: both the player and enemies have a maximum HP stat) 




 
 ## Phase III

**SOLID UML UPDATES:** (SRP – Single Responsibility Principle, OCP – Open/Closed Principle, LSP – Liskov Substitution Principle, ISP – Interface Segregation Principle, DIP – Dependency Inversion Principle)

 * floorTile:
S: floorTile prints itself so a renderer was added to main so floorTIle doesn’t have to print
O: adding new types of tiles requires changing preexisting code, so the class was split up so if a new tile type has to be made, you can just make a new subclass
L: children works as functioning tiles
I: Already accomplished, the class uses everything in its dependencies whether directly or indirectly
D: Abstracted with the creation of multiple subclasses

 * floor:
S: floor prints itself so a renderer was added to main  so floor doesn’t have to print Also moved checking for a valid tile to the player
O: Already accomplished, is made so adding floors doesn’t require changing code for any floors already present
L: Already accomplished, no children
I: Already accomplished, everything in floorTile is used in floor, both directly and indirectly, no other dependencies
D: Already accomplished, everything is abstract

 * dungeon:
S: dungeon prints itself so a renderer was added to main  so dungeon doesn’t have to print
O: Already accomplished, can be extended in anyway without changing the code already present in dungeon
L: Already accomplished, no children
I: Already accomplished, everything in floor is used in dungeon, both directly and indirectly, no other dependencies
D: Already accomplished, everything is abstract

 * Actor:
 S: Already accomplised, Actor only deals with holding location information and whether the character is alive
 O: Already accomplised, you can add more Actors without having to edit existing code
 L: Already accomplised, main super class LSP doesn't need to be worried about
 I: Already accomplised, Actor has no functions that it can't make use of
 D: Already accomplised, Actor is not dependent on concretions

 * Character:
 S: Already accomplised, Actor only deals with holding stat information like level, actual stats, and growth rate
 O: Already accomplised, you can add more Characters without having to edit existing code
 L: Already accomplised, Character is able to do everything that Actor can if it is needed
 I: Already accomplised, Character has no functions that it can't make use of
 D: Already accomplised, Character is not dependent on concretions

 * Enemy:
 S: Already accomplised, Actor only deals with holding enemy specific informaiton like name, family, and loot
 O: Already accomplised, you can add more Enemies without having to edit existing code
 L: Already accomplised, Enemy is able to do everything that Actor and/or Character can if it is needed
 I: Already accomplised, Enemy has no functions that it can't make use of
 D: Already accomplised, Enemy is not dependent on concretions

 * Item:
For the Item class, the increaseQuantity method was removed to better follow the SRP; the count member already has a getter and setter. The useItem method removed and put into an interface called IUsable which usables items will inherit from; this follows ISP. This also follows the LSP because IUsable will act as a parent class for all derived kinds of items. This helps us write better code because we can have active-use items and inactive-use items both derive from the same item class still.

 * Inventory:
For the Inventory class, the vector of Item is now a vector of Item* which allows the Inventory class to hold any Item types and not worry about how they are implmented or created or destroyed, and this follows the SRP, the OCP, the LSP, and the DIP. The Inventory class can now work with any class that inherits from Item. It also no longer is responsible for knowing details about the Item objects it holds because it only has their pointers. This helps us write better code because we can modify Item-derived classes without having to modify Inventory.

 * Weapon, healthPotion:
For Weapon and healthPotion which both derive from Item, they both now also implement the IUsable interface which follows the ISP and the OCP. Also, for the healthPotion the getter and setter were both removed to remove the ability for other classes which interact with healthPotion objects to modify the heal amount of it after construction. A constructor was also added so now a health potion's heal amount can only be set at construction which is following the SRP and the OCP. These changes make coding for us easier because they allow weapons and health potions to still be considered items (even though they also use an interface that some other items don't) and treated as such in other parts of the program and because they will prevent certain bugs that might have arised with health potion heal amounts being modified by outside classes in the future.
 
 > ## Final deliverable

 ## UML Diagram (Final)
 > <img width="2436" height="1756" alt="CS100 Project Class UML Diagram drawio (1)" src="https://github.com/user-attachments/assets/d5722ea5-a7ef-4c3e-8cba-2e7bb2074126" />

 ## Screenshots
 > Screenshots of the input/output after running your application

Valgrind memcheck:

 <img width="503" height="320" alt="image" src="https://github.com/user-attachments/assets/ec16e873-ab18-4fab-a8e0-f563f8a59ea9" />

Game Screen Shots

Welcome Screen:


<img width="632" height="407" alt="Welcome screen" src="https://github.com/user-attachments/assets/7eee8f53-8d7f-4537-b3b7-d58adec395a8" />


If the user inputs 0 it leads to the How to Choose Your Class Screen
If the user inputs 1 it leads to the How to Play Screen
If the user inputs 2 it leads to the Lore Screen
If the user inputs 3 it Quits the Game

How to Play Screen:


<img width="630" height="407" alt="How to Play screen" src="https://github.com/user-attachments/assets/211882fe-641c-49ea-9b2f-90d23e8a05dc" />

Lore Screen:


<img width="636" height="237" alt="Lore screen" src="https://github.com/user-attachments/assets/df98679c-90e1-4b2c-8bf8-97ae5bea4947" />

Choose Your Class Screen:


<img width="533" height="300" alt="Choose Your Class" src="https://github.com/user-attachments/assets/a9bea041-9df2-446b-b103-4c7778102a32" />

If the user inputs 1 it leads to the Swordsman Screen
If the user inputs 2 it leads to the Mage Screen
If the user inputs 3 it leads to the Assasin Screen
If the user inputs 4 it leads to the Tank Screen

Swordsman school choice Screen:


<img width="618" height="170" alt="Choose Your School(swordsman example)" src="https://github.com/user-attachments/assets/c1b8c6e3-38ae-48b0-afc2-042430f75368" />

If the user inputs 1 or 2 or 3 it will lead to the confirm Entry to the Dungeon Screen


Confirm Entry to the Dungeon:


<img width="553" height="283" alt="Confirm Entry to the Dungeon" src="https://github.com/user-attachments/assets/87bd1998-8dae-4279-a4b4-b5d2eca164a5" />


if the User inputs 0 they will go to the floor navigation screen if it is 1 they go back to the beginning

Floor Navigation Screen

<img width="897" height="508" alt="Floor Navigation" src="https://github.com/user-attachments/assets/0dce81ab-e0c8-454d-8a3d-9feaa087d434" />

If the user inputs w,s,l,d they move to the corresponding location tile if avaliable (Battle Encounter Screen, Trap Screen, NPC screen, Treasure Screen, Boss Encounter Screen, Empty/Complete Tile Screen)

If the user inputs E it leads to the How to Play Screen
If the user inputs Q it leads to the Lore Screen
If the user inputs P it Quits the Game
If the user inputs L it Quits the Game


Open Inventory screen:

<img width="907" height="375" alt="Open Inventory" src="https://github.com/user-attachments/assets/7253ce47-ddc5-4827-a9e9-d2bb910c1b5b" />

If the User inputs a it would Use item 
If the User inputs b it would Equip/Unequip armor 
If the User inputs c it would go Back

View Character screen: 


<img width="796" height="432" alt="view Charachter" src="https://github.com/user-attachments/assets/eecd8a14-baaa-4855-9c5f-e7c1f7b3ae59" />

If the User inputs 0 it would go Back

Pause/Save screen:


<img width="508" height="107" alt="Pause screen" src="https://github.com/user-attachments/assets/cf038a53-7819-4359-9992-d1dac472f82c" />

If the User inputs any char it would go Back


Trap Screen:

<img width="537" height="136" alt="Trap Screen" src="https://github.com/user-attachments/assets/b9331990-afd8-47a5-b3aa-a3ec08376674" />

if the user enters 0 it will go back to floor navigation screen

NPC Screen:


<img width="618" height="116" alt="NPC" src="https://github.com/user-attachments/assets/31c53ced-e2c1-4afa-8219-5e1c8bf2dbc9" />

if the user enters bye it will go back to floor navigation screen
if the user enters any set of strings it will talk to the bot


Treasure Screen:

<img width="578" height="135" alt="Treasure Tile" src="https://github.com/user-attachments/assets/83d9674c-3cfa-4605-b6e2-a4409634f5c1" />

if the user enters 0 it will go back to floor navigation screen


Empty/Complete Tile Screen:


<img width="601" height="151" alt="Empty or Completed Tile" src="https://github.com/user-attachments/assets/29f59963-ea94-4cc8-9781-773752b9e8e4" />

if the user enters 0 it will go back to floor navigation screen


Boss Encounter Screen(not completed):

<img width="577" height="157" alt="Boss Encounter (not completed)" src="https://github.com/user-attachments/assets/72ea281c-15be-4bcd-8ddc-6306b2a34d31" />


if the user enters 0 it will go back to floor navigation screen



Battle Encounter Screen:

<img width="572" height="243" alt="Battle Encounter Screen" src="https://github.com/user-attachments/assets/e30220f3-dfd5-4912-a9f1-749a689fece1" />

if the user enters 1 it will go to battle screen
if the user enters 2 it will either to floor navigation screen or battle screen
if the user enters 3 it will use an item


battle screen:


<img width="580" height="440" alt="Battle Screen" src="https://github.com/user-attachments/assets/9484c1d3-77f4-48cf-96da-6a436a18418b" />


if the user enters 1 it will attack
if the user enters 2 it will use an item

lose screen:


<img width="142" height="47" alt="Game Over Screen" src="https://github.com/user-attachments/assets/922514bc-2503-44cc-b047-7c6c3040040d" />

Final GTests:

<img width="655" height="386" alt="image" src="https://github.com/user-attachments/assets/cfff092f-2361-471a-a0c4-d87aa8e5c948" />


 ## Installation/Usage
To play the game you just need to open up the terminal and go to the root directory for the project. Then run cmake cmakeLists.txt . Then run make. then run ./game_exec all in the terminal finally to begin the game.
 ## Testing
Testing was mostly done with google test, but there is a singluar unit test that is just done via the terminal due to requiring user input.
 

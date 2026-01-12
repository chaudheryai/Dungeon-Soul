#include "../header/CharacterStats.h"

const std::unordered_map<std::string, int CharacterStats::*> CharacterStats::statLookup = {

    {"maxHealth", &CharacterStats::maxHealth},
    {"currHealth", &CharacterStats::currHealth},

    {"vigor", &CharacterStats::vigor},
    {"physicalDef", &CharacterStats::physicalDef},
    {"magicalPower", &CharacterStats::magicalPower},
    {"magicalDef", &CharacterStats::magicalDef},
    {"immunity", &CharacterStats::immunity},
    {"agility", &CharacterStats::agility},

    {"strength", &CharacterStats::strength},
    {"stamina", &CharacterStats::stamina},

    {"pierceResistance", &CharacterStats::pierceResistance},
    {"bluntResistance", &CharacterStats::bluntResistance},
    {"slashResistance", &CharacterStats::slashResistance},

    {"fireAffinity", &CharacterStats::fireAffinity},
    {"earthAffinity", &CharacterStats::earthAffinity},
    {"waterAffinity", &CharacterStats::waterAffinity},
    {"windAffinity", &CharacterStats::windAffinity},
    {"lightningAffinity", &CharacterStats::lightningAffinity},

    {"fireResistance", &CharacterStats::fireResistance},
    {"earthResistance", &CharacterStats::earthResistance},
    {"waterResistance", &CharacterStats::waterResistance},
    {"windResistance", &CharacterStats::windResistance},
    {"lightningResistance", &CharacterStats::lightningResistance},

    {"poisonResistance", &CharacterStats::poisonResistance},
    {"sleepResistance", &CharacterStats::sleepResistance},
    {"paralysisResistance", &CharacterStats::paralysisResistance},
    {"statResistance", &CharacterStats::statResistance},

    {"dexterity", &CharacterStats::dexterity},
    {"speed", &CharacterStats::speed},
};

#pragma once
#include "NPC.h"
#include "Structures.h"
#include <vector>

class Wizard : virtual public NPC
{
protected:
    short intellect{ 29 };
    std::vector<Spell> spells;

public:
    Wizard();

    void Create() override;
    void GetInfo() override;
    void LearnSpell();

    ~Wizard() override;
};

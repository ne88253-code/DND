#pragma once
#include "NPC.h"
#include "Structures.h"
#include <vector>

class Warrior : virtual public NPC
{
protected:
    short strength{ 21 };
    std::vector<Weapon> weapons;

public:
    Warrior();
    Warrior(std::string name, unsigned int lvl);

    void Create() override;
    void GetInfo() override;
    void GetWeapon();

    ~Warrior() override;
};

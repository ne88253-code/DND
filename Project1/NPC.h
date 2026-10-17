#pragma once
#include <string>
#include <iostream>

class NPC
{
protected:
    std::string name{ "npc" };
    unsigned int damage{ 2 };
    unsigned int health{ 5 };
    short lvl = 1;
    unsigned int armor = 2;

private:
    bool isEnemy = true;

public:
    unsigned int GetDamage();
    unsigned int GetHealth();
    void SetHealth(unsigned int health);

    virtual void GetInfo();
    virtual void Create();
    void LvlUp();
    void Relaculate();

    friend void TakeDamage(NPC* npc, unsigned int damage);

    virtual ~NPC() = default;
};

// Объявление дружественной функции
void TakeDamage(NPC* npc, unsigned int damage);
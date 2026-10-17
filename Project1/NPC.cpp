#include "NPC.h"

using namespace std;

unsigned int NPC::GetDamage() {
    return damage;
}

unsigned int NPC::GetHealth() {
    return health;
}

void NPC::SetHealth(unsigned int health) {
    this->health = health;
}

void NPC::GetInfo() {
    cout << "имя: " << name << endl;
    cout << "здоровье: " << health << endl;
    cout << "урон: " << damage << endl;
    cout << "уровень: " << lvl << endl;
    cout << "броня: " << armor << endl;
}

void NPC::Create() {}

void NPC::LvlUp() {
    cout << name << " повысил уровень!\n";
    lvl++;
    Relaculate();
}

void NPC::Relaculate() {
    damage += 1;
    health += 1;
    armor += 1;
}

void TakeDamage(NPC* npc, unsigned int damage) {
    if (!npc) return;
    unsigned int currentHealth = npc->GetHealth();
    if (currentHealth >= damage) {
        npc->SetHealth(currentHealth - damage);
    }
    else {
        npc->SetHealth(0);
    }
    cout << "Вам нанесли урон: " << damage << endl;
    cout << "Оставшееся здоровье = " << npc->GetHealth() << endl;
}
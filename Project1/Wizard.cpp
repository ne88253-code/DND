#include "Wizard.h"

using namespace std;

Wizard::Wizard() {
    damage = 27;
    health = 21;
    armor = 10;
}

void Wizard::Create() {
    cout << "Вы создали волшебника\nЗадайте имя игрока:\n";
    cin >> name;

    GetInfo();
    LearnSpell();
}

void Wizard::GetInfo() {
    cout << "имя: " << name << endl;
    cout << "здоровье: " << health << endl;
    cout << "урон: " << damage << endl;
    cout << "интеллект: " << intellect << endl;
}

void Wizard::LearnSpell() {
    Spell spell;
    spell.damage = 2;
    spell.name = "вспышка";
    spells.push_back(spell);

    cout << name << " изучил заклинание " << spells[0].name << endl;
    cout << "добавка к урону = " << spells[0].damage << endl;
}

Wizard::~Wizard() {
    cout << name << " испускает дух\n";
}
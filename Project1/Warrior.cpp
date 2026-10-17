#include "Warrior.h"

using namespace std;

Warrior::Warrior() {
    damage = 20;
    health = 30;
    armor = 15;
}

Warrior::Warrior(string name, unsigned int lvl) : Warrior() {
    this->name = name;
    for (size_t i = 0; i < lvl; i++) {
        LvlUp();
    }
}

void Warrior::Create() {
    cout << "Вы создали воина\nЗадайте имя игрока:\n";
    cin >> name;

    GetInfo();
    GetWeapon();
}

void Warrior::GetInfo() {
    cout << "имя: " << name << endl;
    cout << "здоровье: " << health << endl;
    cout << "урон: " << damage << endl;
    cout << "сила: " << strength << endl;
}

void Warrior::GetWeapon() {
    Weapon weapon;
    weapon.damage = 1;
    weapon.name = "кулаки";
    weapons.push_back(weapon);

    cout << name << " взял в руки оружие " << weapons[0].name << endl;
    cout << "добавка к урону = " << weapons[0].damage << endl;
}

Warrior::~Warrior() {
    cout << name << " пал смертью храбрых\n";
}
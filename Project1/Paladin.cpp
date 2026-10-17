#include "Paladin.h"

using namespace std;

Paladin::Paladin() {
    intellect = 25;
    strength = 19;
    health = 25;
    damage = 25;
}

void Paladin::Create() {
    cout << "Вы создали Паладина\nЗадайте имя игрока:\n";
    cin >> name;

    GetInfo();
    GetWeapon();
    LearnSpell();
}

void Paladin::GetInfo() {
    Warrior::GetInfo();
    cout << "интеллект: " << intellect << endl;
}

Paladin::~Paladin() {
    cout << "Отправляется к праотцам\n";
}
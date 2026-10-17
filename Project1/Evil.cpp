#include "Evil.h"

Evil::Evil() {
    name = "Злодей";
    health = 10;
    damage = 10;
    armor = 3;
}

Evil::Evil(std::string name) : Evil() {
    this->name = name;
}

Evil::Evil(std::string name, unsigned int damage) : Evil(name) {
    this->damage = damage;
}

Evil::Evil(std::string name, unsigned int damage, unsigned int health) : Evil(name, damage) {
    this->health = health;
}

Evil::Evil(std::string name, unsigned int damage, unsigned int health, unsigned int armor) : Evil(name, damage, health) {
    this->armor = armor;
}
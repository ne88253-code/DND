#include <iostream>
#include <memory>
#include "Player.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Paladin.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");

    Player player;
    cout << "Присядь, путник, у костра и расскажи, кто ты: " << endl;
    cout << "\t1 - воин\n\t2 - волшебник\n\t3 - паладин" << endl;
    short choice = 0;
    cin >> choice;

    switch (choice)
    {
    case 1:
        player.Create(make_unique<Warrior>());
        break;
    case 2:
        player.Create(make_unique<Wizard>());
        break;
    case 3:
        player.Create(make_unique<Paladin>());
        break;
    default:
        cout << "Таких героев ещё не было в наших краях.\nПопытай удачу позже.\n";
        return 0;
    }

    TakeDamage(player.GetCharacter(), 5);

    return 0;
}
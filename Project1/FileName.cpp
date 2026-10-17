#include <iostream> 
#include <vector>
#include <memory>

using namespace std;

class NPC
{
protected:
	string name{ "npc" };
	unsigned int damage{ 2 };
	unsigned int health{ 5 };
	short lvl = 1;
	unsigned int armor = 2;
private:
	bool isEnemy = true;
public:
	unsigned int GetDamage() { return damage; }
	unsigned int GetHealth() { return health; }
	void SetHealth(unsigned int health) { this->health = health; }

	virtual void GetInfo()
	{
		cout << "имя: " << name << endl;
		cout << "здоровье: " << health << endl;
		cout << "урон: " << damage << endl;
		cout << "уровень: " << lvl << endl;
		cout << "броня: " << armor << endl;
	}

	virtual void Create() {}

	void LvlUp()
	{
		cout << name << " повысил уровень!\n";
		lvl++;
		Relaculate();
	}

	void Relaculate()
	{
		damage += 1;
		health += 1;
		armor += 1;
	}

	// Исправлено: объявление соответствует реализации
	friend void TakeDamage(NPC* npc, unsigned int damage);

	virtual ~NPC() = default;
};

struct Weapon
{
	string name{ "weapon" };
	unsigned int damage{ 1 };
};

class Warrior : virtual public NPC
{
protected:
	short strength{ 21 };
	vector<Weapon> weapons;
public:
	Warrior()
	{
		damage = 20;
		health = 30;
		armor = 15;
	}

	Warrior(string name, unsigned int lvl) : Warrior()
	{
		this->name = name;
		for (size_t i = 0; i < lvl; i++)
		{
			LvlUp();
		}
	}

	void Create() override
	{
		cout << "Вы создали воина\nЗадайте имя игрока:\n";
		cin >> name;

		GetInfo();
		GetWeapon();
	}

	void GetInfo() override
	{
		cout << "имя: " << name << endl;
		cout << "здоровье: " << health << endl;
		cout << "урон: " << damage << endl;
		cout << "сила: " << strength << endl;
	}

	void GetWeapon()
	{
		Weapon weapon;
		weapon.damage = 1;
		weapon.name = "кулаки";
		weapons.push_back(weapon);

		cout << name << " взял в руки оружие " << weapons[0].name << endl;
		cout << "добавка к урону = " << weapons[0].damage << endl;
	}

	~Warrior()
	{
		cout << name << " пал смертью храбрых\n";
	}
};

struct Spell
{
	string name{ "spell" };
	unsigned int damage{ 1 };
};

class Wizard : virtual public NPC
{
protected:
	short intellect{ 29 };
	vector<Spell> spells;
public:
	Wizard()
	{
		damage = 27;
		health = 21;
		armor = 10;
	}

	void Create() override
	{
		cout << "Вы создали волшебника\nЗадайте имя игрока:\n";
		cin >> name;

		GetInfo();
		LearnSpell();
	}

	void GetInfo() override
	{
		cout << "имя: " << name << endl;
		cout << "здоровье: " << health << endl;
		cout << "урон: " << damage << endl;
		cout << "интеллект: " << intellect << endl;
	}

	void LearnSpell()
	{
		Spell spell;
		spell.damage = 2;
		spell.name = "вспышка";
		spells.push_back(spell);

		cout << name << " изучил заклинание " << spells[0].name << endl;
		cout << "добавка к урону = " << spells[0].damage << endl;
	}

	~Wizard()
	{
		cout << name << " испускает дух\n";
	}
};

class Evil : public NPC
{
public:
	Evil()
	{
		name = "Злодей";
		health = 10;
		damage = 10;
		armor = 3;
	}

	Evil(string name) : Evil()
	{
		this->name = name;
	}

	Evil(string name, unsigned int damage) : Evil(name)
	{
		this->damage = damage;
	}

	Evil(string name, unsigned int damage, unsigned int health) : Evil(name, damage)
	{
		this->health = health;
	}

	// Исправлена опечатка в параметре unsigned intarmor -> unsigned int armor
	Evil(string name, unsigned int damage, unsigned int health, unsigned int armor) : Evil(name, damage, health)
	{
		this->armor = armor;
	}
};

class Paladin : public Warrior, public Wizard
{
public:
	Paladin() {
		intellect = 25;
		strength = 19;
		health = 25;
		damage = 25;
	}

	void Create() override
	{
		cout << "Вы создали Паладина\nЗадайте имя игрока:\n";
		cin >> name;

		GetInfo();
		GetWeapon();
		LearnSpell();
	}

	void GetInfo() override
	{
		Warrior::GetInfo();
		cout << "интеллект: " << intellect << endl;
	}

	~Paladin()
	{
		cout << "Отправляется к праотцам\n";
	}
};

class Player
{
private:
	unique_ptr<NPC> currentCharacter{ nullptr };
public:
	void Create(unique_ptr<NPC> character)
	{
		currentCharacter = move(character);
		currentCharacter->Create();
	}

	NPC* GetCharacter()
	{
		return currentCharacter.get();
	}
};

// Дружественная функция использует геттеры/сеттеры или защищенные поля
void TakeDamage(NPC* npc, unsigned int damage)
{
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
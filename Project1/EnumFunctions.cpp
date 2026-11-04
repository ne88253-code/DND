#include "EnumFunctions.h"

void CharacterTypeInfo(CharacterType type)
{
	switch (type)
	{
	case CharacterType::Warrior:
		std::cout << "Вы - Воин.";

	case CharacterType::Wizard:
		std::cout << "Вы - Маг.";

	case CharacterType::Paladin:
		std::cout << "Вы - Паладин.";

	case CharacterType::Evil:
		std::cout << "Вы - Демон.";

	default:
		std::cout << "Такого у нас тут  еще не видели.";

	}
}

void WeaponQualityInfo(WeaponQuality quality)
{
	switch (quality)
	{
	case WeaponQuality::Common:
		std::cout << "Редкость вашего оружия - обычное.";

	case WeaponQuality::Uncommon:
		std::cout << "Редкость вашего оружия - необычное.";

	case WeaponQuality::Rare:
		std::cout << "Редкость вашего оружия - редкое.";

	case WeaponQuality::Epic:
		std::cout << "Редкость вашего оружия - эпическое.";

	case WeaponQuality::Legendary:
		std::cout << "Редкость вашего оружия - легендарное.";

	default:
		std::cout << "Такое оружие здесь ещё не появлялось.";

	}
}
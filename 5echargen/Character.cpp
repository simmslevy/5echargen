#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "Character.h"
#include <ctime>
#include <array>
#include <cstdlib>
#include <ctime>
#include <string>

// Static look up tables

Character::Races Character::raceData[Character::MAX_RACES]
{
	{ "Hill Dwarf", {0, 0, 2, 0, 1, 0} , true, HILL_DWARF },
	{"Mountain Dwarf", {2, 0, 2, 0, 0, 0}, true, MOUNTAIN_DWARF},
	{ "High Elf", {0, 2, 0, 1, 0, 0}, true, HIGH_ELF },
	{ "Wood Elf",{0, 2, 0, 0, 1, 0}, true, WOOD_ELF },
	{ "Lightfoot Halfling", {0, 2, 0, 0, 0, 1}, false, LIGHTFOOT_HALFLING },
	{ "Stout Halfling",{0, 2, 1, 0, 0, 0}, false, STOUT_HALFLING},
	{ "Human", {1, 1, 1, 1, 1, 1}, false, HUMAN },
	//{"Human (Variant)", {0, 0, 0, 0, 0, 0}, VARIANT_HUMAN}
};


Character::Jobs Character::jobData[Character::MAX_CLASSES]
{
	{ "Cleric", 8, CLERIC },
	{ "Fighter", 10, FIGHTER },
	{ "Rogue", 8, ROGUE },
	{ "Wizard", 6, WIZARD }
};

// Default constructor

Character::Character()
{

	srand(static_cast<unsigned int>(time(0)));
	rand();
	std::cout << "Your ability scores are: " << std::endl;
	populateAbilityScores(COLVILLE);
	printAbilityScore();
	std::cout << std::endl;
	chooseRace();

	//printClass();
	/*m_class = chooseClass();
	m_hp = getClassHP() + (m_AbilityScores[2] - 10) / 2;
	std::cout << "Your chosen class is: " << getClass() << " and you have " << m_hp << " hitpoints." << std::endl;*/
}

// RNG

int Character::getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);  // static used for efficiency, so we only calculate this value once
															// evenly distribute the random number across our range
	return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

// Ability Scores

std::string Character::getAbilityScoreName(Character::ability score)
{
	switch (score)
	{
	case Character::STR: return "STR";
	case Character::DEX: return "DEX";
	case Character::CON: return "CON";
	case Character::INT: return "INT";
	case Character::WIS: return "WIS";
	case Character::CHR: return "CHR";
	default: return "";
	}
}

void Character::printAbilityScore()
{
	for (int count = 0; count < 6; ++count)
		std::cout << getAbilityScoreName(static_cast<ability>(count)) << ' ' << m_AbilityScores[count] << std::endl;
}

int Character::generateAbilityScore()
{
	int array[4]{ getRandomNumber(1,6), getRandomNumber(1,6), getRandomNumber(1,6), getRandomNumber(1,6) };
	int min = 7;
	int sum = 0;
	for (int &element : array)
	{
		sum += element;
		if (element < min)
			min = element;
	}
	return sum - min;
}

void Character::populateAbilityScores(Character::statGenMethod method)
{
	if (method == Character::COLVILLE)
	{
		int count15 = 0;
		for (int &element : m_AbilityScores)
		{
			element = generateAbilityScore();
			if (element >= 15)
				++count15;
		}
		if (count15 < 2)
			Character::populateAbilityScores(method);
	}
}

// Races

void Character::chooseRace()
{
	std::cout << "Select a race by number from the list below:" << std::endl;
	for (int count = 0; count < MAX_RACES; ++count)
	{
		std::cout << count + 1 << ") " << raceData[count].race_name << std::endl;
	}
	int selection;
	std::cin >> selection;
	--selection;
	m_race = static_cast<races>(selection);
	for (int count = 0; count < MAX_ABILITIES; ++count)
		m_AbilityScores[count] += raceData[selection].race_bonuses[count];
	// Add switch case here
	//switch (selection)
	//{
	//case VARIANT_HUMAN: {; }
	//default:
	//	// Do Nothing
	//}
	std::cout << "Your ability scores have increased!" << std::endl;
	printAbilityScore();
}














void const Character::printClass()
{
	for (int count = 0; count < Character::MAX_CLASSES; ++count)
		std::cout << count + 1 << ") " << jobData[count].job_name << std::endl;
}

//Character::job Character::chooseClass()
//{
//	std::cout << "Please enter a class from the followng list" << std::endl;
//	printClass();
//	std::string chosenClass;
//	int count;
//	while (true)
//	{
//		count = 0;
//		std::getline(std::cin, chosenClass);
//		for (count; count < MAX_CLASSES-1; ++count)
//			if (!(chosenClass.compare(m_classes[count])))
//				break;
//		if (!(chosenClass.compare(m_classes[count])))
//			break;
//		std::cout << "Class not found, please re-enter: ";
//	}
//	return static_cast<job>(count);
//}
void Character::chooseBackground() {}



std::string Character::getClass()
{
	switch (m_class)
	{
	case CLERIC: return "Cleric";
	case FIGHTER: return "Fighter";
	case ROGUE: return "Rogue";
	case WIZARD: return "Wizard";
	default: return "";
	}
}

int Character::getClassHP()
{
	switch (m_class)
	{
	case CLERIC: return 8;
	case FIGHTER: return 10;
	case ROGUE: return 8;
	case WIZARD: return 6;
	default: return 8;
	}
}
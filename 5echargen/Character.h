#ifndef CHARACTER_H
#define CHARACTER_H
#include <array>
#include <string>

class Character
{
public:
	enum ability
	{
		STR,
		DEX,
		CON,
		INT,
		WIS,
		CHR,
		MAX_ABILITIES
	};
	
	enum statGenMethod
	{
		COLVILLE,
		MAX_STATGENS
	};
	
	

	enum races
	{
		HILL_DWARF,
		MOUNTAIN_DWARF,
		HIGH_ELF,
		WOOD_ELF,
		LIGHTFOOT_HALFLING,
		STOUT_HALFLING,
		HUMAN,
		//VARIANT_HUMAN,
		MAX_RACES
	};

	enum skills
	{
		ATHLETICS,
		ACROBATICS,
		SLEIGHT_OF_HAND,
		STEALTH,
		ARCANA,
		HISTORY,
		INVESTIGATION,
		NATURE,
		RELIGION,
		ANIMAL_HANDLING,
		INSIGHT,
		MEDICINE,
		PERCEPTION,
		SURVIVAL,
		DECEPTION,
		INTIMIDATION,
		PERFORMANCE,
		PERSUASION,
		MAX_SKILLS
	};

	enum lightArmor
	{
		PADDED,
		LEATHER,
		STUDDED_LEATHER,
		MAX_LIGHT_ARMOR
	};

	enum mediumArmor
	{
		HIDE,
		CHAIN_SHIRT,
		SCALE_MAIL,
		BREASTPLATE,
		HALF_PLATE,
		MAX_MEDIUM_ARMOR
	};

	enum heavyArmor
	{
		RING_MAIL,
		CHAIN_MAIL,
		SPLINT,
		PLATE,
		MAX_HEAVY_ARMOR
	};

	enum simpleMeleeWeapons
	{
		CLUB,
		DAGGER,
		GREATCLUB,
		HANDAXE,
		JAVELIN,
		LIGHT_HAMMER,
		MACE,
		QUARTERSTAFF,
		SICKLE,
		SPEAR,
		MAX_SIMPLE_MELEE_WEAPONS
	};

	enum simpleRangedWeapons
	{
		LIGHT_CROSSBOW,
		DART,
		SHORTBOW,
		SLING,
		MAX_SIMPLE_RANGED_WEAPONS
	};

	enum martialMeleeWEAPONS
	{
		BATTLEAXE,
		FLAIL,
		GLAIVE,
		GREATAXE,
		GREATWORD,
		HALBERD,
		LANCE,
		LONGSWORD,
		MAUL,
		MORNINGSTAR,
		PIKE,
		RAPIER,
		SCIMITAR,
		SHORTSWORD,
		TRIDENT,
		WAR_PICK,
		WARHAMMER,
		WHIP,
		MAX_MARTIAL_MELEE_WEAPONS
	};


	enum martialRangedWeapons
	{
		BLOWGUN,
		HAND_CROSSBOW,
		HEAVY_CROSSBOW,
		LONGBOW,
		NET,
		MAX_MARTIAL_RANGED_WEAPONS
	};

	static struct Races
	{
		std::string race_name;
		std::array<int, MAX_ABILITIES> race_bonuses;
		bool race_darkvision;
		races race_enum;
	};


	/*static struct Background
	{
		int background_name;
		std::array<int, 18> background_skills;
	};*/

	enum background
	{
		HERMIT,
		NOBLE,
		OUTLANDER,
		SOLDIER,
		MAX_BACKGROUNDS
	};

	enum job
	{
		CLERIC,
		FIGHTER,
		ROGUE,
		WIZARD,
		MAX_CLASSES
	};

	struct Jobs
	{
		std::string job_name;
		int job_HD;
		job job_enum;
	};

	
	static Races raceData[races::MAX_RACES];
	static Jobs jobData[job::MAX_CLASSES];
private:
		std::array<int, 6> m_AbilityScores;
		background m_background;
		job m_class;
		int m_hp;
		races m_race;
		
public:
	Character();

	void printAbilityScore();
	int getRandomNumber(int min, int max);
	int generateAbilityScore();
	std::string getAbilityScoreName(ability score);
	void populateAbilityScores(statGenMethod method);

	void chooseRace();

	job chooseClass();
	void chooseBackground();
	void const printClass();
	std::string getClass();
	int getClassHP();
};


//#include <array>
//
//class Character
//{

//
//private:
//	std::array<int, 6> m_AbilityScores;
//
//public:
//	Character();
//
//	//int getAbilityScore(abilities ability) { return m_AbilityScores[static_cast<int>(ability)]; }
//	//void print() {}; // print character sheet to file
//
//	//int generateAbilityScore();
//
//	//int getRandomNumber(int min, int max);
//
//}
#endif
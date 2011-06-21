#include "Data/Skill.h"

#include <string>
#include <vector>
#include <map>

using namespace data;
using namespace std;

/* static data members */
vector<string> Skill::_names;
vector<string> Skill::_level_names;
map<int,vector<int> > Skill::_role_maxima;

/* public static methods */
void Skill::init() {
	static const char* ilnames[] = {
		"Invalid", "Unskilled", "Basic", "Skilled", "Expert", "Master", "Grand Master", NULL
	};
	static const char* isnames[] = {
		"none", "dagger", "knife", "axe", "pick-axe", "short sword", "broadsword", "long sword", "two-handed sword", "scimitar", "saber", "club",
		"mace", "morning star", "flail", "hammer", "quarterstaff", "polearms", "spear", "javelin", "trident", "lance", "bow", "sling", "crossbow",
		"dart", "shuriken", "boomerang", "whip", "unicorn horn", "attack spells", "healing spells", "divination spells", "enchantment spells",
		"clerical spells", "escape spells", "matter spells", "bare handed combat", "two weapon combat", "riding", NULL
	};
	static int roledata[] = { /* this list generated by straightforward editing of Skill_X in u_init.c */
		P_NONE, ARCHEOLOGIST,
		P_DAGGER, P_BASIC,                P_KNIFE,  P_BASIC,
		P_PICK_AXE, P_EXPERT,             P_SHORT_SWORD, P_BASIC,
		P_SCIMITAR, P_SKILLED,            P_SABER, P_EXPERT,
		P_CLUB, P_SKILLED,                P_QUARTERSTAFF, P_SKILLED,
		P_SLING, P_SKILLED,               P_DART, P_BASIC,
		P_BOOMERANG, P_EXPERT,            P_WHIP, P_EXPERT,
		P_UNICORN_HORN, P_SKILLED,
		P_ATTACK_SPELL, P_BASIC,          P_HEALING_SPELL, P_BASIC,
		P_DIVINATION_SPELL, P_EXPERT,      P_MATTER_SPELL, P_BASIC,
		P_RIDING, P_BASIC,
		P_TWO_WEAPON_COMBAT, P_BASIC,
		P_BARE_HANDED_COMBAT, P_EXPERT,
		P_NONE, BARBARIAN,
		P_DAGGER, P_BASIC,                P_AXE, P_EXPERT,
		P_PICK_AXE, P_SKILLED,    P_SHORT_SWORD, P_EXPERT,
		P_BROAD_SWORD, P_SKILLED,         P_LONG_SWORD, P_SKILLED,
		P_TWO_HANDED_SWORD, P_EXPERT,     P_SCIMITAR, P_SKILLED,
		P_SABER, P_BASIC,                 P_CLUB, P_SKILLED,
		P_MACE, P_SKILLED,                P_MORNING_STAR, P_SKILLED,
		P_FLAIL, P_BASIC,                 P_HAMMER, P_EXPERT,
		P_QUARTERSTAFF, P_BASIC,          P_SPEAR, P_SKILLED,
		P_TRIDENT, P_SKILLED,             P_BOW, P_BASIC,
		P_ATTACK_SPELL, P_SKILLED,
		P_RIDING, P_BASIC,
		P_TWO_WEAPON_COMBAT, P_BASIC,
		P_BARE_HANDED_COMBAT, P_MASTER,
		P_NONE, CAVEMAN,
		P_DAGGER, P_BASIC,                P_KNIFE,  P_SKILLED,
		P_AXE, P_SKILLED,                 P_PICK_AXE, P_BASIC,
		P_CLUB, P_EXPERT,                 P_MACE, P_EXPERT,
		P_MORNING_STAR, P_BASIC,          P_FLAIL, P_SKILLED,
		P_HAMMER, P_SKILLED,              P_QUARTERSTAFF, P_EXPERT,
		P_POLEARMS, P_SKILLED,            P_SPEAR, P_EXPERT,
		P_JAVELIN, P_SKILLED,             P_TRIDENT, P_SKILLED,
		P_BOW, P_SKILLED,                 P_SLING, P_EXPERT,
		P_ATTACK_SPELL, P_BASIC,          P_MATTER_SPELL, P_SKILLED,
		P_BOOMERANG, P_EXPERT,            P_UNICORN_HORN, P_BASIC,
		P_BARE_HANDED_COMBAT, P_MASTER,
		P_NONE, HEALER,
		P_DAGGER, P_SKILLED,              P_KNIFE, P_EXPERT,
		P_SHORT_SWORD, P_SKILLED,         P_SCIMITAR, P_BASIC,
		P_SABER, P_BASIC,                 P_CLUB, P_SKILLED,
		P_MACE, P_BASIC,                  P_QUARTERSTAFF, P_EXPERT,
		P_POLEARMS, P_BASIC,              P_SPEAR, P_BASIC,
		P_JAVELIN, P_BASIC,               P_TRIDENT, P_BASIC,
		P_SLING, P_SKILLED,               P_DART, P_EXPERT,
		P_SHURIKEN, P_SKILLED,            P_UNICORN_HORN, P_EXPERT,
		P_HEALING_SPELL, P_EXPERT,
		P_BARE_HANDED_COMBAT, P_BASIC,
		P_NONE, KNIGHT,
		P_DAGGER, P_BASIC,                P_KNIFE, P_BASIC,
		P_AXE, P_SKILLED,                 P_PICK_AXE, P_BASIC,
		P_SHORT_SWORD, P_SKILLED,         P_BROAD_SWORD, P_SKILLED,
		P_LONG_SWORD, P_EXPERT,   P_TWO_HANDED_SWORD, P_SKILLED,
		P_SCIMITAR, P_BASIC,              P_SABER, P_SKILLED,
		P_CLUB, P_BASIC,                  P_MACE, P_SKILLED,
		P_MORNING_STAR, P_SKILLED,        P_FLAIL, P_BASIC,
		P_HAMMER, P_BASIC,                P_POLEARMS, P_SKILLED,
		P_SPEAR, P_SKILLED,               P_JAVELIN, P_SKILLED,
		P_TRIDENT, P_BASIC,               P_LANCE, P_EXPERT,
		P_BOW, P_BASIC,                   P_CROSSBOW, P_SKILLED,
		P_ATTACK_SPELL, P_SKILLED,        P_HEALING_SPELL, P_SKILLED,
		P_CLERIC_SPELL, P_SKILLED,
		P_RIDING, P_EXPERT,
		P_TWO_WEAPON_COMBAT, P_SKILLED,
		P_BARE_HANDED_COMBAT, P_EXPERT,
		P_NONE, MONK,
		P_QUARTERSTAFF, P_BASIC,      P_SPEAR, P_BASIC,
		P_JAVELIN, P_BASIC,                   P_CROSSBOW, P_BASIC,
		P_SHURIKEN, P_BASIC,
		P_ATTACK_SPELL, P_BASIC,      P_HEALING_SPELL, P_EXPERT,
		P_DIVINATION_SPELL, P_BASIC,  P_ENCHANTMENT_SPELL, P_BASIC,
		P_CLERIC_SPELL, P_SKILLED,    P_ESCAPE_SPELL, P_BASIC,
		P_MATTER_SPELL, P_BASIC,
		P_MARTIAL_ARTS, P_GRAND_MASTER,
		P_NONE, PRIEST,
		P_CLUB, P_EXPERT,                 P_MACE, P_EXPERT,
		P_MORNING_STAR, P_EXPERT,         P_FLAIL, P_EXPERT,
		P_HAMMER, P_EXPERT,               P_QUARTERSTAFF, P_EXPERT,
		P_POLEARMS, P_SKILLED,            P_SPEAR, P_SKILLED,
		P_JAVELIN, P_SKILLED,             P_TRIDENT, P_SKILLED,
		P_LANCE, P_BASIC,                 P_BOW, P_BASIC,
		P_SLING, P_BASIC,                 P_CROSSBOW, P_BASIC,
		P_DART, P_BASIC,                  P_SHURIKEN, P_BASIC,
		P_BOOMERANG, P_BASIC,             P_UNICORN_HORN, P_SKILLED,
		P_HEALING_SPELL, P_EXPERT,        P_DIVINATION_SPELL, P_EXPERT,
		P_CLERIC_SPELL, P_EXPERT,
		P_BARE_HANDED_COMBAT, P_BASIC,
		P_NONE, ROGUE,
		P_DAGGER, P_EXPERT,               P_KNIFE,  P_EXPERT,
		P_SHORT_SWORD, P_EXPERT,          P_BROAD_SWORD, P_SKILLED,
		P_LONG_SWORD, P_SKILLED,          P_TWO_HANDED_SWORD, P_BASIC,
		P_SCIMITAR, P_SKILLED,            P_SABER, P_SKILLED,
		P_CLUB, P_SKILLED,                P_MACE, P_SKILLED,
		P_MORNING_STAR, P_BASIC,          P_FLAIL, P_BASIC,
		P_HAMMER, P_BASIC,                P_POLEARMS, P_BASIC,
		P_SPEAR, P_BASIC,                 P_CROSSBOW, P_EXPERT,
		P_DART, P_EXPERT,                 P_SHURIKEN, P_SKILLED,
		P_DIVINATION_SPELL, P_SKILLED,    P_ESCAPE_SPELL, P_SKILLED,
		P_MATTER_SPELL, P_SKILLED,
		P_RIDING, P_BASIC,
		P_TWO_WEAPON_COMBAT, P_EXPERT,
		P_BARE_HANDED_COMBAT, P_EXPERT,
		P_NONE, RANGER,
		P_DAGGER, P_EXPERT,                P_KNIFE,  P_SKILLED,
		P_AXE, P_SKILLED,          P_PICK_AXE, P_BASIC,
		P_SHORT_SWORD, P_BASIC,    P_MORNING_STAR, P_BASIC,
		P_FLAIL, P_SKILLED,        P_HAMMER, P_BASIC,
		P_QUARTERSTAFF, P_BASIC,   P_POLEARMS, P_SKILLED,
		P_SPEAR, P_SKILLED,        P_JAVELIN, P_EXPERT,
		P_TRIDENT, P_BASIC,        P_BOW, P_EXPERT,
		P_SLING, P_EXPERT,         P_CROSSBOW, P_EXPERT,
		P_DART, P_EXPERT,          P_SHURIKEN, P_SKILLED,
		P_BOOMERANG, P_EXPERT,     P_WHIP, P_BASIC,
		P_HEALING_SPELL, P_BASIC,
		P_DIVINATION_SPELL, P_EXPERT,
		P_ESCAPE_SPELL, P_BASIC,
		P_RIDING, P_BASIC,
		P_BARE_HANDED_COMBAT, P_BASIC,
		P_NONE, SAMURAI,
		P_DAGGER, P_BASIC,                P_KNIFE,  P_SKILLED,
		P_SHORT_SWORD, P_EXPERT,          P_BROAD_SWORD, P_SKILLED,
		P_LONG_SWORD, P_EXPERT,           P_TWO_HANDED_SWORD, P_EXPERT,
		P_SCIMITAR, P_BASIC,              P_SABER, P_BASIC,
		P_FLAIL, P_SKILLED,               P_QUARTERSTAFF, P_BASIC,
		P_POLEARMS, P_SKILLED,            P_SPEAR, P_BASIC,
		P_JAVELIN, P_BASIC,               P_LANCE, P_SKILLED,
		P_BOW, P_EXPERT,                  P_SHURIKEN, P_EXPERT,
		P_ATTACK_SPELL, P_SKILLED,        P_CLERIC_SPELL, P_SKILLED,
		P_RIDING, P_SKILLED,
		P_TWO_WEAPON_COMBAT, P_EXPERT,
		P_MARTIAL_ARTS, P_MASTER,
		P_NONE, TOURIST,
		P_DAGGER, P_EXPERT,               P_KNIFE,  P_SKILLED,
		P_AXE, P_BASIC,                   P_PICK_AXE, P_BASIC,
		P_SHORT_SWORD, P_EXPERT,          P_BROAD_SWORD, P_BASIC,
		P_LONG_SWORD, P_BASIC,            P_TWO_HANDED_SWORD, P_BASIC,
		P_SCIMITAR, P_SKILLED,            P_SABER, P_SKILLED,
		P_MACE, P_BASIC,                  P_MORNING_STAR, P_BASIC,
		P_FLAIL, P_BASIC,                 P_HAMMER, P_BASIC,
		P_QUARTERSTAFF, P_BASIC,          P_POLEARMS, P_BASIC,
		P_SPEAR, P_BASIC,                 P_JAVELIN, P_BASIC,
		P_TRIDENT, P_BASIC,               P_LANCE, P_BASIC,
		P_BOW, P_BASIC,                   P_SLING, P_BASIC,
		P_CROSSBOW, P_BASIC,              P_DART, P_EXPERT,
		P_SHURIKEN, P_BASIC,              P_BOOMERANG, P_BASIC,
		P_WHIP, P_BASIC,                  P_UNICORN_HORN, P_SKILLED,
		P_DIVINATION_SPELL, P_BASIC,      P_ENCHANTMENT_SPELL, P_BASIC,
		P_ESCAPE_SPELL, P_SKILLED,
		P_RIDING, P_BASIC,
		P_TWO_WEAPON_COMBAT, P_SKILLED,
		P_BARE_HANDED_COMBAT, P_SKILLED,
		P_NONE, VALKYRIE,
		P_DAGGER, P_EXPERT,               P_AXE, P_EXPERT,
		P_PICK_AXE, P_SKILLED,            P_SHORT_SWORD, P_SKILLED,
		P_BROAD_SWORD, P_SKILLED,         P_LONG_SWORD, P_EXPERT,
		P_TWO_HANDED_SWORD, P_EXPERT,     P_SCIMITAR, P_BASIC,
		P_SABER, P_BASIC,                 P_HAMMER, P_EXPERT,
		P_QUARTERSTAFF, P_BASIC,          P_POLEARMS, P_SKILLED,
		P_SPEAR, P_SKILLED,               P_JAVELIN, P_BASIC,
		P_TRIDENT, P_BASIC,               P_LANCE, P_SKILLED,
		P_SLING, P_BASIC,
		P_ATTACK_SPELL, P_BASIC,          P_ESCAPE_SPELL, P_BASIC,
		P_RIDING, P_SKILLED,
		P_TWO_WEAPON_COMBAT, P_SKILLED,
		P_BARE_HANDED_COMBAT, P_EXPERT,
		P_NONE, WIZARD,
		P_DAGGER, P_EXPERT,               P_KNIFE,  P_SKILLED,
		P_AXE, P_SKILLED,                 P_SHORT_SWORD, P_BASIC,
		P_CLUB, P_SKILLED,                P_MACE, P_BASIC,
		P_QUARTERSTAFF, P_EXPERT,         P_POLEARMS, P_SKILLED,
		P_SPEAR, P_BASIC,                 P_JAVELIN, P_BASIC,
		P_TRIDENT, P_BASIC,               P_SLING, P_SKILLED,
		P_DART, P_EXPERT,                 P_SHURIKEN, P_BASIC,
		P_ATTACK_SPELL, P_EXPERT,         P_HEALING_SPELL, P_SKILLED,
		P_DIVINATION_SPELL, P_EXPERT,     P_ENCHANTMENT_SPELL, P_SKILLED,
		P_CLERIC_SPELL, P_SKILLED,        P_ESCAPE_SPELL, P_EXPERT,
		P_MATTER_SPELL, P_EXPERT,
		P_RIDING, P_BASIC,
		P_BARE_HANDED_COMBAT, P_BASIC,
		P_NONE, UNKNOWN_ROLE
	};

	for (const char** lnp = ilnames; *lnp; ++lnp)
		_level_names.push_back(string(*lnp));

	for (const char** snp = isnames; *snp; ++snp)
		_names.push_back(string(*snp));

	vector<int>* cri;
	for (int* rmp = roledata; ; rmp += 2) {
		if (rmp[0] == P_NONE) {
			if (rmp[1] == UNKNOWN_ROLE)
				break;
			cri = &_role_maxima[rmp[1]];
			cri->resize(P_NUM_SKILLS, P_UNSKILLED);
		} else {
			(*cri)[rmp[0]] = rmp[1];
		}
	}
}

int Skill::parse(const string& name) {
	for (int i = 1; i < P_NUM_SKILLS; ++i) {
		if (_names[i] == name)
			return i;
	}
	return P_NONE;
}

const string& Skill::name(int skill) {
	return _names[skill];
}

const vector<string>& Skill::names() {
	return _names;
}

int Skill::levelParse(const string& name) {
	for (int i = 1; i <= P_GRAND_MASTER; ++i) {
		if (_level_names[i] == name)
			return i;
	}
	return 0;
}

const string& Skill::levelName(int level) {
	return _level_names[level];
}

const vector<string>& Skill::levelNames() {
	return _level_names;
}

int Skill::roleMax(int role, int skill) {
	if (role == UNKNOWN_ROLE)
		return P_UNSKILLED;
	return _role_maxima[role][skill];
}
#include "Creature.h"


// Base class
int Creature::count = 0;

Creature::Creature() {
	this->id = count++;
};

Creature::~Creature() {};

int Creature::getId() const {
	return id;
};

int Creature::getCount() {
	return count;
}

void Creature::printInfo() const {
	emptyLine();
	cout << HORIZONTAL_LINE << endl;
	cout << "Id: " << id << endl;
}

void Creature::printShort() const {
	cout << HORIZONTAL_LINE << endl;
	cout << "Id: " << id << endl;
}

// First step class
DummyCreature::DummyCreature(const EnumElement& type) {
	this->type = type;
	this->name = getNameFor(type);
}

DummyCreature::~DummyCreature() {
}

EnumElement DummyCreature::getType() const {
	return type;
}

string DummyCreature::getName() const {
	return name;
}

void DummyCreature::setName(const string& name) {
	this->name = name;
}

void DummyCreature::printInfo() const {
	//Creature::printInfo();
	cout << "Name: " << name << endl;
	cout << "Element: " << getElementTxt(type) << endl;
}

void DummyCreature::printShort() const {
	Creature::printInfo();
	cout << "Name: " << name << endl;
	cout << "Element: " << getElementTxt(type) << endl;
}

/*
	CAPABLE CREATURE - provide basic stats
*/


int CapableCreature::calculateHp() const {
	return curStrength * 3 + curDexterity;
}

CapableCreature::CapableCreature(const EnumElement& element) : DummyCreature(element) {
	this->maxStrength = getRandomFrom(CREAT_MIN_STRENGTH, CREAT_STARTING_STRENGTH_BOUND);
	this->maxDexterity = getRandomFrom(CREAT_MIN_DEXTERITY, CREAT_STARTING_DEXTERITY_BOUND);
	this->curStrength = maxStrength;
	this->curDexterity = maxDexterity;
	this->maxHp = calculateHp();
	this->curHp = maxHp;
	this->selected = false;
}

CapableCreature::~CapableCreature() {};

int CapableCreature::getMaxStrength() const {
	return maxStrength;
}

int CapableCreature::getCurStrength() const {
	return curStrength;
}

int CapableCreature::getMaxDexterity() const {
	return maxDexterity;
}

int CapableCreature::getCurDexterity() const {
	return curDexterity;
}

int CapableCreature::getMaxHp() const {
	return maxHp;
}

int CapableCreature::getCurHp() const {
	return curHp;
}

bool CapableCreature::isSelected() const {
	return selected;
}

void CapableCreature::setMaxStrength(const int val) {
	this->maxStrength = val;
}

void CapableCreature::setCurStrength(const int val) {
	this->curStrength = val;
}

void CapableCreature::setMaxDexterity(const int val) {
	this->maxDexterity = val;
}

void CapableCreature::setCurDexterity(const int val) {
	this->curDexterity = val;
}

void CapableCreature::setMaxHp(const int val) {
	this->maxHp = val;
}

void CapableCreature::setCurHp(const int val) {
	this->curHp = val;
}

void CapableCreature::setSelected(const bool val) {
	this->selected = val;
}

void CapableCreature::printInfo() const {
	Creature::printInfo();
	DummyCreature::printInfo();
	cout << "Strength: " << curStrength << " / " << maxStrength << endl;
	cout << "Dexterity: " << curDexterity << " / " << maxDexterity << endl;
	cout << "HP: " << curHp << " / " << maxHp << endl;
}

void CapableCreature::printShort() const {
	cout << "[ " << id << " ] = " << name << " (" << getElementTxt(type) << ") STR: " << maxStrength << " DEX: " << maxDexterity << " HP: " << maxHp << endl;
}

FightingCreature::FightingCreature(const EnumElement& element) : CapableCreature(element) {
	this->xp = 0;
	this->maxLevel = 0;
	this->curLevel = 0;
};

FightingCreature::~FightingCreature() {}

int FightingCreature::getXp() const {
	return xp;
}

void FightingCreature::setXp(const int val) {
	xp = val > xp ? val : xp;
}

void FightingCreature::addXp(const int val) {
	if (val > 0) {
		setXp(getXp() + val);
	}
}

int FightingCreature::getCurLevel() const {
	return curLevel;
}

void FightingCreature::setCurLevel(const int val) {
	curLevel = val > curLevel ? val : curLevel;
}

int FightingCreature::getMaxLevel() const {
	return maxLevel;
}

void FightingCreature::setMaxLevel(const int val) {
	maxLevel = val > maxLevel ? val : maxLevel;
}

void FightingCreature::printInfo() const {
	Creature::printInfo();
	DummyCreature::printInfo();
	CapableCreature::printInfo();
	cout << "XP: " << xp << endl;
	cout << "Level: " << curLevel << " / " << maxLevel << endl;
}

void FightingCreature::printShort() const {
	cout << "[ " << id << " ] = " << name << " (" << getElementTxt(type) << ") STR: " << maxStrength << " DEX: " << maxDexterity << " HP: " << maxHp << " XP: " << xp << " Lvl: " << curLevel << endl;
}

bool FightingCreature::strike(const FightingCreature& other) const {
	int bonusToHit = 0;
	int bonusToAvoid = 0;
	if (compareElementWith(other) == 1) {
		bonusToHit += dice(6, 3);
	}
	else if (compareElementWith(other) == -1) {
		bonusToAvoid += dice(6, 1);
	}
	
	int chanceToHit = curStrength + dice(10) + bonusToHit;
	int chanceToAvoid = other.curDexterity + dice(8) + bonusToAvoid;
	return chanceToHit > chanceToAvoid;
}

int FightingCreature::compareElementWith(const FightingCreature& other) const {
	return compareMix(getType(), other.getType());
}

int FightingCreature::calculateHit(const FightingCreature& other) const {
	int bonusToHit = 0;
	if (compareElementWith(other) == 1) {
		bonusToHit += dice(10, 3);
	}
	else if (compareElementWith(other) == -1) {
		bonusToHit += dice(6);
	}
	else {
		bonusToHit += dice(10);
	}
	return curStrength + bonusToHit;
}

void FightingCreature::takeHarm(const int val) {
	if (val > 0) {
		curHp = val > curHp ? 0 : curHp - val;
	}
}

int FightingCreature::calculateXp(const FightingCreature& other) const {
	int bonusLevel = other.curLevel - curLevel > 0 ? other.curLevel - curLevel * 50 : 0;
	return other.getMaxHp() + bonusLevel;
}

int FightingCreature::calculateMaxLevel() const {
	if (xp < 201) {
		return xp / 50;
	}
	else {
		return (xp - 200) / 150;
	}
}

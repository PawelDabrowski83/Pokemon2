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
const static int CREAT_MIN_STRENGTH = 1;
const static int CREAT_MAX_STRENGTH = 20;
const static int CREAT_STARTING_STRENGTH_BOUND = 6;
const static int CREAT_MIN_DEXTERITY = 1;
const static int CREAT_MAX_DEXTERITY = 20;
const static int CREAT_STARTING_DEXTERITY_BOUND = 6;

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
	selected = val;
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

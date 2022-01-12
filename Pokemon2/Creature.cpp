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
}

CapableCreature::~CapableCreature() {};


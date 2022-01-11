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

/*

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

*/
#pragma once
#include "Utils.h"
#include "EnumElements.h"
#include <string>

using std::string;

class Creature {
protected:
	static int count;
	int id;
public:
	int getId() const;
	Creature();
	virtual ~Creature();
};

class DummyCreature : public Creature {
protected:
	EnumElement type;
	string name;
public:
	DummyCreature(const EnumElement&);
	~DummyCreature();
	string getName() const;
	void setName(const string&);
	EnumElement getType() const;
};

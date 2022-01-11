#pragma once
#include "MessageSeparator.h"
#include "Utils.h"
#include <string>
#include <iostream>

using std::string;
using std::endl;
using std::cout;

class Creature {
protected:
	static int count;
	int id;
public:
	int getId() const;
	Creature();
	virtual ~Creature();
	virtual void printInfo() const;
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
	virtual void printInfo() const;
};

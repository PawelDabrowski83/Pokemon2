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
	virtual ~DummyCreature();
	string getName() const;
	void setName(const string&);
	EnumElement getType() const;
	virtual void printInfo() const;
};

class CapableCreature : public DummyCreature {
protected:
	int curStrength;
	int curDexterity;
	int curHp;
	int maxStrength;
	int maxDexterity;
	int maxHp;
public:
	int calculateHp() const;
	CapableCreature(const EnumElement&);
	~CapableCreature();
	int getCurStrength() const;
	void setCurStrength(const int);
	int getCurDexterity() const;
	void setCurDexterity(const int);
	int getCurHp() const;
	void setCurHp(const int);
	int getMaxStrength() const;
	void setMaxStrength(const int);
	int getMaxDexterity() const;
	void setMaxDexterity(const int);
	int getMaxHp() const;
	void setMaxHp(const int);
	virtual void printInfo() const;
};
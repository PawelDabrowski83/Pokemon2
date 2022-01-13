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
	virtual void printShort() const;
	static int getCount();
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
	virtual void printShort() const;
};

const static int CREAT_MIN_STRENGTH = 1;
const static int CREAT_MAX_STRENGTH = 20;
const static int CREAT_STARTING_STRENGTH_BOUND = 6;
const static int CREAT_MIN_DEXTERITY = 1;
const static int CREAT_MAX_DEXTERITY = 20;
const static int CREAT_STARTING_DEXTERITY_BOUND = 6;

class CapableCreature : public DummyCreature {
protected:
	int curStrength;
	int curDexterity;
	int curHp;
	int maxStrength;
	int maxDexterity;
	int maxHp;
	bool selected;
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
	bool isSelected() const;
	void setSelected(const bool);
	
	virtual void printInfo() const;
	virtual void printShort() const;
};

class FightingCreature : public CapableCreature {
protected:
	int xp;
	int curLevel;
	int maxLevel;
public:
	FightingCreature(const EnumElement&);
	virtual ~FightingCreature();
	int getXp() const;
	void setXp(const int);
	void addXp(const int);
	int getCurLevel() const;
	void setCurLevel(const int);
	int getMaxLevel() const;
	void setMaxLevel(const int);

	virtual void printInfo() const;
	virtual void printShort() const;

	bool attack(const FightingCreature&) const;
	int calculateHit(const FightingCreature&) const;
	int compareElementWith(const FightingCreature&) const;
	void takeHarm(const int);
	int calculateXp(const FightingCreature&) const;
	int calculateMaxLevel() const;
};
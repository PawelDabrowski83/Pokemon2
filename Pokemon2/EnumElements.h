#pragma once

enum EnumElement
{
	FIRE,
	WATER,
	AIR,
	EARTH,
	ICE,
	STEEL
};

inline const char* toString(EnumElement v)
{
    switch (v)
    {
    case FIRE:      return "Fire";
    case WATER:     return "Water";
    case AIR:       return "Air";
    case EARTH:     return "Earth";
    case ICE:       return "Ice";
    case STEEL:     return "Steel";
    default:      return "[Unknown]";
    }
}

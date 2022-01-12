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

// toString txt to: https://stackoverflow.com/a/5094430/13521548
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
    default:        return "[Unknown]";
    }
}

int compare(const EnumElement& source, const EnumElement& target) {
    switch (source) {
        case FIRE:
            switch (target) {
                case ICE:       case STEEL:     return 1;
                case WATER:     case EARTH:     return -1;
                default:        return 0;
             }
            break;
        case WATER:
            switch (target) {
                case WATER:     return -1;
                case EARTH:     case FIRE:      return 1;
                default:        return 0;
            }
            break;
        case AIR:
            switch (target) {
                case ICE:       return 1;
                case EARTH:     case STEEL:     return -1;
                default:        return 0;
            }
            break;
        case EARTH:
            switch (target) {
                case AIR:       return -1;
                case FIRE:      case ICE:       case STEEL:     return 1;
                default:        return 0;
            }
            break;
        case ICE:
            switch (target) {
                case EARTH:     return 1;
                case WATER:     case FIRE:      case ICE:       return -1;
                default:        return 0;
            }
            break;
        case STEEL:
            switch (target) {
                case FIRE:      case STEEL:     return -1;
                case WATER:     case AIR:       return 1;
                default:        return 0;
            }
            break;
        default: break;
    }
    return 0;
}

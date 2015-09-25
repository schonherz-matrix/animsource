#include "animfactory.h"
#include "chessanim.h"
#include "verticalanim.h"
#include "solidanim.h"

const std::map<std::string, AnimFactory::AnimType> AnimFactory::AnimTypeString = {
    {"Chess", CHESS},
    {"Vertical", VERTICAL},
    {"Horizontal", HORIZONTAL},
    {"Solid", SOLID}
};

AnimInterface* AnimFactory::getAnim(AnimType type, const SourceConfiguration& configuration, const QColor& primary_color, const QColor& secondary_color, int num) {
    switch (type) {
    case CHESS:
    {
        return new ChessAnim{configuration, primary_color, secondary_color, num};
    }
        break;
    case VERTICAL:
    {
        return new VerticalAnim{configuration, primary_color, secondary_color, num, true};
    }
        break;
    case HORIZONTAL:
    {
        return new VerticalAnim{configuration, primary_color, secondary_color, num, false};
    }
        break;
    case SOLID:
    {
        return new SolidAnim{configuration, primary_color, secondary_color, num};
    }
        break;
    default:
    {
        return nullptr;
    }
    }
}

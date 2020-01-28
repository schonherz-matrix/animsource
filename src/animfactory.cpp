#include "animfactory.h"
#include "chessanim.h"
#include "solidanim.h"
#include "verticalanim.h"

AnimFactory::AnimFactory(QObject *parent) : QObject(parent) {}

const std::map<AnimFactory::AnimType, QString> AnimFactory::AnimTypeString = {
    {CHESS, "Chess"},
    {VERTICAL, "Vertical"},
    {HORIZONTAL, "Horizontal"},
    {SOLID, "Solid"}};

std::unique_ptr<AbstractAnimation> AnimFactory::getAnimation(
    AnimType type, const QColor &primaryColor, const QColor &secondaryColor) {
  switch (type) {
    case CHESS:
      return std::make_unique<ChessAnim>(primaryColor, secondaryColor);
    case VERTICAL:
      return std::make_unique<VerticalAnim>(primaryColor, secondaryColor, true);

    case HORIZONTAL:
      return std::make_unique<VerticalAnim>(primaryColor, secondaryColor,
                                            false);
    case SOLID:
      return std::make_unique<SolidAnim>(primaryColor, secondaryColor);
  }

  return nullptr;
}

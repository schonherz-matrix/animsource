#include "abstractanimation.h"

AbstractAnimation::AbstractAnimation(const QColor &primaryColor,
                                     const QColor &secondaryColor)
    : m_primaryColor(primaryColor), m_secondaryColor(secondaryColor) {
  m_frame.fill(Qt::black);
}

void AbstractAnimation::setPrimaryColor(const QColor &color) {
  m_primaryColor = color;
  primaryColorChanged();
}

void AbstractAnimation::setSecondaryColor(const QColor &color) {
  m_secondaryColor = color;
  secondaryColorChanged();
}

int AbstractAnimation::animationSpeed() const
{
    return m_animationSpeed;
}

#include "abstractanimation.h"

#include "muebtransmitter.h"

AbstractAnimation::AbstractAnimation(const QColor &primaryColor,
                                     const QColor &secondaryColor)
    : m_primaryColor(primaryColor), m_secondaryColor(secondaryColor) {
  auto &transmitter = libmueb::MuebTransmitter::Instance();
  m_frame = transmitter.frame();
  window_per_floor_ = transmitter.window_per_floor();
  windows_ = transmitter.windows();
  floors_ = transmitter.floors();
  horizontal_pixel_unit_ = transmitter.horizontal_pixel_unit();
  vertical_pixel_unit_ = transmitter.vertical_pixel_unit();
}

void AbstractAnimation::setPrimaryColor(const QColor &color) {
  m_primaryColor = color;
  primaryColorChanged();
}

void AbstractAnimation::setSecondaryColor(const QColor &color) {
  m_secondaryColor = color;
  secondaryColorChanged();
}

int AbstractAnimation::animationSpeed() const { return m_animationSpeed; }

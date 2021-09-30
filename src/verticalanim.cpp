#include "verticalanim.h"

VerticalAnim::VerticalAnim(const QColor& primaryColor,
                           const QColor& secondary_color, bool isVertical)
    : AbstractAnimation(primaryColor, secondary_color),
      m_isVertical(isVertical) {
  m_animationSpeed = 5;
}

QImage VerticalAnim::nextFrame() {
  for (int row = 0; row < m_frame.height(); row++) {
    for (int col = 0; col < m_frame.width(); col++) {
      int r = 0;
      int g = 0;
      int number = 0;

      if (m_isVertical) {
        number = m_tick + row * 10;

        if ((number % 512) > 255) {
          r = 255 - (number % 256);
        } else {
          r = number % 256;
        }

        if ((((m_tick + 256) + row * 10) % 512) > 255) {
          g = 255 - (number % 256);
        } else {
          g = number % 256;
        }
      } else {
        number = m_tick + col * 10;

        if ((number % 512) > 255) {
          r = 255 - (number % 256);
        } else {
          r = number % 256;
        }

        if ((((m_tick + 256) + col * 10) % 512) > 255) {
          g = 255 - (number % 256);
        } else {
          g = number % 256;
        }
      }

      double first_percent = r / 255.0;
      double second_percent = g / 255.0;

      m_frame.setPixelColor(
          col, row,
          QColor(m_primaryColor.red() * first_percent +
                     m_secondaryColor.red() * second_percent,
                 m_primaryColor.green() * first_percent +
                     m_secondaryColor.green() * second_percent,
                 m_primaryColor.blue() * first_percent +
                     m_secondaryColor.blue() * second_percent));
    }
  }

  m_tick++;
  return m_frame;
}

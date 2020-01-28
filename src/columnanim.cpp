#include "columnanim.h"

#include "libmueb_global.h"

ColumnAnim::ColumnAnim(const QColor &primaryColor, const QColor &secondaryColor)
    : AbstractAnimation(primaryColor, secondaryColor) {
  generateFrames();
}

void ColumnAnim::generateFrames() {
  using namespace libmueb::defaults;

  for (int windowIdx = 0; windowIdx < windows; ++windowIdx) {
    auto row = (windowIdx / windowPerRow) * verticalPixelUnit;
    auto col = (windowIdx % windowPerRow) * horizontalPixelUnit;

    for (int y = 0; y < verticalPixelUnit; ++y) {
      for (int x = 0; x < horizontalPixelUnit; ++x) {
        if (windowIdx % 2 == 0)
          m_frame.setPixelColor(col + x, row + y, m_primaryColor);
        else
          m_secondFrame.setPixelColor(col + x, row + y, m_secondaryColor);
      }
    }
  }
}

QImage ColumnAnim::nextFrame() {
  m_first = !m_first;

  if (m_first)
    return m_frame;
  else
    return m_secondFrame;
}

void ColumnAnim::primaryColorChanged() { generateFrames(); }

void ColumnAnim::secondaryColorChanged() { generateFrames(); }

#include "rowanim.h"

RowAnim::RowAnim(const QColor &primaryColor, const QColor &secondaryColor)
    : AbstractAnimation(primaryColor, secondaryColor) {
  generateFrames();
}

void RowAnim::generateFrames() {
  for (int windowIdx = 0; windowIdx < windows_; ++windowIdx) {
    auto row = (windowIdx / window_per_floor_) * vertical_pixel_unit_;
    auto col = (windowIdx % window_per_floor_) * horizontal_pixel_unit_;

    for (int y = 0; y < vertical_pixel_unit_; ++y) {
      for (int x = 0; x < horizontal_pixel_unit_; ++x) {
        if ((windowIdx / window_per_floor_) % 2 == 0)
          m_frame.setPixelColor(col + x, row + y, m_primaryColor);
        else
          m_secondFrame.setPixelColor(col + x, row + y, m_secondaryColor);
      }
    }
  }
}

QImage RowAnim::nextFrame() {
  m_first = !m_first;

  if (m_first)
    return m_frame;
  else
    return m_secondFrame;
}

void RowAnim::primaryColorChanged() { generateFrames(); }

void RowAnim::secondaryColorChanged() { generateFrames(); }

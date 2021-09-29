#include "rowanim.h"

RowAnim::RowAnim(const QColor &primaryColor, const QColor &secondaryColor)
    : AbstractAnimation(primaryColor, secondaryColor) {}

QImage RowAnim::nextFrame() {
  m_frame.fill(Qt::black);

  auto row = m_row * vertical_pixel_unit_;

  for (int col = 0; col < window_per_floor_; ++col) {
    for (int y = 0; y < vertical_pixel_unit_; ++y) {
      for (int x = 0; x < horizontal_pixel_unit_; ++x) {
        m_frame.setPixelColor(col * horizontal_pixel_unit_ + x, row + y,
                              m_primaryColor);
      }
    }
  }

  m_row++;
  if (m_row == floors_) m_row = 0;

  return m_frame;
}

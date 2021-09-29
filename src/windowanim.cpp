#include "windowanim.h"

WindowAnim::WindowAnim(const QColor& primaryColor, const QColor& secondaryColor)
    : AbstractAnimation(primaryColor, secondaryColor) {
  m_animationSpeed = 50;
}

QImage WindowAnim::nextFrame() {
  if (m_done) return m_frame;

  auto row = (m_windowIdx / window_per_floor_) * vertical_pixel_unit_;
  auto col = (m_windowIdx % window_per_floor_) * horizontal_pixel_unit_;

  for (int y = 0; y < vertical_pixel_unit_; ++y) {
    for (int x = 0; x < horizontal_pixel_unit_; ++x) {
      m_frame.setPixelColor(col + x, row + y,
                            (m_first) ? m_primaryColor : m_secondaryColor);
    }
  }

  m_first = !m_first;
  m_windowIdx++;
  if (m_windowIdx == windows_) m_done = true;

  return m_frame;
}

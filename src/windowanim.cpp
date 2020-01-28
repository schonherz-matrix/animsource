#include "windowanim.h"

#include "libmueb_global.h"

WindowAnim::WindowAnim(const QColor& primaryColor, const QColor& secondaryColor)
    : AbstractAnimation(primaryColor, secondaryColor) {
  m_animationSpeed = 50;
}

QImage WindowAnim::nextFrame() {
  if (m_done) return m_frame;

  using namespace libmueb::defaults;

  auto row = (m_windowIdx / windowPerRow) * verticalPixelUnit;
  auto col = (m_windowIdx % windowPerRow) * horizontalPixelUnit;

  for (int y = 0; y < verticalPixelUnit; ++y) {
    for (int x = 0; x < horizontalPixelUnit; ++x) {
      m_frame.setPixelColor(col + x, row + y,
                            (m_first) ? m_primaryColor : m_secondaryColor);
    }
  }

  m_first = !m_first;
  m_windowIdx++;
  if (m_windowIdx == windows) m_done = true;

  return m_frame;
}

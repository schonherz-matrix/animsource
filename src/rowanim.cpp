#include "rowanim.h"

#include "libmueb_global.h"

RowAnim::RowAnim(const QColor &primaryColor, const QColor &secondaryColor)
    : AbstractAnimation(primaryColor, secondaryColor) {}

QImage RowAnim::nextFrame() {
  using namespace libmueb::defaults;

  m_frame.fill(Qt::black);

  auto row = m_row * verticalPixelUnit;

  for (int col = 0; col < windowPerRow; ++col) {
    for (int y = 0; y < verticalPixelUnit; ++y) {
      for (int x = 0; x < horizontalPixelUnit; ++x) {
        m_frame.setPixelColor(col * horizontalPixelUnit + x, row + y,
                              m_primaryColor);
      }
    }
  }

  m_row++;
  if (m_row == rows) m_row = 0;

  return m_frame;
}

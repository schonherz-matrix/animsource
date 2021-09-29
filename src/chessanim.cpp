#include "chessanim.h"

#include "muebtransmitter.h"

ChessAnim::ChessAnim(const QColor& primaryColor, const QColor& secondaryColor)
    : AbstractAnimation(primaryColor, secondaryColor) {
  generateFrames();
}

void ChessAnim::generateFrames() {
  for (int row = 0; row < m_frame.height(); row++) {
    for (int col = 0; col < m_frame.width(); col++) {
      m_frame.setPixelColor(
          col, row,
          ((col / horizontal_pixel_unit_ + row / vertical_pixel_unit_) % 2)
              ? m_primaryColor
              : m_secondaryColor);
      m_secondFrame.setPixelColor(
          col, row,
          ((col / horizontal_pixel_unit_ + row / vertical_pixel_unit_) % 2)
              ? m_secondaryColor
              : m_primaryColor);
    }
  }
}

QImage ChessAnim::nextFrame() {
  m_first = !m_first;

  if (m_first) {
    return m_frame;
  } else {
    return m_secondFrame;
  }
}

void ChessAnim::primaryColorChanged() { generateFrames(); }

void ChessAnim::secondaryColorChanged() { generateFrames(); }

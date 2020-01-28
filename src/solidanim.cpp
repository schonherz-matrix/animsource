#include "solidanim.h"

SolidAnim::SolidAnim(const QColor& primaryColor, const QColor& secondaryColor)
    : AbstractAnimation(primaryColor, secondaryColor) {
  m_frame.fill(primaryColor);
  m_secondFrame.fill(secondaryColor);
}

QImage SolidAnim::nextFrame() {
  m_first = !m_first;

  if (m_first)
    return m_frame;
  else
    return m_secondFrame;
}

void SolidAnim::primaryColorChanged() { m_frame.fill(m_primaryColor); }

void SolidAnim::secondaryColorChanged() {
  m_secondFrame.fill(m_secondaryColor);
}

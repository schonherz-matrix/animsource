#ifndef VERTICALANIM_H
#define VERTICALANIM_H

#include "abstractanimation.h"

class VerticalAnim : public AbstractAnimation {
 public:
  VerticalAnim(const QColor& primary_color, const QColor& secondary_color,
               bool isVertical);
  QImage nextFrame() override;

 private:
  int m_tick{0};
  bool m_isVertical;
};

#endif  // VERTICALANIM_H

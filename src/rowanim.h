#ifndef ROWANIM_H
#define ROWANIM_H

#include "abstractanimation.h"

class RowAnim : public AbstractAnimation {
 public:
  RowAnim(const QColor& primaryColor, const QColor& secondaryColor);

  // AbstractAnimation interface
  QImage nextFrame() override;

 private:
  int m_row{0};
};

#endif  // ROWANIM_H

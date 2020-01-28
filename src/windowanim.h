#ifndef WINDOWANIM_H
#define WINDOWANIM_H

#include "abstractanimation.h"

class WindowAnim : public AbstractAnimation {
 public:
  WindowAnim(const QColor& primaryColor, const QColor& secondaryColor);

  // AbstractAnimation interface
  QImage nextFrame() override;

 private:
  int m_windowIdx{0};
  bool m_first{false};
  bool m_done{false};
};

#endif  // WINDOWANIM_H

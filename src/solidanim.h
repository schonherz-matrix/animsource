#ifndef SOLID_ANIM_H
#define SOLID_ANIM_H

#include "abstractanimation.h"

class SolidAnim : public AbstractAnimation {
 public:
  SolidAnim(const QColor& primaryColor, const QColor& secondaryColor);
  QImage nextFrame() override;

 private:
  bool m_first{false};
  QImage m_secondFrame{m_frame};

  // AbstractAnimation interface
 protected:
  void primaryColorChanged() override;
  void secondaryColorChanged() override;
};

#endif

#ifndef ROWANIM_H
#define ROWANIM_H

#include "abstractanimation.h"

class RowAnim : public AbstractAnimation {
 public:
  RowAnim(const QColor& primaryColor, const QColor& secondaryColor);

  // AbstractAnimation interface
  QImage nextFrame() override;

  // AbstractAnimation interface
 protected:
  void primaryColorChanged() override;
  void secondaryColorChanged() override;

 private:
  QImage m_secondFrame{m_frame};
  bool m_first{false};

  void generateFrames();
};

#endif  // ROWANIM_H

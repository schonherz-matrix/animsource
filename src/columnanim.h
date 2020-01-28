#ifndef COLUMNANIM_H
#define COLUMNANIM_H

#include "abstractanimation.h"

class ColumnAnim : public AbstractAnimation {
 public:
  ColumnAnim(const QColor& primaryColor, const QColor& secondaryColor);

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

#endif  // COLUMNANIM_H

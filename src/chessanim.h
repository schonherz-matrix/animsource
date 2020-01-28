#ifndef CHESS_ANIM_H
#define CHESS_ANIM_H

#include "abstractanimation.h"

class ChessAnim : public AbstractAnimation {
 public:
  ChessAnim(const QColor& primaryColor, const QColor& secondaryColor);
  QImage nextFrame() override;

  // AbstractAnimation interface
 protected:
  void primaryColorChanged() override;
  void secondaryColorChanged() override;

 private:
  bool m_first{false};
  QImage m_secondFrame{m_frame};

  void generateFrames();
};

#endif

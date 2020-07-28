#ifndef ABSTRACTANIMATION_H
#define ABSTRACTANIMATION_H

#include <QImage>

#include "libmuebconfig.h"

class AbstractAnimation {
 public:
  AbstractAnimation() {}
  AbstractAnimation(const QColor &primaryColor, const QColor &secondaryColor);

  virtual ~AbstractAnimation() {}
  virtual QImage nextFrame() = 0;
  void setPrimaryColor(const QColor &color);
  void setSecondaryColor(const QColor &color);
  int animationSpeed() const;

 protected:
  QColor m_primaryColor, m_secondaryColor;
  QImage m_frame{libmueb::defaults::frame};
  int m_animationSpeed{500};

  virtual void primaryColorChanged() {}
  virtual void secondaryColorChanged() {}
};

#endif  // ABSTRACTANIMATION_H

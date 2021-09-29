#ifndef ABSTRACTANIMATION_H
#define ABSTRACTANIMATION_H

#include <QImage>

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
  QImage m_frame;
  int m_animationSpeed{500};
  quint32 window_per_floor_;
  quint32 windows_;
  quint32 floors_;
  quint8 horizontal_pixel_unit_;
  quint8 vertical_pixel_unit_;

  virtual void primaryColorChanged() {}
  virtual void secondaryColorChanged() {}
};

#endif  // ABSTRACTANIMATION_H

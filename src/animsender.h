#ifndef DRAW_SENDER_H
#define DRAW_SENDER_H

#include <QWidget>
#include <memory>

#include "animfactory.h"
#include "muebtransmitter.h"

namespace Ui {
class AnimSender;
}

class AnimSender : public QWidget {
  Q_OBJECT

 public:
  AnimSender(QWidget* parent = nullptr);
  ~AnimSender();

  // QObject interface
 protected:
  void timerEvent(QTimerEvent* event) override;

 private:
  libmueb::MuebTransmitter& transmitter_;
  QColor m_primaryColor{Qt::black}, m_secondaryColor{Qt::black};
  std::unique_ptr<AbstractAnimation> m_animation;
  Ui::AnimSender* ui{nullptr};
  AnimFactory::AnimType m_type;
  int m_timerId = -1;

 private slots:
  void on_primaryColor_clicked();
  void on_secondaryColor_clicked();
  void on_animationType_activated(int index);
  void on_animationSpeed_valueChanged(int speed);
};

#endif

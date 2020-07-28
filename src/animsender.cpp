#include "animsender.h"

#include "ui_animsender.h"

AnimSender::AnimSender(QWidget* parent)
    : QWidget(parent),
      m_transmitter(MuebTransmitter::getInstance()),
      ui(new Ui::AnimSender) {
  ui->setupUi(this);
  ui->colorDialog->setWindowFlags(Qt::Widget);
  ui->colorDialog->setOptions(QColorDialog::DontUseNativeDialog |
                              QColorDialog::NoButtons);
  setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint |
                 Qt::MSWindowsFixedSizeDialogHint);

  for (const auto& i : AnimFactory::AnimTypeString) {
    ui->animationType->addItem(i.second, i.first);
  }

  adjustSize();
}

AnimSender::~AnimSender() { delete ui; }

void AnimSender::timerEvent(QTimerEvent*) {
  if (m_animation) m_transmitter.sendFrame(m_animation->nextFrame());
}

static void inline setButtonColor(QPushButton* button, const QColor& color) {
  QPalette palette = button->palette();
  palette.setColor(QPalette::Button, color);
  button->setPalette(palette);
  button->update();
}

void AnimSender::on_primaryColor_clicked() {
  m_primaryColor = ui->colorDialog->currentColor();
  setButtonColor(ui->primaryColor, m_primaryColor);

  if (m_animation) m_animation->setPrimaryColor(m_primaryColor);
}

void AnimSender::on_secondaryColor_clicked() {
  m_secondaryColor = ui->colorDialog->currentColor();
  setButtonColor(ui->secondaryColor, m_secondaryColor);

  if (m_animation) m_animation->setSecondaryColor(m_secondaryColor);
}

void AnimSender::on_animationType_activated(int index) {
  if (m_timerId < 0) m_timerId = startTimer(ui->animationSpeed->value());

  m_animation = AnimFactory::getAnimation(
      ui->animationType->itemData(index).value<AnimFactory::AnimType>(),
      m_primaryColor, m_secondaryColor);

  ui->animationSpeed->setValue(m_animation->animationSpeed());
}

void AnimSender::on_animationSpeed_valueChanged(int speed) {
  killTimer(m_timerId);

  m_timerId = startTimer(speed);
}

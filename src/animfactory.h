#ifndef ANIM_FACTORY_H
#define ANIM_FACTORY_H

#include <QObject>
#include <QString>
#include <map>

#include "abstractanimation.h"
#include "memory"

class AnimFactory : public QObject {
  Q_OBJECT

 public:
  explicit AnimFactory(QObject *parent = nullptr);

  enum AnimType { CHESS, VERTICAL, HORIZONTAL, SOLID, WINDOW, ROW, COLUMN };
  const static std::map<AnimFactory::AnimType, QString> AnimTypeString;
  static std::unique_ptr<AbstractAnimation> getAnimation(
      AnimType type, const QColor &primaryColor, const QColor &secondaryColor);

 private:
  Q_ENUM(AnimType)
};

#endif

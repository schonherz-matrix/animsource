#include <QApplication>
#include <iostream>
#include "animsender.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  AnimSender w;
  w.show();

  return a.exec();
}

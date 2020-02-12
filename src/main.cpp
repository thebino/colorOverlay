#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QMessageBox>
#include <QPainter>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    MainWindow mainwindow;
    mainwindow.show();
 
    return app.exec();
}

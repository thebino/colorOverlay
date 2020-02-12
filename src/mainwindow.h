#ifndef mainwindow_h
#define mainwindow_h

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QMessageBox>
#include <QPainter>
#include <QLabel>

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QAction>
class MainWindow : public QMainWindow
{
	public:
		MainWindow (QWidget *parent = 0);
		~MainWindow();
	private slots:
		void dragEnterEvent(QDragEnterEvent *e);
		void dropEvent(QDropEvent *e);
};
#endif

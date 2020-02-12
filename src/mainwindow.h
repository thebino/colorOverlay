#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QMessageBox>
#include <QPainter>
#include <QLabel>
#include <QColorDialog>
#include <QColor>
#include <QDebug>
#include <QVBoxLayout>

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QAction>
class MainWindow : public QMainWindow
{
	Q_OBJECT

	private slots:
		void dragEnterEvent(QDragEnterEvent *e);
		void dropEvent(QDropEvent *e);
    	void selectColor();

	public:
		MainWindow (QWidget *parent = 0);
		~MainWindow();
		void setupUi(QMainWindow *parent);
		
	private:
		QColor *color;
		QWidget *central;
		QGridLayout *layout;
		QLabel *label;
		QPushButton *button;
};

#endif // MAINWINDOW_H

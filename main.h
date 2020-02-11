#ifndef MAIN_H
#define MAIN_H
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

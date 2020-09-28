#ifndef MAINWINDOWMED_H
#define MAINWINDOWMED_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
	
private:
	Ui::MainWindow* ui;

protected:
	
private slots :

	//Funciones a llamar mediante slots QT
   
};

#endif // MAINWINDOWMED_H

#ifndef MAINWINDOWMED_H
#define MAINWINDOWMED_H

#include <QMainWindow>
#include "QrCode.hpp"

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
	void printQr(qrcodegen::QrCode& qr);

protected:
	
private slots :

	//Funciones a llamar mediante slots QT
	void Buscar();

   
};

#endif // MAINWINDOWMED_H

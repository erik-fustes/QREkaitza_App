#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
	//Scene initialization
	ui = new Ui::MainWindow;
	ui->setupUi(this);

	//connect(ui->actionLoad_Calibration, &QAction::triggered, this, &MainWindow::loadCalibration);
	//connect(ui->aoiX, SIGNAL(returnPressed()), this, SLOT(updateData()));

}

MainWindow::~MainWindow()
{
    delete ui;

}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFileDialog>
#include <QPainter>
#include <QImage>
#include <QSvgRenderer>
#include <iostream>

using std::uint8_t;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
	//Scene initialization
	ui = new Ui::MainWindow;
	ui->setupUi(this);


	const char* text = "Hello, world!";              // User-supplied text
	const QrCode::Ecc errCorLvl = QrCode::Ecc::LOW;  // Error correction level

	// Make and print the QR Code symbol
	QrCode qr = QrCode::encodeText(text, errCorLvl);
	printQr(qr);


	// Load your SVG
	QSvgRenderer renderer(QString("./svg-logo-h.svg"));

	// Prepare a QImage with desired characteritisc
	QImage image(500, 200, QImage::Format_ARGB32);
	image.fill(0xaaA08080);  // partly transparent red-ish background

	// Get QPainter that paints to the image
	QPainter painter(&image);
	renderer.render(&painter);

	// Save, image format based on file extension
	image.save("./svg-logo-h.png");
	//ui->label_qr->setPixmap(QPixmap());



	//connect(ui->actionLoad_Calibration, &QAction::triggered, this, &MainWindow::loadCalibration);
	//connect(ui->aoiX, SIGNAL(returnPressed()), this, SLOT(updateData()));

	//connect(ui->browseButton, &QAction::triggered, this, &MainWindow::Buscar);
	connect(ui->browseButton, SIGNAL(clicked()), this, SLOT(Buscar()));


}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::Buscar() {

	std::cout << "Hola" << std::endl;
	ui->lineEdit_fileDirectory->setText("Buscar");
}

/*---- Utilities ----*/

// Prints the given QrCode object to the console.
void MainWindow::printQr( QrCode& qr) {
	int border = 4;
	for (int y = -border; y < qr.getSize() + border; y++) {
		for (int x = -border; x < qr.getSize() + border; x++) {
			std::cout << (qr.getModule(x, y) ? "##" : "  ");
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
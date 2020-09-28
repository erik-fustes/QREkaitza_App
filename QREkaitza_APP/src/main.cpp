#include "mainwindow.h"

#if QT_VERSION >= 0x050000
#include <QtWidgets/qapplication.h>
#include <QtGlobal>
#else
#include <qapplication.h>
#include <qglobal.h>
#endif


// Database
#include <QDir>
#include <QFile>
#include <QProcessEnvironment>
#include <string>

// End Database

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
	MainWindow w;
    w.show();

    return a.exec();
}

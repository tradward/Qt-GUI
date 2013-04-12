#include <QApplication>

#include "dialog.h"
#include "mainwindow.h"
//#include "whatsnew.h"
#include "connector.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Dialog dialog;
	MainWindow mainwindow;
	//WhatsNew whatsnew;
    
    if(dialog.exec()==QDialog::Accepted)
    {
        mainwindow.show();
        return app.exec();
    }
    else return 0;
}



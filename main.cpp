#include <QApplication>

#include "dialog.h"
#include "mainwindow.h"
//#include "whatsnew.h"
#include "connector.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Dialog dialog;
    
	
	//WhatsNew whatsnew;
    cout << "starting ... " << endl;
    if(dialog.exec()!=QDialog::Accepted) {
        return 0;
    }

    cout << "creating main window ..." << endl;
    MainWindow mainwindow;
    cout << "creating main window ..." << endl;
    mainwindow.show();
    app.exec();
    return 1;



     	/*QApplication app(argc, argv);
     	Dialog dialog;
	MainWindow mainwindow;
	//WhatsNew whatsnew;
    cout << "starting ... " << endl;
        if(dialog.exec()==QDialog::Accepted)  
        {  
        	mainwindow.show();  
        	return app.exec();  
        }  
        else return 0;   */
}



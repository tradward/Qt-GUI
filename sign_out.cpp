
 #include <QtGui>
 #include <QApplication>
 #include "sign_out.h"
 #include "dialog.h"
 #include "mainwindow.h"
 #include "whats_new.h"
 #include "favorite.h"
 #include "movies.h"
 #include "series.h"
 #include "connector.h"

 SignOut::SignOut()
 {
     createMenu_8();
     createHorizontalGroupBox_8();

     QVBoxLayout *mainLayout_8 = new QVBoxLayout;
     mainLayout_8->setMenuBar(menuBar_8);
     mainLayout_8->addWidget(sign_out_label);
     mainLayout_8->addWidget(horizontalGroupBox_8);
     setLayout(mainLayout_8);
     setWindowTitle(tr(""));
	loadStyleSheet_8();
 }

 void SignOut::createMenu_8()
 {
     menuBar_8 = new QMenuBar;

     fileMenu_8 = new QMenu(tr("&File"), this);
     exitAction_8 = fileMenu_8->addAction(tr("E&xit"));
     menuBar_8->addMenu(fileMenu_8);

     connect(exitAction_8, SIGNAL(triggered()), this, SLOT(accept()));
 }

 void SignOut::createHorizontalGroupBox_8()
 {

	sign_out_label = new QLabel(tr("Do you really want to sign out?"));
     horizontalGroupBox_8 = new QGroupBox();
     QHBoxLayout *layout_8 = new QHBoxLayout;

	confirm_signout = new QPushButton(tr("Yes, sign me out"));
	cancel_signout = new QPushButton(tr("Cancel"));  
	//submit->setText("Submit"); 
	QObject::connect(confirm_signout, SIGNAL(clicked()),this, SLOT(handleButton_8_1()));
	QObject::connect(cancel_signout, SIGNAL(clicked()),this, SLOT(handleButton_8_2()));
	//QObject::connect(button2, SIGNAL(clicked()),this, SLOT(clickedSlot()));
	confirm_signout->setFlat(true);
	cancel_signout->setFlat(true);
	layout_8->addWidget(confirm_signout);
	layout_8->addWidget(cancel_signout);
     horizontalGroupBox_8->setLayout(layout_8);
 }



void SignOut::handleButton_8_1()
{
    hide();
    Dialog dialog;
    dialog.exec();
    show();

}

void SignOut::handleButton_8_2()
{
    	if(Connector::signout_p == 0){
    		hide();
    		MainWindow mainwindow_8;
    		mainwindow_8.exec();
    		show();
	}else if(Connector::signout_p == 1){
    		hide();
    		WhatsNew whatsnew_8;
    		whatsnew_8.exec();
    		show();
	}else if(Connector::signout_p == 2){
    		hide();
    		Favorite favorite_8;
    		favorite_8.exec();
    		show();
	}else if(Connector::signout_p == 3){
    		hide();
    		Movies movies_8;
    		movies_8.exec();
    		show();
	}else if(Connector::signout_p == 4){
    		hide();
    		Series series_8;
    		series_8.exec();
    		show();
	}
}

void SignOut::loadStyleSheet_8()
{
	QFile qss("style.qss");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();
}


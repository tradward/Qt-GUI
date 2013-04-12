
#include <QtGui>
#include <QApplication>
#include "dialog.h"
#include "create_account.h"
#include <string>
#include <QString>
#include <vector>
#include <iostream>
#include "common.h"
//#include <iostream>
//#include <functional>
#include "connector.h"
using namespace std;

Dialog::Dialog()
{
    createMenu();
    createFormGroupBox();
    createHorizontalGroupBox();
    
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(formGroupBox);
    mainLayout->addWidget(horizontalGroupBox);
    setLayout(mainLayout);
    setWindowTitle(tr("Log in here:"));
	loadStyleSheet_2();
}

void Dialog::createMenu()
{
    menuBar = new QMenuBar;
    
    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);
    
    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}

void Dialog::createHorizontalGroupBox()
{
    horizontalGroupBox = new QGroupBox();
    QHBoxLayout *layout = new QHBoxLayout;
    
	create_account = new QPushButton(tr("Create Account"));
	submit = new QPushButton(tr("Submit"));
	QObject::connect(create_account, SIGNAL(clicked()),this, SLOT(handleButton_2()));
	QObject::connect(submit, SIGNAL(clicked()),this, SLOT(handleButton()));
	create_account->setFlat(true);
	submit->setFlat(true);
	layout->addWidget(create_account);
	layout->addWidget(submit);
    horizontalGroupBox->setLayout(layout);
}


void Dialog::createFormGroupBox()
{
    formGroupBox = new QGroupBox();
    QFormLayout *layout = new QFormLayout;
	passwd = new QLineEdit;
	username = new QLineEdit;
	indication = new QLabel(tr("Please input your information:"));
	passwd->setEchoMode(QLineEdit::Password);
    
    layout->addRow(indication);
    layout->addRow(new QLabel(tr("Username: ")), username);
    layout->addRow(new QLabel(tr("Password: ")), passwd);
    
    formGroupBox->setLayout(layout);
	
}

void Dialog::handleButton_2()
{
	hide();
	CreateAccount create_account_a;
    create_account_a.exec();
    show();
}

void Dialog::handleButton()
{
	QString str_2 = QString();
	str_2 = passwd->text();
	string str_2_string = string((const char *)str_2.toLocal8Bit());
	//std::hash<string> str_hash;
	//string hashed_password = str_hash(str_2_string);
	//size_t hashed_password = str_hash(str_2_string);
    
	//stringstream ss;
	//ss << hashed_password;
	//string temp = ss.str();
    
	QString str_2_2 = QString();
	str_2_2 = username->text();
	string str_2_2_string = string((const char *)str_2_2.toLocal8Bit());
    
	
    
	//login*_*jianan*_*123456
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string inputCommand = "login*_*" + str_2_2_string +"*_*" +str_2_string;
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
	string response = client::Clie_GetResponse(clientfd);
    client::Clie_close(clientfd);
    
	if(response == "Success"){
		Connector::username = str_2_2;
		Connector::password = str_2;
		accept();
	}
    
	if(response == "Fail"){
		indication->setText("Wrong information! Please input again!");
	}
}



void Dialog::loadStyleSheet_2()
{
	QFile qss("style.qss");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();
}


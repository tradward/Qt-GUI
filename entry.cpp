
#include <QtGui>
#include <QApplication>
#include "entry.h"
#include "mainwindow.h"
#include "whats_new.h"
#include "favorite.h"
#include "movies.h"
#include "series.h"
#include "connector.h"
#include "common.h"
#include <string.h>
#include <string>
#include <QString>
#include <vector>
#include <iostream>
#include <QCloseEvent>
#include "result.h"
using namespace std;

Entry::Entry()
{
	favorite = "0";
    createMenu_4();
	create_inf();
	create_comment();
	create_button();
	loadStyleSheet_4();
    
    QVBoxLayout *mainLayout_4 = new QVBoxLayout;
    mainLayout_4->setMenuBar(menuBar_4);
    mainLayout_4->addWidget(info_groupbox);
    mainLayout_4->addWidget(synosis_label);
    mainLayout_4->addWidget(synosis_content);
    mainLayout_4->addWidget(comment_label);
    mainLayout_4->addWidget(comment_content);
    mainLayout_4->addWidget(rate_and_submit);
    mainLayout_4->addWidget(back_button_4);
    setLayout(mainLayout_4);
    
    setWindowTitle(tr(""));
	loadStyleSheet_4();
}



void Entry::closeEvent_4(QCloseEvent *event){
    if(Connector::entry_p == 0){
        hide();
        MainWindow mainwindow_4;
        mainwindow_4.exec();
        show();
	}else if(Connector::entry_p == 1){
        hide();
        WhatsNew whatsnew_4;
        whatsnew_4.exec();
        show();
	}else if(Connector::entry_p == 2){
        hide();
        Favorite favorite_4;
        favorite_4.exec();
        show();
	}else if(Connector::entry_p == 3){
        hide();
        Movies movies_4;
        movies_4.exec();
        show();
	}else if(Connector::entry_p == 4){
        hide();
        Series series_4;
        series_4.exec();
        show();
	}else if(Connector::entry_p == 5){
        hide();
        Result result_4;
        result_4.exec();
        show();
	}
	event->accept();
}

void Entry::createMenu_4()
{
    menuBar_4 = new QMenuBar;
    
    fileMenu_4 = new QMenu(tr("&File"), this);
    exitAction_4 = fileMenu_4->addAction(tr("&Exit"));
    menuBar_4->addMenu(fileMenu_4);
    
    connect(exitAction_4, SIGNAL(triggered()), this, SLOT(accept()));
}

void Entry::create_inf()
{
 	string inputCommand = "display*_*" + Connector::e1 + "*_*MTDetails";
    int clientfd_str= client::Clie_SockEstablish();
 	string url = Connector::ip.toStdString();
	client::Clie_ClientConnect(clientfd_str, (char *)url.c_str());
    client::Clie_SendCommand(clientfd_str, inputCommand.c_str());
    struct MovieData* ptr = client::Clie_SaveStruct(clientfd_str);
    client::Clie_close(clientfd_str);
    //get picture
    int clientfd_pic= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd_pic, (char *)url.c_str());
    client::Clie_GetResponse(clientfd_pic);
    client::Clie_SaveContent(clientfd_pic, (char *)url.c_str(), ptr->pic);
    client::Clie_close(clientfd_pic);
	
    
    
	//info_v_groupbox
	info_v_groupbox = new QGroupBox();
    QGridLayout *info_v_groupbox_layout = new QGridLayout;
    
	name = new QLabel(tr("Film Name: "));
	name_result = new QLabel(tr(ptr->name));
	date = new QLabel(tr("Date: "));
	date_result = new QLabel(tr(ptr->year));
	director = new QLabel(tr("Director:"));
	director_result = new QLabel(tr(ptr->director));
	stars = new QLabel(tr("Starring(s):"));
	stars_result = new QLabel(tr(ptr->cast));
	length = new QLabel(tr("Length:"));
	length_result = new QLabel(tr(ptr->length)+" mins");
    
	//Connector:: entry_id = ptr->number;
    
	info_v_groupbox_layout->addWidget(name,0,0);
	info_v_groupbox_layout->addWidget(name_result,0,1);
	info_v_groupbox_layout->addWidget(date,1,0);
	info_v_groupbox_layout->addWidget(date_result,1,1);
	info_v_groupbox_layout->addWidget(director,2,0);
	info_v_groupbox_layout->addWidget(director_result,2,1);
	info_v_groupbox_layout->addWidget(stars,3,0);
	info_v_groupbox_layout->addWidget(stars_result,3,1);
	info_v_groupbox_layout->addWidget(length,4,0);
	info_v_groupbox_layout->addWidget(length_result,4,1);
    
	info_v_groupbox->setLayout(info_v_groupbox_layout);
	
	//info_v_groupbox_2
	info_v_groupbox_2 = new QGroupBox();
    QVBoxLayout *info_v_groupbox_layout_2 = new QVBoxLayout;
    
    
    
    QString pic_string = ptr->pic;
	picture_button = new QPushButton();
	picture_button->setIcon(QIcon(pic_string));
	picture_button->setIconSize(QSize(120,200));
	picture_button->setFlat(true);
	picture_button->setToolTip(tr("Click to add to FAVORITE!"));
	QObject::connect(picture_button, SIGNAL(clicked()),this, SLOT(handleButton_4_1()));
    
    
	rate_label = new QLabel();
	rate_label->setText("<img src=\"five_star.png\">");
    rate_label->setAlignment(Qt::AlignHCenter);
	info_v_groupbox_layout_2->addWidget(picture_button);
	info_v_groupbox_layout_2->addWidget(rate_label);
	info_v_groupbox_2->setLayout(info_v_groupbox_layout_2);
	info_v_groupbox_2->setFixedHeight(250);
    
	//info_groupbox
	info_groupbox = new QGroupBox();
	QHBoxLayout *info_groupbox_layout = new QHBoxLayout;
	info_groupbox_layout->addWidget(info_v_groupbox_2);
	info_groupbox_layout->addWidget(info_v_groupbox);
	info_groupbox->setLayout(info_groupbox_layout);
    
	//synosis
	synosis_label = new QLabel(tr("Synosis:"));
	synosis_content = new QLabel();
	synosis_content->setText(tr(ptr->content));
	synosis_content->setWordWrap(true);
	synosis_content->setAlignment(Qt::AlignLeft);
	synosis_content->adjustSize();
}

void Entry::create_comment(){
	comment_label = new QLabel(tr("Enter comment here:"));
	comment_content = new QTextEdit();
}

void Entry::create_button(){
	rate_and_submit = new QGroupBox();
	QHBoxLayout *rate_and_submit_layout = new QHBoxLayout;
    
	rate_here_label = new QLabel(tr("Rate here:"));
	rate_combo=new QComboBox();
	rate_combo->addItem("1");
	rate_combo->addItem("2");
	rate_combo->addItem("3");
	rate_combo->addItem("4");
	rate_combo->addItem("5");
	rate_combo->setMaxCount(5);
    
	submit_button_4 = new QPushButton(tr("Submit Comment"));
	submit_button_4->setFlat(true);
	QObject::connect(submit_button_4, SIGNAL(clicked()),this, SLOT(handleButton_4_3()));
    
	rate_and_submit_layout->addWidget(rate_here_label);
	rate_and_submit_layout->addWidget(rate_combo);
	rate_and_submit_layout->addWidget(submit_button_4);
	
	rate_and_submit->setLayout(rate_and_submit_layout);
	back_button_4 = new QPushButton(tr("<<Back"));
	back_button_4->setFlat(true);
	QObject::connect(back_button_4, SIGNAL(clicked()),this, SLOT(handleButton_4_2()));
}


void Entry::handleButton_4_1()
{
	//changemovie*_*username+number+comments+rate(1+5)+favorite?
	favorite = "1";
}


void Entry::handleButton_4_3()
{
	//changemovie*_*username+number+comments+rate(1+5)+favorite?
    
	QString user_name = QString();
	user_name = Connector::username;
	string user_name_string = string((const char *)user_name.toLocal8Bit());
    
    
	QString entry = QString::fromLocal8Bit(Connector::entry_id.c_str());
	string entry_string = string((const char *)entry.toLocal8Bit());
    
	QString comment = QString();
	comment = comment_content->toPlainText();
	string comment_string = string((const char *)comment.toLocal8Bit());
    
	QString rate = QString();
	rate = rate_combo->currentText();
	string rate_string = string((const char *)rate.toLocal8Bit());
    
	cout << "Change movie" << endl;
	char url[20] = "10.190.53.95";
	//string inputCommand = "changemovie*_*" + user_name_string +"*_*" +entry_string  +"*_*"+ comment_content  +"*_*"+ rate_string  +"*_*"+ favorite;
	string inputCommand = "changemovie";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, url);
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
	string response;
	//response = client::Clie_GetResponse_11(clientfd);
    client::Clie_close(clientfd);
}


void Entry::handleButton_4_2()
{
    if(Connector::entry_p == 0){
        hide();
        MainWindow mainwindow_4;
        mainwindow_4.exec();
        show();
	}else if(Connector::entry_p == 1){
        hide();
        WhatsNew whatsnew_4;
        whatsnew_4.exec();
        show();
	}else if(Connector::entry_p == 2){
        hide();
        Favorite favorite_4;
        favorite_4.exec();
        show();
	}else if(Connector::entry_p == 3){
        hide();
        Movies movies_4;
        movies_4.exec();
        show();
	}else if(Connector::entry_p == 4){
        hide();
        Series series_4;
        series_4.exec();
        show();
	}
}


void Entry::loadStyleSheet_4()
{
	QFile qss("style.qss");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();
}


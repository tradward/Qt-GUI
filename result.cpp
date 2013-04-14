
#include <QtGui>
#include <QApplication>
#include "result.h"
#include "mainwindow.h"
#include "whats_new.h"
#include "favorite.h"
#include "movies.h"
#include "series.h"
#include "connector.h"
#include "entry.h"
#include "common.h"
#include <QCloseEvent>


Result::Result()
{
    createMenu_5();
	create_result_logo();
	create_line_5();
    create_inf_1();
    //create_inf_2();
	create_back();
	
    QVBoxLayout *mainLayout_5 = new QVBoxLayout;
    mainLayout_5->setMenuBar(menuBar_5);
    mainLayout_5->setMenuBar(result_logo);
    mainLayout_5->addWidget(line_logo_5_1);
    mainLayout_5->addWidget(message_favorite);
    mainLayout_5->addWidget(vertical_images_5);
    mainLayout_5->addWidget(line_logo_5_3);
    mainLayout_5->addWidget(back_button_5);
    
    
    
    setLayout(mainLayout_5);
    
    setWindowTitle(tr(""));
	loadStyleSheet_5();
}

void Result::closeEvent_5(QCloseEvent *event){
    if(Connector::search_p == 0){
        hide();
        MainWindow mainwindow_5;
        mainwindow_5.exec();
        show();
	}else if(Connector::search_p == 1){
        hide();
        WhatsNew whatsnew_5;
        whatsnew_5.exec();
        show();
	}else if(Connector::search_p == 2){
        hide();
        Favorite favorite_5;
        favorite_5.exec();
        show();
	}else if(Connector::search_p == 3){
        hide();
        Movies movies_5;
        movies_5.exec();
        show();
	}else if(Connector::search_p == 4){
        hide();
        Series series_5;
        series_5.exec();
        show();
	}
	event->accept();
}


void Result::createMenu_5()
{
    menuBar_5 = new QMenuBar;
    
    fileMenu_5 = new QMenu(tr("&File"), this);
    exitAction_5 = fileMenu_5->addAction(tr("&Exit"));
    menuBar_5->addMenu(fileMenu_5);
    
    connect(exitAction_5, SIGNAL(triggered()), this, SLOT(accept()));
}

void Result::create_result_logo(){
	result_logo = new QLabel();
	result_logo->setText("<img src=\"result_logo.png\">");
    result_logo->setAlignment(Qt::AlignHCenter);
    message_favorite = new QLabel();
}

void Result::create_inf_1()
{
    
	string inputCommand = "search*_*" + Connector::search_metric.toStdString();
    int clientfd_str= client::Clie_SockEstablish();
 	string url = Connector::ip.toStdString();
	client::Clie_ClientConnect(clientfd_str, (char *)url.c_str());
    client::Clie_SendCommand(clientfd_str, inputCommand.c_str());
	
    string n = client::Clie_GetResponse(clientfd_str);
    if (n == "Emtpy favourites") {
    	cout << "Emtpy favourites" << endl;
    	client::Clie_close(clientfd_str);
    	message_favorite->setText("No matched result found.");
		return;
  	}
    
    num_5 = atoi(n.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<num_5;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::result_entry[i] = s[0];
        
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd_str);
    assert((int)entry.size() == num_5);
    
    
    
    vertical_images_5 = new QGroupBox();
    QVBoxLayout *vertical_images_5_layout = new QVBoxLayout;
    
    if(num_5 <=5){
    	horizontal_images_5_1 = new QGroupBox();
    	QHBoxLayout *horizontal_images_5_1_layout = new QHBoxLayout;
        
    	for(int i = 0; i < num_5; i++){
            const char * button_3_str = entry[i][1].c_str();
    		QPushButton *button = new QPushButton();
    		button->setIcon(QIcon(entry[i][2].c_str()));
			button->setIconSize(QSize(120,200));
			button->setToolTip(tr(button_3_str));
			button->setFlat(true);
			result_buttons.push_back(button);
 			horizontal_images_5_1_layout->addWidget(result_buttons[i]);
    	}
    	horizontal_images_5_1->setLayout(horizontal_images_5_1_layout);
    	vertical_images_5_layout->addWidget(horizontal_images_5_1);
    	vertical_images_5->setLayout(vertical_images_5_layout);
        
    }else{
    	horizontal_images_5_2 = new QGroupBox();
    	QHBoxLayout *horizontal_images_5_2_layout = new QHBoxLayout;
    	horizontal_images_5_3 = new QGroupBox();
    	QHBoxLayout *horizontal_images_5_3_layout = new QHBoxLayout;
        
    	for(int i = 0; i < 5; i++){
            const char * button_3_str = entry[i][1].c_str();
            QPushButton *button = new QPushButton();
            button->setIcon(QIcon(entry[i][2].c_str()));
            button->setIconSize(QSize(120,200));
            button->setToolTip(tr(button_3_str));
            button->setFlat(true);
            result_buttons.push_back(button);
 			horizontal_images_5_2_layout->addWidget(result_buttons[i]);
            
    	}
    	horizontal_images_5_2->setLayout(horizontal_images_5_2_layout);
		horizontal_images_5_2->setFixedHeight(220);
        
        
    	for(int i = 5; i < num_5; i++){
            const char * button_3_str = entry[i][1].c_str();
            QPushButton *button = new QPushButton();
            button->setIcon(QIcon(entry[i][2].c_str()));
            button->setIconSize(QSize(120,200));
            button->setToolTip(tr(button_3_str));
            button->setFlat(true);
            result_buttons.push_back(button);
 			horizontal_images_5_3_layout->addWidget(result_buttons[i]);
    	}
    	horizontal_images_5_3->setLayout(horizontal_images_5_3_layout);
    	horizontal_images_5_3->setFixedHeight(220);
    	vertical_images_5_layout->addWidget(horizontal_images_5_2);
    	vertical_images_5_layout->addWidget(horizontal_images_5_3);
    	vertical_images_5->setLayout(vertical_images_5_layout);
    }
    
    
    
    if(num_5 == 1){
    	QObject::connect(result_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_1()));
    }
    else if(num_5 == 2){
    	QObject::connect(result_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_1()));
    	QObject::connect(result_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_2()));
    }
    else if(num_5 == 3){
    	QObject::connect(result_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_1()));
    	QObject::connect(result_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_2()));
    	QObject::connect(result_buttons[2], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_3()));
    }
    else if(num_5 == 4){
    	QObject::connect(result_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_1()));
    	QObject::connect(result_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_2()));
    	QObject::connect(result_buttons[2], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_3()));
    	QObject::connect(result_buttons[3], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_4()));
    }
    else if(num_5 == 5){
    	QObject::connect(result_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_1()));
    	QObject::connect(result_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_2()));
    	QObject::connect(result_buttons[2], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_3()));
    	QObject::connect(result_buttons[3], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_4()));
    	QObject::connect(result_buttons[4], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_5()));
    }
    else if(num_5 == 6){
    	QObject::connect(result_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_1()));
    	QObject::connect(result_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_2()));
    	QObject::connect(result_buttons[2], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_3()));
    	QObject::connect(result_buttons[3], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_4()));
    	QObject::connect(result_buttons[4], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_5()));
    	QObject::connect(result_buttons[5], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_6()));
    }
    else if(num_5 == 7){
    	QObject::connect(result_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_1()));
    	QObject::connect(result_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_2()));
    	QObject::connect(result_buttons[2], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_3()));
    	QObject::connect(result_buttons[3], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_4()));
    	QObject::connect(result_buttons[4], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_5()));
    	QObject::connect(result_buttons[5], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_6()));
    	QObject::connect(result_buttons[6], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_7()));
    }
    else if(num_5 == 8){
    	QObject::connect(result_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_1()));
    	QObject::connect(result_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_2()));
    	QObject::connect(result_buttons[2], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_3()));
    	QObject::connect(result_buttons[3], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_4()));
    	QObject::connect(result_buttons[4], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_5()));
    	QObject::connect(result_buttons[5], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_6()));
    	QObject::connect(result_buttons[6], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_7()));
    	QObject::connect(result_buttons[7], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_8()));
    }
    else if(num_5 == 9){
    	QObject::connect(result_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_1()));
    	QObject::connect(result_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_2()));
    	QObject::connect(result_buttons[2], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_3()));
    	QObject::connect(result_buttons[3], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_4()));
    	QObject::connect(result_buttons[4], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_5()));
    	QObject::connect(result_buttons[5], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_6()));
    	QObject::connect(result_buttons[6], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_7()));
    	QObject::connect(result_buttons[7], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_8()));
    	QObject::connect(result_buttons[8], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_9()));
    }
    else if(num_5 == 10){
    	QObject::connect(result_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_1()));
    	QObject::connect(result_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_2()));
    	QObject::connect(result_buttons[2], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_3()));
    	QObject::connect(result_buttons[3], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_4()));
    	QObject::connect(result_buttons[4], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_5()));
    	QObject::connect(result_buttons[5], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_6()));
    	QObject::connect(result_buttons[6], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_7()));
    	QObject::connect(result_buttons[7], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_8()));
    	QObject::connect(result_buttons[8], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_9()));
    	QObject::connect(result_buttons[9], SIGNAL(clicked()),this, SLOT(handleButton_5_pic_10()));
    }
    
    
    
}




void Result::create_back(){
	back_button_5 = new QPushButton(tr("<<Back"));
	back_button_5->setFlat(true);
	QObject::connect(back_button_5, SIGNAL(clicked()),this, SLOT(handleButton_5()));
}

void Result::create_line_5(){
	line_logo_5_1 = new QLabel();
	line_logo_5_1->setText("<img src=\"17.png\">");
	line_logo_5_2 = new QLabel();
	line_logo_5_2->setText("<img src=\"17.png\">");
	line_logo_5_3 = new QLabel();
	line_logo_5_3->setText("<img src=\"17.png\">");
}


void  Result::handleButton_5_pic_1(){
    
	Connector::entry_p = 5;
	Connector::e1 = Connector::result_entry[0];
    hide();
    Entry entry;
    entry.exec();
    show();
    
}

void  Result::handleButton_5_pic_2(){
    
	Connector::entry_p = 5;
	Connector::e1 = Connector::result_entry[1];
    hide();
    Entry entry;
    entry.exec();
    show();
    
}
void  Result::handleButton_5_pic_3(){
    
	Connector::entry_p = 5;
	Connector::e1 = Connector::result_entry[2];
    hide();
    Entry entry;
    entry.exec();
    show();
    
}

void  Result::handleButton_5_pic_4(){
    
	Connector::entry_p = 5;
	Connector::e1 = Connector::result_entry[3];
    hide();
    Entry entry;
    entry.exec();
    show();
    
}

void  Result::handleButton_5_pic_5(){
    
	Connector::entry_p = 5;
	Connector::e1 = Connector::result_entry[4];
    hide();
    Entry entry;
    entry.exec();
    show();
    
}

void  Result::handleButton_5_pic_6(){
    
	Connector::entry_p = 5;
	Connector::e1 = Connector::result_entry[5];
    hide();
    Entry entry;
    entry.exec();
    show();
    
}

void  Result::handleButton_5_pic_7(){
    
	Connector::entry_p = 5;
	Connector::e1 = Connector::result_entry[6];
    hide();
    Entry entry;
    entry.exec();
    show();
    
}

void  Result::handleButton_5_pic_8(){
    
	Connector::entry_p = 5;
	Connector::e1 = Connector::result_entry[7];
    hide();
    Entry entry;
    entry.exec();
    show();
    
}

void  Result::handleButton_5_pic_9(){
    
	Connector::entry_p = 5;
	Connector::e1 = Connector::result_entry[8];
    hide();
    Entry entry;
    entry.exec();
    show();
    
}

void  Result::handleButton_5_pic_10(){
    
	Connector::entry_p = 5;
	Connector::e1 = Connector::result_entry[9];
    hide();
    Entry entry;
    entry.exec();
    show();
    
}


void Result::handleButton_5()
{
    if(Connector::search_p == 0){
        hide();
        MainWindow mainwindow_5;
        mainwindow_5.exec();
        show();
	}else if(Connector::search_p == 1){
        hide();
        WhatsNew whatsnew_5;
        whatsnew_5.exec();
        show();
	}else if(Connector::search_p == 2){
        hide();
        Favorite favorite_5;
        favorite_5.exec();
        show();
	}else if(Connector::search_p == 3){
        hide();
        Movies movies_5;
        movies_5.exec();
        show();
	}else if(Connector::search_p == 4){
        hide();
        Series series_5;
        series_5.exec();
        show();
	}
}


void Result::loadStyleSheet_5()
{
	QFile qss("style.qss");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();
}


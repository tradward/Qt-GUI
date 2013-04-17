#include "account.h"

Account::Account()
{
    createMenu_9();
    createHorizontalGroupBox_9();
	create_logo_9();
	create_bottom_9();
	create_line_9();
    QVBoxLayout *mainLayout_9 = new QVBoxLayout;
    mainLayout_9->setMenuBar(menuBar_9);
    mainLayout_9->addWidget(account_label);
    mainLayout_9->addWidget(line_logo_9_1);
    mainLayout_9->addWidget(message_9);
    mainLayout_9->addWidget(horizontalGroupBox_9_2);
    mainLayout_9->addWidget(horizontalGroupBox_9_2_2);
    mainLayout_9->addWidget(line_logo_9_2);
    mainLayout_9->addWidget(bottom_area_9);
    setLayout(mainLayout_9);
    setWindowTitle(tr(""));
	loadStyleSheet_9();
}

void Account::closeEvent_9(QCloseEvent *event){
    if(Connector::account_p == 0){
        hide();
        MainWindow mainwindow_9;
        mainwindow_9.exec();
        show();
	}else if(Connector::account_p == 1){
        hide();
        WhatsNew whatsnew_9;
        whatsnew_9.exec();
        show();
	}else if(Connector::account_p == 2){
        hide();
        Favorite favorite_9;
        favorite_9.exec();
        show();
	}else if(Connector::account_p == 3){
        hide();
        Movies movies_9;
        movies_9.exec();
        show();
	}else if(Connector::account_p == 4){
        hide();
        Series series_9;
        series_9.exec();
        show();
	}
	event->accept();
}


void Account::createMenu_9()
{
    menuBar_9 = new QMenuBar;
    
    fileMenu_9 = new QMenu(tr("&File"), this);
    exitAction_9 = fileMenu_9->addAction(tr("E&xit"));
    menuBar_9->addMenu(fileMenu_9);
    
    connect(exitAction_9, SIGNAL(triggered()), this, SLOT(accept()));
}

void Account::create_logo_9(){
	account_label = new QLabel();
	account_label->setText("<img src=\"account_logo.png\">");
    account_label->setAlignment(Qt::AlignHCenter);
}


void Account::create_line_9(){
    
	line_logo_9_1 = new QLabel();
	line_logo_9_1->setText("<img src=\"17.png\">");
    
	line_logo_9_2 = new QLabel();
	line_logo_9_2->setText("<img src=\"17.png\">");
    
}


void Account::createHorizontalGroupBox_9()
{
    
	message_9 = new QLabel(tr("Password should be a combination of upper letters, lower letters and digits:"));
    horizontalGroupBox_9_2 = new QGroupBox();
    QHBoxLayout *layout_9_2 = new QHBoxLayout;
    
	change_opw_label = new QLabel(tr("Input current password here:"));
	change_opw_field = new QLineEdit();
	change_opw_field->setEchoMode(QLineEdit::Password);
	layout_9_2->addWidget(change_opw_label);
	layout_9_2->addWidget(change_opw_field);
	horizontalGroupBox_9_2->setLayout(layout_9_2);
    
    horizontalGroupBox_9_2_2 = new QGroupBox();
    QHBoxLayout *layout_9_2_2 = new QHBoxLayout;
    
	change_pw_label = new QLabel(tr("Input new password here:"));
	change_pw_field = new QLineEdit();
	change_pw_field->setEchoMode(QLineEdit::Password);
	layout_9_2_2->addWidget(change_pw_label);
	layout_9_2_2->addWidget(change_pw_field);
	horizontalGroupBox_9_2_2->setLayout(layout_9_2_2);
    
}

void Account::create_bottom_9()
{
	bottom_area_9 = new QGroupBox();
	QHBoxLayout *bottom_area_layout_9 = new QHBoxLayout;
    
	//logo_3_2
	logo_9_2 = new QLabel();
	logo_9_2 ->setText("<img src=\"logo2.png\">");
	
	//copyright
	copy_right_9 = new QLabel();
	copy_right_9->setText("Copy right ...........:");
    
	//sign_out_9 = new QPushButton(tr("<Sign Out>"));
	//sign_out_9->setFlat(true);
    
    
	change_pw_back = new QPushButton(tr("<<Back"));
	change_pw_back->setFlat(true);
	change_pw_submit = new QPushButton(tr("Submit change"));
	change_pw_submit->setFlat(true);
	QObject::connect(change_pw_submit, SIGNAL(clicked()),this, SLOT(handleButton_9_1()));
    
	//QObject::connect(sign_out_9, SIGNAL(clicked()),this, SLOT(handleButton_9_1()));
	QObject::connect(change_pw_back, SIGNAL(clicked()),this, SLOT(handleButton_9_2()));
    
    
	bottom_area_layout_9->addWidget(logo_9_2);
	bottom_area_layout_9->addWidget(copy_right_9);
	bottom_area_layout_9->addWidget(change_pw_submit);
	bottom_area_layout_9->addWidget(change_pw_back);
	bottom_area_9->setLayout(bottom_area_layout_9);
}

void Account::handleButton_9_1()
{
	QString str2_9 = QString();
	str2_9 = Connector::username;
	string str2_9_string = string((const char *)str2_9.toLocal8Bit());
    
	QString str_9 = QString();
	str_9 = change_pw_field->text();
	string str_9_string = string((const char *)str_9.toLocal8Bit());
    
	QString str3_9 = QString();
	str3_9 = change_opw_field->text();
	string str3_9_string = string((const char *)str3_9.toLocal8Bit());
    
    
	bool is_valid_9 = true;
	int upper_count_9 = 0;
	int lower_count_9 = 0;
	int sign_count_9 = 0;
	
	if(str_9.length()==0){
		is_valid_9 = false;
	}
    
	for(int i = 0; i < str_9.length(); i++){
		if(str_9[i]==' '){
			is_valid_9 =  false;
		}
		if(str_9[i]>='A' && str_9[i]<='Z'){
			upper_count_9++;
		}
		if(str_9[i]>='a' && str_9[i]<='z'){
			lower_count_9++;
		}
		if(str_9[i]>='0' && str_9[i]<='9'){
			sign_count_9++;
		}
	}
	if((upper_count_9 == 0 )|( lower_count_9 == 0) |( sign_count_9 == 0)){
		is_valid_9 =  false;
	}
	int sum_9 = upper_count_9+lower_count_9+sign_count_9;
	if(sum_9!=str_9.length()){
		is_valid_9 =  false;
	}
	
	if(is_valid_9){
        
		cout << "Get Images" << endl;
		string url = Connector::ip.toStdString();
		string inputCommand = "changeuser*_*" + str2_9_string+ "*_*"+str3_9_string+"*_*"+str_9_string;
    	int clientfd= client::Clie_SockEstablish();
    	client::Clie_ClientConnect(clientfd, (char*)url.c_str());
    	client::Clie_SendCommand(clientfd, inputCommand.c_str());
		string response = client::Clie_GetResponse(clientfd);
    	client::Clie_close(clientfd);
        
		if(response == "Success"){
			Connector::password = str_9;
			message_9->setText("Success!");
		}else{
			message_9->setText("Fail to change the password. Please try again!");
		}
	}else{
		message_9->setText("Invalid new password. Please input again.");
	}
	
}

void Account::handleButton_9_2()
{
    if(Connector::account_p == 0){
        hide();
        MainWindow mainwindow_9;
        mainwindow_9.exec();
        show();
	}else if(Connector::account_p == 1){
        hide();
        WhatsNew whatsnew_9;
        whatsnew_9.exec();
        show();
	}else if(Connector::account_p == 2){
        hide();
        Favorite favorite_9;
        favorite_9.exec();
        show();
	}else if(Connector::account_p == 3){
        hide();
        Movies movies_9;
        movies_9.exec();
        show();
	}else if(Connector::account_p == 4){
        hide();
        Series series_9;
        series_9.exec();
        show();
	}
}


void Account::loadStyleSheet_9()
{
	QFile qss("style.qss");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();
}


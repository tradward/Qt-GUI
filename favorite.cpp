 #include "favorite.h"


 Favorite::Favorite()
 {
    createMenu_6();
	create_logo_6();
	display_search_6();
	display_favorite();
    create_line_6();
	createBottom_6();

    QVBoxLayout *mainLayout_6 = new QVBoxLayout;
    mainLayout_6->setMenuBar(menuBar_6);

    mainLayout_6->addWidget(favorite_logo);
	mainLayout_6->addWidget(line_logo_6_1);
	mainLayout_6->addWidget(search_area_6);
	mainLayout_6->addWidget(line_logo_6_2);
	mainLayout_6->addWidget(message_favorite);
	mainLayout_6->addWidget(vertical_images_6);
	mainLayout_6->addWidget(line_logo_6_3);
	mainLayout_6->addWidget(bottom_area_6);

    setLayout(mainLayout_6);
    setWindowTitle(tr("Welcome,user"));
	loadStyleSheet_6();
 }


void Favorite::closeEvent_6(QCloseEvent *event){
	Connector::signout_p = 2;
    hide();
    SignOut signout;
    signout.exec();
    //signout.setParent(this);
    show();
    event->accept();
}

 void  Favorite::createMenu_6()
 {
     menuBar_6 = new QMenuBar;

     fileMenu_6 = new QMenu(tr("&File"), this);
     exitAction_6 = fileMenu_6->addAction(tr("E&xit"));
     menuBar_6->addMenu(fileMenu_6);

     connect(exitAction_6, SIGNAL(triggered()), this, SLOT(accept()));
 }


 void Favorite::create_logo_6(){
	favorite_logo = new QLabel();
	favorite_logo->setText("<img src=\"favorite_logo.png\">");
    favorite_logo->setAlignment(Qt::AlignHCenter);	
 }


 void Favorite::create_line_6(){
	line_logo_6_1 = new QLabel();
	line_logo_6_1->setText("<img src=\"17.png\">");

	line_logo_6_2 = new QLabel();
	line_logo_6_2->setText("<img src=\"17.png\">");

	line_logo_6_3 = new QLabel();
	line_logo_6_3->setText("<img src=\"17.png\">");

	message_favorite = new QLabel();
	message_favorite->setText("");

 }



void Favorite::display_search_6(){
	search_area_6 = new QGroupBox();
	QHBoxLayout *search_area_layout_6 = new QHBoxLayout;
	search_label_6 = new QLabel();
	search_label_6->setText("Please enter movies'name or director:");
	//editfile
	search_field_6 = new QLineEdit(tr("Search here:"));
	QObject::connect(search_field_6, SIGNAL(returnPressed()),this, SLOT(handleButton_6_1()));
	back_home_6 = new QPushButton(tr("<<Back to Home"));
	back_home_6->setFlat(true);
	QObject::connect(back_home_6, SIGNAL(clicked()),this, SLOT(handleButton_6_2()));
	search_area_layout_6->addWidget(search_label_6);
	search_area_layout_6->addWidget(search_field_6);
	search_area_layout_6->addWidget(back_home_6);
	search_area_6->setLayout(search_area_layout_6);
}


void Favorite::display_favorite(){
	string username_favorite = string((const char *)Connector::username.toLocal8Bit());  
 	string inputCommand = "display*_*" + username_favorite + "*_*favorites";
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
    
    num = atoi(n.c_str());
 
    vector<vector<string> > entry;
    for(int i=0; i<num;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        entry.push_back(s);    
        Connector::favorites_entry[i] = s[0];
        assert(s.size() == 3);
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd_str); 
    assert(entry.size() == num);


    vertical_images_6 = new QGroupBox();
    QVBoxLayout *vertical_images_6_layout = new QVBoxLayout;

    if(num <=5){
    	horizontal_images_6_1 = new QGroupBox();
    	QHBoxLayout *horizontal_images_6_1_layout = new QHBoxLayout;

    	for(int i = 0; i < num; i++){
    		QPushButton *button = new QPushButton();
            const char * button_str = entry[i][1].c_str();
            button->setIcon(QIcon(entry[i][2].c_str()));
			button->setIconSize(QSize(120,200));
			button->setToolTip(tr(button_str)); 
			button->setFlat(true);
			favorite_buttons.push_back(button);  	
 			horizontal_images_6_1_layout->addWidget(favorite_buttons[i]);	
    	}
    	horizontal_images_6_1->setLayout(horizontal_images_6_1_layout);
    	vertical_images_6_layout->addWidget(horizontal_images_6_1);
    	vertical_images_6->setLayout(vertical_images_6_layout);

    }else{
    	horizontal_images_6_2 = new QGroupBox();
    	QHBoxLayout *horizontal_images_6_2_layout = new QHBoxLayout;
    	horizontal_images_6_3 = new QGroupBox();
    	QHBoxLayout *horizontal_images_6_3_layout = new QHBoxLayout;

    	for(int i = 0; i < 5; i++){
    		QPushButton *button = new QPushButton();
            const char * button_str = entry[i][1].c_str();
            button->setIcon(QIcon(entry[i][2].c_str()));
			button->setIconSize(QSize(120,200));
			button->setToolTip(tr(button_str)); 
			button->setFlat(true);
			favorite_buttons.push_back(button);  	
 			horizontal_images_6_2_layout->addWidget(favorite_buttons[i]);

    	}
    	horizontal_images_6_2->setLayout(horizontal_images_6_2_layout);
		horizontal_images_6_2->setFixedHeight(220);


    	for(int i = 5; i < num; i++){
            QPushButton *button = new QPushButton();
            const char * button_str = entry[i][1].c_str();
            button->setIcon(QIcon(entry[i][2].c_str()));
            button->setIconSize(QSize(120,200));
            button->setToolTip(tr(button_str)); 
            button->setFlat(true);
            favorite_buttons.push_back(button);  
 			horizontal_images_6_3_layout->addWidget(favorite_buttons[i]);	
    	}
    	horizontal_images_6_3->setLayout(horizontal_images_6_3_layout);
    	horizontal_images_6_3->setFixedHeight(220);
    	vertical_images_6_layout->addWidget(horizontal_images_6_2);
    	vertical_images_6_layout->addWidget(horizontal_images_6_3);
    	vertical_images_6->setLayout(vertical_images_6_layout);
    }



    if(num == 1){
    	QObject::connect(favorite_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_1()));
    }
    else if(num == 2){
    	QObject::connect(favorite_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_1()));
    	QObject::connect(favorite_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_2()));
    }
    else if(num == 3){
    	QObject::connect(favorite_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_1()));
    	QObject::connect(favorite_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_2()));
    	QObject::connect(favorite_buttons[2], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_3()));
    }
    else if(num == 4){
    	QObject::connect(favorite_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_1()));
    	QObject::connect(favorite_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_2()));
    	QObject::connect(favorite_buttons[2], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_3()));
    	QObject::connect(favorite_buttons[3], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_4()));
    }
    else if(num == 5){
    	QObject::connect(favorite_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_1()));
    	QObject::connect(favorite_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_2()));
    	QObject::connect(favorite_buttons[2], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_3()));
    	QObject::connect(favorite_buttons[3], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_4()));
    	QObject::connect(favorite_buttons[4], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_5()));
    }
    else if(num == 6){
    	QObject::connect(favorite_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_1()));
    	QObject::connect(favorite_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_2()));
    	QObject::connect(favorite_buttons[2], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_3()));
    	QObject::connect(favorite_buttons[3], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_4()));
    	QObject::connect(favorite_buttons[4], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_5()));
    	QObject::connect(favorite_buttons[5], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_6()));
    }
    else if(num == 7){
    	QObject::connect(favorite_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_1()));
    	QObject::connect(favorite_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_2()));
    	QObject::connect(favorite_buttons[2], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_3()));
    	QObject::connect(favorite_buttons[3], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_4()));
    	QObject::connect(favorite_buttons[4], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_5()));
    	QObject::connect(favorite_buttons[5], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_6()));
    	QObject::connect(favorite_buttons[6], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_7()));
    }
    else if(num == 8){
    	QObject::connect(favorite_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_1()));
    	QObject::connect(favorite_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_2()));
    	QObject::connect(favorite_buttons[2], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_3()));
    	QObject::connect(favorite_buttons[3], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_4()));
    	QObject::connect(favorite_buttons[4], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_5()));
    	QObject::connect(favorite_buttons[5], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_6()));
    	QObject::connect(favorite_buttons[6], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_7()));
    	QObject::connect(favorite_buttons[7], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_8()));
    }
    else if(num == 9){
    	QObject::connect(favorite_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_1()));
    	QObject::connect(favorite_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_2()));
    	QObject::connect(favorite_buttons[2], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_3()));
    	QObject::connect(favorite_buttons[3], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_4()));
    	QObject::connect(favorite_buttons[4], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_5()));
    	QObject::connect(favorite_buttons[5], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_6()));
    	QObject::connect(favorite_buttons[6], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_7()));
    	QObject::connect(favorite_buttons[7], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_8()));
    	QObject::connect(favorite_buttons[8], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_9()));
    }
    else if(num == 10){
    	QObject::connect(favorite_buttons[0], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_1()));
    	QObject::connect(favorite_buttons[1], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_2()));
    	QObject::connect(favorite_buttons[2], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_3()));
    	QObject::connect(favorite_buttons[3], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_4()));
    	QObject::connect(favorite_buttons[4], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_5()));
    	QObject::connect(favorite_buttons[5], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_6()));
    	QObject::connect(favorite_buttons[6], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_7()));
    	QObject::connect(favorite_buttons[7], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_8()));
    	QObject::connect(favorite_buttons[8], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_9()));
    	QObject::connect(favorite_buttons[9], SIGNAL(clicked()),this, SLOT(handleButton_6_pic_10()));
    }


}


 void Favorite::createBottom_6()
 {
	bottom_area_6 = new QGroupBox();
	QHBoxLayout *bottom_area_layout_6 = new QHBoxLayout;

	//logo_3_2
	logo_6_2 = new QLabel();
	logo_6_2 ->setText("<img src=\"logo2.png\">");
	
	//copyright
	copy_right_6 = new QLabel();
	copy_right_6->setText("Copy right ...........:");

	sign_out_6 = new QPushButton(tr("<Sign Out>"));
	manage_account_6 = new QPushButton(tr("<Manage Account>"));
	sign_out_6->setFlat(true);
	manage_account_6->setFlat(true);
	QObject::connect(sign_out_6, SIGNAL(clicked()),this, SLOT(handleButton_6_3()));
	QObject::connect(manage_account_6, SIGNAL(clicked()),this, SLOT(handleButton_6_4()));

	bottom_area_layout_6->addWidget(logo_6_2);
	bottom_area_layout_6->addWidget(copy_right_6);
	bottom_area_layout_6->addWidget(sign_out_6);
	bottom_area_layout_6->addWidget(manage_account_6);
	bottom_area_6->setLayout(bottom_area_layout_6);
 }


void  Favorite::handleButton_6_pic_1(){

	Connector::entry_p = 2;
	Connector::e1 = Connector::favorites_entry[0];
    hide();
    Entry entry;
    entry.exec();
    show();

}

void  Favorite::handleButton_6_pic_2(){

	Connector::entry_p = 2;
	Connector::e1 = Connector::favorites_entry[1];
    hide();
    Entry entry;
    entry.exec();
    show();

}


void  Favorite::handleButton_6_pic_3(){

	Connector::entry_p = 2;
	Connector::e1 = Connector::favorites_entry[2];
    hide();
    Entry entry;
    entry.exec();
    show();

}


void  Favorite::handleButton_6_pic_4(){

	Connector::entry_p = 2;
	Connector::e1 = Connector::favorites_entry[3];
    hide();
    Entry entry;
    entry.exec();
    show();

}


void  Favorite::handleButton_6_pic_5(){

	Connector::entry_p = 2;
	Connector::e1 = Connector::favorites_entry[4];
    hide();
    Entry entry;
    entry.exec();
    show();

}


void  Favorite::handleButton_6_pic_6(){

	Connector::entry_p = 2;
	Connector::e1 = Connector::favorites_entry[5];
    Entry entry;
    entry.exec();
    show();

}


void  Favorite::handleButton_6_pic_7(){

	Connector::entry_p = 2;
	Connector::e1 = Connector::favorites_entry[6];
    hide();
    Entry entry;
    entry.exec();
    show();

}


void  Favorite::handleButton_6_pic_8(){

	Connector::entry_p = 2;
	Connector::e1 = Connector::favorites_entry[7];
    hide();
    Entry entry;
    entry.exec();
    show();

}

void  Favorite::handleButton_6_pic_9(){

	Connector::entry_p = 2;
	Connector::e1 = Connector::favorites_entry[8];
    hide();
    Entry entry;
    entry.exec();
    show();

}


void  Favorite::handleButton_6_pic_10(){

	Connector::entry_p = 2;
	Connector::e1 = Connector::favorites_entry[9];
    hide();
    Entry entry;
    entry.exec();
    show();

} 



void  Favorite::handleButton_6_1()
{
	Connector::search_p = 2;
	Connector::search_metric = search_field_6->text();
    hide();
    Result result_6;
    result_6.exec();
    show();
}


void  Favorite::handleButton_6_2()
{
	hide();
}


void  Favorite::handleButton_6_3()
{
		Connector::signout_p = 2;
    hide();
    SignOut signout_6;
    signout_6.exec();
    show();
}

void  Favorite::handleButton_6_4()
{
		Connector::account_p = 2;
    hide();
    Account account_6;
    account_6.exec();
    show();
}

void  Favorite::loadStyleSheet_6()
{
	QFile qss("style.qss");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();
}


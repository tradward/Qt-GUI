#include "whats_new.h"

WhatsNew::WhatsNew() {
    createMenu_7();
	create_logo_7();
	display_search_7();
	display_whatsnew();
    create_line_7();
	createBottom_7();
    
    QVBoxLayout *mainLayout_7 = new QVBoxLayout;
    mainLayout_7->setMenuBar(menuBar_7);
    
    mainLayout_7->addWidget(whatsnew_logo);
	mainLayout_7->addWidget(line_logo_7_1);
	mainLayout_7->addWidget(search_area_7);
	mainLayout_7->addWidget(line_logo_7_2);
	mainLayout_7->addWidget(horizontalGroupBox_images_7);
	mainLayout_7->addWidget(horizontalGroupBox_images_7_2);
	mainLayout_7->addWidget(line_logo_7_3);
	mainLayout_7->addWidget(bottom_area_7);
    
    setLayout(mainLayout_7);
    setWindowTitle(tr("Welcome!"));
	loadStyleSheet_7();
}

void WhatsNew::closeEvent_7(QCloseEvent *event){
	Connector::signout_p = 1;
    hide();
    SignOut signout;
    signout.exec();
    //signout.setParent(this);
    show();
    event->accept();
}



void  WhatsNew::createMenu_7() {
    menuBar_7 = new QMenuBar;
    
    fileMenu_7 = new QMenu(tr("&File"), this);
    exitAction_7 = fileMenu_7->addAction(tr("E&xit"));
    menuBar_7->addMenu(fileMenu_7);
    
    connect(exitAction_7, SIGNAL(triggered()), this, SLOT(accept()));
}


void WhatsNew::create_logo_7() {
	whatsnew_logo = new QLabel();
	whatsnew_logo->setText("<img src=\"whatsnew_logo.png\">");
    whatsnew_logo->setAlignment(Qt::AlignHCenter);
}


void WhatsNew::create_line_7() {
	line_logo_7_1 = new QLabel();
	line_logo_7_1->setText("<img src=\"17.png\">");
    
	line_logo_7_2 = new QLabel();
	line_logo_7_2->setText("<img src=\"17.png\">");
    
	line_logo_7_3 = new QLabel();
	line_logo_7_3->setText("<img src=\"17.png\">");
}

void WhatsNew::display_search_7() {
	search_area_7 = new QGroupBox();
	QHBoxLayout *search_area_layout_7 = new QHBoxLayout;
	search_label_7 = new QLabel();
	search_label_7->setText("Please enter movies'name or director:");
	//editfile
	search_field_7 = new QLineEdit(tr("Search here:"));
	QObject::connect(search_field_7, SIGNAL(returnPressed()),this, SLOT(handleButton_7_2()));
	back_home_7 = new QPushButton(tr("<<Back to Home"));
	back_home_7->setFlat(true);
	QObject::connect(back_home_7, SIGNAL(clicked()),this, SLOT(handleButton_7_1()));
	search_area_layout_7->addWidget(search_label_7);
	search_area_layout_7->addWidget(search_field_7);
	search_area_layout_7->addWidget(back_home_7);
	search_area_7->setLayout(search_area_layout_7);
}
 
void WhatsNew::display_whatsnew() {
	cout << "Get Images2" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*new";
    int clientfd= client::client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char*)url.c_str());
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<12;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char*)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::new_entry[i] = s[0];
        
        client::Clie_SaveContent(clientfdx, (char*)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 12);
    
    const char * a_button_7_str = entry[0][1].c_str();
	a_button_7 = new QPushButton();
	a_button_7->setIcon(QIcon(entry[0][2].c_str()));
	a_button_7->setIconSize(QSize(120,200));
	a_button_7->setToolTip(tr(a_button_7_str));
    
    const char * b_button_7_str = entry[1][1].c_str();
	b_button_7 = new QPushButton();
	b_button_7->setIcon(QIcon(entry[1][2].c_str()));
	b_button_7->setIconSize(QSize(120,200));
	b_button_7->setToolTip(tr(b_button_7_str));
    
    const char * c_button_7_str = entry[2][1].c_str();
	c_button_7 = new QPushButton();
	c_button_7->setIcon(QIcon(entry[2][2].c_str()));
	c_button_7->setIconSize(QSize(120,200));;
	c_button_7->setToolTip(tr(c_button_7_str));
    
    const char * d_button_7_str = entry[3][1].c_str();
	d_button_7 = new QPushButton();
	d_button_7->setIcon(QIcon(entry[3][2].c_str()));
	d_button_7->setIconSize(QSize(120,200));
	d_button_7->setToolTip(tr(d_button_7_str));
    
    const char * e_button_7_str = entry[4][1].c_str();
	e_button_7 = new QPushButton();
	e_button_7->setIcon(QIcon(entry[4][2].c_str()));
	e_button_7->setIconSize(QSize(120,200));
	e_button_7->setToolTip(tr(e_button_7_str));
    
    const char * f_button_7_str = entry[5][1].c_str();
	f_button_7 = new QPushButton();
	f_button_7->setIcon(QIcon(entry[5][2].c_str()));
	f_button_7->setIconSize(QSize(120,200));
	f_button_7->setToolTip(tr(f_button_7_str));
    
    
    const char * g_button_7_str = entry[6][1].c_str();
	g_button_7 = new QPushButton();
	g_button_7->setIcon(QIcon(entry[6][2].c_str()));
	g_button_7->setIconSize(QSize(120,200));
	g_button_7->setToolTip(tr(g_button_7_str));
    
    const char * h_button_7_str = entry[7][1].c_str();
	h_button_7 = new QPushButton();
	h_button_7->setIcon(QIcon(entry[7][2].c_str()));
	h_button_7->setIconSize(QSize(120,200));
	h_button_7->setToolTip(tr(h_button_7_str));
    
    
    const char * i_button_7_str = entry[8][1].c_str();
	i_button_7 = new QPushButton();
	i_button_7->setIcon(QIcon(entry[8][2].c_str()));
	i_button_7->setIconSize(QSize(120,200));
	i_button_7->setToolTip(tr(i_button_7_str));
    
    const char * j_button_7_str = entry[9][1].c_str();
	j_button_7 = new QPushButton();
	j_button_7->setIcon(QIcon(entry[9][2].c_str()));
	j_button_7->setIconSize(QSize(120,200));
	j_button_7->setToolTip(tr(j_button_7_str));
    
    const char * k_button_7_str = entry[10][1].c_str();
	k_button_7 = new QPushButton();
	k_button_7->setIcon(QIcon(entry[10][2].c_str()));
	k_button_7->setIconSize(QSize(120,200));
	k_button_7->setToolTip(tr(k_button_7_str));
    
    const char * l_button_7_str = entry[11][1].c_str();
	l_button_7 = new QPushButton();
	l_button_7->setIcon(QIcon(entry[11][2].c_str()));
	l_button_7->setIconSize(QSize(120,200));
	l_button_7->setToolTip(tr(l_button_7_str));
    
    
	QObject::connect(a_button_7, SIGNAL(clicked()),this, SLOT(handle_a_button_7()));
	QObject::connect(b_button_7, SIGNAL(clicked()),this, SLOT(handle_b_button_7()));
	QObject::connect(c_button_7, SIGNAL(clicked()),this, SLOT(handle_c_button_7()));
	QObject::connect(d_button_7, SIGNAL(clicked()),this, SLOT(handle_d_button_7()));
	QObject::connect(e_button_7, SIGNAL(clicked()),this, SLOT(handle_e_button_7()));
	QObject::connect(f_button_7, SIGNAL(clicked()),this, SLOT(handle_f_button_7()));
    
	QObject::connect(g_button_7, SIGNAL(clicked()),this, SLOT(handle_g_button_7()));
	QObject::connect(h_button_7, SIGNAL(clicked()),this, SLOT(handle_h_button_7()));
	QObject::connect(i_button_7, SIGNAL(clicked()),this, SLOT(handle_i_button_7()));
	QObject::connect(j_button_7, SIGNAL(clicked()),this, SLOT(handle_j_button_7()));
	QObject::connect(k_button_7, SIGNAL(clicked()),this, SLOT(handle_k_button_7()));
	QObject::connect(l_button_7, SIGNAL(clicked()),this, SLOT(handle_l_button_7()));
    
	a_button_7->setFlat(true);
	b_button_7->setFlat(true);
	c_button_7->setFlat(true);
	d_button_7->setFlat(true);
	e_button_7->setFlat(true);
	f_button_7->setFlat(true);
	g_button_7->setFlat(true);
	h_button_7->setFlat(true);
	i_button_7->setFlat(true);
	j_button_7->setFlat(true);
	k_button_7->setFlat(true);
	l_button_7->setFlat(true);
    
    horizontalGroupBox_images_7 = new QGroupBox();
    QHBoxLayout *layout_images_7 = new QHBoxLayout;
	layout_images_7->addWidget(a_button_7);
	layout_images_7->addWidget(b_button_7);
	layout_images_7->addWidget(c_button_7);
	layout_images_7->addWidget(d_button_7);
	layout_images_7->addWidget(e_button_7);
	layout_images_7->addWidget(f_button_7);
    horizontalGroupBox_images_7->setLayout(layout_images_7);
	horizontalGroupBox_images_7->setFixedHeight(220);
    
    
    horizontalGroupBox_images_7_2 = new QGroupBox();
    QHBoxLayout *layout_images_7_2 = new QHBoxLayout;
	layout_images_7_2->addWidget(g_button_7);
	layout_images_7_2->addWidget(h_button_7);
	layout_images_7_2->addWidget(i_button_7);
	layout_images_7_2->addWidget(j_button_7);
	layout_images_7_2->addWidget(k_button_7);
	layout_images_7_2->addWidget(l_button_7);
    horizontalGroupBox_images_7_2->setLayout(layout_images_7_2);
	horizontalGroupBox_images_7_2->setFixedHeight(220);
}

void WhatsNew::createBottom_7() {
	bottom_area_7 = new QGroupBox();
	QHBoxLayout *bottom_area_layout_7 = new QHBoxLayout;
    
	//logo_3_2
	logo_7_2 = new QLabel();
	logo_7_2 ->setText("<img src=\"logo2.png\">");
	
	//copyright
	copy_right_7 = new QLabel();
	copy_right_7->setText(Connector::copyright);
    
	sign_out_7 = new QPushButton(tr("<Sign Out>"));
	manage_account_7 = new QPushButton(tr("<Manage Account>"));
	sign_out_7->setFlat(true);
	manage_account_7->setFlat(true);
	QObject::connect(sign_out_7, SIGNAL(clicked()),this, SLOT(handleButton_7_3()));
	QObject::connect(manage_account_7, SIGNAL(clicked()),this, SLOT(handleButton_7_4()));
	bottom_area_layout_7->addWidget(logo_7_2);
	bottom_area_layout_7->addWidget(copy_right_7);
	bottom_area_layout_7->addWidget(sign_out_7);
	bottom_area_layout_7->addWidget(manage_account_7);
	bottom_area_7->setLayout(bottom_area_layout_7);
}

void WhatsNew::handleButton_7_1() {
    this->hide();
    //this->parentWidget()->show();
}

void WhatsNew::handleButton_7_2() {
	Connector::search_p = 1;
	Connector::search_metric = search_field_7->text();
    hide();
    Result result_7;
    result_7.exec();
    show();
}

void WhatsNew::handleButton_7_3() {
	Connector::signout_p = 1;
    hide();
    SignOut signout_7;
    signout_7.exec();
    show();
}

void WhatsNew::handleButton_7_4() {
	Connector::account_p = 1;
    hide();
    Account account_7;
    //account_7.setParent(this);
    account_7.exec();
    show();
}

void WhatsNew::handle_a_button_7() {
	Connector::entry_p = 1;
	Connector::e1 = Connector::new_entry[0];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void WhatsNew::handle_b_button_7() {
	Connector::entry_p = 1;
	Connector::e1 = Connector::new_entry[1];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void WhatsNew::handle_c_button_7() {
	Connector::entry_p = 1;
	Connector::e1 = Connector::new_entry[2];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void WhatsNew::handle_d_button_7() {
	Connector::entry_p = 1;
	Connector::e1 = Connector::new_entry[3];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void WhatsNew::handle_e_button_7() {
	Connector::entry_p = 1;
	Connector::e1 = Connector::new_entry[4];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void WhatsNew::handle_f_button_7() {
	Connector::entry_p = 1;
	Connector::e1 = Connector::new_entry[5];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void WhatsNew::handle_g_button_7() {
	Connector::entry_p = 1;
	Connector::e1 = Connector::new_entry[6];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void WhatsNew::handle_h_button_7() {
	Connector::entry_p = 1;
	Connector::e1 = Connector::new_entry[7];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void WhatsNew::handle_i_button_7() {
	Connector::entry_p = 1;
	Connector::e1 = Connector::new_entry[8];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void WhatsNew::handle_j_button_7() {
	Connector::entry_p = 1;
	Connector::e1 = Connector::new_entry[9];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void WhatsNew::handle_k_button_7() {
	Connector::entry_p = 1;
	Connector::e1 = Connector::new_entry[10];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void WhatsNew::handle_l_button_7() {
	Connector::entry_p = 1;
	Connector::e1 = Connector::new_entry[11];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void  WhatsNew::loadStyleSheet_7() {
	QFile qss("style.qss");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();
}

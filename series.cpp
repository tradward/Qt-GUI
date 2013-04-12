
#include <QtGui>
#include <QApplication>//add it
#include "series.h"
#include "favorite.h"
#include "result.h"
#include "connector.h"
#include "sign_out.h"
#include "account.h"
#include "mainwindow.h"
#include "entry.h"
#include "common.h"
#include <QCloseEvent>
#include <vector>

Series::Series()
{
    createMenu_8();
    createHorizontalGroupBox_8();
	createBottom_8();
	createImages_8();
	display_options();
	display_search();
	create_labels();
    QVBoxLayout *mainLayout_8 = new QVBoxLayout;
    mainLayout_8->setMenuBar(menuBar_8);
    mainLayout_8->addWidget(series_logo);
	mainLayout_8->addWidget(line_logo_2_1);
	mainLayout_8->addWidget(search_area);
	mainLayout_8->addWidget(line_logo_2_2);
	mainLayout_8->addWidget(history_label);
	mainLayout_8->addWidget(horizontalGroupBox_images_8);
	mainLayout_8->addWidget(line_logo_2_8);
    
	mainLayout_8->addWidget(classification_label);
	mainLayout_8->addWidget(options_1_8);
	mainLayout_8->addWidget(options_2_8);
	mainLayout_8->addWidget(line_logo_2_4);
	mainLayout_8->addWidget(bottom_area);
    setLayout(mainLayout_8);
    setWindowTitle(tr("Welcome,user"));
	loadStyleSheet_8();
}


void Series::closeEvent_8(QCloseEvent *event){
	Connector::signout_p = 4;
    hide();
    SignOut signout;
    signout.exec();
    //signout.setParent(this);
    show();
    event->accept();
}


void Series:: create_labels(){
	history_label = new QLabel();
	history_label->setText("<img src=\"history.png\">");
    
	classification_label = new QLabel();
	classification_label->setText("<img src=\"classification.png\">");
}

void  Series::createMenu_8()
{
    menuBar_8 = new QMenuBar;
    
    fileMenu_8 = new QMenu(tr("&File"), this);
    exitAction_8 = fileMenu_8->addAction(tr("E&xit"));
    menuBar_8->addMenu(fileMenu_8);
    
    connect(exitAction_8, SIGNAL(triggered()), this, SLOT(accept()));
}

void  Series::createHorizontalGroupBox_8()
{
	series_logo = new QLabel();
	series_logo->setText("<img src=\"series_logo.png\">");
	series_logo->setAlignment(Qt::AlignHCenter);
    
	line_logo_2_1 = new QLabel();
	line_logo_2_1->setText("<img src=\"17.png\">");
    
	line_logo_2_2 = new QLabel();
	line_logo_2_2->setText("<img src=\"17.png\">");
    
	line_logo_2_8 = new QLabel();
	line_logo_2_8->setText("<img src=\"17.png\">");
    
	line_logo_2_4 = new QLabel();
	line_logo_2_4->setText("<img src=\"17.png\">");
}



void Series::createBottom_8()
{
	bottom_area = new QGroupBox();
	QHBoxLayout *bottom_area_layout = new QHBoxLayout;
    
	//logo_8_2
	logo_8_2 = new QLabel();
	logo_8_2 ->setText("<img src=\"logo2.png\">");
	
	//copyright
	copy_right = new QLabel();
	copy_right->setText("Copy right ...........:");
    
	sign_out_8 = new QPushButton(tr("<Sign Out>"));
	manage_account_8 = new QPushButton(tr("<Manage Account>"));
	sign_out_8->setFlat(true);
	manage_account_8->setFlat(true);
	QObject::connect(sign_out_8, SIGNAL(clicked()),this, SLOT(handleButton_8_3()));
	QObject::connect(manage_account_8, SIGNAL(clicked()),this, SLOT(handleButton_8_4()));
	bottom_area_layout->addWidget(logo_8_2);
	bottom_area_layout->addWidget(copy_right);
	bottom_area_layout->addWidget(sign_out_8);
	bottom_area_layout->addWidget(manage_account_8);
	bottom_area->setLayout(bottom_area_layout);
}

void Series::display_search(){
	search_area = new QGroupBox();
	QHBoxLayout *search_area_layout = new QHBoxLayout;
	search_label_8 = new QLabel();
	search_label_8->setText("Please enter series'name or director:");
	//editfile
	search_field_8 = new QLineEdit(tr("Search here:"));
	QObject::connect(search_field_8, SIGNAL(returnPressed()),this, SLOT(handleButton_8_1()));
	back_home = new QPushButton(tr("<<Back to Home"));
	back_home->setFlat(true);
	QObject::connect(back_home, SIGNAL(clicked()),this, SLOT(handleButton_8_2()));
	search_area_layout->addWidget(search_label_8);
	search_area_layout->addWidget(search_field_8);
	search_area_layout->addWidget(back_home);
	search_area->setLayout(search_area_layout);
}

void Series::display_options(){
    
    
	//1st line
	options_1_8 = new QGroupBox();
	QHBoxLayout *options_layout_1_8 = new QHBoxLayout;
    
    
    
	action_8 =    		new QPushButton(tr("   =Action=         "));
	action_8->setFlat(true);
	biography_8 =    	new QPushButton(tr("   =Biography=      "));
	biography_8->setFlat(true);
	classics_8 =    	new QPushButton(tr("   =Classics=       "));
	classics_8->setFlat(true);
	comic_8 =    		new QPushButton(tr("   =Comic=          "));
	comic_8->setFlat(true);
	commedy_8 =    		new QPushButton(tr("   =Comedy=         "));
	commedy_8->setFlat(true);
	discovery_8 =    	new QPushButton(tr("   =Discovery=      "));
	discovery_8->setFlat(true);
    
	QObject::connect(action_8, SIGNAL(clicked()),this, SLOT(handle_action_button_8()));
	QObject::connect(biography_8, SIGNAL(clicked()),this, SLOT(handle_biography_button_8()));
	QObject::connect(classics_8, SIGNAL(clicked()),this, SLOT(handle_classics_button_8()));
	QObject::connect(comic_8, SIGNAL(clicked()),this, SLOT(handle_comic_button_8()));
	QObject::connect(commedy_8, SIGNAL(clicked()),this, SLOT(handle_comedy_button_8()));
	QObject::connect(discovery_8, SIGNAL(clicked()),this, SLOT(handle_discovery_button_8()));
    
    
	options_layout_1_8 ->addWidget(action_8);
	options_layout_1_8 ->addWidget(biography_8);
	options_layout_1_8 ->addWidget(classics_8);
	options_layout_1_8 ->addWidget(comic_8);
	options_layout_1_8 ->addWidget(commedy_8);
	options_layout_1_8 ->addWidget(discovery_8);
    options_1_8 ->setLayout(options_layout_1_8);
    
    
    
	//2nd line
	options_2_8 = new QGroupBox();
	QHBoxLayout *options_layout_2_8 = new QHBoxLayout;
    
    
    
	documentary_8 = 	new QPushButton(tr("   =Documentary=    "));
	documentary_8->setFlat(true);
	history_8 = 		new QPushButton(tr("   =History=        "));
	history_8->setFlat(true);
	kids_8 =    		new QPushButton(tr("   =Kids=           "));
	kids_8->setFlat(true);
	miniseries_8 = 		new QPushButton(tr("   =Mystery=        "));
	miniseries_8->setFlat(true);
	reality_8=		new QPushButton(tr("   =Reality=        "));
	reality_8->setFlat(true);
	science_fiction_8 =	new QPushButton(tr("   =Science Fiction="));
	science_fiction_8->setFlat(true);
    
    
	QObject::connect(documentary_8, SIGNAL(clicked()),this, SLOT(handle_documentary_button_8()));
	QObject::connect(history_8, SIGNAL(clicked()),this, SLOT(handle_history_button_8()));
	QObject::connect(kids_8, SIGNAL(clicked()),this, SLOT(handle_kids_button_8()));
	QObject::connect(miniseries_8, SIGNAL(clicked()),this, SLOT(handle_miniseries_button_8()));
	QObject::connect(reality_8, SIGNAL(clicked()),this, SLOT(handle_reality_button_8()));
	QObject::connect(science_fiction_8, SIGNAL(clicked()),this, SLOT(handle_science_fiction_button_8()));
    
	options_layout_2_8->addWidget(documentary_8);
	options_layout_2_8->addWidget(history_8);
	options_layout_2_8->addWidget(kids_8);
	options_layout_2_8->addWidget(miniseries_8);
	options_layout_2_8->addWidget(reality_8);
	options_layout_2_8->addWidget(science_fiction_8);
	options_2_8->setLayout(options_layout_2_8);
    
}


void Series::createImages_8(){
	Connector::series_type = "series";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*series";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char*)url.c_str());
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<6;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::series_entry[i] = s[0];
        
        client::Clie_SaveContent(clientfdx, (char*)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
	a_button_8 = new QPushButton();
	a_button_8->setIcon(QIcon(entry[0][2].c_str()));
	a_button_8->setIconSize(QSize(120,200));
	const char * a_button_8_str = entry[0][1].c_str();
	a_button_8->setToolTip(tr(a_button_8_str));
    
	b_button_8 = new QPushButton();
	b_button_8->setIcon(QIcon(entry[1][2].c_str()));
	b_button_8->setIconSize(QSize(120,200));
	const char * b_button_8_str = entry[1][1].c_str();
	b_button_8->setToolTip(tr(b_button_8_str));
    
	c_button_8 = new QPushButton();
	c_button_8->setIcon(QIcon(entry[2][2].c_str()));
	c_button_8->setIconSize(QSize(120,200));
	const char * c_button_8_str = entry[2][1].c_str();
	c_button_8->setToolTip(tr(c_button_8_str));
    
	d_button_8 = new QPushButton();
	d_button_8->setIcon(QIcon(entry[3][2].c_str()));
	d_button_8->setIconSize(QSize(120,200));
	const char * d_button_8_str = entry[3][1].c_str();
	d_button_8->setToolTip(tr(d_button_8_str));
    
	e_button_8 = new QPushButton();
	e_button_8->setIcon(QIcon(entry[4][2].c_str()));
	e_button_8->setIconSize(QSize(120,200));
	const char * e_button_8_str = entry[4][1].c_str();
	e_button_8->setToolTip(tr(e_button_8_str));
    
	f_button_8 = new QPushButton();
	f_button_8->setIcon(QIcon(entry[5][2].c_str()));
	f_button_8->setIconSize(QSize(120,200));
	const char * f_button_8_str = entry[5][1].c_str();
	f_button_8->setToolTip(tr(f_button_8_str));
    
	QObject::connect(a_button_8, SIGNAL(clicked()),this, SLOT(handle_a_button_8()));
	QObject::connect(b_button_8, SIGNAL(clicked()),this, SLOT(handle_b_button_8()));
	QObject::connect(c_button_8, SIGNAL(clicked()),this, SLOT(handle_c_button_8()));
	QObject::connect(d_button_8, SIGNAL(clicked()),this, SLOT(handle_d_button_8()));
	QObject::connect(e_button_8, SIGNAL(clicked()),this, SLOT(handle_e_button_8()));
	QObject::connect(f_button_8, SIGNAL(clicked()),this, SLOT(handle_f_button_8()));
    
    
	a_button_8->setFlat(true);
	b_button_8->setFlat(true);
	c_button_8->setFlat(true);
	d_button_8->setFlat(true);
	e_button_8->setFlat(true);
	f_button_8->setFlat(true);
    
    horizontalGroupBox_images_8 = new QGroupBox();
    QHBoxLayout *layout_images_8 = new QHBoxLayout;
	layout_images_8->addWidget(a_button_8);
	layout_images_8->addWidget(b_button_8);
	layout_images_8->addWidget(c_button_8);
	layout_images_8->addWidget(d_button_8);
	layout_images_8->addWidget(e_button_8);
	layout_images_8->addWidget(f_button_8);
    horizontalGroupBox_images_8->setLayout(layout_images_8);
	horizontalGroupBox_images_8->setFixedHeight(220);
}



void Series::handle_action_button_8(){
    
	Connector::series_type = "action";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*series*_*Action&Advanture";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char*)url.c_str());
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<6;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::series_action_entry[i] = s[0];
        
        client::Clie_SaveContent(clientfdx, (char*)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_8_str = entry[0][1].c_str();
	a_button_8->setIcon(QIcon(entry[0][2].c_str()));
	a_button_8->setToolTip(tr(a_button_8_str));
    
	const char * b_button_8_str = entry[1][1].c_str();
	b_button_8->setIcon(QIcon(entry[1][2].c_str()));
	b_button_8->setToolTip(tr(b_button_8_str));
    
    const char * c_button_8_str = entry[2][1].c_str();
	c_button_8->setIcon(QIcon(entry[2][2].c_str()));
	c_button_8->setToolTip(tr(c_button_8_str));
    
    const char * d_button_8_str = entry[3][1].c_str();
	d_button_8->setIcon(QIcon(entry[3][2].c_str()));
	d_button_8->setToolTip(tr(d_button_8_str));
    
    const char * e_button_8_str = entry[4][1].c_str();
	e_button_8->setIcon(QIcon(entry[4][2].c_str()));
	e_button_8->setToolTip(tr(e_button_8_str));
    
    const char * f_button_8_str = entry[5][1].c_str();
	f_button_8->setIcon(QIcon(entry[5][2].c_str()));
	f_button_8->setToolTip(tr(f_button_8_str));
    
}

void Series::handle_biography_button_8(){
    
	Connector::series_type = "biography";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*series*_*biography";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char*)url.c_str());
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<6;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::series_biography_entry[i] = s[0];
        
        client::Clie_SaveContent(clientfdx, (char*)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    
    const char * a_button_8_str = entry[0][1].c_str();
	a_button_8->setIcon(QIcon(entry[0][2].c_str()));
	a_button_8->setToolTip(tr(a_button_8_str));
    
	const char * b_button_8_str = entry[1][1].c_str();
	b_button_8->setIcon(QIcon(entry[1][2].c_str()));
	b_button_8->setToolTip(tr(b_button_8_str));
    
    const char * c_button_8_str = entry[2][1].c_str();
	c_button_8->setIcon(QIcon(entry[2][2].c_str()));
	c_button_8->setToolTip(tr(c_button_8_str));
    
    const char * d_button_8_str = entry[3][1].c_str();
	d_button_8->setIcon(QIcon(entry[3][2].c_str()));
	d_button_8->setToolTip(tr(d_button_8_str));
    
    const char * e_button_8_str = entry[4][1].c_str();
	e_button_8->setIcon(QIcon(entry[4][2].c_str()));
	e_button_8->setToolTip(tr(e_button_8_str));
    
    const char * f_button_8_str = entry[5][1].c_str();
	f_button_8->setIcon(QIcon(entry[5][2].c_str()));
	f_button_8->setToolTip(tr(f_button_8_str));
}

void Series::handle_classics_button_8(){
    
	Connector::series_type = "classics";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*series*_*classics";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char*)url.c_str());
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<6;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::series_classics_entry[i] = s[0];

        client::Clie_SaveContent(clientfdx, (char*)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_8_str = entry[0][1].c_str();
	a_button_8->setIcon(QIcon(entry[0][2].c_str()));
	a_button_8->setToolTip(tr(a_button_8_str));
    
	const char * b_button_8_str = entry[1][1].c_str();
	b_button_8->setIcon(QIcon(entry[1][2].c_str()));
	b_button_8->setToolTip(tr(b_button_8_str));
    
    const char * c_button_8_str = entry[2][1].c_str();
	c_button_8->setIcon(QIcon(entry[2][2].c_str()));
	c_button_8->setToolTip(tr(c_button_8_str));
    
    const char * d_button_8_str = entry[3][1].c_str();
	d_button_8->setIcon(QIcon(entry[3][2].c_str()));
	d_button_8->setToolTip(tr(d_button_8_str));
    
    const char * e_button_8_str = entry[4][1].c_str();
	e_button_8->setIcon(QIcon(entry[4][2].c_str()));
	e_button_8->setToolTip(tr(e_button_8_str));
    
    const char * f_button_8_str = entry[5][1].c_str();
	f_button_8->setIcon(QIcon(entry[5][2].c_str()));
	f_button_8->setToolTip(tr(f_button_8_str));
    
}

void Series::handle_comic_button_8(){
    
	Connector::series_type = "comic";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*series*_*comic";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char*)url.c_str());
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<6;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::series_comic_entry[i] = s[0];
        
        client::Clie_SaveContent(clientfdx, (char*)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    

    const char * a_button_8_str = entry[0][1].c_str();
	a_button_8->setIcon(QIcon(entry[0][2].c_str()));
	a_button_8->setToolTip(tr(a_button_8_str));
    
	const char * b_button_8_str = entry[1][1].c_str();
	b_button_8->setIcon(QIcon(entry[1][2].c_str()));
	b_button_8->setToolTip(tr(b_button_8_str));
    
    const char * c_button_8_str = entry[2][1].c_str();
	c_button_8->setIcon(QIcon(entry[2][2].c_str()));
	c_button_8->setToolTip(tr(c_button_8_str));
    
    const char * d_button_8_str = entry[3][1].c_str();
	d_button_8->setIcon(QIcon(entry[3][2].c_str()));
	d_button_8->setToolTip(tr(d_button_8_str));
    
    const char * e_button_8_str = entry[4][1].c_str();
	e_button_8->setIcon(QIcon(entry[4][2].c_str()));
	e_button_8->setToolTip(tr(e_button_8_str));
    
    const char * f_button_8_str = entry[5][1].c_str();
	f_button_8->setIcon(QIcon(entry[5][2].c_str()));
	f_button_8->setToolTip(tr(f_button_8_str));
    
}

void Series::handle_comedy_button_8(){
    
	Connector::series_type = "comedy";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*series*_*Comedy";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char*)url.c_str());
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<6;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::series_comedy_entry[i] = s[0];
        
        client::Clie_SaveContent(clientfdx, (char*)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_8_str = entry[0][1].c_str();
	a_button_8->setIcon(QIcon(entry[0][2].c_str()));
	a_button_8->setToolTip(tr(a_button_8_str));
    
	const char * b_button_8_str = entry[1][1].c_str();
	b_button_8->setIcon(QIcon(entry[1][2].c_str()));
	b_button_8->setToolTip(tr(b_button_8_str));
    
    const char * c_button_8_str = entry[2][1].c_str();
	c_button_8->setIcon(QIcon(entry[2][2].c_str()));
	c_button_8->setToolTip(tr(c_button_8_str));
    
    const char * d_button_8_str = entry[3][1].c_str();
	d_button_8->setIcon(QIcon(entry[3][2].c_str()));
	d_button_8->setToolTip(tr(d_button_8_str));
    
    const char * e_button_8_str = entry[4][1].c_str();
	e_button_8->setIcon(QIcon(entry[4][2].c_str()));
	e_button_8->setToolTip(tr(e_button_8_str));
    
    const char * f_button_8_str = entry[5][1].c_str();
	f_button_8->setIcon(QIcon(entry[5][2].c_str()));
	f_button_8->setToolTip(tr(f_button_8_str));
}

void Series::handle_discovery_button_8(){
    
	Connector::series_type = "discovery";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*series*_*Discovery";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char*)url.c_str());
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<6;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::series_discovery_entry[i] = s[0];

        client::Clie_SaveContent(clientfdx, (char*)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_8_str = entry[0][1].c_str();
	a_button_8->setIcon(QIcon(entry[0][2].c_str()));
	a_button_8->setToolTip(tr(a_button_8_str));
    
	const char * b_button_8_str = entry[1][1].c_str();
	b_button_8->setIcon(QIcon(entry[1][2].c_str()));
	b_button_8->setToolTip(tr(b_button_8_str));
    
    const char * c_button_8_str = entry[2][1].c_str();
	c_button_8->setIcon(QIcon(entry[2][2].c_str()));
	c_button_8->setToolTip(tr(c_button_8_str));
    
    const char * d_button_8_str = entry[3][1].c_str();
	d_button_8->setIcon(QIcon(entry[3][2].c_str()));
	d_button_8->setToolTip(tr(d_button_8_str));
    
    const char * e_button_8_str = entry[4][1].c_str();
	e_button_8->setIcon(QIcon(entry[4][2].c_str()));
	e_button_8->setToolTip(tr(e_button_8_str));
    
    const char * f_button_8_str = entry[5][1].c_str();
	f_button_8->setIcon(QIcon(entry[5][2].c_str()));
	f_button_8->setToolTip(tr(f_button_8_str));
    
}

void Series::handle_documentary_button_8(){
    
	Connector::series_type = "documentary";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*series*_*Documentary";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char*)url.c_str());
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<6;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::series_documentary_entry[i] = s[0];

        client::Clie_SaveContent(clientfdx, (char*)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
	const char * a_button_8_str = entry[0][1].c_str();
	a_button_8->setIcon(QIcon(entry[0][2].c_str()));
	a_button_8->setToolTip(tr(a_button_8_str));
    
	const char * b_button_8_str = entry[1][1].c_str();
	b_button_8->setIcon(QIcon(entry[1][2].c_str()));
	b_button_8->setToolTip(tr(b_button_8_str));
    
    const char * c_button_8_str = entry[2][1].c_str();
	c_button_8->setIcon(QIcon(entry[2][2].c_str()));
	c_button_8->setToolTip(tr(c_button_8_str));
    
    const char * d_button_8_str = entry[3][1].c_str();
	d_button_8->setIcon(QIcon(entry[3][2].c_str()));
	d_button_8->setToolTip(tr(d_button_8_str));
    
    const char * e_button_8_str = entry[4][1].c_str();
	e_button_8->setIcon(QIcon(entry[4][2].c_str()));
	e_button_8->setToolTip(tr(e_button_8_str));
    
    const char * f_button_8_str = entry[5][1].c_str();
	f_button_8->setIcon(QIcon(entry[5][2].c_str()));
	f_button_8->setToolTip(tr(f_button_8_str));
    
}

void Series::handle_history_button_8(){
    
	Connector::series_type = "history";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*series*_*history";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char*)url.c_str());
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<6;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::series_history_entry[i] = s[0];
        
        client::Clie_SaveContent(clientfdx, (char*)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_8_str = entry[0][1].c_str();
	a_button_8->setIcon(QIcon(entry[0][2].c_str()));
	a_button_8->setToolTip(tr(a_button_8_str));
    
	const char * b_button_8_str = entry[1][1].c_str();
	b_button_8->setIcon(QIcon(entry[1][2].c_str()));
	b_button_8->setToolTip(tr(b_button_8_str));
    
    const char * c_button_8_str = entry[2][1].c_str();
	c_button_8->setIcon(QIcon(entry[2][2].c_str()));
	c_button_8->setToolTip(tr(c_button_8_str));
    
    const char * d_button_8_str = entry[3][1].c_str();
	d_button_8->setIcon(QIcon(entry[3][2].c_str()));
	d_button_8->setToolTip(tr(d_button_8_str));
    
    const char * e_button_8_str = entry[4][1].c_str();
	e_button_8->setIcon(QIcon(entry[4][2].c_str()));
	e_button_8->setToolTip(tr(e_button_8_str));
    
    const char * f_button_8_str = entry[5][1].c_str();
	f_button_8->setIcon(QIcon(entry[5][2].c_str()));
	f_button_8->setToolTip(tr(f_button_8_str));
    
}

void Series::handle_kids_button_8(){
    
	Connector::series_type = "kids";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*series*_*kids";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char*)url.c_str());
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<6;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::series_kids_entry[i] = s[0];
        
        client::Clie_SaveContent(clientfdx, (char*)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    
    const char * a_button_8_str = entry[0][1].c_str();
	a_button_8->setIcon(QIcon(entry[0][2].c_str()));
	a_button_8->setToolTip(tr(a_button_8_str));
    
	const char * b_button_8_str = entry[1][1].c_str();
	b_button_8->setIcon(QIcon(entry[1][2].c_str()));
	b_button_8->setToolTip(tr(b_button_8_str));
    
    const char * c_button_8_str = entry[2][1].c_str();
	c_button_8->setIcon(QIcon(entry[2][2].c_str()));
	c_button_8->setToolTip(tr(c_button_8_str));
    
    const char * d_button_8_str = entry[3][1].c_str();
	d_button_8->setIcon(QIcon(entry[3][2].c_str()));
	d_button_8->setToolTip(tr(d_button_8_str));
    
    const char * e_button_8_str = entry[4][1].c_str();
	e_button_8->setIcon(QIcon(entry[4][2].c_str()));
	e_button_8->setToolTip(tr(e_button_8_str));
    
    const char * f_button_8_str = entry[5][1].c_str();
	f_button_8->setIcon(QIcon(entry[5][2].c_str()));
	f_button_8->setToolTip(tr(f_button_8_str));
    
    
}

void Series::handle_miniseries_button_8(){
    
	Connector::series_type = "miniseries";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*series*_*MiniSeries";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char*)url.c_str());
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<6;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::series_miniseries_entry[i] = s[0];
        
        client::Clie_SaveContent(clientfdx, (char*)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
   
    const char * a_button_8_str = entry[0][1].c_str();
	a_button_8->setIcon(QIcon(entry[0][2].c_str()));
	a_button_8->setToolTip(tr(a_button_8_str));
    
	const char * b_button_8_str = entry[1][1].c_str();
	b_button_8->setIcon(QIcon(entry[1][2].c_str()));
	b_button_8->setToolTip(tr(b_button_8_str));
    
    const char * c_button_8_str = entry[2][1].c_str();
	c_button_8->setIcon(QIcon(entry[2][2].c_str()));
	c_button_8->setToolTip(tr(c_button_8_str));
    
    const char * d_button_8_str = entry[3][1].c_str();
	d_button_8->setIcon(QIcon(entry[3][2].c_str()));
	d_button_8->setToolTip(tr(d_button_8_str));
    
    const char * e_button_8_str = entry[4][1].c_str();
	e_button_8->setIcon(QIcon(entry[4][2].c_str()));
	e_button_8->setToolTip(tr(e_button_8_str));
    
    const char * f_button_8_str = entry[5][1].c_str();
	f_button_8->setIcon(QIcon(entry[5][2].c_str()));
	f_button_8->setToolTip(tr(f_button_8_str));
    
}

void Series::handle_reality_button_8(){
    
	Connector::series_type = "reality";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*series*_*Reality";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char*)url.c_str());
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<6;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::series_reality_entry[i] = s[0];
        
        client::Clie_SaveContent(clientfdx, (char*)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_8_str = entry[0][1].c_str();
	a_button_8->setIcon(QIcon(entry[0][2].c_str()));
	a_button_8->setToolTip(tr(a_button_8_str));
    
	const char * b_button_8_str = entry[1][1].c_str();
	b_button_8->setIcon(QIcon(entry[1][2].c_str()));
	b_button_8->setToolTip(tr(b_button_8_str));
    
    const char * c_button_8_str = entry[2][1].c_str();
	c_button_8->setIcon(QIcon(entry[2][2].c_str()));
	c_button_8->setToolTip(tr(c_button_8_str));
    
    const char * d_button_8_str = entry[3][1].c_str();
	d_button_8->setIcon(QIcon(entry[3][2].c_str()));
	d_button_8->setToolTip(tr(d_button_8_str));
    
    const char * e_button_8_str = entry[4][1].c_str();
	e_button_8->setIcon(QIcon(entry[4][2].c_str()));
	e_button_8->setToolTip(tr(e_button_8_str));
    
    const char * f_button_8_str = entry[5][1].c_str();
	f_button_8->setIcon(QIcon(entry[5][2].c_str()));
	f_button_8->setToolTip(tr(f_button_8_str));
    
}

void Series::handle_science_fiction_button_8(){
    
	Connector::series_type = "science_fiction";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*series*_*Science&Fiction";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char*)url.c_str());
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<6;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::series_science_fiction_entry[i] = s[0];
        
        client::Clie_SaveContent(clientfdx, (char*)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    const char * a_button_8_str = entry[0][1].c_str();
	a_button_8->setIcon(QIcon(entry[0][2].c_str()));
	a_button_8->setToolTip(tr(a_button_8_str));
    
	const char * b_button_8_str = entry[1][1].c_str();
	b_button_8->setIcon(QIcon(entry[1][2].c_str()));
	b_button_8->setToolTip(tr(b_button_8_str));
    
    const char * c_button_8_str = entry[2][1].c_str();
	c_button_8->setIcon(QIcon(entry[2][2].c_str()));
	c_button_8->setToolTip(tr(c_button_8_str));
    
    const char * d_button_8_str = entry[3][1].c_str();
	d_button_8->setIcon(QIcon(entry[3][2].c_str()));
	d_button_8->setToolTip(tr(d_button_8_str));
    
    const char * e_button_8_str = entry[4][1].c_str();
	e_button_8->setIcon(QIcon(entry[4][2].c_str()));
	e_button_8->setToolTip(tr(e_button_8_str));
    
    const char * f_button_8_str = entry[5][1].c_str();
	f_button_8->setIcon(QIcon(entry[5][2].c_str()));
	f_button_8->setToolTip(tr(f_button_8_str));
    
}



void  Series::handleButton_8_1()
{
	Connector::search_p = 4;
	Connector::search_metric = search_field_8->text();
    hide();
    Result result_8;
    result_8.exec();
    show();
}


void  Series::handleButton_8_2()
{
	hide();
	MainWindow mainwindow_8;
	mainwindow_8.exec();
	show();
}


void  Series::handleButton_8_3()
{
    Connector::signout_p = 4;
    hide();
    SignOut signout_8;
    signout_8.exec();
    show();
}

void  Series::handleButton_8_4()
{
    Connector::account_p = 4;
    hide();
    Account account_8;
    account_8.exec();
    show();
}

void Series::handle_a_button_8()
{
	Connector::entry_p = 4;
    
	if(Connector::series_type == "series"){
		Connector::e1 = Connector::series_entry[0];
	}else if(Connector::series_type == "action"){
		Connector::e1 = Connector::series_action_entry[0];
	}else if(Connector::series_type == "biography"){
		Connector::e1 = Connector::series_biography_entry[0];
	}else if(Connector::series_type == "classics"){
		Connector::e1 = Connector::series_classics_entry[0];
	}else if(Connector::series_type == "comic"){
		Connector::e1 = Connector::series_comic_entry[0];
	}else if(Connector::series_type == "comedy"){
		Connector::e1 = Connector::series_comedy_entry[0];
	}else if(Connector::series_type == "discovery"){
		Connector::e1 = Connector::series_discovery_entry[0];
	}else if(Connector::series_type == "documentary"){
		Connector::e1 = Connector::series_documentary_entry[0];
	}else if(Connector::series_type == "history"){
		Connector::e1 = Connector::series_history_entry[0];
	}else if(Connector::series_type == "kids"){
		Connector::e1 = Connector::series_kids_entry[0];
	}else if(Connector::series_type == "miniseries"){
		Connector::e1 = Connector::series_miniseries_entry[0];
	}else if(Connector::series_type == "reality"){
		Connector::e1 = Connector::series_reality_entry[0];
	}else if(Connector::series_type == "science_fiction"){
		Connector::e1 = Connector::series_science_fiction_entry[0];
	}
    
    
    hide();
    Entry entry;
    entry.exec();
    show();
}



void Series::handle_b_button_8()
{
	Connector::entry_p = 4;
    
	if(Connector::series_type == "series"){
		Connector::e1 = Connector::series_entry[1];
	}else if(Connector::series_type == "action"){
		Connector::e1 = Connector::series_action_entry[1];
	}else if(Connector::series_type == "biography"){
		Connector::e1 = Connector::series_biography_entry[1];
	}else if(Connector::series_type == "classics"){
		Connector::e1 = Connector::series_classics_entry[0];
	}else if(Connector::series_type == "comic"){
		Connector::e1 = Connector::series_comic_entry[1];
	}else if(Connector::series_type == "comedy"){
		Connector::e1 = Connector::series_comedy_entry[1];
	}else if(Connector::series_type == "discovery"){
		Connector::e1 = Connector::series_discovery_entry[1];
	}else if(Connector::series_type == "documentary"){
		Connector::e1 = Connector::series_documentary_entry[1];
	}else if(Connector::series_type == "history"){
		Connector::e1 = Connector::series_history_entry[1];
	}else if(Connector::series_type == "kids"){
		Connector::e1 = Connector::series_kids_entry[1];
	}else if(Connector::series_type == "miniseries"){
		Connector::e1 = Connector::series_miniseries_entry[1];
	}else if(Connector::series_type == "reality"){
		Connector::e1 = Connector::series_reality_entry[1];
	}else if(Connector::series_type == "science_fiction"){
		Connector::e1 = Connector::series_science_fiction_entry[1];
	}
    
    hide();
    Entry entry;
    entry.exec();
    show();
}




void Series::handle_c_button_8()
{
	Connector::entry_p = 4;
    
	if(Connector::series_type == "series"){
		Connector::e1 = Connector::series_entry[2];
	}else if(Connector::series_type == "action"){
		Connector::e1 = Connector::series_action_entry[2];
	}else if(Connector::series_type == "biography"){
		Connector::e1 = Connector::series_biography_entry[2];
	}else if(Connector::series_type == "classics"){
		Connector::e1 = Connector::series_classics_entry[0];
	}else if(Connector::series_type == "comic"){
		Connector::e1 = Connector::series_comic_entry[2];
	}else if(Connector::series_type == "comedy"){
		Connector::e1 = Connector::series_comedy_entry[2];
	}else if(Connector::series_type == "discovery"){
		Connector::e1 = Connector::series_discovery_entry[2];
	}else if(Connector::series_type == "documentary"){
		Connector::e1 = Connector::series_documentary_entry[2];
	}else if(Connector::series_type == "history"){
		Connector::e1 = Connector::series_history_entry[2];
	}else if(Connector::series_type == "kids"){
		Connector::e1 = Connector::series_kids_entry[2];
	}else if(Connector::series_type == "miniseries"){
		Connector::e1 = Connector::series_miniseries_entry[2];
	}else if(Connector::series_type == "reality"){
		Connector::e1 = Connector::series_reality_entry[2];
	}else if(Connector::series_type == "science_fiction"){
		Connector::e1 = Connector::series_science_fiction_entry[2];
	}
    
    hide();
    Entry entry;
    entry.exec();
    show();
}



void Series::handle_d_button_8()
{
	Connector::entry_p = 4;
    
	if(Connector::series_type == "series"){
		Connector::e1 = Connector::series_entry[3];
	}else if(Connector::series_type == "action"){
		Connector::e1 = Connector::series_action_entry[3];
	}else if(Connector::series_type == "biography"){
		Connector::e1 = Connector::series_biography_entry[3];
	}else if(Connector::series_type == "classics"){
		Connector::e1 = Connector::series_classics_entry[0];
	}else if(Connector::series_type == "comic"){
		Connector::e1 = Connector::series_comic_entry[3];
	}else if(Connector::series_type == "comedy"){
		Connector::e1 = Connector::series_comedy_entry[3];
	}else if(Connector::series_type == "discovery"){
		Connector::e1 = Connector::series_discovery_entry[3];
	}else if(Connector::series_type == "documentary"){
		Connector::e1 = Connector::series_documentary_entry[3];
	}else if(Connector::series_type == "history"){
		Connector::e1 = Connector::series_history_entry[3];
	}else if(Connector::series_type == "kids"){
		Connector::e1 = Connector::series_kids_entry[3];
	}else if(Connector::series_type == "miniseries"){
		Connector::e1 = Connector::series_miniseries_entry[3];
	}else if(Connector::series_type == "reality"){
		Connector::e1 = Connector::series_reality_entry[3];
	}else if(Connector::series_type == "science_fiction"){
		Connector::e1 = Connector::series_science_fiction_entry[3];
	}
    
    hide();
    Entry entry;
    entry.exec();
    show();
}




void Series::handle_e_button_8()
{
	Connector::entry_p = 4;
    
	if(Connector::series_type == "series"){
		Connector::e1 = Connector::series_entry[4];
	}else if(Connector::series_type == "action"){
		Connector::e1 = Connector::series_action_entry[4];
	}else if(Connector::series_type == "biography"){
		Connector::e1 = Connector::series_biography_entry[4];
	}else if(Connector::series_type == "classics"){
		Connector::e1 = Connector::series_classics_entry[0];
	}else if(Connector::series_type == "comic"){
		Connector::e1 = Connector::series_comic_entry[4];
	}else if(Connector::series_type == "comedy"){
		Connector::e1 = Connector::series_comedy_entry[4];
	}else if(Connector::series_type == "discovery"){
		Connector::e1 = Connector::series_discovery_entry[4];
	}else if(Connector::series_type == "documentary"){
		Connector::e1 = Connector::series_documentary_entry[4];
	}else if(Connector::series_type == "history"){
		Connector::e1 = Connector::series_history_entry[4];
	}else if(Connector::series_type == "kids"){
		Connector::e1 = Connector::series_kids_entry[4];
	}else if(Connector::series_type == "miniseries"){
		Connector::e1 = Connector::series_miniseries_entry[4];
	}else if(Connector::series_type == "reality"){
		Connector::e1 = Connector::series_reality_entry[4];
	}else if(Connector::series_type == "science_fiction"){
		Connector::e1 = Connector::series_science_fiction_entry[4];
	}
    
    hide();
    Entry entry;
    entry.exec();
    show();
}



void Series::handle_f_button_8()
{
	Connector::entry_p = 4;
    
	if(Connector::series_type == "series"){
		Connector::e1 = Connector::series_entry[5];
	}else if(Connector::series_type == "action"){
		Connector::e1 = Connector::series_action_entry[5];
	}else if(Connector::series_type == "biography"){
		Connector::e1 = Connector::series_biography_entry[5];
	}else if(Connector::series_type == "classics"){
		Connector::e1 = Connector::series_classics_entry[0];
	}else if(Connector::series_type == "comic"){
		Connector::e1 = Connector::series_comic_entry[5];
	}else if(Connector::series_type == "comedy"){
		Connector::e1 = Connector::series_comedy_entry[5];
	}else if(Connector::series_type == "discovery"){
		Connector::e1 = Connector::series_discovery_entry[5];
	}else if(Connector::series_type == "documentary"){
		Connector::e1 = Connector::series_documentary_entry[5];
	}else if(Connector::series_type == "history"){
		Connector::e1 = Connector::series_history_entry[5];
	}else if(Connector::series_type == "kids"){
		Connector::e1 = Connector::series_kids_entry[5];	
	}else if(Connector::series_type == "miniseries"){
		Connector::e1 = Connector::series_miniseries_entry[5];	
	}else if(Connector::series_type == "reality"){
		Connector::e1 = Connector::series_reality_entry[5];	
	}else if(Connector::series_type == "science_fiction"){
		Connector::e1 = Connector::series_science_fiction_entry[5];	
	}
    
    hide();
    Entry entry;
    entry.exec();
    show();
}




void  Series::loadStyleSheet_8()
{
	QFile qss("style.qss");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();
}


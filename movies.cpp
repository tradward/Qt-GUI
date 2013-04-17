
#include <QtGui>
#include <QApplication>//add it
#include "movies.h"
#include "favorite.h"
#include "result.h"
#include "connector.h"
#include "sign_out.h"
#include "account.h"
#include "mainwindow.h"
#include "common.h"
#include "entry.h"
#include <QCloseEvent>
#include <vector>

Movies::Movies()
{
    createMenu_3();
    createHorizontalGroupBox_3();
	createBottom_3();
	createImages_3();
	display_options();
	display_search();
	create_labels();
    QVBoxLayout *mainLayout_3 = new QVBoxLayout;
    mainLayout_3->setMenuBar(menuBar_3);
    mainLayout_3->addWidget(movies_logo);
	mainLayout_3->addWidget(line_logo_2_1);
	mainLayout_3->addWidget(search_area);
	mainLayout_3->addWidget(line_logo_2_2);
	//mainLayout_3->addWidget(history_label);
	mainLayout_3->addWidget(horizontalGroupBox_images_3);
	mainLayout_3->addWidget(line_logo_2_3);
    
	mainLayout_3->addWidget(classification_label);
	mainLayout_3->addWidget(options_1);
	mainLayout_3->addWidget(options_2);
	mainLayout_3->addWidget(options_3);
	mainLayout_3->addWidget(line_logo_2_4);
	mainLayout_3->addWidget(bottom_area);
    setLayout(mainLayout_3);
    setWindowTitle(tr("Welcome,user"));
	loadStyleSheet_3();
}

void Movies::closeEvent_3(QCloseEvent *event){
	Connector::signout_p = 3;
    hide();
    SignOut signout;
    signout.exec();
    //signout.setParent(this);
    show();
    event->accept();
}


void Movies:: create_labels(){
	history_label = new QLabel();
	history_label->setText("<img src=\"history.png\">");
    
	classification_label = new QLabel();
	classification_label->setText("<img src=\"classification.png\">");
}

void  Movies::createMenu_3()
{
    menuBar_3 = new QMenuBar;
    
    fileMenu_3 = new QMenu(tr("&File"), this);
    exitAction_3 = fileMenu_3->addAction(tr("E&xit"));
    menuBar_3->addMenu(fileMenu_3);
    
    connect(exitAction_3, SIGNAL(triggered()), this, SLOT(accept()));
}

void  Movies::createHorizontalGroupBox_3()
{
	movies_logo = new QLabel();
	movies_logo->setText("<img src=\"movies_logo.png\">");
	movies_logo->setAlignment(Qt::AlignHCenter);
    
	line_logo_2_1 = new QLabel();
	line_logo_2_1->setText("<img src=\"17.png\">");
    
	line_logo_2_2 = new QLabel();
	line_logo_2_2->setText("<img src=\"17.png\">");
    
	line_logo_2_3 = new QLabel();
	line_logo_2_3->setText("<img src=\"17.png\">");
    
	line_logo_2_4 = new QLabel();
	line_logo_2_4->setText("<img src=\"17.png\">");
}



void Movies::createBottom_3()
{
	bottom_area = new QGroupBox();
	QHBoxLayout *bottom_area_layout = new QHBoxLayout;
    
	//logo_3_2
	logo_3_2 = new QLabel();
	logo_3_2 ->setText("<img src=\"logo2.png\">");
	
	//copyright
	copy_right = new QLabel();
	copy_right->setText(Connector::copyright);
    
	sign_out_3 = new QPushButton(tr("<Sign Out>"));
	manage_account_3 = new QPushButton(tr("<Manage Account>"));
	sign_out_3->setFlat(true);
	manage_account_3->setFlat(true);
	QObject::connect(sign_out_3, SIGNAL(clicked()),this, SLOT(handleButton_3_3()));
	QObject::connect(manage_account_3, SIGNAL(clicked()),this, SLOT(handleButton_3_4()));
    
	bottom_area_layout->addWidget(logo_3_2);
	bottom_area_layout->addWidget(copy_right);
	bottom_area_layout->addWidget(sign_out_3);
	bottom_area_layout->addWidget(manage_account_3);
	bottom_area->setLayout(bottom_area_layout);
}

void Movies::display_search(){
	search_area = new QGroupBox();
	QHBoxLayout *search_area_layout = new QHBoxLayout;
	search_label_3 = new QLabel();
	search_label_3->setText("Please enter movies'name or director:");
	//editfile
	search_field_3 = new QLineEdit(tr("Search here:"));
	QObject::connect(search_field_3, SIGNAL(returnPressed()),this, SLOT(handleButton_3_1()));
	back_home = new QPushButton(tr("<<Back to Home"));
	back_home->setFlat(true);
	QObject::connect(back_home, SIGNAL(clicked()),this, SLOT(handleButton_3_2()));
	search_area_layout->addWidget(search_label_3);
	search_area_layout->addWidget(search_field_3);
	search_area_layout->addWidget(back_home);
	search_area->setLayout(search_area_layout);
}

void Movies::display_options(){
    
    
	//1st line
	options_1 = new QGroupBox();
	QHBoxLayout *options_layout_1 = new QHBoxLayout;
    
	action =    	new QPushButton(tr("   =Action=         "));
	action->setFlat(true);
	animation = 	new QPushButton(tr("   =Animation=      "));
	animation->setFlat(true);
	comedy =     	new QPushButton(tr("   =Comedy=         "));
	comedy->setFlat(true);
	documentary = 	new QPushButton(tr("   =Documentary=    "));
	documentary->setFlat(true);
	drama = 	new QPushButton(tr("   =Drama=          "));
	drama->setFlat(true);
    
	options_layout_1->addWidget(action);
	options_layout_1->addWidget(animation);
	options_layout_1->addWidget(comedy);
	options_layout_1->addWidget(documentary);
	options_layout_1->addWidget(drama);
    options_1->setLayout(options_layout_1);
	//2nd line
	options_2 = new QGroupBox();
	QHBoxLayout *options_layout_2 = new QHBoxLayout;
	family_kids = 	new QPushButton(tr("   =Family/Kids=    "));
	family_kids->setFlat(true);
	foreign = 	new QPushButton(tr("   =Foreigns=       "));
	foreign->setFlat(true);
	horror =    	new QPushButton(tr("   =Horror=         "));
	horror->setFlat(true);
	music_art = 	new QPushButton(tr("   =Music/Art=      "));
	music_art->setFlat(true);
	mystery_suspense=new QPushButton(tr("   =Mystery=        "));
	mystery_suspense->setFlat(true);
    
	options_layout_2->addWidget(family_kids);
	options_layout_2->addWidget(foreign);
	options_layout_2->addWidget(horror);
	options_layout_2->addWidget(music_art);
	options_layout_2->addWidget(mystery_suspense);
	options_2->setLayout(options_layout_2);
	//3rd line
	options_3 = new QGroupBox();
	QHBoxLayout *options_layout_3 = new QHBoxLayout;
	romance = 	new QPushButton(tr("   =Romance=        "));
	romance->setFlat(true);
	science_fiction=new QPushButton(tr("   =Science Fiction="));
	science_fiction->setFlat(true);
	sports =    	new QPushButton(tr("   =Sports=         "));
	sports->setFlat(true);
	war = 	        new QPushButton(tr("   =War=            "));
	war->setFlat(true);
	western= 	new QPushButton(tr("   =Western=        "));
 	western->setFlat(true);
	
	QObject::connect(action, SIGNAL(clicked()),this, SLOT(handle_action_button_3()));
	QObject::connect(animation, SIGNAL(clicked()),this, SLOT(handle_animation_button_3()));
	QObject::connect(comedy, SIGNAL(clicked()),this, SLOT(handle_comedy_button_3()));
	QObject::connect(documentary, SIGNAL(clicked()),this, SLOT(handle_documentary_button_3()));
	QObject::connect(drama, SIGNAL(clicked()),this, SLOT(handle_drama_button_3()));
    
	QObject::connect(family_kids, SIGNAL(clicked()),this, SLOT(handle_family_kids_button_3()));
	QObject::connect(foreign, SIGNAL(clicked()),this, SLOT(handle_foreign_button_3()));
	QObject::connect(horror, SIGNAL(clicked()),this, SLOT(handle_horror_button_3()));
	QObject::connect(music_art, SIGNAL(clicked()),this, SLOT(handle_music_art_button_3()));
	QObject::connect(mystery_suspense, SIGNAL(clicked()),this, SLOT(handle_mystery_suspense_button_3()));
    
	QObject::connect(romance, SIGNAL(clicked()),this, SLOT(handle_romance_button_3()));
	QObject::connect(science_fiction, SIGNAL(clicked()),this, SLOT(handle_science_fiction_button_3()));
	QObject::connect(sports, SIGNAL(clicked()),this, SLOT(handle_sports_button_3()));
	QObject::connect(war, SIGNAL(clicked()),this, SLOT(handle_war_button_3()));
	QObject::connect(western, SIGNAL(clicked()),this, SLOT(handle_western_button_3()));
    
    
	options_layout_3->addWidget(romance);
	options_layout_3->addWidget(science_fiction);
	options_layout_3->addWidget(sports);
	options_layout_3->addWidget(war);
	options_layout_3->addWidget(western);
    options_3->setLayout(options_layout_3);
}


void Movies::createImages_3(){
	Connector::movies_type = "movies";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*movies";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
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
        Connector::movies_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    
    
    const char * a_button_3_str = entry[0][1].c_str();
    //QString a_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[0][1].c_str()));
	a_button_3 = new QPushButton();
	a_button_3->setIcon(QIcon(entry[0][2].c_str()));
	a_button_3->setIconSize(QSize(120,200));
	a_button_3->setToolTip(tr(a_button_3_str));
    
    const char * b_button_3_str = entry[1][1].c_str();
    //QString b_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[1][1].c_str()));
	b_button_3 = new QPushButton();
	b_button_3->setIcon(QIcon(entry[1][2].c_str()));
	b_button_3->setIconSize(QSize(120,200));
	b_button_3->setToolTip(tr(b_button_3_str));
    
    const char * c_button_3_str = entry[2][1].c_str();
    //QString c_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[2][1].c_str()));
	c_button_3 = new QPushButton();
	c_button_3->setIcon(QIcon(entry[2][2].c_str()));
	c_button_3->setIconSize(QSize(120,200));;
	c_button_3->setToolTip(tr(c_button_3_str));
    
    const char * d_button_3_str = entry[3][1].c_str();
    //QString d_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[3][1].c_str()));
	d_button_3 = new QPushButton();
	d_button_3->setIcon(QIcon(entry[3][2].c_str()));
	d_button_3->setIconSize(QSize(120,200));
	d_button_3->setToolTip(tr(d_button_3_str));
    
    const char * e_button_3_str = entry[4][1].c_str();
    //QString e_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[4][1].c_str()));
	e_button_3 = new QPushButton();
	e_button_3->setIcon(QIcon(entry[4][2].c_str()));
	e_button_3->setIconSize(QSize(120,200));
	e_button_3->setToolTip(tr(e_button_3_str));
    
    const char * f_button_3_str = entry[5][1].c_str();
    //QString f_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[5][1].c_str()));
	f_button_3 = new QPushButton();
	f_button_3->setIcon(QIcon(entry[5][2].c_str()));
	f_button_3->setIconSize(QSize(120,200));
	f_button_3->setToolTip(tr(f_button_3_str));
    
    
    
	QObject::connect(a_button_3, SIGNAL(clicked()),this, SLOT(handle_a_button_3()));
	QObject::connect(b_button_3, SIGNAL(clicked()),this, SLOT(handle_b_button_3()));
	QObject::connect(c_button_3, SIGNAL(clicked()),this, SLOT(handle_c_button_3()));
	QObject::connect(d_button_3, SIGNAL(clicked()),this, SLOT(handle_d_button_3()));
	QObject::connect(e_button_3, SIGNAL(clicked()),this, SLOT(handle_e_button_3()));
	QObject::connect(f_button_3, SIGNAL(clicked()),this, SLOT(handle_f_button_3()));
    
    
	a_button_3->setFlat(true);
	b_button_3->setFlat(true);
	c_button_3->setFlat(true);
	d_button_3->setFlat(true);
	e_button_3->setFlat(true);
	f_button_3->setFlat(true);
    
    horizontalGroupBox_images_3 = new QGroupBox();
    QHBoxLayout *layout_images_3 = new QHBoxLayout;
	layout_images_3->addWidget(a_button_3);
	layout_images_3->addWidget(b_button_3);
	layout_images_3->addWidget(c_button_3);
	layout_images_3->addWidget(d_button_3);
	layout_images_3->addWidget(e_button_3);
	layout_images_3->addWidget(f_button_3);
    horizontalGroupBox_images_3->setLayout(layout_images_3);
	horizontalGroupBox_images_3->setFixedHeight(220);
}


void Movies::handle_action_button_3(){
	Connector::movies_type = "action";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*movies*_*Action";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
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
        Connector::movies_action_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_3_str = entry[0][1].c_str();
	a_button_3->setIcon(QIcon(entry[0][2].c_str()));
	a_button_3->setToolTip(tr(a_button_3_str));
    
    const char * b_button_3_str = entry[1][1].c_str();
	b_button_3->setIcon(QIcon(entry[1][2].c_str()));
	b_button_3->setToolTip(tr(b_button_3_str));
    
    const char * c_button_3_str = entry[2][1].c_str();
	c_button_3->setIcon(QIcon(entry[2][2].c_str()));
	c_button_3->setToolTip(tr(c_button_3_str));
    
    const char * d_button_3_str = entry[3][1].c_str();
	d_button_3->setIcon(QIcon(entry[3][2].c_str()));
	d_button_3->setToolTip(tr(d_button_3_str));
    
    
    const char * e_button_3_str = entry[4][1].c_str();
	e_button_3->setIcon(QIcon(entry[4][2].c_str()));
	e_button_3->setToolTip(tr(e_button_3_str));
    
    const char * f_button_3_str = entry[5][1].c_str();
	f_button_3->setIcon(QIcon(entry[5][2].c_str()));
	f_button_3->setToolTip(tr(f_button_3_str));
}

void Movies::handle_animation_button_3(){
	Connector::movies_type = "animation";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*movies*_*Animation";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char*)url.c_str());
    client::Clie_SendCommand(clientfd, (char *)inputCommand.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<6;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::movies_animation_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_3_str = entry[0][1].c_str();
	a_button_3->setIcon(QIcon(entry[0][2].c_str()));
	a_button_3->setToolTip(tr(a_button_3_str));
    
    const char * b_button_3_str = entry[1][1].c_str();
	b_button_3->setIcon(QIcon(entry[1][2].c_str()));
	b_button_3->setToolTip(tr(b_button_3_str));
    
    const char * c_button_3_str = entry[2][1].c_str();
	c_button_3->setIcon(QIcon(entry[2][2].c_str()));
	c_button_3->setToolTip(tr(c_button_3_str));
    
    const char * d_button_3_str = entry[3][1].c_str();
	d_button_3->setIcon(QIcon(entry[3][2].c_str()));
	d_button_3->setToolTip(tr(d_button_3_str));
    
    
    const char * e_button_3_str = entry[4][1].c_str();
	e_button_3->setIcon(QIcon(entry[4][2].c_str()));
	e_button_3->setToolTip(tr(e_button_3_str));
    
    const char * f_button_3_str = entry[5][1].c_str();
	f_button_3->setIcon(QIcon(entry[5][2].c_str()));
	f_button_3->setToolTip(tr(f_button_3_str));
    
}


void Movies::handle_comedy_button_3(){
	Connector::movies_type = "comedy";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*movies*_*comedy";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
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
        Connector::movies_comedy_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_3_str = entry[0][1].c_str();
	a_button_3->setIcon(QIcon(entry[0][2].c_str()));
	a_button_3->setToolTip(tr(a_button_3_str));
    
    const char * b_button_3_str = entry[1][1].c_str();
	b_button_3->setIcon(QIcon(entry[1][2].c_str()));
	b_button_3->setToolTip(tr(b_button_3_str));
    
    const char * c_button_3_str = entry[2][1].c_str();
	c_button_3->setIcon(QIcon(entry[2][2].c_str()));
	c_button_3->setToolTip(tr(c_button_3_str));
    
    const char * d_button_3_str = entry[3][1].c_str();
	d_button_3->setIcon(QIcon(entry[3][2].c_str()));
	d_button_3->setToolTip(tr(d_button_3_str));
    
    
    const char * e_button_3_str = entry[4][1].c_str();
	e_button_3->setIcon(QIcon(entry[4][2].c_str()));
	e_button_3->setToolTip(tr(e_button_3_str));
    
    const char * f_button_3_str = entry[5][1].c_str();
	f_button_3->setIcon(QIcon(entry[5][2].c_str()));
	f_button_3->setToolTip(tr(f_button_3_str));
}


void Movies::handle_documentary_button_3(){
    
	Connector::movies_type = "documentary";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*movies*_*documentary";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
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
        Connector::movies_documentary_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_3_str = entry[0][1].c_str();
	a_button_3->setIcon(QIcon(entry[0][2].c_str()));
	a_button_3->setToolTip(tr(a_button_3_str));
    
    const char * b_button_3_str = entry[1][1].c_str();
	b_button_3->setIcon(QIcon(entry[1][2].c_str()));
	b_button_3->setToolTip(tr(b_button_3_str));
    
    const char * c_button_3_str = entry[2][1].c_str();
	c_button_3->setIcon(QIcon(entry[2][2].c_str()));
	c_button_3->setToolTip(tr(c_button_3_str));
    
    const char * d_button_3_str = entry[3][1].c_str();
	d_button_3->setIcon(QIcon(entry[3][2].c_str()));
	d_button_3->setToolTip(tr(d_button_3_str));
    
    
    const char * e_button_3_str = entry[4][1].c_str();
	e_button_3->setIcon(QIcon(entry[4][2].c_str()));
	e_button_3->setToolTip(tr(e_button_3_str));
    
    const char * f_button_3_str = entry[5][1].c_str();
	f_button_3->setIcon(QIcon(entry[5][2].c_str()));
	f_button_3->setToolTip(tr(f_button_3_str));
    
    
}
void Movies::handle_drama_button_3(){
	Connector::movies_type = "drama";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*movies*_*Drama";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
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
        Connector::movies_drama_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_3_str = entry[0][1].c_str();
	a_button_3->setIcon(QIcon(entry[0][2].c_str()));
	a_button_3->setToolTip(tr(a_button_3_str));
    
    const char * b_button_3_str = entry[1][1].c_str();
	b_button_3->setIcon(QIcon(entry[1][2].c_str()));
	b_button_3->setToolTip(tr(b_button_3_str));
    
    const char * c_button_3_str = entry[2][1].c_str();
	c_button_3->setIcon(QIcon(entry[2][2].c_str()));
	c_button_3->setToolTip(tr(c_button_3_str));
    
    const char * d_button_3_str = entry[3][1].c_str();
	d_button_3->setIcon(QIcon(entry[3][2].c_str()));
	d_button_3->setToolTip(tr(d_button_3_str));
    
    
    const char * e_button_3_str = entry[4][1].c_str();
	e_button_3->setIcon(QIcon(entry[4][2].c_str()));
	e_button_3->setToolTip(tr(e_button_3_str));
    
    const char * f_button_3_str = entry[5][1].c_str();
	f_button_3->setIcon(QIcon(entry[5][2].c_str()));
	f_button_3->setToolTip(tr(f_button_3_str));
}

void Movies::handle_family_kids_button_3(){
	Connector::movies_type = "family";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*movies*_*Family&kids";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
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
        Connector::movies_family_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_3_str = entry[0][1].c_str();
	a_button_3->setIcon(QIcon(entry[0][2].c_str()));
	a_button_3->setToolTip(tr(a_button_3_str));
    
    const char * b_button_3_str = entry[1][1].c_str();
	b_button_3->setIcon(QIcon(entry[1][2].c_str()));
	b_button_3->setToolTip(tr(b_button_3_str));
    
    const char * c_button_3_str = entry[2][1].c_str();
	c_button_3->setIcon(QIcon(entry[2][2].c_str()));
	c_button_3->setToolTip(tr(c_button_3_str));
    
    const char * d_button_3_str = entry[3][1].c_str();
	d_button_3->setIcon(QIcon(entry[3][2].c_str()));
	d_button_3->setToolTip(tr(d_button_3_str));
    
    
    const char * e_button_3_str = entry[4][1].c_str();
	e_button_3->setIcon(QIcon(entry[4][2].c_str()));
	e_button_3->setToolTip(tr(e_button_3_str));
    
    const char * f_button_3_str = entry[5][1].c_str();
	f_button_3->setIcon(QIcon(entry[5][2].c_str()));
	f_button_3->setToolTip(tr(f_button_3_str));
}

void Movies::handle_foreign_button_3(){
	Connector::movies_type = "foreign";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*movies*_*Foreign";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
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
        Connector::movies_foreign_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_3_str = entry[0][1].c_str();
	a_button_3->setIcon(QIcon(entry[0][2].c_str()));
	a_button_3->setToolTip(tr(a_button_3_str));
    
    const char * b_button_3_str = entry[1][1].c_str();
	b_button_3->setIcon(QIcon(entry[1][2].c_str()));
	b_button_3->setToolTip(tr(b_button_3_str));
    
    const char * c_button_3_str = entry[2][1].c_str();
	c_button_3->setIcon(QIcon(entry[2][2].c_str()));
	c_button_3->setToolTip(tr(c_button_3_str));
    
    const char * d_button_3_str = entry[3][1].c_str();
	d_button_3->setIcon(QIcon(entry[3][2].c_str()));
	d_button_3->setToolTip(tr(d_button_3_str));
    
    
    const char * e_button_3_str = entry[4][1].c_str();
	e_button_3->setIcon(QIcon(entry[4][2].c_str()));
	e_button_3->setToolTip(tr(e_button_3_str));
    
    const char * f_button_3_str = entry[5][1].c_str();
	f_button_3->setIcon(QIcon(entry[5][2].c_str()));
	f_button_3->setToolTip(tr(f_button_3_str));
}

void Movies::handle_horror_button_3(){
	Connector::movies_type = "horror";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*movies*_*Horror";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
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
        Connector::movies_horror_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_3_str = entry[0][1].c_str();
	a_button_3->setIcon(QIcon(entry[0][2].c_str()));
	a_button_3->setToolTip(tr(a_button_3_str));
    
    const char * b_button_3_str = entry[1][1].c_str();
	b_button_3->setIcon(QIcon(entry[1][2].c_str()));
	b_button_3->setToolTip(tr(b_button_3_str));
    
    const char * c_button_3_str = entry[2][1].c_str();
	c_button_3->setIcon(QIcon(entry[2][2].c_str()));
	c_button_3->setToolTip(tr(c_button_3_str));
    
    const char * d_button_3_str = entry[3][1].c_str();
	d_button_3->setIcon(QIcon(entry[3][2].c_str()));
	d_button_3->setToolTip(tr(d_button_3_str));
    
    
    const char * e_button_3_str = entry[4][1].c_str();
	e_button_3->setIcon(QIcon(entry[4][2].c_str()));
	e_button_3->setToolTip(tr(e_button_3_str));
    
    const char * f_button_3_str = entry[5][1].c_str();
	f_button_3->setIcon(QIcon(entry[5][2].c_str()));
	f_button_3->setToolTip(tr(f_button_3_str));
    
}

void Movies::handle_music_art_button_3(){
	Connector::movies_type = "art";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*movies*_*MusicPerformance";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
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
        Connector::movies_music_art_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_3_str = entry[0][1].c_str();
	a_button_3->setIcon(QIcon(entry[0][2].c_str()));
	a_button_3->setToolTip(tr(a_button_3_str));
    
    const char * b_button_3_str = entry[1][1].c_str();
	b_button_3->setIcon(QIcon(entry[1][2].c_str()));
	b_button_3->setToolTip(tr(b_button_3_str));
    
    const char * c_button_3_str = entry[2][1].c_str();
	c_button_3->setIcon(QIcon(entry[2][2].c_str()));
	c_button_3->setToolTip(tr(c_button_3_str));
    
    const char * d_button_3_str = entry[3][1].c_str();
	d_button_3->setIcon(QIcon(entry[3][2].c_str()));
	d_button_3->setToolTip(tr(d_button_3_str));
    
    
    const char * e_button_3_str = entry[4][1].c_str();
	e_button_3->setIcon(QIcon(entry[4][2].c_str()));
	e_button_3->setToolTip(tr(e_button_3_str));
    
    const char * f_button_3_str = entry[5][1].c_str();
	f_button_3->setIcon(QIcon(entry[5][2].c_str()));
	f_button_3->setToolTip(tr(f_button_3_str));
}

void Movies::handle_mystery_suspense_button_3(){
    
	Connector::movies_type = "mystery_suspense";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*movies*_*Mystery&Suspense";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
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
        Connector::movies_mystery_suspense_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_3_str = entry[0][1].c_str();
	a_button_3->setIcon(QIcon(entry[0][2].c_str()));
	a_button_3->setToolTip(tr(a_button_3_str));
    
    const char * b_button_3_str = entry[1][1].c_str();
	b_button_3->setIcon(QIcon(entry[1][2].c_str()));
	b_button_3->setToolTip(tr(b_button_3_str));
    
    const char * c_button_3_str = entry[2][1].c_str();
	c_button_3->setIcon(QIcon(entry[2][2].c_str()));
	c_button_3->setToolTip(tr(c_button_3_str));
    
    const char * d_button_3_str = entry[3][1].c_str();
	d_button_3->setIcon(QIcon(entry[3][2].c_str()));
	d_button_3->setToolTip(tr(d_button_3_str));
    
    
    const char * e_button_3_str = entry[4][1].c_str();
	e_button_3->setIcon(QIcon(entry[4][2].c_str()));
	e_button_3->setToolTip(tr(e_button_3_str));
    
    const char * f_button_3_str = entry[5][1].c_str();
	f_button_3->setIcon(QIcon(entry[5][2].c_str()));
	f_button_3->setToolTip(tr(f_button_3_str));
    
}
void Movies::handle_romance_button_3(){
    
	Connector::movies_type = "romance";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*movies*_*Romance";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
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
        Connector::movies_romance_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_3_str = entry[0][1].c_str();
	a_button_3->setIcon(QIcon(entry[0][2].c_str()));
	a_button_3->setToolTip(tr(a_button_3_str));
    
    const char * b_button_3_str = entry[1][1].c_str();
	b_button_3->setIcon(QIcon(entry[1][2].c_str()));
	b_button_3->setToolTip(tr(b_button_3_str));
    
    const char * c_button_3_str = entry[2][1].c_str();
	c_button_3->setIcon(QIcon(entry[2][2].c_str()));
	c_button_3->setToolTip(tr(c_button_3_str));
    
    const char * d_button_3_str = entry[3][1].c_str();
	d_button_3->setIcon(QIcon(entry[3][2].c_str()));
	d_button_3->setToolTip(tr(d_button_3_str));
    
    
    const char * e_button_3_str = entry[4][1].c_str();
	e_button_3->setIcon(QIcon(entry[4][2].c_str()));
	e_button_3->setToolTip(tr(e_button_3_str));
    
    const char * f_button_3_str = entry[5][1].c_str();
	f_button_3->setIcon(QIcon(entry[5][2].c_str()));
	f_button_3->setToolTip(tr(f_button_3_str));
}

void Movies::handle_science_fiction_button_3(){
    
	Connector::movies_type = "science_fiction";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*movies*_*Sci&Fi";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
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
        Connector::movies_science_fiction_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_3_str = entry[0][1].c_str();
	a_button_3->setIcon(QIcon(entry[0][2].c_str()));
	a_button_3->setToolTip(tr(a_button_3_str));
    
    const char * b_button_3_str = entry[1][1].c_str();
	b_button_3->setIcon(QIcon(entry[1][2].c_str()));
	b_button_3->setToolTip(tr(b_button_3_str));
    
    const char * c_button_3_str = entry[2][1].c_str();
	c_button_3->setIcon(QIcon(entry[2][2].c_str()));
	c_button_3->setToolTip(tr(c_button_3_str));
    
    const char * d_button_3_str = entry[3][1].c_str();
	d_button_3->setIcon(QIcon(entry[3][2].c_str()));
	d_button_3->setToolTip(tr(d_button_3_str));
    
    
    const char * e_button_3_str = entry[4][1].c_str();
	e_button_3->setIcon(QIcon(entry[4][2].c_str()));
	e_button_3->setToolTip(tr(e_button_3_str));
    
    const char * f_button_3_str = entry[5][1].c_str();
	f_button_3->setIcon(QIcon(entry[5][2].c_str()));
	f_button_3->setToolTip(tr(f_button_3_str));
    
}

void Movies::handle_sports_button_3(){
    
	Connector::movies_type = "sports";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*movies*_*Sports";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
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
        Connector::movies_sports_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_3_str = entry[0][1].c_str();
	a_button_3->setIcon(QIcon(entry[0][2].c_str()));
	a_button_3->setToolTip(tr(a_button_3_str));
    
    const char * b_button_3_str = entry[1][1].c_str();
	b_button_3->setIcon(QIcon(entry[1][2].c_str()));
	b_button_3->setToolTip(tr(b_button_3_str));
    
    const char * c_button_3_str = entry[2][1].c_str();
	c_button_3->setIcon(QIcon(entry[2][2].c_str()));
	c_button_3->setToolTip(tr(c_button_3_str));
    
    const char * d_button_3_str = entry[3][1].c_str();
	d_button_3->setIcon(QIcon(entry[3][2].c_str()));
	d_button_3->setToolTip(tr(d_button_3_str));
    
    
    const char * e_button_3_str = entry[4][1].c_str();
	e_button_3->setIcon(QIcon(entry[4][2].c_str()));
	e_button_3->setToolTip(tr(e_button_3_str));
    
    const char * f_button_3_str = entry[5][1].c_str();
	f_button_3->setIcon(QIcon(entry[5][2].c_str()));
	f_button_3->setToolTip(tr(f_button_3_str));
}

void Movies::handle_war_button_3(){
    
	Connector::movies_type = "war";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*movies*_*War";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
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
        Connector::movies_war_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_3_str = entry[0][1].c_str();
	a_button_3->setIcon(QIcon(entry[0][2].c_str()));
	a_button_3->setToolTip(tr(a_button_3_str));
    
    const char * b_button_3_str = entry[1][1].c_str();
	b_button_3->setIcon(QIcon(entry[1][2].c_str()));
	b_button_3->setToolTip(tr(b_button_3_str));
    
    const char * c_button_3_str = entry[2][1].c_str();
	c_button_3->setIcon(QIcon(entry[2][2].c_str()));
	c_button_3->setToolTip(tr(c_button_3_str));
    
    const char * d_button_3_str = entry[3][1].c_str();
	d_button_3->setIcon(QIcon(entry[3][2].c_str()));
	d_button_3->setToolTip(tr(d_button_3_str));
    
    
    const char * e_button_3_str = entry[4][1].c_str();
	e_button_3->setIcon(QIcon(entry[4][2].c_str()));
	e_button_3->setToolTip(tr(e_button_3_str));
    
    const char * f_button_3_str = entry[5][1].c_str();
	f_button_3->setIcon(QIcon(entry[5][2].c_str()));
	f_button_3->setToolTip(tr(f_button_3_str));
    
}

void Movies::handle_western_button_3(){
    
	Connector::movies_type = "western";
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*movies*_*Western";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
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
        Connector::movies_western_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 6);
    
    
    const char * a_button_3_str = entry[0][1].c_str();
	a_button_3->setIcon(QIcon(entry[0][2].c_str()));
	a_button_3->setToolTip(tr(a_button_3_str));
    
    const char * b_button_3_str = entry[1][1].c_str();
	b_button_3->setIcon(QIcon(entry[1][2].c_str()));
	b_button_3->setToolTip(tr(b_button_3_str));
    
    const char * c_button_3_str = entry[2][1].c_str();
	c_button_3->setIcon(QIcon(entry[2][2].c_str()));
	c_button_3->setToolTip(tr(c_button_3_str));
    
    const char * d_button_3_str = entry[3][1].c_str();
	d_button_3->setIcon(QIcon(entry[3][2].c_str()));
	d_button_3->setToolTip(tr(d_button_3_str));
    
    
    const char * e_button_3_str = entry[4][1].c_str();
	e_button_3->setIcon(QIcon(entry[4][2].c_str()));
	e_button_3->setToolTip(tr(e_button_3_str));
    
    const char * f_button_3_str = entry[5][1].c_str();
	f_button_3->setIcon(QIcon(entry[5][2].c_str()));
	f_button_3->setToolTip(tr(f_button_3_str));
    
}


void  Movies::handleButton_3_1()
{
    Connector::search_p = 3;
    Connector::search_metric = search_field_3->text();
    hide();
    Result result_3;
    result_3.exec();
    show();
}


void  Movies::handleButton_3_2()
{
	hide();
	MainWindow mainwindow_3;
	mainwindow_3.exec();
	show();
}


void  Movies::handleButton_3_3()
{
	Connector::signout_p = 3;
    hide();
    SignOut signout_3;
    signout_3.exec();
    show();
}

void  Movies::handleButton_3_4()
{
	Connector::account_p = 3;
    hide();
    Account account_3;
    account_3.exec();
    show();
}

void Movies::handle_a_button_3()
{
	Connector::entry_p = 3;
    
	if(Connector::movies_type == "movies"){
		Connector::e1 = Connector::movies_entry[0];
	}else if(Connector::movies_type == "action"){
		Connector::e1 = Connector::movies_action_entry[0];
	}else if(Connector::movies_type == "animation"){
		Connector::e1 = Connector::movies_animation_entry[0];
	}else if(Connector::movies_type == "comedy"){
		Connector::e1 = Connector::movies_comedy_entry[0];
	}else if(Connector::movies_type == "documentary"){
		Connector::e1 = Connector::movies_documentary_entry[0];
	}else if(Connector::movies_type == "drama"){
		Connector::e1 = Connector::movies_drama_entry[0];
	}else if(Connector::movies_type == "family_kids"){
		Connector::e1 = Connector::movies_family_entry[0];
	}else if(Connector::movies_type == "foreign"){
		Connector::e1 = Connector::movies_foreign_entry[0];
	}else if(Connector::movies_type == "horror"){
		Connector::e1 = Connector::movies_horror_entry[0];
	}else if(Connector::movies_type == "music_art"){
		Connector::e1 = Connector::movies_music_art_entry[0];
	}else if(Connector::movies_type == "mystery_suspense"){
		Connector::e1 = Connector::movies_mystery_suspense_entry[0];
	}else if(Connector::movies_type == "romance"){
		Connector::e1 = Connector::movies_romance_entry[0];
	}else if(Connector::movies_type == "science_fiction"){
		Connector::e1 = Connector::movies_science_fiction_entry[0];
	}else if(Connector::movies_type == "sports"){
		Connector::e1 = Connector::movies_sports_entry[0];
	}else if(Connector::movies_type == "war"){
		Connector::e1 = Connector::movies_war_entry[0];
	}else if(Connector::movies_type == "western"){
		Connector::e1 = Connector::movies_western_entry[0];
	}
    
    hide();
    Entry entry;
    entry.exec();
    show();
}



void Movies::handle_b_button_3()
{
	Connector::entry_p = 3;
    
	if(Connector::movies_type == "movies"){
		Connector::e1 = Connector::movies_entry[1];
	}else if(Connector::movies_type == "action"){
		Connector::e1 = Connector::movies_action_entry[1];
	}else if(Connector::movies_type == "animation"){
		Connector::e1 = Connector::movies_animation_entry[1];
	}else if(Connector::movies_type == "comedy"){
		Connector::e1 = Connector::movies_comedy_entry[1];
	}else if(Connector::movies_type == "documentary"){
		Connector::e1 = Connector::movies_documentary_entry[1];
	}else if(Connector::movies_type == "drama"){
		Connector::e1 = Connector::movies_drama_entry[1];
	}else if(Connector::movies_type == "family_kids"){
		Connector::e1 = Connector::movies_family_entry[1];
	}else if(Connector::movies_type == "foreign"){
		Connector::e1 = Connector::movies_foreign_entry[1];
	}else if(Connector::movies_type == "horror"){
		Connector::e1 = Connector::movies_horror_entry[1];
	}else if(Connector::movies_type == "music_art"){
		Connector::e1 = Connector::movies_music_art_entry[1];
	}else if(Connector::movies_type == "mystery_suspense"){
		Connector::e1 = Connector::movies_mystery_suspense_entry[1];
	}else if(Connector::movies_type == "romance"){
		Connector::e1 = Connector::movies_romance_entry[1];
	}else if(Connector::movies_type == "science_fiction"){
		Connector::e1 = Connector::movies_science_fiction_entry[1];
	}else if(Connector::movies_type == "sports"){
		Connector::e1 = Connector::movies_sports_entry[1];
	}else if(Connector::movies_type == "war"){
		Connector::e1 = Connector::movies_war_entry[1];
	}else if(Connector::movies_type == "western"){
		Connector::e1 = Connector::movies_western_entry[1];
	}
    
    hide();
    Entry entry;
    entry.exec();
    show();
}




void Movies::handle_c_button_3()
{
	Connector::entry_p = 3;
    
	if(Connector::movies_type == "movies"){
		Connector::e1 = Connector::movies_entry[2];
	}else if(Connector::movies_type == "action"){
		Connector::e1 = Connector::movies_action_entry[2];
	}else if(Connector::movies_type == "animation"){
		Connector::e1 = Connector::movies_animation_entry[2];
	}else if(Connector::movies_type == "comedy"){
		Connector::e1 = Connector::movies_comedy_entry[2];
	}else if(Connector::movies_type == "documentary"){
		Connector::e1 = Connector::movies_documentary_entry[2];
	}else if(Connector::movies_type == "drama"){
		Connector::e1 = Connector::movies_drama_entry[2];
	}else if(Connector::movies_type == "family_kids"){
		Connector::e1 = Connector::movies_family_entry[2];
	}else if(Connector::movies_type == "foreign"){
		Connector::e1 = Connector::movies_foreign_entry[2];
	}else if(Connector::movies_type == "horror"){
		Connector::e1 = Connector::movies_horror_entry[2];
	}else if(Connector::movies_type == "music_art"){
		Connector::e1 = Connector::movies_music_art_entry[2];
	}else if(Connector::movies_type == "mystery_suspense"){
		Connector::e1 = Connector::movies_mystery_suspense_entry[2];
	}else if(Connector::movies_type == "romance"){
		Connector::e1 = Connector::movies_romance_entry[2];
	}else if(Connector::movies_type == "science_fiction"){
		Connector::e1 = Connector::movies_science_fiction_entry[2];
	}else if(Connector::movies_type == "sports"){
		Connector::e1 = Connector::movies_sports_entry[2];
	}else if(Connector::movies_type == "war"){
		Connector::e1 = Connector::movies_war_entry[2];
	}else if(Connector::movies_type == "western"){
		Connector::e1 = Connector::movies_western_entry[2];
	}
    
    hide();
    Entry entry;
    entry.exec();
    show();
}



void Movies::handle_d_button_3()
{
	Connector::entry_p = 3;
    
	if(Connector::movies_type == "movies"){
		Connector::e1 = Connector::movies_entry[3];
	}else if(Connector::movies_type == "action"){
		Connector::e1 = Connector::movies_action_entry[3];
	}else if(Connector::movies_type == "animation"){
		Connector::e1 = Connector::movies_animation_entry[3];
	}else if(Connector::movies_type == "comedy"){
		Connector::e1 = Connector::movies_comedy_entry[3];
	}else if(Connector::movies_type == "documentary"){
		Connector::e1 = Connector::movies_documentary_entry[3];
	}else if(Connector::movies_type == "drama"){
		Connector::e1 = Connector::movies_drama_entry[3];
	}else if(Connector::movies_type == "family_kids"){
		Connector::e1 = Connector::movies_family_entry[3];
	}else if(Connector::movies_type == "foreign"){
		Connector::e1 = Connector::movies_foreign_entry[3];
	}else if(Connector::movies_type == "horror"){
		Connector::e1 = Connector::movies_horror_entry[3];
	}else if(Connector::movies_type == "music_art"){
		Connector::e1 = Connector::movies_music_art_entry[3];
	}else if(Connector::movies_type == "mystery_suspense"){
		Connector::e1 = Connector::movies_mystery_suspense_entry[3];
	}else if(Connector::movies_type == "romance"){
		Connector::e1 = Connector::movies_romance_entry[3];
	}else if(Connector::movies_type == "science_fiction"){
		Connector::e1 = Connector::movies_science_fiction_entry[3];
	}else if(Connector::movies_type == "sports"){
		Connector::e1 = Connector::movies_sports_entry[3];
	}else if(Connector::movies_type == "war"){
		Connector::e1 = Connector::movies_war_entry[3];
	}else if(Connector::movies_type == "western"){
		Connector::e1 = Connector::movies_western_entry[3];
	}
    
    hide();
    Entry entry;
    entry.exec();
    show();
}




void Movies::handle_e_button_3()
{
	Connector::entry_p = 3;
    
	if(Connector::movies_type == "movies"){
		Connector::e1 = Connector::movies_entry[4];
	}else if(Connector::movies_type == "action"){
		Connector::e1 = Connector::movies_action_entry[4];
	}else if(Connector::movies_type == "animation"){
		Connector::e1 = Connector::movies_animation_entry[4];
	}else if(Connector::movies_type == "comedy"){
		Connector::e1 = Connector::movies_comedy_entry[4];
	}else if(Connector::movies_type == "documentary"){
		Connector::e1 = Connector::movies_documentary_entry[4];
	}else if(Connector::movies_type == "drama"){
		Connector::e1 = Connector::movies_drama_entry[4];
	}else if(Connector::movies_type == "family_kids"){
		Connector::e1 = Connector::movies_family_entry[4];
	}else if(Connector::movies_type == "foreign"){
		Connector::e1 = Connector::movies_foreign_entry[4];
	}else if(Connector::movies_type == "horror"){
		Connector::e1 = Connector::movies_horror_entry[4];
	}else if(Connector::movies_type == "music_art"){
		Connector::e1 = Connector::movies_music_art_entry[4];
	}else if(Connector::movies_type == "mystery_suspense"){
		Connector::e1 = Connector::movies_mystery_suspense_entry[4];
	}else if(Connector::movies_type == "romance"){
		Connector::e1 = Connector::movies_romance_entry[4];
	}else if(Connector::movies_type == "science_fiction"){
		Connector::e1 = Connector::movies_science_fiction_entry[4];
	}else if(Connector::movies_type == "sports"){
		Connector::e1 = Connector::movies_sports_entry[4];
	}else if(Connector::movies_type == "war"){
		Connector::e1 = Connector::movies_war_entry[4];
	}else if(Connector::movies_type == "western"){
		Connector::e1 = Connector::movies_western_entry[4];
	}
    
    hide();
    Entry entry;
    entry.exec();
    show();
}



void Movies::handle_f_button_3()
{
	Connector::entry_p = 3;
    
	if(Connector::movies_type == "movies"){
		Connector::e1 = Connector::movies_entry[5];
	}else if(Connector::movies_type == "action"){
		Connector::e1 = Connector::movies_action_entry[5];
	}else if(Connector::movies_type == "animation"){
		Connector::e1 = Connector::movies_animation_entry[5];
	}else if(Connector::movies_type == "comedy"){
		Connector::e1 = Connector::movies_comedy_entry[5];
	}else if(Connector::movies_type == "documentary"){
		Connector::e1 = Connector::movies_documentary_entry[5];
	}else if(Connector::movies_type == "drama"){
		Connector::e1 = Connector::movies_drama_entry[5];
	}else if(Connector::movies_type == "family_kids"){
		Connector::e1 = Connector::movies_family_entry[5];
	}else if(Connector::movies_type == "foreign"){
		Connector::e1 = Connector::movies_foreign_entry[5];
	}else if(Connector::movies_type == "horror"){
		Connector::e1 = Connector::movies_horror_entry[5];
	}else if(Connector::movies_type == "music_art"){
		Connector::e1 = Connector::movies_music_art_entry[5];
	}else if(Connector::movies_type == "mystery_suspense"){
		Connector::e1 = Connector::movies_mystery_suspense_entry[5];
	}else if(Connector::movies_type == "romance"){
		Connector::e1 = Connector::movies_romance_entry[5];
	}else if(Connector::movies_type == "science_fiction"){
		Connector::e1 = Connector::movies_science_fiction_entry[5];
	}else if(Connector::movies_type == "sports"){
		Connector::e1 = Connector::movies_sports_entry[5];
	}else if(Connector::movies_type == "war"){
		Connector::e1 = Connector::movies_war_entry[5];
	}else if(Connector::movies_type == "western"){
		Connector::e1 = Connector::movies_western_entry[5];
	}
    
    hide();
    Entry entry;
    entry.exec();
    show();
}



void  Movies::loadStyleSheet_3()
{
	QFile qss("style.qss");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();
}


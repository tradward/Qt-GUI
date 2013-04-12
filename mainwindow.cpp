#include "mainwindow.h"

MainWindow::MainWindow() {
    createMenu_2();
    createHorizontalGroupBox_2();
	createImages();
    
    
    QVBoxLayout *mainLayout_2 = new QVBoxLayout;
    mainLayout_2->setMenuBar(menuBar_2);
    
    mainLayout_2->addWidget(horizontalGroupBox_2);
	mainLayout_2->addWidget(line_label);
    //mainLayout_2->addWidget(formGroupBox_2);
	//mainLayout_2->addWidget(line_label_3);
	mainLayout_2->addWidget(horizontalGroupBox_images);
	mainLayout_2->addWidget(horizontalGroupBox_images_2);
    setLayout(mainLayout_2);
	loadStyleSheet();
	//setWidgetResizable(true);
	setWindowTitle(tr("Welcome!"));
}

void MainWindow::closeEvent(QCloseEvent *event) {
	Connector::signout_p = 0;
    hide();
    SignOut signout;
    signout.exec();
    //signout.setParent(this);
    show();
}

void MainWindow::createMenu_2() {
    menuBar_2 = new QMenuBar;
    
    fileMenu_2 = new QMenu(tr("&File"), this);
    exitAction_2 = fileMenu_2->addAction(tr("&Exit"));
    menuBar_2->addMenu(fileMenu_2);
    
    connect(exitAction_2, SIGNAL(triggered()), this, SLOT(accept()));
}

void MainWindow::createHorizontalGroupBox_2() {
    horizontalGroupBox_2 = new QGroupBox();
    QHBoxLayout *layout_2 = new QHBoxLayout;
	line_label = new QLabel();
	line_label->setText("<img src=\"17.png\">");
	line_label_2 = new QLabel();
	line_label_2->setText("<img src=\"17.png\">");
	line_label_3 = new QLabel();
	line_label_3->setText("<img src=\"17.png\">");
    line_label->setAlignment(Qt::AlignHCenter);
	line_label->setMinimumSize(line_label->sizeHint());
    
	logo_label = new QLabel();
	logo_label->setText("<img src=\"logo.png\">");
    logo_label->setAlignment(Qt::AlignHCenter);
	//little grid
	whats_new = new QPushButton(tr("=WHAT'S NEW="));
	favorite = new QPushButton(tr("= FAVORITE ="));
	movies = new QPushButton(tr("=  MOVIES  ="));
	series = new QPushButton(tr("= TV SHOWS ="));
	whats_new->setFlat(true);
	favorite->setFlat(true);
	movies->setFlat(true);
	series->setFlat(true);
	
	QObject::connect(movies, SIGNAL(clicked()),this, SLOT(handleButton_2()));
	QObject::connect(favorite, SIGNAL(clicked()),this, SLOT(handleButton_3()));
	QObject::connect(whats_new, SIGNAL(clicked()),this, SLOT(handleButton_4()));
	QObject::connect(series, SIGNAL(clicked()),this, SLOT(handleButton_5()));
    
    
	horizontalGroupBox_2_grid = new QGroupBox();
	QGridLayout *horizontalGroupBox_2_grid_layout = new QGridLayout();
	horizontalGroupBox_2_grid_layout->addWidget(whats_new, 0, 0);
	horizontalGroupBox_2_grid_layout->addWidget(movies, 0, 1);
	horizontalGroupBox_2_grid_layout->addWidget(favorite, 1, 0);
	horizontalGroupBox_2_grid_layout->addWidget(series, 1, 1);
    horizontalGroupBox_2_grid->setLayout(horizontalGroupBox_2_grid_layout);
    
    
	//right grid
	search_field = new QLineEdit(tr("Search here:"));
	QObject::connect(search_field, SIGNAL(returnPressed()),this, SLOT(search_2()));
    
	sign_out = new QPushButton(tr("<Sign Out>"));
	QObject::connect(sign_out, SIGNAL(clicked()),this, SLOT(handleButton_6()));
	manage_account = new QPushButton(tr("<Manage Account>"));
	QObject::connect(manage_account, SIGNAL(clicked()),this, SLOT(handleButton_7()));
	sign_out->setFlat(true);
	manage_account->setFlat(true);
    
    
	horizontalGroupBox_2_grid2h = new QGroupBox();
	QHBoxLayout *horizontalGroupBox_2_grid2h_layout = new QHBoxLayout();
	horizontalGroupBox_2_grid2h_layout->addWidget(manage_account);
	horizontalGroupBox_2_grid2h_layout->addWidget(sign_out);
	horizontalGroupBox_2_grid2h->setLayout(horizontalGroupBox_2_grid2h_layout);
    
	
	horizontalGroupBox_2_grid2 = new QGroupBox();
	QVBoxLayout *horizontalGroupBox_2_grid2_layout = new QVBoxLayout();
	horizontalGroupBox_2_grid2_layout->addWidget(search_field);
	horizontalGroupBox_2_grid2_layout->addWidget(horizontalGroupBox_2_grid2h);
    horizontalGroupBox_2_grid2->setLayout(horizontalGroupBox_2_grid2_layout);
	
	layout_2->addWidget(horizontalGroupBox_2_grid);
	layout_2->addWidget(logo_label);
	layout_2->addWidget(horizontalGroupBox_2_grid2);
    
    horizontalGroupBox_2->setLayout(layout_2);
    //horizontalGroupBox_2->setAlignment(Qt::AlignHCenter);
	horizontalGroupBox_2->setMinimumSize(horizontalGroupBox_2->sizeHint());
}

void MainWindow::handleButton_2() {
    hide();
    Movies movies;
    movies.exec();
    //movies.setParent(this);
    movies.show();
}

void MainWindow::handleButton_3() {
    hide();
    Favorite favorite;
    favorite.exec();
    //favorite.setParent(this);
    show();
}

void MainWindow::handleButton_4() {
    hide();
    WhatsNew whatsnew;
    whatsnew.exec();
    //whatsnew.setParent(this);
    show();
}

void MainWindow::handleButton_5() {
    hide();
    Series series;
    series.exec();
    //series.setParent(this);
    show();
}

void MainWindow::handleButton_6() {
	Connector::signout_p = 0;
    hide();
    SignOut signout;
    signout.exec();
    //signout.setParent(this);
    show();
}

void MainWindow::handleButton_7() {
	Connector::account_p = 0;
    hide();
    Account account1;
    account1.exec();
    //account1.setParent(this);
    show();
}

void MainWindow::search_2() {
	Connector::search_p = 0;
	Connector::search_metric = search_field->text();
    hide();
    Result result;
    result.exec();
    show();
}

void MainWindow::handle_a_button_2() {
	Connector::entry_p = 0;
	Connector::e1 = Connector::main_entry[0];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void MainWindow::handle_b_button_2() {
	Connector::entry_p = 0;
	Connector::e1 = Connector::main_entry[1];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void MainWindow::handle_c_button_2() {
	Connector::entry_p = 0;
	Connector::e1 = Connector::main_entry[2];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void MainWindow::handle_d_button_2() {
	Connector::entry_p = 0;
	Connector::e1 = Connector::main_entry[3];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void MainWindow::handle_e_button_2() {
	Connector::entry_p = 0;
	Connector::e1 = Connector::main_entry[4];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void MainWindow::handle_f_button_2() {
	Connector::entry_p = 0;
	Connector::e1 = Connector::main_entry[5];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void MainWindow::handle_g_button_2() {
	Connector::entry_p = 0;
	Connector::e1 = Connector::main_entry[6];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void MainWindow::handle_h_button_2() {
	Connector::entry_p = 0;
	Connector::e1 = Connector::main_entry[7];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void MainWindow::handle_i_button_2() {
	Connector::entry_p = 0;
	Connector::e1 = Connector::main_entry[8];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void MainWindow::handle_j_button_2() {
	Connector::entry_p = 0;
	Connector::e1 = Connector::main_entry[9];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void MainWindow::handle_k_button_2() {
	Connector::entry_p = 0;
	Connector::e1 = Connector::main_entry[10];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void MainWindow::handle_l_button_2() {
	Connector::entry_p = 0;
	Connector::e1 = Connector::main_entry[11];
    hide();
    Entry entry;
    entry.exec();
    show();
}

void MainWindow::createImages() {
	cout << "Get Images" << endl;
	string url = Connector::ip.toStdString();
	string username_main = Connector::username.toStdString();
	string inputCommand = "display*_*" + username_main +"*_*main";
    int clientfd= client::Clie_SockEstablish();
    client::Clie_ClientConnect(clientfd, (char *)url.c_str());
    client::Clie_SendCommand(clientfd, inputCommand.c_str());
    
    vector<vector<string> > entry;
    for(int i=0; i<12;i++){
        cout << i << endl;
        int clientfdx = client::Clie_SockEstablish();;
        client::Clie_ClientConnect(clientfdx, (char *)url.c_str());
        string re = client::Clie_GetResponse(clientfdx);
        vector<string> s = client::split(re, "||||");
        assert(s.size() == 3);
        entry.push_back(s);
        Connector::main_entry[i] = s[0];
        client::Clie_SaveContent(clientfdx, (char *)url.c_str(), s[2]);
        client::Clie_close(clientfdx);
    }
    client::Clie_close(clientfd);
    assert(entry.size() == 12);
    
    
    const char * a_button_str = entry[0][1].c_str();
    //QString a_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[0][1].c_str()));
	a_button = new QPushButton();
	a_button->setIcon(QIcon(entry[0][2].c_str()));
	a_button->setIconSize(QSize(120,200));
	a_button->setToolTip(tr(a_button_str));
    
    const char * b_button_str = entry[1][1].c_str();
    //QString b_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[1][1].c_str()));
	b_button = new QPushButton();
	b_button->setIcon(QIcon(entry[1][2].c_str()));
	b_button->setIconSize(QSize(120,200));
	b_button->setToolTip(tr(b_button_str));
    
    const char * c_button_str = entry[2][1].c_str();
    //QString c_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[2][1].c_str()));
	c_button = new QPushButton();
	c_button->setIcon(QIcon(entry[2][2].c_str()));
	c_button->setIconSize(QSize(120,200));;
	c_button->setToolTip(tr(c_button_str));
    
    const char * d_button_str = entry[3][1].c_str();
    //QString d_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[3][1].c_str()));
	d_button = new QPushButton();
	d_button->setIcon(QIcon(entry[3][2].c_str()));
	d_button->setIconSize(QSize(120,200));
	d_button->setToolTip(tr(d_button_str));
    
    const char * e_button_str = entry[4][1].c_str();
    //QString e_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[4][1].c_str()));
	e_button = new QPushButton();
	e_button->setIcon(QIcon(entry[4][2].c_str()));
	e_button->setIconSize(QSize(120,200));
	e_button->setToolTip(tr(e_button_str));
    
    const char * f_button_str = entry[5][1].c_str();
    //QString f_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[5][1].c_str()));
	f_button = new QPushButton();
	f_button->setIcon(QIcon(entry[5][2].c_str()));
	f_button->setIconSize(QSize(120,200));
	f_button->setToolTip(tr(f_button_str));
    
    
    const char * g_button_str = entry[6][1].c_str();
    //QString g_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[6][1].c_str()));
	g_button = new QPushButton();
	g_button->setIcon(QIcon(entry[6][2].c_str()));
	g_button->setIconSize(QSize(120,200));
	g_button->setToolTip(tr(g_button_str));
    
    const char * h_button_str = entry[7][1].c_str();
    //QString h_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[7][1].c_str()));
	h_button = new QPushButton();
	h_button->setIcon(QIcon(entry[7][2].c_str()));
	h_button->setIconSize(QSize(120,200));
	h_button->setToolTip(tr(h_button_str));
    
    const char * i_button_str = entry[8][1].c_str();
    //QString i_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[8][1].c_str()));
	i_button = new QPushButton();
	i_button->setIcon(QIcon(entry[8][2].c_str()));
	i_button->setIconSize(QSize(120,200));
	i_button->setToolTip(tr(i_button_str));
    
    const char * j_button_str = entry[9][1].c_str();
    //QString j_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[9][1].c_str()));
	j_button = new QPushButton();
	j_button->setIcon(QIcon(entry[9][2].c_str()));
	j_button->setIconSize(QSize(120,200));
	j_button->setToolTip(tr(j_button_str));
    
    const char * k_button_str = entry[10][1].c_str();
    //QString k_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[10][1].c_str()));
	k_button = new QPushButton();
	k_button->setIcon(QIcon(entry[10][2].c_str()));
	k_button->setIconSize(QSize(120,200));
	k_button->setToolTip(tr(k_button_str));
    
    const char * l_button_str = entry[11][1].c_str();
    //QString l_button_str = QString(QString::fromLocal8Bit(Connector::main_entry[11][1].c_str()));
	l_button = new QPushButton();
	l_button->setIcon(QIcon(entry[11][2].c_str()));
	l_button->setIconSize(QSize(120,200));
	l_button->setToolTip(tr(l_button_str));
    
	a_button->setFlat(true);
	b_button->setFlat(true);
	c_button->setFlat(true);
	d_button->setFlat(true);
	e_button->setFlat(true);
	f_button->setFlat(true);
	
    
	g_button->setFlat(true);
	h_button->setFlat(true);
	i_button->setFlat(true);
	j_button->setFlat(true);
	k_button->setFlat(true);
	l_button->setFlat(true);
    
	QObject::connect(a_button, SIGNAL(clicked()),this, SLOT(handle_a_button_2()));
	QObject::connect(b_button, SIGNAL(clicked()),this, SLOT(handle_b_button_2()));
	QObject::connect(c_button, SIGNAL(clicked()),this, SLOT(handle_c_button_2()));
	QObject::connect(d_button, SIGNAL(clicked()),this, SLOT(handle_d_button_2()));
	QObject::connect(e_button, SIGNAL(clicked()),this, SLOT(handle_e_button_2()));
	QObject::connect(f_button, SIGNAL(clicked()),this, SLOT(handle_f_button_2()));
    
	QObject::connect(g_button, SIGNAL(clicked()),this, SLOT(handle_g_button_2()));
	QObject::connect(h_button, SIGNAL(clicked()),this, SLOT(handle_h_button_2()));
	QObject::connect(i_button, SIGNAL(clicked()),this, SLOT(handle_i_button_2()));
	QObject::connect(j_button, SIGNAL(clicked()),this, SLOT(handle_j_button_2()));
	QObject::connect(k_button, SIGNAL(clicked()),this, SLOT(handle_k_button_2()));
	QObject::connect(l_button, SIGNAL(clicked()),this, SLOT(handle_l_button_2()));
    
    horizontalGroupBox_images = new QGroupBox();
    QHBoxLayout *layout_images = new QHBoxLayout;
	layout_images->addWidget(a_button);
	layout_images->addWidget(b_button);
	layout_images->addWidget(c_button);
	layout_images->addWidget(d_button);
	layout_images->addWidget(e_button);
	layout_images->addWidget(f_button);
    
    horizontalGroupBox_images_2 = new QGroupBox();
    QHBoxLayout *layout_images_2 = new QHBoxLayout;
	layout_images_2->addWidget(g_button);
	layout_images_2->addWidget(h_button);
	layout_images_2->addWidget(i_button);
	layout_images_2->addWidget(j_button);
	layout_images_2->addWidget(k_button);
	layout_images_2->addWidget(l_button);
    
    
    horizontalGroupBox_images->setLayout(layout_images);
	horizontalGroupBox_images->setFixedHeight(220);
    horizontalGroupBox_images_2->setLayout(layout_images_2);
	horizontalGroupBox_images_2->setFixedHeight(220);
}

void MainWindow::loadStyleSheet() {
	QFile qss("style.qss");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();
}

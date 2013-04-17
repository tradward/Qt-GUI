#include "create_account.h"

CreateAccount::CreateAccount()
{
    createMenu_a();
    createFormGroupBox_a();
    createHorizontalGroupBox_a();
    
    QVBoxLayout *mainLayout_a = new QVBoxLayout;
    mainLayout_a->setMenuBar(menuBar_a);
    mainLayout_a->addWidget(formGroupBox_a);
    mainLayout_a->addWidget(horizontalGroupBox_a);
    // mainLayout_a->addWidget(test);
    setLayout(mainLayout_a);
    setWindowTitle(tr(""));
    loadStyleSheet_a();
}
void CreateAccount::closeEvent_a(QCloseEvent *event){
    hide();
    Dialog dialog_a;
    dialog_a.exec();
    show();
    event->accept();
}

void CreateAccount::createMenu_a()
{
    menuBar_a = new QMenuBar;
    
    fileMenu_a = new QMenu(tr("&File"), this);
    exitAction_a = fileMenu_a->addAction(tr("E&xit"));
    menuBar_a->addMenu(fileMenu_a);
    
    connect(exitAction_a, SIGNAL(triggered()), this, SLOT(accept()));
}

void CreateAccount::createHorizontalGroupBox_a()
{
	
    horizontalGroupBox_a = new QGroupBox();
    QHBoxLayout *layout_a = new QHBoxLayout;
    
	submit_a = new QPushButton(tr("Submit"));
	submit_a->setFlat(true);
	QObject::connect(submit_a, SIGNAL(clicked()),this, SLOT(handleButton_a()));
    
	cancel_a = new QPushButton(tr("Cancel"));
	cancel_a->setFlat(true);
	QObject::connect(cancel_a, SIGNAL(clicked()),this, SLOT(handleButton_a_2()));
    
    
	layout_a->addWidget(submit_a);
	layout_a->addWidget(cancel_a);
    horizontalGroupBox_a->setLayout(layout_a);
}


void CreateAccount::createFormGroupBox_a()
{
    formGroupBox_a = new QGroupBox();
    QFormLayout *layout_a = new QFormLayout;
	username_input = new QLineEdit;
	password_input = new QLineEdit;
	//password_input_new = new QLineEdit;
	password_input->setEchoMode(QLineEdit::Password);
	warning = new QLabel(tr("Password should be a mix of upper letters, lower letters, and digits."));
    layout_a->addRow(warning);
    layout_a->addRow(new QLabel(tr("Username: ")), username_input);
    layout_a->addRow(new QLabel(tr("Old password: ")), password_input);
    //layout_a->addRow(new QLabel(tr("New password: ")), password_input_new);
    formGroupBox_a->setLayout(layout_a);
	
}

void CreateAccount::handleButton_a()
{
	str2 = QString();
	str2 = username_input->text();
    
	str = QString();
	str = password_input->text();
    
    
	//QFile file("out.txt");
    //if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    // return;
    
    //QTextStream stream(&file);
    //stream << "The magic number is: " << "49 ";
    
	bool is_valid = true;
	bool is_valid2 = true;
	int upper_count = 0;
	int lower_count = 0;
	int sign_count = 0;
	
	if(str.length()==0){
		is_valid = false;
	}
    
	for(int i = 0; i < str.length(); i++){
		if(str[i]==' '){
			is_valid =  false;
		}
		if(str[i]>='A' && str[i]<='Z'){
			upper_count++;
		}
		if(str[i]>='a' && str[i]<='z'){
			lower_count++;
		}
		if(str[i]>='0' && str[i]<='9'){
			sign_count++;
		}
	}
	if((upper_count == 0 )|( lower_count == 0) |( sign_count == 0)){
		is_valid =  false;
	}
	int sum = upper_count+lower_count+sign_count;
	if(sum!=str.length()){
		is_valid =  false;
	}
	
	for(int j = 0; j < str2.length(); j++){
		if(str2[j]==' '){
			is_valid2 = false;
		}
        
	}
    
	if(str2.length() == 0){
		is_valid2 = false;
	}
	
	if(is_valid && is_valid2){
		//createuser*_*jianan*_*123456
		string str_a = string((const char *)str.toLocal8Bit());
		string str2_a = string((const char *)str2.toLocal8Bit());
		cout << "Get Images" << endl;
        
		string url = Connector::ip.toStdString();
		string inputCommand = "createuser*_*" + str2_a+ "*_*"+str_a;
        int clientfd= client::Clie_SockEstablish();
        client::Clie_ClientConnect(clientfd, (char*)url.c_str());
        client::Clie_SendCommand(clientfd, inputCommand.c_str());
        string response = client::Clie_GetResponse(clientfd);
        client::Clie_close(clientfd);
		if(response == "Success"){
			Connector::username = str2;
			Connector::password = str;
			hide();
			MainWindow mainwindow_a;
            mainwindow_a.exec();
            show();
		}else{
			warning->setText("Username already exist!");
		}
	}else{
		if(!is_valid2){
			warning->setText("Please enter the username!");
		}else if(!is_valid){
			warning->setText("Invalid password. Please create a valid one!");
		}else{
			warning->setText("Please enter the username and check password!");
		}
	}
}



void CreateAccount::handleButton_a_2()
{
    hide();
    Dialog dialog_a;
    dialog_a.exec();
    show();
}




void CreateAccount::loadStyleSheet_a()
{
	QFile qss("style.qss");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();
}


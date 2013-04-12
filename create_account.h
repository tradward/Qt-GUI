
#ifndef CREATE_ACCOUNT_H
#define CREATE_ACCOUNT_H

#include <QDialog>

class QAction;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QApplication;
class QString;


class CreateAccount : public QDialog
{
    Q_OBJECT
    
public:
    CreateAccount();
    
    private slots:
    void handleButton_a();
	void handleButton_a_2();
private:
    void createMenu_a();
    void createHorizontalGroupBox_a();
    void createFormGroupBox_a();
	void loadStyleSheet_a();
	void closeEvent_a(QCloseEvent *event);
    
    
    QMenuBar *menuBar_a;
    QGroupBox *formGroupBox_a;
    QPushButton *submit_a;
    QPushButton *cancel_a;
    QMenu *fileMenu_a;
    QAction *exitAction_a;
	QLineEdit *username_input;
	QLineEdit *password_input;
	//QLineEdit *password_input_new;
	QString str;
	QString str2;
	//QString str3;
	QLabel *warning;
 	QGroupBox *horizontalGroupBox_a;
	
};




#endif


 #ifndef _ACCOUNT_H
 #define _ACCOUNT_H

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

 class Account : public QDialog
 {
     Q_OBJECT

 public:
     Account();
 private slots:
    void handleButton_9_1();
    void handleButton_9_2();
 private:
     	void createMenu_9();
     	void createHorizontalGroupBox_9();
	void create_logo_9();
	void loadStyleSheet_9();
 	void create_line_9();
	void create_bottom_9();
	void closeEvent_9(QCloseEvent *event);
	
	//logo
	QLabel *account_label;

	//menu
     	QMenuBar *menuBar_9;
     	QMenu *fileMenu_9;
     	QAction *exitAction_9;

	//horizontal
     	QGroupBox *horizontalGroupBox_9_1;
     	QGroupBox *horizontalGroupBox_9_2;
     	QGroupBox *horizontalGroupBox_9_2_2;

	QLabel *message_9;
	QLabel *username_label;
	QLabel *username_label_result;
	QLabel *change_pw_label;
	QLineEdit *change_pw_field;
	QLabel *change_opw_label;
	QLineEdit *change_opw_field;
	QPushButton *change_pw_submit;
	QPushButton *change_pw_back;


	//line
	QLabel *line_logo_9_1;
	QLabel *line_logo_9_2;

	//bottom
	QGroupBox *bottom_area_9;
	QLabel *copy_right_9;
	QLabel *logo_9_2;
	QPushButton *sign_out_9;

	//QString str_9;
	//QString str2_9;
	//QString str3_9;
};




 #endif

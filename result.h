
 #ifndef RESULT_H
 #define RESULT_H

 #include <QDialog>
 #include <vector>
 #include <iostream>

using namespace std;

 class QAction;
 class QGroupBox;
 class QLabel;
 class QMenu;
 class QMenuBar;
 class QPushButton;
 class QApplication;
 class QTextEdit;


 class Result : public QDialog
 {
     	Q_OBJECT

 public:
     	Result();
 private slots:
    	void handleButton_5();
		void handleButton_5_pic_1();
		void handleButton_5_pic_2();
		void handleButton_5_pic_3();
		void handleButton_5_pic_4();
		void handleButton_5_pic_5();
		void handleButton_5_pic_6();
		void handleButton_5_pic_7();
		void handleButton_5_pic_8();
		void handleButton_5_pic_9();
		void handleButton_5_pic_10();

 private:
     	void createMenu_5();
	void create_line_5();
     	void create_inf_1();
     	//void create_inf_2();
	void create_back();
	void create_result_logo();
	void loadStyleSheet_5();
	void closeEvent_5(QCloseEvent *event);
 
	//Menu
     	QMenuBar *menuBar_5;
	QMenu *fileMenu_5;

	QAction *exitAction_5;
	QLabel *message_favorite;
	int num_5;
	QGroupBox *vertical_images_5;
	QGroupBox *horizontal_images_5_1;	
	QGroupBox *horizontal_images_5_2;
	QGroupBox *horizontal_images_5_3;

	//info_groupbox_1
	//QGroupBox *info_v_groupbox_1;
	//QGroupBox *info_v_groupbox_2_1;	
	//QGroupBox *info_groupbox_1;		
	/*QLabel *name_1;
	QLabel *name_result_1;
	QLabel *date_1;
	QLabel *date_result_1;
	QLabel *director_1;
	QLabel *director_result_1;
	QLabel *stars_1;
	QLabel *stars_result_1;
	QPushButton *picture_button_1;	
	QLabel *rate_label_1;*/



	//info_groupbox_2
	/*QGroupBox *info_v_groupbox_2;
	QGroupBox *info_v_groupbox_2_2;	
	QGroupBox *info_groupbox_2;		
	QLabel *name_2;
	QLabel *name_result_2;
	QLabel *date_2;
	QLabel *date_result_2;
	QLabel *director_2;
	QLabel *director_result_2;
	QLabel *stars_2;
	QLabel *stars_result_2;
	QPushButton *picture_button_2;		
	QLabel *rate_label_2;*/



	//line
	QLabel *line_logo_5_1;
	QLabel *line_logo_5_2;
	QLabel *line_logo_5_3;

	//button
	QPushButton *back_button_5;
	QLabel *result_logo;
	vector<QPushButton*> result_buttons;

 };




 #endif

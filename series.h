
 #ifndef SERIES_H
 #define SERIES_H

 #include <QDialog>

 class QAction;
 class QGroupBox;
 class QLabel;
 class QLineEdit;
 class QMenu;
 class QMenuBar;
 class QPushButton;
 class QApplication;
 //class MainWindow;
 //class QMainWindow;

 class Series : public QDialog
 {
     Q_OBJECT

 public:
     Series();
 private slots:
    	void handleButton_8_1();
    	void handleButton_8_2();
    	void handleButton_8_3();
    	void handleButton_8_4();
	void handle_a_button_8();
	void handle_b_button_8();
	void handle_c_button_8();
	void handle_d_button_8();
	void handle_e_button_8();
	void handle_f_button_8();

	void handle_action_button_8();
	void handle_biography_button_8();
	void handle_classics_button_8();
	void handle_comic_button_8();
	void handle_comedy_button_8();
	void handle_discovery_button_8();

	void handle_documentary_button_8();
	void handle_history_button_8();
	void handle_kids_button_8();
	void handle_miniseries_button_8();
	void handle_reality_button_8();
	void handle_science_fiction_button_8();


 private:
     void createMenu_8();
     void createHorizontalGroupBox_8();
     void createFormGroupBox_8();
	void loadStyleSheet_8();
	void createBottom_8();
	void display_options();
	void createImages_8();
	void display_search();
	void create_labels();
	void closeEvent_8(QCloseEvent *event);
    //void main_window();
	//void clickedSlot();
	//void handleButton();

     QMenuBar *menuBar_8;
     //QGroupBox *horizontalGroupBox_8;
     QGroupBox *formGroupBox_8;
     //QPushButton *back_8;
     QMenu *fileMenu_8;
     QAction *exitAction_8;
	//QLabel * logo_2;
	QLabel * series_logo;
	//QLabel * this_logo;
	//QLabel * this_logo_2;
	QLabel * line_logo_2_1;
	QLabel * line_logo_2_2;
	QLabel * line_logo_2_8;
	QLabel * line_logo_2_4;
    // MainWindow *mainwindow;
	//QLabel * search_label_8;
	QLineEdit *search_field_8;
	QGroupBox *header_vertical_box_8;
	QPushButton *sign_out_8;
	QPushButton *manage_account_8;
	QGroupBox *header_horizontal_box_8;

	QGroupBox *options_1_8;
	QGroupBox *options_2_8;


     QPushButton *action_8;
     QPushButton *biography_8;
     QPushButton *classics_8;
     QPushButton *comic_8;
     QPushButton *commedy_8;
     QPushButton *discovery_8;
     QPushButton *documentary_8;
     QPushButton *history_8;
     QPushButton *kids_8;
     QPushButton *miniseries_8;
     QPushButton *reality_8;
     QPushButton *science_fiction_8;

	QPushButton *back_8;
 
	//display_search
	QGroupBox *search_area;
	QLabel *search_label_8;
	QPushButton *back_home;
	
	//images: just for try
	QPushButton *a_button_8;
	QPushButton *b_button_8;
	QPushButton *c_button_8;
	QPushButton *d_button_8;
	QPushButton *e_button_8;
	QPushButton *f_button_8;
	QGroupBox *horizontalGroupBox_images_8;

	//bottom:
	QGroupBox *bottom_area;
	QLabel *copy_right;
	QLabel *logo_8_2;

	//two small labels
	QLabel *history_label;
	QLabel *classification_label;


 };




 #endif

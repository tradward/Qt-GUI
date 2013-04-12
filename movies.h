
 #ifndef MOVIES_H
 #define MOVIES_H

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

 class Movies : public QDialog
 {
     Q_OBJECT

 public:
     Movies();
 private slots:
    void handleButton_3_1();
    void handleButton_3_2();
    void handleButton_3_3();
    void handleButton_3_4();
	void handle_a_button_3();
	void handle_b_button_3();
	void handle_c_button_3();
	void handle_d_button_3();
	void handle_e_button_3();
	void handle_f_button_3();

	void handle_action_button_3();
	void handle_animation_button_3();
	void handle_comedy_button_3();
	void handle_documentary_button_3();
	void handle_drama_button_3();
	void handle_family_kids_button_3();
	void handle_foreign_button_3();
	void handle_horror_button_3();
	void handle_music_art_button_3();
	void handle_mystery_suspense_button_3();
	void handle_romance_button_3();
	void handle_science_fiction_button_3();
	void handle_sports_button_3();
	void handle_war_button_3();
	void handle_western_button_3();

 private:
    void createMenu_3();
    void createHorizontalGroupBox_3();
    void createFormGroupBox_3();
	void loadStyleSheet_3();
	void createBottom_3();
	void display_options();
	void createImages_3();
	void display_search();
	void create_labels();
	void closeEvent_3(QCloseEvent *event);
    //void main_window();
	//void clickedSlot();
	//void handleButton();

     QMenuBar *menuBar_3;
     //QGroupBox *horizontalGroupBox_3;
     QGroupBox *formGroupBox_3;
     //QPushButton *back_3;
     QMenu *fileMenu_3;
     QAction *exitAction_3;
	//QLabel * logo_2;
	QLabel * movies_logo;
	//QLabel * this_logo;
	//QLabel * this_logo_2;
	QLabel * line_logo_2_1;
	QLabel * line_logo_2_2;
	QLabel * line_logo_2_3;
	QLabel * line_logo_2_4;
    // MainWindow *mainwindow;
	//QLabel * search_label_3;
	QLineEdit *search_field_3;
	QGroupBox *header_vertical_box_3;
	QPushButton *sign_out_3;
	QPushButton *manage_account_3;
	QGroupBox *header_horizontal_box_3;

	QGroupBox *options_1;
	QGroupBox *options_2;
	QGroupBox *options_3;

     QPushButton *action;
     QPushButton *animation;
     QPushButton *comedy;
     QPushButton *documentary;
     QPushButton *drama;
     QPushButton *family_kids;
     QPushButton *foreign;
     QPushButton *horror;
     QPushButton *music_art;
     QPushButton *mystery_suspense;
     QPushButton *romance;
     QPushButton *science_fiction;
     QPushButton *sports;
     QPushButton *war;
     QPushButton *western;

	QPushButton *back_3;
 
	//display_search
	QGroupBox *search_area;
	QLabel *search_label_3;
	QPushButton *back_home;
	
	//images: just for try
	QPushButton *a_button_3;
	QPushButton *b_button_3;
	QPushButton *c_button_3;
	QPushButton *d_button_3;
	QPushButton *e_button_3;
	QPushButton *f_button_3;
	QGroupBox *horizontalGroupBox_images_3;

	//bottom:
	QGroupBox *bottom_area;
	QLabel *copy_right;
	QLabel *logo_3_2;

	//two small labels
	QLabel *history_label;
	QLabel *classification_label;


 };




 #endif

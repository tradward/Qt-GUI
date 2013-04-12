#ifndef WHATS_NEW_H
#define WHATS_NEW_H

#include <QDialog>
#include <QtGui>
#include <QApplication>//add it
#include <QCloseEvent>

#include "result.h"
#include "sign_out.h"
#include "account.h"
#include "connector.h"
#include "common.h"
#include "entry.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class QAction;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QApplication;

class WhatsNew : public QDialog {
    Q_OBJECT  
public:
    WhatsNew();
    private slots:
    void handleButton_7_1();
	void handleButton_7_2();
    void handleButton_7_3();
	void handleButton_7_4();
    
	void handle_a_button_7();
	void handle_b_button_7();
	void handle_c_button_7();
	void handle_d_button_7();
	void handle_e_button_7();
	void handle_f_button_7();
    
	void handle_g_button_7();
	void handle_h_button_7();
	void handle_i_button_7();
	void handle_j_button_7();
	void handle_k_button_7();
	void handle_l_button_7();
private:
    void createMenu_7();
	void create_logo_7();
	void display_search_7();
	void display_whatsnew();
    void create_line_7();
	void createBottom_7();
	void loadStyleSheet_7();
	void closeEvent_7(QCloseEvent *event);
    QMenuBar *menuBar_7;
	QMenu *fileMenu_7;
    
    QAction *exitAction_7;
    
	//logo
	QLabel *whatsnew_logo;
    
	//line
	QLabel * line_logo_7_1;
	QLabel * line_logo_7_2;
	QLabel * line_logo_7_3;
    
	//search
	QGroupBox *search_area_7;
	QLabel *search_label_7;
	QPushButton *back_home_7;
	QLineEdit *search_field_7;
    
	//display
	QPushButton *a_button_7;
	QPushButton *b_button_7;
	QPushButton *c_button_7;
	QPushButton *d_button_7;
	QPushButton *e_button_7;
	QPushButton *f_button_7;
	QGroupBox *horizontalGroupBox_images_7;
    
	QPushButton *g_button_7;
	QPushButton *h_button_7;
	QPushButton *i_button_7;
	QPushButton *j_button_7;
	QPushButton *k_button_7;
	QPushButton *l_button_7;
	QGroupBox *horizontalGroupBox_images_7_2;
    
	//bottom
	QGroupBox *bottom_area_7;
	QLabel *copy_right_7;
	QLabel *logo_7_2;
	QPushButton *sign_out_7;
	QPushButton *manage_account_7;   
};

#endif


#ifndef FAVORITE_H
#define FAVORITE_H

#include <QDialog>
#include <iostream>
#include <QtGui>
#include <QApplication>//add it
#include "result.h"
#include "connector.h"
#include "sign_out.h"
#include "account.h"
#include <QCloseEvent>
#include "common.h"
#include <vector>
#include <string>
#include "entry.h"

using namespace std;

class QAction;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QApplication;

class Favorite : public QDialog
{
    Q_OBJECT
    
public:
    Favorite();
    private slots:
    void handleButton_6_1();
    void handleButton_6_2();
    void handleButton_6_3();
    void handleButton_6_4();
    void handleButton_6_pic_1();
    void handleButton_6_pic_2();
    void handleButton_6_pic_3();
    void handleButton_6_pic_4();
    void handleButton_6_pic_5();
    void handleButton_6_pic_6();
    void handleButton_6_pic_7();
    void handleButton_6_pic_8();
    void handleButton_6_pic_9();
    void handleButton_6_pic_10();
private:
    void createMenu_6();
	void create_logo_6();
	void display_search_6();
	void display_favorite();
    void create_line_6();
	void createBottom_6();
	void loadStyleSheet_6();
	void closeEvent_6(QCloseEvent *event);
    QMenuBar *menuBar_6;
	QMenu *fileMenu_6;
    
    QAction *exitAction_6;
    
	//logo
	QLabel *favorite_logo;
    
	//line
	QLabel * line_logo_6_1;
	QLabel * line_logo_6_2;
	QLabel * line_logo_6_3;
    
	//search
	QGroupBox *search_area_6;
	QLabel *search_label_6;
	QPushButton *back_home_6;
	QLineEdit *search_field_6;
    
	//display
	/*QPushButton *a_button_6;
     QPushButton *b_button_6;
     QPushButton *c_button_6;
     QPushButton *d_button_6;
     QPushButton *e_button_6;
     QPushButton *f_button_6;
     QGroupBox *horizontalGroupBox_images_6;
     
     QPushButton *g_button_6;
     QPushButton *h_button_6;
     QPushButton *i_button_6;
     QPushButton *j_button_6;
     QPushButton *k_button_6;
     QPushButton *l_button_6;
     QGroupBox *horizontalGroupBox_images_6_2;*/
    
	QGroupBox *vertical_images_6;
	QGroupBox *horizontal_images_6_1;
	QGroupBox *horizontal_images_6_2;
	QGroupBox *horizontal_images_6_3;
    QVBoxLayout *mainLayout_6;
    
	//bottom
	QGroupBox *bottom_area_6;
	QLabel *copy_right_6;
	QLabel *logo_6_2;
	QPushButton *sign_out_6;
	QPushButton *manage_account_6;
    
	QLabel *message_favorite;
	int num;
	vector<QPushButton*> favorite_buttons;
    
};




#endif

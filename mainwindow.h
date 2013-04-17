#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QtGui>
#include <QApplication>
#include <QCloseEvent>
#include <QString>
#include <QVector>

#include <iostream>
#include <vector>
#include <string>

#include "movies.h"
#include "dialog.h"
#include "entry.h"
#include "result.h"
#include "favorite.h"
#include "whats_new.h"
#include "series.h"
#include "sign_out.h"
#include "account.h"
#include "connector.h"
#include "common.h"
//#include "loading.h"

using namespace std;

class QAction;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QApplication;
class QImage;
class QLabel;

class MainWindow : public QDialog
{
    Q_OBJECT
    
public:
    MainWindow();

    void createImages();
    
    private slots:
    void handleButton_2();
    void handleButton_3();
    void handleButton_4();
    void handleButton_5();
    void handleButton_6();
    void handleButton_7();
	void search_2();
	void handle_a_button_2();
	void handle_b_button_2();
	void handle_c_button_2();
	void handle_d_button_2();
	void handle_e_button_2();
	void handle_f_button_2();
    
	void handle_g_button_2();
	void handle_h_button_2();
	void handle_i_button_2();
	void handle_j_button_2();
	void handle_k_button_2();
	void handle_l_button_2();
    
private:
    void createMenu_2();
    void createHorizontalGroupBox_2();
	void loadStyleSheet();
	void closeEvent(QCloseEvent *event);
    //void main_window();
	//void clickedSlot();
	//void handleButton();
    
    QMenuBar *menuBar_2;
    QGroupBox *header_vertical_box;
    QGroupBox *header_horizontal_box;
    QGroupBox *horizontalGroupBox_2;
	QGroupBox *horizontalGroupBox_2_1;
	QGroupBox *horizontalGroupBox_2_2;
	QGroupBox *verticalGroupBox_2_1;
	QGroupBox *verticalGroupBox_2_2;
	QGroupBox *horizontalGroupBox_2_grid;
	QGroupBox *horizontalGroupBox_2_grid2;
	QGroupBox *horizontalGroupBox_2_grid2h;
    QGroupBox *formGroupBox_2;
	//classifying buttons
    /*QPushButton *action;
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
     QPushButton *western;*/
    QPushButton *whats_new;
    QPushButton *favorite;
    QPushButton *movies;
    QPushButton *series;
    QPushButton *sign_out;
    QPushButton *manage_account;
	QImage *logo;
	QLabel *logo_label;
	QLabel *line_label;
	QLabel *line_label_2;
	QLabel *line_label_3;
	QLineEdit *search_field;
    QMenu *fileMenu_2;
    QAction *exitAction_2;
    // MainWindow *mainwindow;
    
    
    
	//images: just for try
	QGroupBox *horizontalGroupBox_images;
	QGroupBox *horizontalGroupBox_images_2;
	QPushButton *a_button;
	QPushButton *b_button;
	QPushButton *c_button;
	QPushButton *d_button;
	QPushButton *e_button;
	QPushButton *f_button;
	QPushButton *g_button;
	QPushButton *h_button;
	QPushButton *i_button;
	QPushButton *j_button;
	QPushButton *k_button;
	QPushButton *l_button;
    
};




#endif

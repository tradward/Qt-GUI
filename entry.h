
#ifndef ENTRY_H
#define ENTRY_H

#include <QDialog>

class QAction;
class QGroupBox;
class QLabel;
class QMenu;
class QMenuBar;
class QPushButton;
class QApplication;
class QTextEdit;
class QComboBox;
class QString;

class Entry : public QDialog
{
    Q_OBJECT
    
public:
    Entry();
    private slots:
    void handleButton_4_1();
    void handleButton_4_2();
    void handleButton_4_3();
private:
    void createMenu_4();
    void create_inf();
    //void create_synosis();
	void create_comment();
	void create_button();
	void loadStyleSheet_4();
	void closeEvent_4(QCloseEvent *event);
    
	//Menu
    QMenuBar *menuBar_4;
	QMenu *fileMenu_4;
    
	//info_groupbox
	QGroupBox *info_v_groupbox;
	QGroupBox *info_v_groupbox_2;
	QGroupBox *info_groupbox;
	QLabel *name;
	QLabel *name_result;
	QLabel *date;
	QLabel *date_result;
	QLabel *director;
	QLabel *director_result;
	QLabel *stars;
	QLabel *stars_result;
	QLabel *length;
	QLabel *length_result;
    
	QPushButton *picture_button;
	QLabel *rate_label;
    
	//synosis
	QLabel *synosis_label;
	QLabel *synosis_content;
    
	//comment
	QLabel *comment_label;
	QTextEdit *comment_content;
    
	//button
	QPushButton *submit_button_4;
	QPushButton *back_button_4;
    
	QAction *exitAction_4;
    
	QGroupBox *rate_and_submit;
	QLabel *rate_here_label;
	QComboBox *rate_combo;
	QString favorite;
    
    
    
};




#endif

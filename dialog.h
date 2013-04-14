#ifndef DIALOG_H
#define DIALOG_H

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


class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    Dialog();
    
    private slots:
    void handleButton();
    void handleButton_2();
    void search_dialog();
private:
    void createMenu();
    void createHorizontalGroupBox();
    void createFormGroupBox();
	void loadStyleSheet_2();
    
    
    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox;
    QGroupBox *formGroupBox;
    QPushButton *create_account;
    QPushButton *submit;
    QMenu *fileMenu;
    QAction *exitAction;
	QString str;
	QLabel *indication;
	QLineEdit *passwd;
	QLineEdit *username;
    // MainWindow *mainwindow;
};




#endif

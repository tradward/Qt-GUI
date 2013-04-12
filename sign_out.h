
 #ifndef SIGNOUT_H
 #define SIGNOUT_H

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

 class SignOut : public QDialog
 {
     Q_OBJECT

 public:
     SignOut();
 private slots:
    void handleButton_8_1();
    void handleButton_8_2();
 private:
     void createMenu_8();
     void createHorizontalGroupBox_8();
	void loadStyleSheet_8();


     QMenuBar *menuBar_8;
     QGroupBox *horizontalGroupBox_8;
     QPushButton *confirm_signout;
     QPushButton *cancel_signout;
     QMenu *fileMenu_8;
     QAction *exitAction_8;
 	QLabel *sign_out_label;
 };




 #endif

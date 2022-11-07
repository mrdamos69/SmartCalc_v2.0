/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_tch;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_sub;
    QPushButton *pushButton_mult;
    QPushButton *pushButton_result;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_0;
    QPushButton *pushButton_1;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_div;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_R;
    QPushButton *pushButton_L;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_log;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_x;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_asin;
    QLineEdit *lineEdit;
    QPushButton *pushButton_graph;
    QPushButton *pushButton_sin_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_credit_calc;
    QPushButton *pushButton_graph_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName(QString::fromUtf8("View"));
        View->setEnabled(true);
        View->resize(709, 482);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(View->sizePolicy().hasHeightForWidth());
        View->setSizePolicy(sizePolicy);
        View->setMinimumSize(QSize(709, 482));
        View->setMaximumSize(QSize(709, 482));
        View->setSizeIncrement(QSize(0, -1));
        View->setBaseSize(QSize(-1, 0));
        View->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color:rgb(32, 33, 36);\n"
"}"));
        centralwidget = new QWidget(View);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(709, 482));
        centralwidget->setMaximumSize(QSize(709, 482));
        centralwidget->setMouseTracking(false);
        centralwidget->setTabletTracking(false);
        pushButton_tch = new QPushButton(centralwidget);
        pushButton_tch->setObjectName(QString::fromUtf8("pushButton_tch"));
        pushButton_tch->setGeometry(QRect(610, 330, 91, 51));
        QFont font;
        font.setPointSize(20);
        pushButton_tch->setFont(font);
        pushButton_tch->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setGeometry(QRect(610, 270, 91, 51));
        pushButton_plus->setFont(font);
        pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_sub = new QPushButton(centralwidget);
        pushButton_sub->setObjectName(QString::fromUtf8("pushButton_sub"));
        pushButton_sub->setGeometry(QRect(610, 210, 91, 51));
        pushButton_sub->setFont(font);
        pushButton_sub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_mult = new QPushButton(centralwidget);
        pushButton_mult->setObjectName(QString::fromUtf8("pushButton_mult"));
        pushButton_mult->setGeometry(QRect(610, 150, 91, 51));
        pushButton_mult->setFont(font);
        pushButton_mult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_result = new QPushButton(centralwidget);
        pushButton_result->setObjectName(QString::fromUtf8("pushButton_result"));
        pushButton_result->setGeometry(QRect(410, 330, 191, 51));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        pushButton_result->setFont(font1);
        pushButton_result->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:rgb(147, 179, 242);\n"
"  	color:rgb(32, 33, 36); \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #87CEEB, stop: 1 #00BFFF);\n"
"}\n"
""));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(510, 270, 91, 51));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:rgb(61, 64, 67);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #696969, stop: 1 #2F4F4F);\n"
"}\n"
""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 270, 91, 51));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:rgb(61, 64, 67);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #696969, stop: 1 #2F4F4F);\n"
"}\n"
""));
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(310, 330, 91, 51));
        pushButton_0->setFont(font);
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:rgb(61, 64, 67);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #696969, stop: 1 #2F4F4F);\n"
"}\n"
""));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(310, 270, 91, 51));
        pushButton_1->setFont(font);
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:rgb(61, 64, 67);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #696969, stop: 1 #2F4F4F);\n"
"}\n"
""));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(410, 210, 91, 51));
        pushButton_5->setFont(font);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:rgb(61, 64, 67);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #696969, stop: 1 #2F4F4F);\n"
"}\n"
""));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(310, 210, 91, 51));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:rgb(61, 64, 67);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #696969, stop: 1 #2F4F4F);\n"
"}\n"
""));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(510, 210, 91, 51));
        pushButton_6->setFont(font);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:rgb(61, 64, 67);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #696969, stop: 1 #2F4F4F);\n"
"}\n"
""));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(410, 150, 91, 51));
        pushButton_8->setFont(font);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:rgb(61, 64, 67);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #696969, stop: 1 #2F4F4F);\n"
"}\n"
""));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(310, 150, 91, 51));
        pushButton_7->setFont(font);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:rgb(61, 64, 67);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #696969, stop: 1 #2F4F4F);\n"
"}\n"
""));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(510, 150, 91, 51));
        pushButton_9->setFont(font);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:rgb(61, 64, 67);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #696969, stop: 1 #2F4F4F);\n"
"}\n"
""));
        pushButton_div = new QPushButton(centralwidget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setGeometry(QRect(610, 90, 91, 51));
        pushButton_div->setFont(font);
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(510, 90, 91, 51));
        pushButton_mod->setFont(font);
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_R = new QPushButton(centralwidget);
        pushButton_R->setObjectName(QString::fromUtf8("pushButton_R"));
        pushButton_R->setGeometry(QRect(410, 90, 91, 51));
        pushButton_R->setFont(font);
        pushButton_R->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_L = new QPushButton(centralwidget);
        pushButton_L->setObjectName(QString::fromUtf8("pushButton_L"));
        pushButton_L->setGeometry(QRect(310, 90, 91, 51));
        pushButton_L->setFont(font);
        pushButton_L->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_acos = new QPushButton(centralwidget);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setGeometry(QRect(110, 210, 91, 51));
        pushButton_acos->setFont(font);
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_sin = new QPushButton(centralwidget);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setGeometry(QRect(10, 150, 91, 51));
        pushButton_sin->setFont(font);
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setGeometry(QRect(210, 270, 91, 51));
        pushButton_sqrt->setFont(font);
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_log = new QPushButton(centralwidget);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setGeometry(QRect(210, 210, 91, 51));
        pushButton_log->setFont(font);
        pushButton_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_pow = new QPushButton(centralwidget);
        pushButton_pow->setObjectName(QString::fromUtf8("pushButton_pow"));
        pushButton_pow->setGeometry(QRect(10, 330, 91, 51));
        pushButton_pow->setFont(font);
        pushButton_pow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_ln = new QPushButton(centralwidget);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setGeometry(QRect(210, 150, 91, 51));
        pushButton_ln->setFont(font);
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_tan = new QPushButton(centralwidget);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setGeometry(QRect(10, 270, 91, 51));
        pushButton_tan->setFont(font);
        pushButton_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_cos = new QPushButton(centralwidget);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setGeometry(QRect(10, 210, 91, 51));
        pushButton_cos->setFont(font);
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_x = new QPushButton(centralwidget);
        pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
        pushButton_x->setGeometry(QRect(210, 90, 91, 51));
        pushButton_x->setFont(font);
        pushButton_x->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_atan = new QPushButton(centralwidget);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setGeometry(QRect(110, 270, 91, 51));
        pushButton_atan->setFont(font);
        pushButton_atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_asin = new QPushButton(centralwidget);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setGeometry(QRect(110, 150, 91, 51));
        pushButton_asin->setFont(font);
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 0, 691, 81));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Kefa")});
        font2.setPointSize(36);
        lineEdit->setFont(font2);
        lineEdit->setTabletTracking(true);
        lineEdit->setLayoutDirection(Qt::LeftToRight);
        lineEdit->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  	qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"}"));
        lineEdit->setMaxLength(255);
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);
        pushButton_graph = new QPushButton(centralwidget);
        pushButton_graph->setObjectName(QString::fromUtf8("pushButton_graph"));
        pushButton_graph->setGeometry(QRect(110, 330, 191, 51));
        pushButton_graph->setFont(font);
        pushButton_graph->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_sin_2 = new QPushButton(centralwidget);
        pushButton_sin_2->setObjectName(QString::fromUtf8("pushButton_sin_2"));
        pushButton_sin_2->setGeometry(QRect(10, 90, 91, 51));
        pushButton_sin_2->setFont(font);
        pushButton_sin_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 90, 91, 51));
        lineEdit_2->setFont(font);
        lineEdit_2->setStyleSheet(QString::fromUtf8("\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"\n"
""));
        lineEdit_2->setAlignment(Qt::AlignCenter);
        pushButton_credit_calc = new QPushButton(centralwidget);
        pushButton_credit_calc->setObjectName(QString::fromUtf8("pushButton_credit_calc"));
        pushButton_credit_calc->setGeometry(QRect(10, 390, 341, 71));
        pushButton_credit_calc->setFont(font);
        pushButton_credit_calc->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        pushButton_graph_3 = new QPushButton(centralwidget);
        pushButton_graph_3->setObjectName(QString::fromUtf8("pushButton_graph_3"));
        pushButton_graph_3->setGeometry(QRect(360, 390, 341, 71));
        pushButton_graph_3->setFont(font);
        pushButton_graph_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(96, 99, 103);\n"
"  	color: white; \n"
"	border-radius: 7px;\n"
"}\n"
"QPushButton:pressed {\n"
"    	border: 1px solid  gray;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #A9A9A9, stop: 1 #808080);\n"
"}"));
        View->setCentralWidget(centralwidget);
        menubar = new QMenuBar(View);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 709, 17));
        View->setMenuBar(menubar);
        statusbar = new QStatusBar(View);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        View->setStatusBar(statusbar);

        retranslateUi(View);

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        View->setWindowTitle(QCoreApplication::translate("View", "s21_smart_calc_cpp", nullptr));
        pushButton_tch->setText(QCoreApplication::translate("View", ".", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("View", "+", nullptr));
        pushButton_sub->setText(QCoreApplication::translate("View", "-", nullptr));
        pushButton_mult->setText(QCoreApplication::translate("View", "x", nullptr));
        pushButton_result->setText(QCoreApplication::translate("View", "=", nullptr));
        pushButton_3->setText(QCoreApplication::translate("View", "3", nullptr));
        pushButton_2->setText(QCoreApplication::translate("View", "2", nullptr));
        pushButton_0->setText(QCoreApplication::translate("View", "0", nullptr));
        pushButton_1->setText(QCoreApplication::translate("View", "1", nullptr));
        pushButton_5->setText(QCoreApplication::translate("View", "5", nullptr));
        pushButton_4->setText(QCoreApplication::translate("View", "4", nullptr));
        pushButton_6->setText(QCoreApplication::translate("View", "6", nullptr));
        pushButton_8->setText(QCoreApplication::translate("View", "8", nullptr));
        pushButton_7->setText(QCoreApplication::translate("View", "7", nullptr));
        pushButton_9->setText(QCoreApplication::translate("View", "9", nullptr));
        pushButton_div->setText(QCoreApplication::translate("View", "/", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("View", "%", nullptr));
        pushButton_R->setText(QCoreApplication::translate("View", ")", nullptr));
        pushButton_L->setText(QCoreApplication::translate("View", "(", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("View", "acos", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("View", "sin", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("View", "\342\210\232", nullptr));
        pushButton_log->setText(QCoreApplication::translate("View", "log", nullptr));
        pushButton_pow->setText(QCoreApplication::translate("View", "x^y", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("View", "ln", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("View", "tan", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("View", "cos", nullptr));
        pushButton_x->setText(QCoreApplication::translate("View", "= x", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("View", "atan", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("View", "asin", nullptr));
        lineEdit->setText(QString());
        pushButton_graph->setText(QCoreApplication::translate("View", "graph", nullptr));
        pushButton_sin_2->setText(QCoreApplication::translate("View", "C", nullptr));
        lineEdit_2->setText(QString());
        pushButton_credit_calc->setText(QCoreApplication::translate("View", "credit calc", nullptr));
        pushButton_graph_3->setText(QCoreApplication::translate("View", "deposit calc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H

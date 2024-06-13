/********************************************************************************
** Form generated from reading UI file 'xingyunwin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XINGYUNWIN_H
#define UI_XINGYUNWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XingyunWin
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *winHWID;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *winYLE;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *winHLE;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *winXLE;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *winWLE;
    QTextEdit *textEdit;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *XingyunWin)
    {
        if (XingyunWin->objectName().isEmpty())
            XingyunWin->setObjectName(QString::fromUtf8("XingyunWin"));
        XingyunWin->resize(800, 600);
        centralwidget = new QWidget(XingyunWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 10, 80, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 130, 80, 23));
        winHWID = new QLineEdit(centralwidget);
        winHWID->setObjectName(QString::fromUtf8("winHWID"));
        winHWID->setGeometry(QRect(170, 10, 113, 23));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(220, 50, 111, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        winYLE = new QLineEdit(layoutWidget);
        winYLE->setObjectName(QString::fromUtf8("winYLE"));

        horizontalLayout_2->addWidget(winYLE);

        layoutWidget_3 = new QWidget(centralwidget);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(220, 80, 111, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        winHLE = new QLineEdit(layoutWidget_3);
        winHLE->setObjectName(QString::fromUtf8("winHLE"));

        horizontalLayout_4->addWidget(winHLE);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(100, 50, 111, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        winXLE = new QLineEdit(layoutWidget_2);
        winXLE->setObjectName(QString::fromUtf8("winXLE"));

        horizontalLayout->addWidget(winXLE);

        layoutWidget_4 = new QWidget(centralwidget);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(100, 80, 111, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        winWLE = new QLineEdit(layoutWidget_4);
        winWLE->setObjectName(QString::fromUtf8("winWLE"));

        horizontalLayout_3->addWidget(winWLE);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 160, 761, 391));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(340, 10, 101, 23));
        XingyunWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(XingyunWin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        XingyunWin->setMenuBar(menubar);
        statusbar = new QStatusBar(XingyunWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        XingyunWin->setStatusBar(statusbar);

        retranslateUi(XingyunWin);

        QMetaObject::connectSlotsByName(XingyunWin);
    } // setupUi

    void retranslateUi(QMainWindow *XingyunWin)
    {
        XingyunWin->setWindowTitle(QCoreApplication::translate("XingyunWin", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("XingyunWin", "\346\263\250\345\206\214\347\252\227\345\217\243", nullptr));
        pushButton_2->setText(QCoreApplication::translate("XingyunWin", "\345\274\200\345\247\213\346\212\275", nullptr));
        label_2->setText(QCoreApplication::translate("XingyunWin", "Y", nullptr));
        label_4->setText(QCoreApplication::translate("XingyunWin", "H", nullptr));
        label->setText(QCoreApplication::translate("XingyunWin", "X", nullptr));
        label_3->setText(QCoreApplication::translate("XingyunWin", "W", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("XingyunWin", "900*600", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("XingyunWin", "1600", nullptr));

    } // retranslateUi

};

namespace Ui {
    class XingyunWin: public Ui_XingyunWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XINGYUNWIN_H

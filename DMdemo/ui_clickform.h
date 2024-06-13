/********************************************************************************
** Form generated from reading UI file 'clickform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLICKFORM_H
#define UI_CLICKFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClickForm
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *winHLE;
    QCheckBox *apCheck;
    QPushButton *setEnd;
    QPushButton *pushButton_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *winWLE;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *mouseDely;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *winYLE;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *winXLE;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *checkDely;
    QLineEdit *winHWID;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *waitDely;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *apbuzuLe;
    QWidget *page_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QTextEdit *textEdit;
    QPushButton *stopBT;

    void setupUi(QWidget *ClickForm)
    {
        if (ClickForm->objectName().isEmpty())
            ClickForm->setObjectName(QString::fromUtf8("ClickForm"));
        ClickForm->resize(368, 558);
        stackedWidget = new QStackedWidget(ClickForm);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(9, 9, 361, 540));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_3 = new QGridLayout(page);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_3->addWidget(pushButton_3, 9, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        winHLE = new QLineEdit(page);
        winHLE->setObjectName(QString::fromUtf8("winHLE"));

        horizontalLayout_4->addWidget(winHLE);


        gridLayout_3->addLayout(horizontalLayout_4, 1, 1, 1, 2);

        apCheck = new QCheckBox(page);
        apCheck->setObjectName(QString::fromUtf8("apCheck"));

        gridLayout_3->addWidget(apCheck, 7, 0, 1, 1);

        setEnd = new QPushButton(page);
        setEnd->setObjectName(QString::fromUtf8("setEnd"));

        gridLayout_3->addWidget(setEnd, 9, 2, 1, 1);

        pushButton_5 = new QPushButton(page);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout_3->addWidget(pushButton_5, 9, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        winWLE = new QLineEdit(page);
        winWLE->setObjectName(QString::fromUtf8("winWLE"));

        horizontalLayout_3->addWidget(winWLE);


        gridLayout_3->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        mouseDely = new QLineEdit(page);
        mouseDely->setObjectName(QString::fromUtf8("mouseDely"));

        horizontalLayout_7->addWidget(mouseDely);


        gridLayout_3->addLayout(horizontalLayout_7, 5, 0, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        winYLE = new QLineEdit(page);
        winYLE->setObjectName(QString::fromUtf8("winYLE"));

        horizontalLayout_2->addWidget(winYLE);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 1, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        winXLE = new QLineEdit(page);
        winXLE->setObjectName(QString::fromUtf8("winXLE"));

        horizontalLayout->addWidget(winXLE);


        gridLayout_3->addLayout(horizontalLayout, 2, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        checkDely = new QLineEdit(page);
        checkDely->setObjectName(QString::fromUtf8("checkDely"));

        horizontalLayout_5->addWidget(checkDely);


        gridLayout_3->addLayout(horizontalLayout_5, 3, 0, 1, 3);

        winHWID = new QLineEdit(page);
        winHWID->setObjectName(QString::fromUtf8("winHWID"));

        gridLayout_3->addWidget(winHWID, 0, 1, 1, 2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        waitDely = new QLineEdit(page);
        waitDely->setObjectName(QString::fromUtf8("waitDely"));

        horizontalLayout_6->addWidget(waitDely);


        gridLayout_3->addLayout(horizontalLayout_6, 4, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 248, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 8, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(page);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        apbuzuLe = new QLineEdit(page);
        apbuzuLe->setObjectName(QString::fromUtf8("apbuzuLe"));

        horizontalLayout_8->addWidget(apbuzuLe);


        gridLayout_3->addLayout(horizontalLayout_8, 6, 0, 1, 3);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout = new QGridLayout(page_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 0, 1, 2);

        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 2);

        pushButton_6 = new QPushButton(page_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 0, 1, 2);

        textEdit = new QTextEdit(page_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 4, 0, 1, 2);

        stopBT = new QPushButton(page_2);
        stopBT->setObjectName(QString::fromUtf8("stopBT"));

        gridLayout->addWidget(stopBT, 3, 0, 1, 2);

        stackedWidget->addWidget(page_2);

        retranslateUi(ClickForm);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClickForm);
    } // setupUi

    void retranslateUi(QWidget *ClickForm)
    {
        ClickForm->setWindowTitle(QCoreApplication::translate("ClickForm", "Form", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ClickForm", "\346\224\276\345\274\203", nullptr));
        label_4->setText(QCoreApplication::translate("ClickForm", "H", nullptr));
        apCheck->setText(QCoreApplication::translate("ClickForm", "\344\275\277\347\224\250ap\350\215\257", nullptr));
        setEnd->setText(QCoreApplication::translate("ClickForm", "\350\256\276\345\256\232\345\256\214\346\257\225", nullptr));
        pushButton_5->setText(QCoreApplication::translate("ClickForm", "\346\265\213\350\257\225\347\211\251\345\223\201", nullptr));
        label_3->setText(QCoreApplication::translate("ClickForm", "W", nullptr));
        pushButton->setText(QCoreApplication::translate("ClickForm", "\346\224\276\345\234\250\347\252\227\345\217\243\344\270\2122\347\247\222\346\235\245\350\216\267\345\217\226\347\252\227\345\217\243\345\217\245\346\237\204", nullptr));
        label_7->setText(QCoreApplication::translate("ClickForm", "\351\274\240\346\240\207\347\202\271\345\207\273\345\220\216\347\255\211\345\276\205\346\227\266\351\227\264\345\206\215\345\201\232\344\270\213\346\255\245\345\212\250\344\275\234", nullptr));
        mouseDely->setText(QCoreApplication::translate("ClickForm", "200", nullptr));
        label_2->setText(QCoreApplication::translate("ClickForm", "Y", nullptr));
        label->setText(QCoreApplication::translate("ClickForm", "X", nullptr));
        label_5->setText(QCoreApplication::translate("ClickForm", "\346\243\200\346\265\213\345\244\261\350\264\245\346\227\266\347\255\211\345\276\205\346\227\266\351\227\264\345\220\216\345\206\215\346\254\241\346\243\200\346\265\213", nullptr));
        checkDely->setText(QCoreApplication::translate("ClickForm", "1800", nullptr));
        winHWID->setText(QString());
        label_6->setText(QCoreApplication::translate("ClickForm", "\346\243\200\346\265\213\346\210\220\345\212\237\345\220\216\347\255\211\345\276\205\346\227\266\351\227\264\345\220\216\345\260\206\351\274\240\346\240\207\347\247\273\350\277\207\345\216\273\347\202\271\345\207\273", nullptr));
        waitDely->setText(QCoreApplication::translate("ClickForm", "2200", nullptr));
        label_8->setText(QCoreApplication::translate("ClickForm", "\347\255\211\345\276\205AP\344\270\215\350\266\263\347\225\214\351\235\242\345\207\272\347\216\260", nullptr));
        apbuzuLe->setText(QCoreApplication::translate("ClickForm", "7000", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ClickForm", "\344\273\216\351\200\211\345\205\263\345\215\241\345\274\200\345\247\213", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ClickForm", "\344\273\216\350\207\252\345\212\250\345\206\215\346\210\230\345\274\200\345\247\213", nullptr));
        pushButton_6->setText(QCoreApplication::translate("ClickForm", "\344\273\216\346\243\200\346\265\213\346\270\270\346\210\217\347\211\251\345\223\201\345\274\200\345\247\213", nullptr));
        stopBT->setText(QCoreApplication::translate("ClickForm", "\345\201\234\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClickForm: public Ui_ClickForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLICKFORM_H

/********************************************************************************
** Form generated from reading UI file 'look.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOOK_H
#define UI_LOOK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_look
{
public:
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_time;
    QPushButton *pushButton_screenshot;

    void setupUi(QDialog *look)
    {
        if (look->objectName().isEmpty())
            look->setObjectName(QString::fromUtf8("look"));
        look->resize(800, 480);
        look->setStyleSheet(QString::fromUtf8("#look{background-image: url(:/new/prefix1/tv.png);}"));
        pushButton_2 = new QPushButton(look);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 420, 121, 51));
        label = new QLabel(look);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 120, 320, 240));
        label_time = new QLabel(look);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(570, 10, 221, 21));
        QFont font;
        font.setPointSize(16);
        label_time->setFont(font);
        pushButton_screenshot = new QPushButton(look);
        pushButton_screenshot->setObjectName(QString::fromUtf8("pushButton_screenshot"));
        pushButton_screenshot->setGeometry(QRect(640, 140, 111, 51));

        retranslateUi(look);

        QMetaObject::connectSlotsByName(look);
    } // setupUi

    void retranslateUi(QDialog *look)
    {
        look->setWindowTitle(QApplication::translate("look", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("look", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("look", "shipin", 0, QApplication::UnicodeUTF8));
        label_time->setText(QApplication::translate("look", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton_screenshot->setText(QApplication::translate("look", "\346\210\252\345\233\276", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class look: public Ui_look {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOOK_H

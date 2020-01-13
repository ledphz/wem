/********************************************************************************
** Form generated from reading UI file 'feel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEEL_H
#define UI_FEEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_feel
{
public:
    QPushButton *pushButton;
    QLabel *label_tmpe;
    QLabel *label_hum;
    QLabel *label_nh3;
    QLabel *label_time;

    void setupUi(QDialog *feel)
    {
        if (feel->objectName().isEmpty())
            feel->setObjectName(QString::fromUtf8("feel"));
        feel->resize(800, 480);
        feel->setStyleSheet(QString::fromUtf8("#feel{background-image: url(:/new/prefix1/water_2.png);}"));
        pushButton = new QPushButton(feel);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(640, 420, 111, 41));
        label_tmpe = new QLabel(feel);
        label_tmpe->setObjectName(QString::fromUtf8("label_tmpe"));
        label_tmpe->setGeometry(QRect(40, 110, 401, 251));
        QFont font;
        font.setPointSize(130);
        label_tmpe->setFont(font);
        label_tmpe->setStyleSheet(QString::fromUtf8(""));
        label_tmpe->setAlignment(Qt::AlignCenter);
        label_hum = new QLabel(feel);
        label_hum->setObjectName(QString::fromUtf8("label_hum"));
        label_hum->setGeometry(QRect(510, 100, 251, 111));
        QFont font1;
        font1.setPointSize(72);
        label_hum->setFont(font1);
        label_hum->setStyleSheet(QString::fromUtf8(""));
        label_hum->setAlignment(Qt::AlignCenter);
        label_nh3 = new QLabel(feel);
        label_nh3->setObjectName(QString::fromUtf8("label_nh3"));
        label_nh3->setGeometry(QRect(510, 290, 251, 111));
        label_nh3->setFont(font1);
        label_nh3->setStyleSheet(QString::fromUtf8(""));
        label_nh3->setTextFormat(Qt::AutoText);
        label_nh3->setAlignment(Qt::AlignCenter);
        label_time = new QLabel(feel);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(570, 10, 211, 21));
        QFont font2;
        font2.setPointSize(16);
        label_time->setFont(font2);

        retranslateUi(feel);

        QMetaObject::connectSlotsByName(feel);
    } // setupUi

    void retranslateUi(QDialog *feel)
    {
        feel->setWindowTitle(QApplication::translate("feel", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("feel", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label_tmpe->setText(QApplication::translate("feel", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_hum->setText(QApplication::translate("feel", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_nh3->setText(QApplication::translate("feel", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class feel: public Ui_feel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEEL_H

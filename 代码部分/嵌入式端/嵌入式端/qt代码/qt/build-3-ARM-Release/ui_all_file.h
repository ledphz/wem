/********************************************************************************
** Form generated from reading UI file 'all_file.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALL_FILE_H
#define UI_ALL_FILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_all_file
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_time;

    void setupUi(QDialog *all_file)
    {
        if (all_file->objectName().isEmpty())
            all_file->setObjectName(QString::fromUtf8("all_file"));
        all_file->resize(800, 480);
        all_file->setStyleSheet(QString::fromUtf8("#all_file{background-image: url(:/new/prefix1/ml1.png);}"));
        pushButton = new QPushButton(all_file);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(600, 70, 150, 50));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        pushButton_2 = new QPushButton(all_file);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(600, 270, 150, 50));
        pushButton_2->setStyleSheet(QString::fromUtf8(""));
        pushButton_3 = new QPushButton(all_file);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(600, 170, 150, 50));
        pushButton_3->setStyleSheet(QString::fromUtf8(""));
        pushButton_4 = new QPushButton(all_file);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(600, 370, 150, 50));
        pushButton_4->setStyleSheet(QString::fromUtf8(""));
        pushButton_5 = new QPushButton(all_file);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 10, 121, 51));
        label_time = new QLabel(all_file);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(580, 10, 211, 31));
        QFont font;
        font.setPointSize(16);
        label_time->setFont(font);

        retranslateUi(all_file);

        QMetaObject::connectSlotsByName(all_file);
    } // setupUi

    void retranslateUi(QDialog *all_file)
    {
        all_file->setWindowTitle(QApplication::translate("all_file", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("all_file", "\350\247\206\351\242\221\347\233\221\346\216\247", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("all_file", "\346\266\210\346\201\257\346\227\245\345\277\227", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("all_file", "\347\216\257\345\242\203\347\233\221\346\265\213", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("all_file", "\345\216\206\345\217\262\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("all_file", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        label_time->setText(QApplication::translate("all_file", "<html><head/><body><p><span style=\" font-size:22pt;\">TextLabel</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class all_file: public Ui_all_file {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALL_FILE_H

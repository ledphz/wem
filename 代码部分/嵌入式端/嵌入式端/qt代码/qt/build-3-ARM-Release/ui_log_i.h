/********************************************************************************
** Form generated from reading UI file 'log_i.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_I_H
#define UI_LOG_I_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_log_i
{
public:
    QPushButton *pushButton;
    QComboBox *comboBox_grade;
    QPushButton *pushButton_query;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QDialog *log_i)
    {
        if (log_i->objectName().isEmpty())
            log_i->setObjectName(QString::fromUtf8("log_i"));
        log_i->resize(800, 480);
        log_i->setStyleSheet(QString::fromUtf8("#log_i{background-image: url(:/new/prefix1/log_1.png);}"));
        pushButton = new QPushButton(log_i);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(660, 420, 121, 41));
        comboBox_grade = new QComboBox(log_i);
        comboBox_grade->setObjectName(QString::fromUtf8("comboBox_grade"));
        comboBox_grade->setGeometry(QRect(210, 10, 161, 40));
        comboBox_grade->setMinimumSize(QSize(30, 40));
        comboBox_grade->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
        comboBox_grade->setIconSize(QSize(16, 16));
        pushButton_query = new QPushButton(log_i);
        pushButton_query->setObjectName(QString::fromUtf8("pushButton_query"));
        pushButton_query->setGeometry(QRect(650, 80, 131, 61));
        textEdit = new QTextEdit(log_i);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 69, 600, 381));
        textEdit->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(log_i);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 161, 41));

        retranslateUi(log_i);

        QMetaObject::connectSlotsByName(log_i);
    } // setupUi

    void retranslateUi(QDialog *log_i)
    {
        log_i->setWindowTitle(QApplication::translate("log_i", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("log_i", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        pushButton_query->setText(QApplication::translate("log_i", "\347\241\256\350\256\244\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("log_i", "<html><head/><body><p><span style=\" font-size:18pt;\">\351\200\211\346\213\251\346\227\245\345\277\227\347\255\211\347\272\247</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class log_i: public Ui_log_i {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_I_H

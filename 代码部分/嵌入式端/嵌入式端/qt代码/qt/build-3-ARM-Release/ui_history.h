/********************************************************************************
** Form generated from reading UI file 'history.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORY_H
#define UI_HISTORY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_history
{
public:
    QPushButton *pushButton;
    QComboBox *comboBox_nhour;
    QLabel *label_3;
    QLabel *label_7;
    QComboBox *comboBox_fyear;
    QLabel *label_10;
    QComboBox *comboBox_nyear;
    QLabel *label_9;
    QPushButton *pushButton_query;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_8;
    QComboBox *comboBox_fhour;
    QLabel *label_4;
    QComboBox *comboBox_fday;
    QLabel *label_2;
    QLabel *label_count;
    QLabel *label_5;
    QComboBox *comboBox_nmon;
    QComboBox *comboBox_nday;
    QComboBox *comboBox_fmon;
    QTableWidget *tableWidget;
    QPushButton *pushButton_last;
    QPushButton *pushButton_next;
    QLabel *label_page;

    void setupUi(QDialog *history)
    {
        if (history->objectName().isEmpty())
            history->setObjectName(QString::fromUtf8("history"));
        history->resize(800, 480);
        history->setCursor(QCursor(Qt::IBeamCursor));
        history->setFocusPolicy(Qt::NoFocus);
        history->setStyleSheet(QString::fromUtf8("#history{background-image: url(:/new/prefix1/his.png);}"));
        pushButton = new QPushButton(history);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(660, 410, 111, 50));
        comboBox_nhour = new QComboBox(history);
        comboBox_nhour->setObjectName(QString::fromUtf8("comboBox_nhour"));
        comboBox_nhour->setGeometry(QRect(510, 90, 85, 50));
        comboBox_nhour->setMaxVisibleItems(6);
        label_3 = new QLabel(history);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 40, 31, 21));
        label_7 = new QLabel(history);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(230, 100, 21, 21));
        comboBox_fyear = new QComboBox(history);
        comboBox_fyear->setObjectName(QString::fromUtf8("comboBox_fyear"));
        comboBox_fyear->setGeometry(QRect(130, 30, 85, 50));
        comboBox_fyear->setStyleSheet(QString::fromUtf8("QComboBox QAbstractItemView::item { min-height: 80px;}"));
        comboBox_fyear->setMaxVisibleItems(6);
        label_10 = new QLabel(history);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(610, 90, 21, 31));
        comboBox_nyear = new QComboBox(history);
        comboBox_nyear->setObjectName(QString::fromUtf8("comboBox_nyear"));
        comboBox_nyear->setGeometry(QRect(130, 90, 85, 50));
        comboBox_nyear->setMaxVisibleItems(6);
        label_9 = new QLabel(history);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(480, 100, 21, 21));
        pushButton_query = new QPushButton(history);
        pushButton_query->setObjectName(QString::fromUtf8("pushButton_query"));
        pushButton_query->setGeometry(QRect(630, 140, 101, 50));
        label = new QLabel(history);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 101, 61));
        QFont font;
        font.setPointSize(26);
        label->setFont(font);
        label_6 = new QLabel(history);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(610, 40, 21, 31));
        label_8 = new QLabel(history);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(360, 100, 31, 31));
        comboBox_fhour = new QComboBox(history);
        comboBox_fhour->setObjectName(QString::fromUtf8("comboBox_fhour"));
        comboBox_fhour->setGeometry(QRect(510, 30, 85, 50));
        comboBox_fhour->setMaxVisibleItems(6);
        label_4 = new QLabel(history);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(360, 40, 31, 31));
        comboBox_fday = new QComboBox(history);
        comboBox_fday->setObjectName(QString::fromUtf8("comboBox_fday"));
        comboBox_fday->setGeometry(QRect(390, 30, 85, 50));
        comboBox_fday->setMaxVisibleItems(6);
        label_2 = new QLabel(history);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 90, 91, 41));
        label_count = new QLabel(history);
        label_count->setObjectName(QString::fromUtf8("label_count"));
        label_count->setGeometry(QRect(640, 220, 161, 31));
        label_5 = new QLabel(history);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(480, 40, 21, 21));
        comboBox_nmon = new QComboBox(history);
        comboBox_nmon->setObjectName(QString::fromUtf8("comboBox_nmon"));
        comboBox_nmon->setGeometry(QRect(260, 90, 85, 50));
        comboBox_nmon->setMaxVisibleItems(6);
        comboBox_nday = new QComboBox(history);
        comboBox_nday->setObjectName(QString::fromUtf8("comboBox_nday"));
        comboBox_nday->setGeometry(QRect(390, 90, 85, 50));
        comboBox_nday->setMaxVisibleItems(6);
        comboBox_fmon = new QComboBox(history);
        comboBox_fmon->setObjectName(QString::fromUtf8("comboBox_fmon"));
        comboBox_fmon->setGeometry(QRect(260, 30, 85, 50));
        comboBox_fmon->setMaxVisibleItems(6);
        tableWidget = new QTableWidget(history);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 160, 600, 290));
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        pushButton_last = new QPushButton(history);
        pushButton_last->setObjectName(QString::fromUtf8("pushButton_last"));
        pushButton_last->setGeometry(QRect(30, 400, 101, 41));
        pushButton_next = new QPushButton(history);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));
        pushButton_next->setGeometry(QRect(510, 400, 101, 41));
        label_page = new QLabel(history);
        label_page->setObjectName(QString::fromUtf8("label_page"));
        label_page->setGeometry(QRect(310, 410, 121, 31));

        retranslateUi(history);

        QMetaObject::connectSlotsByName(history);
    } // setupUi

    void retranslateUi(QDialog *history)
    {
        history->setWindowTitle(QApplication::translate("history", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("history", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("history", "<html><head/><body><p><span style=\" font-size:14pt;\">\345\271\264</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("history", "<html><head/><body><p><span style=\" font-size:14pt;\">\345\271\264</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("history", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\227\266</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("history", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\227\245</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_query->setText(QApplication::translate("history", "\347\241\256\345\256\232\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("history", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\345\274\200\345\247\213\346\227\266\351\227\264</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("history", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\227\266</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("history", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\234\210</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("history", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\234\210</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("history", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\347\273\223\346\235\237\346\227\266\351\227\264</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_count->setText(QApplication::translate("history", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\350\256\260\345\275\225\346\225\260\351\207\217:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("history", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\227\245</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_last->setText(QApplication::translate("history", "\344\270\212\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        pushButton_next->setText(QApplication::translate("history", "\344\270\213\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        label_page->setText(QApplication::translate("history", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">0\351\241\265</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class history: public Ui_history {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_H

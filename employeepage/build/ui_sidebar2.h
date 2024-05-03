/********************************************************************************
** Form generated from reading UI file 'sidebar2.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDEBAR2_H
#define UI_SIDEBAR2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sidebar2
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *label;
    QLabel *label_5;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_6;
    QMenuBar *menubar;

    void setupUi(QMainWindow *sidebar2)
    {
        if (sidebar2->objectName().isEmpty())
            sidebar2->setObjectName("sidebar2");
        sidebar2->resize(800, 600);
        centralwidget = new QWidget(sidebar2);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 81, 600));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8("background-color: #f9f9f9; color: #333333; border-radius: 20px;"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 100, 40, 40));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/shopping-bag.svg")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(6, 11, 71, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font.setPointSize(17);
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: #28A4A6;"));
        label_5->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 90, 60, 60));
        pushButton->raise();
        label->raise();
        label_5->raise();
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 520, 40, 40));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/new/settings.svg")));
        label_4->setScaledContents(true);
        label_4->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 300, 40, 40));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/new/user.svg")));
        label_3->setScaledContents(true);
        label_3->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 200, 40, 40));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/pie-chart.svg")));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 190, 60, 60));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 290, 60, 60));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 510, 60, 60));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(380, 180, 49, 16));
        sidebar2->setCentralWidget(centralwidget);
        pushButton_4->raise();
        pushButton_3->raise();
        pushButton_2->raise();
        widget->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_6->raise();
        menubar = new QMenuBar(sidebar2);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        sidebar2->setMenuBar(menubar);

        retranslateUi(sidebar2);

        QMetaObject::connectSlotsByName(sidebar2);
    } // setupUi

    void retranslateUi(QMainWindow *sidebar2)
    {
        sidebar2->setWindowTitle(QCoreApplication::translate("sidebar2", "sidebar2", nullptr));
        label->setText(QString());
        label_5->setText(QCoreApplication::translate("sidebar2", "POS", nullptr));
        pushButton->setText(QString());
        label_4->setText(QString());
        label_3->setText(QString());
        label_2->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        label_6->setText(QCoreApplication::translate("sidebar2", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sidebar2: public Ui_sidebar2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEBAR2_H

#pragma once

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

#include <string>
#include <iostream>
#include <fstream>

QT_BEGIN_NAMESPACE

class QCalculator: public QMainWindow
{
    Q_OBJECT
public:
    QWidget* centralwidget;
    QPushButton* pushButton;
    QPushButton* pushButton_2;
    QPushButton* pushButton_3;
    QPushButton* pushButton_4;
    QPushButton* pushButton_5;
    QPushButton* pushButton_6;
    QPushButton* pushButton_7;
    QPushButton* pushButton_8;
    QPushButton* pushButton_9;
    QPushButton* pushButton_10;
    QPushButton* pushButton_11;
    QPushButton* pushButton_12;
    QPushButton* pushButton_13;
    QPushButton* pushButton_14;
    QPushButton* pushButton_15;
    QPushButton* pushButton_16;
    QListWidget* listWidget;
    QMenuBar* menubar;
    QStatusBar* statusbar;
private:
    std::string operation;
    int number_a;
    int number_b;
    int numPosition;
    int result;

    std::string Line;
    QListWidgetItem newItem;

public:
    void setupUi(QMainWindow* MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(749, 583);
        QFont font;
        font.setPointSize(16);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 400, 101, 91));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 400, 101, 91));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(160, 290, 101, 91));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 290, 101, 91));
        pushButton_4->setIconSize(QSize(16, 16));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(290, 400, 101, 91));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(40, 30, 51, 41));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(110, 30, 51, 41));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(180, 30, 51, 41));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(40, 90, 51, 41));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(110, 90, 51, 41));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(180, 90, 51, 41));
        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(40, 150, 51, 41));
        pushButton_13 = new QPushButton(centralwidget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(110, 150, 51, 41));
        pushButton_14 = new QPushButton(centralwidget);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(180, 150, 51, 41));
        pushButton_15 = new QPushButton(centralwidget);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setGeometry(QRect(110, 210, 51, 41));
        pushButton_16 = new QPushButton(centralwidget);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setGeometry(QRect(290, 290, 101, 91));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(440, 30, 256, 461));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 749, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        this->numPosition = 0;
        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow* MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "-", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "/", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "*", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "+", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "1", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "2", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "3", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "4", nullptr));
        pushButton_10->setText(QApplication::translate("MainWindow", "5", nullptr));
        pushButton_11->setText(QApplication::translate("MainWindow", "6", nullptr));
        pushButton_12->setText(QApplication::translate("MainWindow", "7", nullptr));
        pushButton_13->setText(QApplication::translate("MainWindow", "8", nullptr));
        pushButton_14->setText(QApplication::translate("MainWindow", "9", nullptr));
        pushButton_15->setText(QApplication::translate("MainWindow", "0", nullptr));
        pushButton_16->setText(QApplication::translate("MainWindow", "=", nullptr));

        
        newItem.setText("the result will be show here");
        listWidget->addItem(&newItem);

    } // retranslateUi

    void configureConnections() {
        //#QtCore.QObject.connect(self.pushButton, QtCore.SIGNAL("clicked()"), self.minus_click)
        QObject::connect(this->pushButton, &QPushButton::clicked, this, &QCalculator::minus_click);
        QObject::connect(this->pushButton_2, &QPushButton::clicked, this, &QCalculator::divide_click);
        QObject::connect(this->pushButton_3, &QPushButton::clicked, this, &QCalculator::multiply_click);
        QObject::connect(this->pushButton_4, &QPushButton::clicked, this, &QCalculator::plus_click);
        QObject::connect(this->pushButton_5, &QPushButton::clicked, this, &QCalculator::clear_click);
        QObject::connect(this->pushButton_6, &QPushButton::clicked, this, &QCalculator::num1_click);
        QObject::connect(this->pushButton_7, &QPushButton::clicked, this, &QCalculator::num2_click);
        QObject::connect(this->pushButton_8, &QPushButton::clicked, this, &QCalculator::num3_click);
        QObject::connect(this->pushButton_9, &QPushButton::clicked, this, &QCalculator::num4_click);
        QObject::connect(this->pushButton_10, &QPushButton::clicked, this, &QCalculator::num5_click);
        QObject::connect(this->pushButton_11, &QPushButton::clicked, this, &QCalculator::num6_click);
        QObject::connect(this->pushButton_12, &QPushButton::clicked, this, &QCalculator::num7_click);
        QObject::connect(this->pushButton_13, &QPushButton::clicked, this, &QCalculator::num8_click);
        QObject::connect(this->pushButton_14, &QPushButton::clicked, this, &QCalculator::num9_click);
        QObject::connect(this->pushButton_15, &QPushButton::clicked, this, &QCalculator::num0_click);
        QObject::connect(this->pushButton_16, &QPushButton::clicked, this, &QCalculator::equal_click);
        
        /*this->pushButton->clicked.connect(minus_click);
        this->pushButton_2->clicked.connect(this->divide_click);
        this->pushButton_3->clicked.connect(this->multiply_click);
        this->pushButton_4->clicked.connect(this->plus_click);
        this->pushButton_5->clicked.connect(this->clear_click);
        this->pushButton_6->clicked.connect(this->num1_click);
        this->pushButton_7->clicked.connect(this->num2_click);
        this->pushButton_8->clicked.connect(this->num3_click);
        this->pushButton_9->clicked.connect(this->num4_click);
        this->pushButton_10->clicked.connect(this->num5_click);
        this->pushButton_11->clicked.connect(this->num6_click);
        this->pushButton_12->clicked.connect(this->num7_click);
        this->pushButton_13->clicked.connect(this->num8_click);
        this->pushButton_14->clicked.connect(this->num9_click);
        this->pushButton_15->clicked.connect(this->num0_click);
        this->pushButton_16->clicked.connect(this->equal_click);*/
    }

    void plus_click() {
        this->operation = "+";
        this->numPosition = 1;
        //this->listWidget.addItem(this->operation);
    }
    void minus_click() {
        this->operation = "-";
        this->numPosition = 1;
        //this->listWidget.addItem(this->operation);
    }
    void multiply_click() {
        this->operation = "*";
        this->numPosition = 1;
        //# .listWidget.addItem( .operation)
    }
    void divide_click() {
        this->operation = "/";
        this->numPosition = 1;
        //# .listWidget.addItem( .operation)
    }

    void clear_click() {
        newItem.setText(QString(" "));
        this->numPosition = 0;
    }

    void num1_click() {
        if (!this->numPosition)
            this->number_a = 1;
        else
            this->number_b = 1;
    }

    void num2_click() {
        if (!this->numPosition)
            this->number_a = 2;
        else
            this->number_b = 2;
    }

    void num3_click() {
        if (!this->numPosition)
            this->number_a = 3;
        else
            this->number_b = 3;
    }
    void num4_click() {
        if (!this->numPosition)
            this->number_a = 4;
        else
            this->number_b = 4;
    }

    void num5_click() {
        if (!this->numPosition)
            this->number_a = 5;
        else
            this->number_b = 5;
    }

    void num6_click() {
        if (!this->numPosition)
            this->number_a = 6;
        else
            this->number_b = 6;
    }
    
    void num7_click() {
        if (!this->numPosition)
            this->number_a = 7;
        else
            this->number_b = 7;
    }
    void num8_click() {
        if (!this->numPosition)
            this->number_a = 8;
        else
            this->number_b = 8;
    }
    void num9_click() {
        if (!this->numPosition)
            this->number_a = 9;
        else
            this->number_b = 9;
    }
    void num0_click() {
        if (!this->numPosition)
            this->number_a = 0;
        else
            this->number_b = 0;
    }
    void equal_click() {
        this->numPosition = 0;
        innerCalculation();
        Line = std::to_string(this->number_a) + " " + this->operation + " " + std::to_string(this->number_b) + " = " + std::to_string(this->result);
        //QListWidgetItem newItem(QString(Line.c_str()));
        newItem.setText(QString(Line.c_str()));
        
        std::ofstream outputfile("result.txt");
        outputfile << Line << std::endl;
        outputfile.close();

    }
private:
    void innerCalculation() {
        std::cout << "!!!";
        if (this->operation == "+")
            this->result = this->number_a + this->number_b;
        else if (this->operation == "-")
            this->result = this->number_a - this->number_b;
        else if (this->operation == "*")
            this->result = this->number_a * this->number_b;
            else if (this->operation == "/")
                if (this->number_b == 0)
                    this->result = 0;
                else
                    this->result = this->number_a / this->number_b;

    }
};

namespace Ui {
    class MainWindow : public QCalculator {};
} // namespace Ui

QT_END_NAMESPACE

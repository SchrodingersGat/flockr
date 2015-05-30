/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "FlockWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    FlockWidget *flockWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_10;
    QSlider *horizontalSlider_10;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_11;
    QSlider *horizontalSlider_11;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_8;
    QSlider *horizontalSlider_8;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_5;
    QSlider *attractionFactor;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_6;
    QSlider *distanceFactor;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSlider *speedFactor;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_9;
    QSlider *jitter;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QSlider *paranoia;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QSlider *aggression;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(896, 590);
        MainWindow->setMinimumSize(QSize(896, 590));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        flockWidget = new FlockWidget(centralWidget);
        flockWidget->setObjectName(QStringLiteral("flockWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(flockWidget->sizePolicy().hasHeightForWidth());
        flockWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(flockWidget, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_12->setFont(font);

        verticalLayout->addWidget(label_12);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_10->addWidget(label_13);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);

        horizontalSlider_10 = new QSlider(centralWidget);
        horizontalSlider_10->setObjectName(QStringLiteral("horizontalSlider_10"));
        horizontalSlider_10->setMinimumSize(QSize(200, 0));
        horizontalSlider_10->setMaximumSize(QSize(200, 16777215));
        horizontalSlider_10->setOrientation(Qt::Horizontal);
        horizontalSlider_10->setTickPosition(QSlider::TicksBelow);

        horizontalLayout_10->addWidget(horizontalSlider_10);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_11->addWidget(label_14);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);

        horizontalSlider_11 = new QSlider(centralWidget);
        horizontalSlider_11->setObjectName(QStringLiteral("horizontalSlider_11"));
        horizontalSlider_11->setMinimumSize(QSize(200, 0));
        horizontalSlider_11->setMaximumSize(QSize(200, 16777215));
        horizontalSlider_11->setOrientation(Qt::Horizontal);
        horizontalSlider_11->setTickPosition(QSlider::TicksBelow);

        horizontalLayout_11->addWidget(horizontalSlider_11);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_8->addWidget(label_10);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        horizontalSlider_8 = new QSlider(centralWidget);
        horizontalSlider_8->setObjectName(QStringLiteral("horizontalSlider_8"));
        horizontalSlider_8->setMinimumSize(QSize(200, 0));
        horizontalSlider_8->setMaximumSize(QSize(200, 16777215));
        horizontalSlider_8->setOrientation(Qt::Horizontal);
        horizontalSlider_8->setTickPosition(QSlider::TicksBelow);

        horizontalLayout_8->addWidget(horizontalSlider_8);


        verticalLayout->addLayout(horizontalLayout_8);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        verticalLayout->addWidget(label_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        attractionFactor = new QSlider(centralWidget);
        attractionFactor->setObjectName(QStringLiteral("attractionFactor"));
        attractionFactor->setMinimumSize(QSize(200, 0));
        attractionFactor->setMaximumSize(QSize(200, 16777215));
        attractionFactor->setOrientation(Qt::Horizontal);
        attractionFactor->setTickPosition(QSlider::TicksBelow);

        horizontalLayout_5->addWidget(attractionFactor);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        distanceFactor = new QSlider(centralWidget);
        distanceFactor->setObjectName(QStringLiteral("distanceFactor"));
        distanceFactor->setMinimumSize(QSize(200, 0));
        distanceFactor->setMaximumSize(QSize(200, 16777215));
        distanceFactor->setOrientation(Qt::Horizontal);
        distanceFactor->setTickPosition(QSlider::TicksBelow);

        horizontalLayout_6->addWidget(distanceFactor);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        speedFactor = new QSlider(centralWidget);
        speedFactor->setObjectName(QStringLiteral("speedFactor"));
        speedFactor->setMinimumSize(QSize(200, 0));
        speedFactor->setMaximumSize(QSize(200, 16777215));
        speedFactor->setOrientation(Qt::Horizontal);
        speedFactor->setTickPosition(QSlider::TicksBelow);

        horizontalLayout->addWidget(speedFactor);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_9->addWidget(label_11);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        jitter = new QSlider(centralWidget);
        jitter->setObjectName(QStringLiteral("jitter"));
        jitter->setMinimumSize(QSize(200, 0));
        jitter->setMaximumSize(QSize(200, 16777215));
        jitter->setOrientation(Qt::Horizontal);
        jitter->setTickPosition(QSlider::TicksBelow);

        horizontalLayout_9->addWidget(jitter);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        paranoia = new QSlider(centralWidget);
        paranoia->setObjectName(QStringLiteral("paranoia"));
        paranoia->setMinimumSize(QSize(200, 0));
        paranoia->setMaximumSize(QSize(200, 16777215));
        paranoia->setOrientation(Qt::Horizontal);
        paranoia->setTickPosition(QSlider::TicksBelow);

        horizontalLayout_3->addWidget(paranoia);


        verticalLayout->addLayout(horizontalLayout_3);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        verticalLayout->addWidget(label_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        aggression = new QSlider(centralWidget);
        aggression->setObjectName(QStringLiteral("aggression"));
        aggression->setMinimumSize(QSize(200, 0));
        aggression->setMaximumSize(QSize(200, 16777215));
        aggression->setOrientation(Qt::Horizontal);
        aggression->setTickPosition(QSlider::TicksBelow);

        horizontalLayout_2->addWidget(aggression);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 896, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_12->setText(QApplication::translate("MainWindow", "Global Settings", 0));
        label_13->setText(QApplication::translate("MainWindow", "Foes", 0));
        label_14->setText(QApplication::translate("MainWindow", "Friends", 0));
        label_10->setText(QApplication::translate("MainWindow", "Flocking", 0));
        label_7->setText(QApplication::translate("MainWindow", "Friend Settings", 0));
        label_5->setText(QApplication::translate("MainWindow", "Attraction", 0));
        label_6->setText(QApplication::translate("MainWindow", "Distance", 0));
        label->setText(QApplication::translate("MainWindow", "Speed Influence", 0));
        label_11->setText(QApplication::translate("MainWindow", "Jitter", 0));
        label_3->setText(QApplication::translate("MainWindow", "Paranoia", 0));
        label_8->setText(QApplication::translate("MainWindow", "Foe Settings", 0));
        label_2->setText(QApplication::translate("MainWindow", "Aggressiveness", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

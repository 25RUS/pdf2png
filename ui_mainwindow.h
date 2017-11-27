/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClose;
    QAction *actionAbout;
    QAction *actionLicense;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(491, 185);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionLicense = new QAction(MainWindow);
        actionLicense->setObjectName(QStringLiteral("actionLicense"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(430, 10, 41, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 50, 41, 31));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(70, 10, 351, 29));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 50, 351, 29));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 9, 55, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 54, 55, 21));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(160, 90, 181, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 491, 27));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionClose);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionLicense);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "pdf2png", Q_NULLPTR));
        actionClose->setText(QApplication::translate("MainWindow", "&Close", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        actionLicense->setText(QApplication::translate("MainWindow", "License", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "PDF file", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Out dir", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Convert to .png", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

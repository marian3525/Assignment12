/********************************************************************************
** Form generated from reading UI file 'ListWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTWINDOW_H
#define UI_LISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListWindow
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ListWindow)
    {
        if (ListWindow->objectName().isEmpty())
            ListWindow->setObjectName(QStringLiteral("ListWindow"));
        ListWindow->resize(400, 300);
        menuBar = new QMenuBar(ListWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ListWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ListWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ListWindow->addToolBar(mainToolBar);
        centralWidget = new QWidget(ListWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ListWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ListWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ListWindow->setStatusBar(statusBar);

        retranslateUi(ListWindow);

        QMetaObject::connectSlotsByName(ListWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ListWindow)
    {
        ListWindow->setWindowTitle(QApplication::translate("ListWindow", "ListWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListWindow: public Ui_ListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTWINDOW_H

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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListWindow
{
public:
    QWidget *centralWidget;
    QListView *list;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ListWindow)
    {
        if (ListWindow->objectName().isEmpty())
            ListWindow->setObjectName(QStringLiteral("ListWindow"));
        ListWindow->resize(436, 645);
        centralWidget = new QWidget(ListWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        list = new QListView(centralWidget);
        list->setObjectName(QStringLiteral("list"));
        list->setGeometry(QRect(0, 30, 421, 551));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 141, 16));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        ListWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ListWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 436, 25));
        ListWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ListWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ListWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ListWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ListWindow->setStatusBar(statusBar);

        retranslateUi(ListWindow);

        QMetaObject::connectSlotsByName(ListWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ListWindow)
    {
        ListWindow->setWindowTitle(QApplication::translate("ListWindow", "ListWindow", nullptr));
        label->setText(QApplication::translate("ListWindow", "Watchlist:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListWindow: public Ui_ListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTWINDOW_H

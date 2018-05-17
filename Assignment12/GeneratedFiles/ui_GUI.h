/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QAction *actionOutput_mode;
    QAction *actionVersion;
    QAction *actionUsage;
    QWidget *centralWidget;
    QListView *tutorialList;
    QListView *watchlist;
    QPushButton *exitButton;
    QPushButton *addToWatchlistButton;
    QPushButton *removeFromWatchlistButton;
    QPushButton *watchButton;
    QLabel *label;
    QPlainTextEdit *titleInput;
    QLabel *label_2;
    QPlainTextEdit *presenterInput;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPlainTextEdit *durationInput;
    QPlainTextEdit *likesInput;
    QPlainTextEdit *linkInput;
    QPushButton *addTutorialButton;
    QPushButton *removeTutorialButton;
    QPushButton *updateTutorialButton;
    QRadioButton *administratorRadio;
    QRadioButton *userRadio;
    QPushButton *likeButton;
    QMenuBar *menuBar;
    QMenu *menuSettings;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QStringLiteral("GUIClass"));
        GUIClass->setEnabled(true);
        GUIClass->resize(1125, 729);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setBold(false);
        font.setWeight(50);
        GUIClass->setFont(font);
        GUIClass->setAutoFillBackground(false);
        actionOutput_mode = new QAction(GUIClass);
        actionOutput_mode->setObjectName(QStringLiteral("actionOutput_mode"));
        actionVersion = new QAction(GUIClass);
        actionVersion->setObjectName(QStringLiteral("actionVersion"));
        actionUsage = new QAction(GUIClass);
        actionUsage->setObjectName(QStringLiteral("actionUsage"));
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tutorialList = new QListView(centralWidget);
        tutorialList->setObjectName(QStringLiteral("tutorialList"));
        tutorialList->setGeometry(QRect(10, 80, 341, 541));
        tutorialList->setAutoFillBackground(false);
        watchlist = new QListView(centralWidget);
        watchlist->setObjectName(QStringLiteral("watchlist"));
        watchlist->setGeometry(QRect(500, 380, 301, 241));
        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setEnabled(true);
        exitButton->setGeometry(QRect(750, 620, 51, 27));
        addToWatchlistButton = new QPushButton(centralWidget);
        addToWatchlistButton->setObjectName(QStringLiteral("addToWatchlistButton"));
        addToWatchlistButton->setGeometry(QRect(360, 440, 131, 27));
        removeFromWatchlistButton = new QPushButton(centralWidget);
        removeFromWatchlistButton->setObjectName(QStringLiteral("removeFromWatchlistButton"));
        removeFromWatchlistButton->setGeometry(QRect(360, 470, 131, 27));
        watchButton = new QPushButton(centralWidget);
        watchButton->setObjectName(QStringLiteral("watchButton"));
        watchButton->setGeometry(QRect(360, 500, 131, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 151, 21));
        QFont font1;
        font1.setPointSize(10);
        label->setFont(font1);
        titleInput = new QPlainTextEdit(centralWidget);
        titleInput->setObjectName(QStringLiteral("titleInput"));
        titleInput->setGeometry(QRect(440, 50, 241, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(360, 60, 31, 21));
        label_2->setFont(font1);
        presenterInput = new QPlainTextEdit(centralWidget);
        presenterInput->setObjectName(QStringLiteral("presenterInput"));
        presenterInput->setGeometry(QRect(440, 90, 241, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(360, 100, 71, 21));
        label_3->setFont(font1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(360, 140, 71, 21));
        label_4->setFont(font1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(360, 180, 41, 21));
        label_5->setFont(font1);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(360, 220, 31, 21));
        label_6->setFont(font1);
        durationInput = new QPlainTextEdit(centralWidget);
        durationInput->setObjectName(QStringLiteral("durationInput"));
        durationInput->setGeometry(QRect(440, 130, 241, 31));
        likesInput = new QPlainTextEdit(centralWidget);
        likesInput->setObjectName(QStringLiteral("likesInput"));
        likesInput->setGeometry(QRect(440, 170, 241, 31));
        linkInput = new QPlainTextEdit(centralWidget);
        linkInput->setObjectName(QStringLiteral("linkInput"));
        linkInput->setGeometry(QRect(440, 210, 241, 31));
        addTutorialButton = new QPushButton(centralWidget);
        addTutorialButton->setObjectName(QStringLiteral("addTutorialButton"));
        addTutorialButton->setGeometry(QRect(360, 250, 91, 27));
        removeTutorialButton = new QPushButton(centralWidget);
        removeTutorialButton->setObjectName(QStringLiteral("removeTutorialButton"));
        removeTutorialButton->setGeometry(QRect(470, 250, 111, 27));
        updateTutorialButton = new QPushButton(centralWidget);
        updateTutorialButton->setObjectName(QStringLiteral("updateTutorialButton"));
        updateTutorialButton->setGeometry(QRect(600, 250, 111, 27));
        administratorRadio = new QRadioButton(centralWidget);
        administratorRadio->setObjectName(QStringLiteral("administratorRadio"));
        administratorRadio->setGeometry(QRect(360, 300, 121, 20));
        userRadio = new QRadioButton(centralWidget);
        userRadio->setObjectName(QStringLiteral("userRadio"));
        userRadio->setGeometry(QRect(360, 330, 92, 20));
        likeButton = new QPushButton(centralWidget);
        likeButton->setObjectName(QStringLiteral("likeButton"));
        likeButton->setGeometry(QRect(358, 410, 131, 27));
        GUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1125, 25));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        GUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GUIClass->setStatusBar(statusBar);

        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuSettings->addAction(actionOutput_mode);
        menuHelp->addAction(actionVersion);
        menuHelp->addAction(actionUsage);

        retranslateUi(GUIClass);

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "GUI", nullptr));
        actionOutput_mode->setText(QApplication::translate("GUIClass", "Output mode", nullptr));
        actionVersion->setText(QApplication::translate("GUIClass", "Version", nullptr));
        actionUsage->setText(QApplication::translate("GUIClass", "Usage", nullptr));
        exitButton->setText(QApplication::translate("GUIClass", "Exit", nullptr));
        addToWatchlistButton->setText(QApplication::translate("GUIClass", "Add to list", nullptr));
        removeFromWatchlistButton->setText(QApplication::translate("GUIClass", "Remove from list", nullptr));
        watchButton->setText(QApplication::translate("GUIClass", "Watch your tutorials", nullptr));
        label->setText(QApplication::translate("GUIClass", "Available Tutorials:", nullptr));
        label_2->setText(QApplication::translate("GUIClass", "Title:", nullptr));
        label_3->setText(QApplication::translate("GUIClass", "Presenter:", nullptr));
        label_4->setText(QApplication::translate("GUIClass", "Duration:", nullptr));
        label_5->setText(QApplication::translate("GUIClass", "Likes:", nullptr));
        label_6->setText(QApplication::translate("GUIClass", "Link:", nullptr));
        addTutorialButton->setText(QApplication::translate("GUIClass", "Add Tutorial", nullptr));
        removeTutorialButton->setText(QApplication::translate("GUIClass", "Remove Tutorial", nullptr));
        updateTutorialButton->setText(QApplication::translate("GUIClass", "Update Tutorial", nullptr));
        administratorRadio->setText(QApplication::translate("GUIClass", "ADMINISTRATOR", nullptr));
        userRadio->setText(QApplication::translate("GUIClass", "USER", nullptr));
        likeButton->setText(QApplication::translate("GUIClass", "Like", nullptr));
        menuSettings->setTitle(QApplication::translate("GUIClass", "Settings", nullptr));
        menuHelp->setTitle(QApplication::translate("GUIClass", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H

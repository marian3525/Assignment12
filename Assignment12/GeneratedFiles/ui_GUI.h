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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
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
    QAction *actionVersion;
    QAction *actionUsage;
    QAction *actionHTML;
    QAction *actionCSV;
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
    QLabel *label_7;
    QPlainTextEdit *filterInput;
    QPushButton *filterButton;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QPushButton *backButton;
    QComboBox *comboBox;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QPushButton *showListButton;
    QMenuBar *menuBar;
    QMenu *menuSettings;
    QMenu *menuOutput_mode;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QStringLiteral("GUIClass"));
        GUIClass->setEnabled(true);
        GUIClass->resize(802, 709);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setBold(false);
        font.setWeight(50);
        GUIClass->setFont(font);
        GUIClass->setAutoFillBackground(false);
        actionVersion = new QAction(GUIClass);
        actionVersion->setObjectName(QStringLiteral("actionVersion"));
        actionUsage = new QAction(GUIClass);
        actionUsage->setObjectName(QStringLiteral("actionUsage"));
        actionHTML = new QAction(GUIClass);
        actionHTML->setObjectName(QStringLiteral("actionHTML"));
        actionHTML->setCheckable(true);
        actionHTML->setChecked(true);
        actionHTML->setAutoRepeat(false);
        actionCSV = new QAction(GUIClass);
        actionCSV->setObjectName(QStringLiteral("actionCSV"));
        actionCSV->setCheckable(true);
        actionCSV->setAutoRepeat(false);
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tutorialList = new QListView(centralWidget);
        tutorialList->setObjectName(QStringLiteral("tutorialList"));
        tutorialList->setGeometry(QRect(10, 40, 341, 581));
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
        label->setGeometry(QRect(10, 10, 151, 21));
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
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(510, 320, 61, 20));
        filterInput = new QPlainTextEdit(centralWidget);
        filterInput->setObjectName(QStringLiteral("filterInput"));
        filterInput->setGeometry(QRect(570, 310, 221, 31));
        filterButton = new QPushButton(centralWidget);
        filterButton->setObjectName(QStringLiteral("filterButton"));
        filterButton->setGeometry(QRect(510, 350, 121, 27));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(360, 280, 441, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(350, 370, 151, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(490, 290, 20, 91));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(350, 610, 151, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(790, 0, 20, 381));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        backButton = new QPushButton(centralWidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(670, 350, 121, 27));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(221, 10, 131, 22));
        undoButton = new QPushButton(centralWidget);
        undoButton->setObjectName(QStringLiteral("undoButton"));
        undoButton->setGeometry(QRect(390, 10, 89, 27));
        redoButton = new QPushButton(centralWidget);
        redoButton->setObjectName(QStringLiteral("redoButton"));
        redoButton->setGeometry(QRect(510, 10, 89, 27));
        showListButton = new QPushButton(centralWidget);
        showListButton->setObjectName(QStringLiteral("showListButton"));
        showListButton->setGeometry(QRect(360, 580, 131, 27));
        GUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 802, 25));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuOutput_mode = new QMenu(menuSettings);
        menuOutput_mode->setObjectName(QStringLiteral("menuOutput_mode"));
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
        menuSettings->addAction(menuOutput_mode->menuAction());
        menuOutput_mode->addAction(actionHTML);
        menuOutput_mode->addAction(actionCSV);
        menuHelp->addAction(actionVersion);
        menuHelp->addAction(actionUsage);

        retranslateUi(GUIClass);

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "GUI", nullptr));
        actionVersion->setText(QApplication::translate("GUIClass", "Version", nullptr));
        actionUsage->setText(QApplication::translate("GUIClass", "Usage", nullptr));
        actionHTML->setText(QApplication::translate("GUIClass", "HTML", nullptr));
#ifndef QT_NO_WHATSTHIS
        actionHTML->setWhatsThis(QApplication::translate("GUIClass", "Set the output mode to HTML", nullptr));
#endif // QT_NO_WHATSTHIS
        actionCSV->setText(QApplication::translate("GUIClass", "CSV", nullptr));
#ifndef QT_NO_WHATSTHIS
        actionCSV->setWhatsThis(QApplication::translate("GUIClass", "Set the output mode to CSV", nullptr));
#endif // QT_NO_WHATSTHIS
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
        label_7->setText(QApplication::translate("GUIClass", "Presenter:", nullptr));
        filterButton->setText(QApplication::translate("GUIClass", "Filter by presenter", nullptr));
        backButton->setText(QApplication::translate("GUIClass", "Back to main list", nullptr));
        comboBox->setItemText(0, QApplication::translate("GUIClass", "Detailed", nullptr));
        comboBox->setItemText(1, QApplication::translate("GUIClass", "Short", nullptr));

        undoButton->setText(QApplication::translate("GUIClass", "Undo", nullptr));
        redoButton->setText(QApplication::translate("GUIClass", "Redo", nullptr));
        showListButton->setText(QApplication::translate("GUIClass", "Show list window", nullptr));
        menuSettings->setTitle(QApplication::translate("GUIClass", "Settings", nullptr));
        menuOutput_mode->setTitle(QApplication::translate("GUIClass", "Output mode", nullptr));
        menuHelp->setTitle(QApplication::translate("GUIClass", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H

#pragma once

#include <QtWidgets/QMainWindow>
#include <QRadioButton.h>
#include "ui_GUI.h"
#include "Controller.h"
#include "qstringlistmodel.h"
#include "QDebug.h"
#include "QMessageBox.h"
#include "QApplication.h"
#include "QPushButton.h"
#include <QStringList>
#include <qshortcut.h>
#include <QStringListModel>
#include "QAbstractItemView"
#include "Validator.h"
#include "Exception.h"
#include "HTMLWriter.h"
#include "CSVWriter.h"
#include "qaction.h"
using namespace std;
class GUI : public QMainWindow
{
	Q_OBJECT

public:
	GUI(QWidget *parent = Q_NULLPTR);
	void buildWindow();

private:
	Controller controller{};
	string mode = "user";
	int displayCode = 0;
	vector<QWidget*> userGroup;
	vector<QWidget*> adminGroup;
	string outputMode;

	Ui::GUIClass ui;
	QMenu* menu;
	QAction* click;  //test only
	QAction* actionHTML;
	QAction* actionCSV;
	QPushButton* addButton;
	QPushButton* removeButton;
	QPushButton* updateButton;
	QPushButton* likeButton;
	QPushButton* addToWatchlistButton;
	QPushButton* removeFromWatchlistButton;
	QPushButton* watchButton;
	QPushButton* exitButton;
	QPushButton* filterButton;
	QPushButton* backButton;
	QPushButton* undoButton;
	QPushButton* redoButton;

	QPlainTextEdit* titleInput;
	QPlainTextEdit* presenterInput;
	QPlainTextEdit* durationInput;
	QPlainTextEdit* likesInput;
	QPlainTextEdit* linkInput;
	QPlainTextEdit* filterInput;

	QListView* tutorialList;
	QListView* watchlist;

	QRadioButton* adminRadio;
	QRadioButton* userRadio;


	QStringListModel* tutorialModel;
	QStringList tutorialStrList;

	QStringListModel* watchlistModel;
	QStringList watchlistStrList;

	QComboBox* displayMode=0;

	QShortcut* undoShortcut;
	QShortcut* redoShortcut;

	void connect();
	void bindWidgets();
	void popWarning(string title, string message);
	void updateStatus(string status = "");
	void onModeChange();
	void updateList(QListView* list, QStringListModel* model, QStringList strList, string repoMode);
	void appendToList(QListView* list, QStringListModel* model, QStringList strList, string element);
	int getMinutes(string duration_str);
	int getSeconds(string duration_str);
	void configureGroups();
	string getTitleFromString(string line);
	string getTitleFromShortString(string line);
	void update();

public slots:
	void onClick();
	void onAdd();
	void onRemove();
	void onUpdate();
	void onAdminRadioCheck();
	void onUserRadioCheck();
	void onWatch();
	void onFilter();
	void onLike();
	void onUserAdd();
	void onUserRemove();
	void onHTMLSelected();
	void onCSVSelected();
	void onExit();
	void onBack();
	void onDisplayChange();
	void onUndo();
	void onRedo();
};

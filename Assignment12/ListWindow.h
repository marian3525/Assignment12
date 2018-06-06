#pragma once

#include <QMainWindow>
#include "ui_ListWindow.h"
#include "CustomListModel.h"
#include <QAbstractItemModel.h>

class ListWindow : public QMainWindow
{
	Q_OBJECT

public:
	ListWindow(QWidget *parent = Q_NULLPTR);
	void update(QStringList str);
private:
	Ui::ListWindow ui;
	CustomListModel* listModel=nullptr;
	QListView* list;
	QWidget* parent = Q_NULLPTR;
};

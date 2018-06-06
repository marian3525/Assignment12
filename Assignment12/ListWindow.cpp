#include "ListWindow.h"
#include <QStringListModel.h>

ListWindow::ListWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	list = findChild<QListView*>("list");
	this->parent = parent;
}

void ListWindow::update(QStringList str) {
	if (listModel != nullptr)
		delete listModel;

	//QStringListModel* model = new QStringListModel(this);
	//model->setStringList(str);
	//list->setModel(model);
	//return;
	listModel = new CustomListModel{ str, this };
	list->setModel(listModel);
	//listModel->insertRows(0, str.size(), QModelIndex());

	list->show();
}

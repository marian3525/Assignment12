#pragma once

#include <QMainWindow>
#include "ui_ListWindow.h"

class ListWindow : public QMainWindow
{
	Q_OBJECT

public:
	ListWindow(QWidget *parent = Q_NULLPTR);
	~ListWindow();

private:
	Ui::ListWindow ui;
};

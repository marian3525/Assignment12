#include "GUI.h"
#include "ListWindow.h"
#include <QtWidgets/QApplication>
#include <Controller.h>
int main(int argc, char *argv[])
{	
	QApplication a(argc, argv);

	GUI w{};
	//ListWindow listWindow = ListWindow{};

	w.show();
	//listWindow.show();

	return a.exec();
}

/*
	TODO:
		-the list doesn't update after undo
*/
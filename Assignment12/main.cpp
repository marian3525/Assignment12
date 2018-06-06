#include "GUI.h"
#include "ListWindow.h"
#include <QtWidgets/QApplication>
#include <Controller.h>
int main(int argc, char *argv[])
{	
	QApplication a(argc, argv);

	GUI mainWindow{};

	mainWindow.show();

	return a.exec();
}
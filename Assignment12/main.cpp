#include "GUI.h"
#include <QtWidgets/QApplication>
#include <Controller.h>
int main(int argc, char *argv[])
{	
	Controller controller{};
	QApplication a(argc, argv);
	GUI w{controller};
	w.show();
	return a.exec();
}

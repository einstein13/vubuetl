#include "VubuEtlProject.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VubuEtlProject w;
	w.show();
	return a.exec();
}

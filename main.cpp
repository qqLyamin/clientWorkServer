#include "entry.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    entry * x = new entry;

	return a.exec();
}

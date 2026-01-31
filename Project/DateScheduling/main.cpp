#include <QApplication>
#include "CalendarWindow.h"
#include "ShiftData.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setStyleSheet("QWidget { background-color: #FFFFFF; color: #000000; }");
    app.setFont(QFont("Microsoft JhengHei UI", 9));

    loadEmployees();

    CalendarWindow window;
    window.show();

    return app.exec();
}
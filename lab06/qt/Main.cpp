#include <QtWidgets/QApplication>


#include "QCalculator.h"

int main(int argc, char* argv[])
{
    //Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);

    QMainWindow mainWin;
    QCalculator calcUI;
    
    calcUI.setupUi(&mainWin);
    mainWin.show();
    calcUI.configureConnections();
    return app.exec();
}

/*
 MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    ui.configureConnections()


*/
#include <QCoreApplication>
#include <fileobserver.h>
#include <ConsoleLog.h>
#include <SourceFile.h>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    SourceFile file("../FileWardenApp/source.txt"); // create container for observer
    ConsoleLog logger; // create logger for observer

    FileObserver &observer = FileObserver::GetInstance(&file, &logger, 1); // put container and logger into observer with refreshRate parameter
    observer.startObservation(); // run cycle

    return app.exec();
}

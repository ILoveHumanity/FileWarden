#include <QCoreApplication>
#include <fileobserver.h>
#include <ConsoleLog.h>
#include <SourceFile.h>
#include <SleepTrigger.h>
#include <MyFInfoVectorContainer.h>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    SourceFile file("../FileWardenApp/source.txt"); // create container for observer
    SleepTrigger trigger(1);
    ConsoleLog logger; // create logger for observer
    MyFInfoVectorContainer container;
    FileObserver &observer = FileObserver::GetInstance(&file, &container, &trigger, &logger); // put container and logger into observer with refreshRate parameter
    observer.startObservation(); // run cycle

    return app.exec();
}

#include <QCoreApplication>
#include <fileobserver.h>
#include <ConsoleLog.h>
#include <SourceFile.h>
#include <SleepTrigger.h>
#include <MyFInfoVectorContainer.h>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    SourceFile file("../FileWardenApp/source.txt");
    SleepTrigger trigger(100);
    ConsoleLog logger;
    MyFInfoVectorContainer container;
    FileObserver &observer = FileObserver::GetInstance(&file, &container, &trigger, &logger);
    observer.startObservation(); // run cycle

    return app.exec();
}

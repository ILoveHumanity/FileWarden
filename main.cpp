#include <QCoreApplication>
#include "FileObserver.h"
#include "ConsoleLog.h"
#include "FileStateSignalLogger.h"
#include "SourceFile.h"
#include "SleepTrigger.h"
#include "MyFInfoVectorContainer.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    SourceFile source("../FileWarden/TestFiles/source.txt");
    SleepTrigger trigger(100);
    ConsoleLog logger;
    FileStateSignalLogger fileStateSignalHandler(&logger);
    MyFInfoVectorContainer myFInfoContainer;
    FileObserver &observer = FileObserver::GetInstance(&source, &myFInfoContainer, &trigger, &fileStateSignalHandler);
    observer.startObservation(); // run cycle
    qDebug("End");
    return app.exec();
}

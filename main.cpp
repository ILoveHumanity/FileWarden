#include <QCoreApplication>
#include "FileObserver.h"
#include "ConsoleLog.h"
#include "FileStateSignalHandlerLogger.h"
#include "ObservationSourceFile.h"
#include "SleepObservationTrigger.h"
#include "MyFInfoVectorContainer.h"
#include <QString>
#include <QTextStream>

int main(int argc, char *argv[])
{
//    QCoreApplication app(argc, argv);
    QString path;
    QTextStream in(stdin);
    QTextStream out(stdout);
    out << "Enter path to ObservationSourceFile: " << Qt::flush;
    path = in.readLine();
    //path = "../FileWarden/TestFiles/source.txt";

    ObservationSourceFile source(path);
    SleepObservationTrigger trigger(100);
    ConsoleLog logger;
    FileStateSignalHandlerLogger fileStateSignalHandler(&logger);
    MyFInfoVectorContainer myFInfoContainer;
    FileObserver &observer = FileObserver::getInstance(&source, &myFInfoContainer, &trigger, &fileStateSignalHandler);
    out << " Observation started." << Qt::endl;
    observer.startObservation(); // run cycle
    out << " Observation ended." << Qt::endl;

    return 0;
//    return app.exec();
}

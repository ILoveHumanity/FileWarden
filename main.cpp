#include <QCoreApplication>
#include "FileObserver.h"
#include "ConsoleLog.h"
#include "FileStateSignalHandlerLogger.h"
#include "ObservationSourceFile.h"
#include "SleepObservationTrigger.h"
#include "MyFInfoVectorContainer.h"
#include <QString>
#include <QTextStream>

/// @brief Точка входа в программу.
/// @param[in] argc количество аргументов командной строки
/// @param[in] argv массив аргументов командной строки
/// @return Код завершения приложения
int main(int argc, char *argv[])
{
//    QCoreApplication app(argc, argv);

    // Запрашиваем путь к источнику списка наблюдения.
    QString path;
    QTextStream in(stdin);
    QTextStream out(stdout);
    out << "Enter path to ObservationSourceFile: " << Qt::flush;
    path = in.readLine();
    //path = "../FileWarden/TestFiles/source.txt";

    // Создаем все необходимые сущности
    ObservationSourceFile source(path);
    SleepObservationTrigger trigger(100);
    ConsoleLog logger;
    MyFInfoVectorContainer myFInfoContainer;
    FileObserver &observer = FileObserver::getInstance();
    observer.setObservationSource(&source);
    observer.setMyFInfoContainer(&myFInfoContainer);
    observer.setObservationTrigger(&trigger);
    FileStateSignalHandlerLogger fileStateSignalHandler(&logger);
    observer.connectFileStateSignalHandler(&fileStateSignalHandler);

    // Запускаем наблюдение
    out << " Observation started." << Qt::endl;
    observer.startObservation(); // run cycle
    out << " Observation ended." << Qt::endl;

    return 0;
//    return app.exec();
}

#include <QCoreApplication>
#include "FileObserver.h"
#include "ConsoleLog.h"
#include "FileStateSignalHandlerLogger.h"
#include "ObservationSourceFile.h"
#include "SleepObservationTrigger.h"
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
    auto source = new ObservationSourceFile(path); // ObservationSourceFile source(path);
    auto trigger = new SleepObservationTrigger(100); // SleepObservationTrigger trigger(100);
    auto logger = new ConsoleLog; // ConsoleLog logger;
    FileObserver &observer = FileObserver::getInstance();
    observer.setObservationSource(std::move(source));
    observer.setObservationTrigger(std::move(trigger));
    FileStateSignalHandlerLogger fileStateSignalHandler(std::move(logger));
    observer.connectFileStateSignalHandler(&fileStateSignalHandler);

    // Запускаем наблюдение
    out << " Observation started." << Qt::endl;
    observer.startObservation(); // run cycle
    out << " Observation ended." << Qt::endl;

    return 0;
//    return app.exec();
}

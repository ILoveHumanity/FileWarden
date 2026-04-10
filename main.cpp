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

    SleepObservationTrigger trigger;
    ConsoleLog logger;
    MyFInfoVectorContainer myFInfoContainer;

//  проверки на некорректные передаваемые значения
    path = "../FileWarden/TestFiles/source.txt";
    ObservationSourceFile source(path);
    FileObserver &observer = FileObserver::getInstance(nullptr, &myFInfoContainer, &trigger);
    {
        out << " Observation started." << Qt::endl;
        observer.startObservation(); // run cycle
        out << " Observation ended." << Qt::endl;
    }

    observer.setObservationSource(&source);
    observer.setMyFInfoContainer(nullptr);
    {
        out << " Observation started." << Qt::endl;
        observer.startObservation(); // run cycle
        out << " Observation ended." << Qt::endl;
    }

    observer.setMyFInfoContainer(&myFInfoContainer);
    observer.setObservationTrigger(nullptr);
    {
        out << " Observation started." << Qt::endl;
        observer.startObservation(); // run cycle
        out << " Observation ended." << Qt::endl;
    }

    observer.setObservationTrigger(&trigger);
    path = "../FileWarden/TestFiles/source1.txt";
    ObservationSourceFile source1(path);
    observer.setObservationSource(&source1);
    {
        out << " Observation started." << Qt::endl;
        observer.startObservation(); // run cycle
        out << " Observation ended." << Qt::endl;
    }

//  проверка на отработку без логгера
    observer.setObservationSource(&source);
    FileStateSignalHandlerLogger fileStateSignalHandler(nullptr);
    observer.connectFileStateSignalHandler(&fileStateSignalHandler);
    {
        out << " Observation started." << Qt::endl;
        observer.startObservation(); // run cycle
        out << " Observation ended." << Qt::endl;
    }

    return 0;
//    return app.exec();
}

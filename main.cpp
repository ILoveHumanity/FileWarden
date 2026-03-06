#include <QCoreApplication>
#include <ILog.h>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    ConsoleLog log;
    QString text = "chto-to";
    log.Log(text);
    return app.exec();
}

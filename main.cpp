#include <QCoreApplication>

#include <QString>
#include <QTextStream>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    QString path;
    QTextStream in(stdin);
    QTextStream out(stdout);
    out << "Enter path: " << Qt::flush;
    path = in.readLine();

    QFileInfo info(path);
    if(info.isFile()){
        out << "File exist\t" << path << "\tsize: " << info.size() << Qt::flush;
    }
    else{
        out << "File dont exist\t" << path << Qt::flush;
    }


    while(true){
        info.refresh();
        if(info.isFile()){
            out << "File exist\t" << path << "\tsize: " << info.size() << Qt::flush;
        }
        else{
            out << "File dont exist\t" << path << Qt::flush;
        }
    }

    return 0;

    //return a.exec();
}

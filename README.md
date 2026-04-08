# FileWardenApp
# Технологии программирования. Лабораторная работа №1
## [Наблюдение за файлами]
> **Селезнев Илья Дмитриевич** группа 932223

##Постановка задачи
Написать программу с консольным интерфейсом, которая выполняет слежение за выбранными файлами.

Ограничимся двумя характеристиками за изменениями которых выполняется слежение  :
1. Существование файла;
2. Размер файла.

Программа будет выводить на консоль уведомление о произошедших изменениях в файле.

Существует несколько ситуаций для наблюдаемого файла:
1. Файл существует, файл не пустой - на экран выводится факт существования файла и его размер.
2. Файл существует, файл был изменен - на экран выводится факт существования файла, сообщение о том что файл был изменен и его размер.  
3. Файл не существует - на экран выводится информация о том что файл не существует.

При возникновении изменения состояния наблюдаемого файла (возникновение события), необходимо выводить на экран соответствующее сообщение.
В данной реализации используем механизм сигнально-слотового соединения для обеспечения обработки события изменения наблюдаемого файла.

### UML-диаграмма классов
```mermaid
classDiagram
	class FileObserver {
		-IMyFInfoContainer* myFInfoContainer
		-IObservationSource* observationSource
		-IObservationTrigger* observationTrigger
		-IFileStateSignalHandler *fileStateSignalHandler
		-FileObserver()
		-~FileObserver()
		+static GetInstance(IObservationSource*, IMyFInfoContainer*, IObservationTrigger*, IFileStateSignalHandler*) FileObserver&
		+setObservationSource(IObservationSource*)
        +setMyFInfoContainer(IMyFInfoContainer*)
		+setObservationTrigger(IObservationTrigger*)
		+setFileStateSignalHandler(IFileStateSignalHandler*)
		+startObservation()
	}
    
	class IMyFInfoContainer {
		<<interface>>
		+~IMyFInfoContainer()*
		+getByPath(const QString&) MyFInfo*
		+getAllPaths() QVector~QString~*
		+setNewData(const QVector~MyFInfo~&)*
		+clear()*
	}
	class MyFInfoVectorContainer {
		-QVector~QString~ VFilePath
		-QVector~bool~ VExist
		-QVector~QDateTime~ VLastModified
		+MyFInfoVectorContainer()
		+~MyFInfoVectorContainer()
		+getByPath(const QString&) MyFInfo
		+getAllPaths() QVector~QString~
		+setNewData(const QVector~MyFInfo~&)
		+clear()
	}

	class IObservationSource {
		<<interface>>
		+~IObservationSource()*
		+update(QVector~QString~&) bool*
	}
	class SourceFile {
		-QString sourceFilePath
		+SourceFile(QString)
		+~SourceFile()
		+update(QVector~QString~&) bool
	}

	class IObservationTrigger {
		<<interface>>
		+~IObservationTrigger()*
		+wait()*
	}
	class SleepTrigger {
		-unsigned int timeInterval
		+SleepTrigger(unsigned int)
		+~SleepTrigger()
		+wait()
	}

    class IFileStateSignalHandler {
        <<abstract>>
        +~IFileStateSignalHandler()*
    }
    class FileStateSignalLogger {
        -Ilog* logger
        +FileStateSignalLogger(ILog*)
        +~FileStateSignalLogger()
        +setLogger(ILog*)
    }

	class ILog {
		<<interface>>
		+~ILog()*
		+log(QString)*
	}
	class ConsoleLog {
		+ConsoleLog()
		+~ConsoleLog()
		+log(QString)
	}

	class MyFInfo {
		-QString filePath
		-bool exist
		-QDateTime lastModified
		+MyFInfo(QString, bool, QDateTime)
		+~MyFInfo()
		+MyFInfo(const MyFInfo&)
		+operator=(const MyFInfo&)
		+getFilePath() QString
		+getExist() bool
		+getLastModified() QDateTime
		+isNull() bool
	}

    MyFInfo <.. IMyFInfoContainer

    FileObserver o-- IMyFInfoContainer
    IMyFInfoContainer <|.. MyFInfoVectorContainer

    FileObserver o-- IObservationSource
    IObservationSource <|.. SourceFile

    FileObserver o-- IObservationTrigger
    IObservationTrigger <|.. SleepTrigger

    FileObserver o-- IFileStateSignalHandler
    IFileStateSignalHandler <|.. FileStateSignalLogger

    ILog --o FileStateSignalLogger
    ILog <|.. ConsoleLog
```

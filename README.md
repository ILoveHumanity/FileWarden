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
		-IMyFInfoContainer* observedFiles
		-IObservationSource* observationSource
		-ILog* logger
		-IObservationTrigger* observationTrigger
		-FileObserver(IObservationSource*, IMyFInfoContainer*, IObservationTrigger*, ILog*)
		-~FileObserver()
		+static GetInstance(IObservationSource*, IMyFInfoContainer*, IObservationTrigger*, ILog*) FileObserver&
		+setObservationSource(IObservationSource*)
		+setLogger(ILog*)
		+setObservationTrigger(IObservationTrigger*)
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
		+update(QVector~QString~&)*
	}
	class SourceFile {
		-QString sourceFilePath
		+SourceFile(QString)
		+~SourceFile()
		+update(QVector~QString~&)
	}

	class ILog {
		<<abstract>>
		+~ConsoleLog()*
		+log(QString data)*
	}
	class ConsoleLog {
		+ConsoleLog()
		+~ConsoleLog()
		+log(QString data)
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

    IMyFInfoContainer <|.. MyFInfoVectorContainer
    IObservationSource <|.. SourceFile
    ILog <|.. ConsoleLog
    IObservationTrigger <|.. SleepTrigger
    IMyFInfoContainer ..> MyFInfo

    FileObserver o-- IMyFInfoContainer
    FileObserver o-- IObservationSource
    FileObserver o-- ILog
    FileObserver o-- IObservationTrigger
```

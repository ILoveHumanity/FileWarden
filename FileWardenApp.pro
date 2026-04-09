QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        FileWardenApp/src/ConsoleLog.cpp \
        FileWardenApp/src/FileStateSignalHandlerLogger.cpp \
        FileWardenApp/src/MyFInfo.cpp \
        FileWardenApp/src/MyFInfoVectorContainer.cpp \
        FileWardenApp/src/ObservationSourceFile.cpp \
        FileWardenApp/src/FileObserver.cpp \
        FileWardenApp/src/SleepObservationTrigger.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    FileWardenApp/FileObserver.h \
    FileWardenApp/src/FileStateSignalHandlerLogger.h \
    FileWardenApp/src/MyFInfo.h \
    FileWardenApp/IObservationSource.h \
    FileWardenApp/IMyFInfoContainer.h \
    FileWardenApp/IObservationTrigger.h \
    FileWardenApp/IFileStateSignalHandler.h \
    FileWardenApp/ILog.h \
    FileWardenApp/src/MyFInfoVectorContainer.h \
    FileWardenApp/src/ObservationSourceFile.h \
    FileWardenApp/src/ConsoleLog.h \
    FileWardenApp/src/SleepObservationTrigger.h

INCLUDEPATH += \
    FileWardenApp/src/ \
    FileWardenApp/


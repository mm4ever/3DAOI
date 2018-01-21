INCLUDEPATH += $$PWD/../../include
DEPENDPATH += $$PWD/../../include

#>>>----------------------------------------------------------------------------
# Job

## load library of job
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/release/ -lJob
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/debug/ -lJob
else:unix: LIBS += -L$$PWD/../../lib/debug -lJob

INCLUDEPATH += $$PWD/../Job
DEPENDPATH += $$PWD/../Job

#<<<----------------------------------------------------------------------------



#>>>----------------------------------------------------------------------------
# SSDK

## load library of SSDK
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/release/ -lSSDK
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/debug/ -lSSDK
else:unix: LIBS += -L$$PWD/../../lib/debug -lSSDK

INCLUDEPATH += $$PWD/../SSDK
DEPENDPATH += $$PWD/../SSDK

#<<<----------------------------------------------------------------------------

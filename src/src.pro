TEMPLATE = app
TARGET = YaToTwit
QT += core \
    gui \
    xml \
    network
HEADERS += twittercli.h \
    YandexHelper.h \
    yatotwit.h
SOURCES += twittercli.cpp \
    YandexHelper.cpp \
    main.cpp \
    yatotwit.cpp
FORMS += yatotwit.ui
RESOURCES += 
LIBS += -lcurl
CONFIG += crypto
CONFIG += kqoauth
macx { 
    CONFIG -= app_bundle
    QMAKE_POST_LINK += install_name_tool \
        -change \
        kqoauth.framework/Versions/0/kqoauth \
        lib/kqoauth.framework/Versions/0/kqoauth \
        $${TARGET}
}
else:unix:# the second argument (after colon) is for
# being able to run make check from the root source directory
LIBS += -Llib:lib
#else:windows:LIBS += -Llib \
#    -lkqoauthd0

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    loadingwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    puzzlewindow.cpp \
    stylehelper.cpp

HEADERS += \
    loadingwidget.h \
    mainwindow.h \
    puzzlewindow.h \
    stylehelper.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    3on3/1.png \
    3on3/2.png \
    3on3/3.png \
    3on3/4.png \
    3on3/5.png \
    3on3/6.png \
    3on3/7.png \
    3on3/8.png \
    3on3/9.png \
    im/allanimals.jpg \
    im/depositphotos_102537306-stock-illustration-ant-and-bee-with-white.jpg \
    im/depositphotos_13270628-stock-illustration-3d-cartoon-bird.jpg \
    im/depositphotos_13270993-stock-illustration-red-bear.jpg \
    im/depositphotos_136889860-stock-photo-funny-cartoon-character.jpg \
    im/depositphotos_223511466-stock-illustration-funny-cartoon-friends.jpg \
    im/depositphotos_28808489-stock-photo-fun-giraffe-with-glasses.jpg \
    im/depositphotos_37483085-stock-photo-fun-koala.jpg \
    im/depositphotos_503220292-stock-photo-illustration-cute-cartoon-character-mask.jpg \
    im/depositphotos_6631424-stock-illustration-fun-cat.jpg \
    im/depositphotos_71499821-stock-photo-fun-cartoon-dog.jpg \
    im/photo_2024-06-29_10-00-48.jpg \
    resources/image_part_001.png \
    resources/image_part_002.png \
    resources/image_part_003.png \
    resources/image_part_004.png \
    resources/image_part_005.png \
    resources/image_part_006.png \
    resources/image_part_007.png \
    resources/image_part_008.png \
    resources/image_part_009.png \
    resources/image_part_010.png \
    resources/image_part_011.png \
    resources/image_part_012.png \
    resources/image_part_013.png \
    resources/image_part_014.png \
    resources/image_part_015.png \
    resources/image_part_016.png \
    resources/images/allanimals.jpg \
    resources/images/depositphotos_102537306-stock-illustration-ant-and-bee-with-white.jpg \
    resources/images/depositphotos_13270628-stock-illustration-3d-cartoon-bird.jpg \
    resources/images/depositphotos_13270993-stock-illustration-red-bear.jpg \
    resources/images/depositphotos_136889860-stock-photo-funny-cartoon-character.jpg \
    resources/images/depositphotos_223511466-stock-illustration-funny-cartoon-friends.jpg \
    resources/images/depositphotos_28808489-stock-photo-fun-giraffe-with-glasses.jpg \
    resources/images/depositphotos_37483085-stock-photo-fun-koala.jpg \
    resources/images/depositphotos_503220292-stock-photo-illustration-cute-cartoon-character-mask.jpg \
    resources/images/depositphotos_6631424-stock-illustration-fun-cat.jpg \
    resources/images/depositphotos_71499821-stock-photo-fun-cartoon-dog.jpg \
    resources/images/photo_2024-06-29_10-00-48.jpg \
    resources/images/photo_2024-06-29_10-04-06.jpg \
    resources/images/фон.m4a

RESOURCES += \
    3on3.qrc \
    icons.qrc \
    loading.qrc \
    pictures/pictures.qrc \
    resources.qrc

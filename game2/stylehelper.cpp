#include "stylehelper.h"
#include<QPixmap>
#include<QPalette>



QString StyleHelper::getStartButtonsStyle()
{
    return "QPushButton{"
           "color:#fff;"
           "border-radius:19px;"
           "background-color:qlineargradient(spread:pad, x1:0.224, y1:0.642045, x2:1, y2:1, stop:0.1 rgba(255, 85, 0, 255), stop:1 rgba(255, 255, 255, 255))"
                    "}";

}
QString StyleHelper::getStartWindowStyle(){
    return "QWidget#centralwidget{"
           "background-image:url(:/resources/resources/picturetiger2.jpg);"
           "background-repeat: no-repeat;"
    "background-position: left;"
    "background-size: 60% 100%;"
     "background-color:orange;"
    "}";
}



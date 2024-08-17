#include "mainwindow.h"
#include "loadingwidget.h"
#include <QApplication>
#include <QThread>
#include <QTimer>
#include <QMainWindow>

/*
1) Реализовать приложение реализующее «подобие» игры.
2) Считать с текстовых  полей данные.
3) Кнопки для выполнения любых действий.
4) Отображение готовых картинок из файлов.
5) Изображение  графических фигур: закраска цветом, устанавливать цвет, толщину и тип линий для графических фигур
6) Возможность выбора толщины  и типа линии ( выбор из списков, таблиц);
7) Вывод текста, использовать шрифт, размер и т.д. (выбор из списков, таблиц или QFontDialog).
8) Обработка  нажатия клавиш мыши (для вывода всплывающего меню или передвижения элементов изображения).
9) Отображение и обработка таблиц QTableWidget, QListWidget
10) Использование одного из классов  компоновки ( QVBoxLayout, QHBoxLayout,  QGridLayout, QFormLayout, QGridLayout).
11) Обработка нажатий клавиш на клавиатуре.
12)  * Дополнительно: Horizontal\Vertical ScrollBar\ Slider


*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Создаем виджет загрузки
    LoadingWidget *loadingWidget = new LoadingWidget();
    loadingWidget->setProgressBarSize(1000, 25);
    loadingWidget->showFullScreen();

    // Создаем таймер для скрытия LoadingWidget и показа MainWindow
    QTimer::singleShot(5000, [&] { // 5000 миллисекунд = 5 секунд
            loadingWidget->hide();
            w.show(); // Показываем MainWindow
        });

    return a.exec();
}

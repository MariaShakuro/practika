#include "loadingwidget.h"
#include<QMovie>
#include<QTimer>
#include<QMainWindow>
#include<QVBoxLayout>
#include<QPixmap>
#include<QPalette>
#include<QResizeEvent>
LoadingWidget::LoadingWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);

    QPixmap bkgnd(":/resources/resources/group-animals-with-zoo-sign_1308-43734.jpg");
     // Установка размера фона в текущий размер виджета
    bkgnd=bkgnd.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    // Устанавливаем палитру
    QPalette p=palette();
    // Используем QPalette::Window
    p.setBrush(QPalette::Window,bkgnd);
    setPalette(p);
  setAutoFillBackground(true); // Включить автоматическую заливку фона

    progressBar = new QProgressBar(this);
    progressBar->setRange(0, 100);
    progressBar->setAlignment(Qt::AlignCenter);
     progressBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
     layout->addWidget(progressBar,0, Qt::AlignCenter);
    setLayout(layout);

    // Создаем таймер и соединяем его сигнал со слотом для обновления прогресса
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &LoadingWidget::updateProgress);
    timer->start(50);
}

// Переопределяем resizeEvent для изменения фона при изменении размера
void LoadingWidget::resizeEvent(QResizeEvent *event)
{
    // Обновляем фон при изменении размера
    QPixmap bkgnd(":/resources/resources/group-animals-with-zoo-sign_1308-43734.jpg");
    bkgnd = bkgnd.scaled(event->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation); // Растягиваем изображение

    QPalette p = palette();
    p.setBrush(QPalette::Window, bkgnd);
    setPalette(p);

    QWidget::resizeEvent(event); // Не забываем вызвать базовый метод
}
void LoadingWidget::updateProgress() {
    int currentValue = progressBar->value();
    if (currentValue < 100) {
        progressBar->setValue(currentValue + 1);
    }
}
void LoadingWidget::setProgressBarSize(int width, int height)
{
    progressBar->setFixedSize(width, height);
}

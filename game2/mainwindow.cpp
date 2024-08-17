#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loadingwidget.h"
#include<QTabBar>
#include<QTimer>
#include<QTimeEdit>
#include<QFrame>
#include<QMouseEvent>
#include<QLabel>
#include"stylehelper.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tabWidget, &MainWindow::customContextMenuRequested, [&](const QPoint& pos) {
        static QMenu* menu = nullptr;

        if (!menu) {
            menu = new QMenu();
            this->restartTimerAction = new QAction("Запустить счетчик ", this);
            this->stopTimerAction = new QAction("Остановить счетчик", this);

            menu->addAction(restartTimerAction);
            menu->addAction(stopTimerAction);

            connect(restartTimerAction, &QAction::triggered, this, &MainWindow::restartTimer);
            connect(stopTimerAction, &QAction::triggered, this, &MainWindow::stopTimer);
        }
        menu->popup( mapToGlobal(pos) );
    });

  //  ui->progressBar->setValue(0);

   // ui->widget->show();
    timer=new QTimer(ui->widget);
    timer->start(20);
   // connect(timer,&QTimer::timeout,this,&MainWindow::onloadout);


    ui->tabWidget->tabBar()->hide();
   ui->tabWidget->setCurrentIndex(0);
    setInterfaceStyle();

    this->current_picture = "";
    this->difficulte = "";


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Escape){
        close();
    }
}

void MainWindow::setInterfaceStyle()
{   ui->centralwidget->setStyleSheet(StyleHelper::getStartWindowStyle());
    ui->pushButton_2->setStyleSheet(StyleHelper::getStartButtonsStyle());
    ui->pushButton->setStyleSheet(StyleHelper::getStartButtonsStyle());
    ui->pushButton_12->setStyleSheet(StyleHelper::getStartButtonsStyle());
    ui->pushButton_7->setStyleSheet(StyleHelper::getStartButtonsStyle());
     ui->pushButton_4->setStyleSheet(StyleHelper::getStartButtonsStyle());
}


void MainWindow::on_pushButton_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    this->current_picture = "";
    this->difficulte = "";
}



void MainWindow::on_pushButton_4_clicked()
{
    if(!isOnSecondClick){

    if(this->current_picture =="" or this->difficulte==""){
        return;
    }
    else{

        this->ui->tabWidget->setCurrentIndex(0);
        this->field = new PuzzleWindow(this->current_picture);
        this->ui->gridLayout_4->addWidget(this->field);
        this->MakeField();
     //РАТЬ,Т.К. ЗАЧЕМ 2 ТАЙМЕРА??????
     //   QTimer*  timer = new QTimer(this);
        // Создаем объект QTimeEdit и устанавливаем текущее время
        timeEdit = new QTimeEdit();
        timeEdit->setDisplayFormat("hh:mm:ss");
        timeEdit->setTime(QTime(0, 0, 0)); // Устанавливаем начальное время
        // Подключаем сигнал таймера к слоту, который будет обновлять время в QTimeEdit
        connect(timer, &QTimer::timeout, this, [=]() {
            QTime currentTime = timeEdit->time().addSecs(1);
            timeEdit->setTime(currentTime);
        });

        // Устанавливаем интервал времени для таймера (1 секунда)
        timer->setInterval(1000);
        //Фича,чтобы исключить редактирование таймера вручную
        timeEdit->setReadOnly(true);
        // Запускаем таймер
        timer->start();
        this->timer = timer;
        ui->layout->addWidget(timeEdit);
         isOnSecondPage = false;
    }
    }else{
    if(isOnSecondClick){
        ui->layout->removeWidget(timeEdit);
        delete timeEdit;
        timeEdit=nullptr;
        // Удаляем старый PuzzleWindow, если он существует
        if (field) {
            ui->gridLayout_4->removeWidget(field);
            delete field;
            field = nullptr;
        }

        if(this->current_picture =="" or this->difficulte==""){
            return;
        }
        else{
            this->ui->tabWidget->setCurrentIndex(0);
            this->field = new PuzzleWindow(this->current_picture);
            this->ui->gridLayout_4->addWidget(this->field);
            this->MakeField();
            //НАДО УБРАТЬ,Т.К. ЗАЧЕМ 2 ТАЙМЕРА??????
            //   QTimer*  timer = new QTimer(this);
            // Создаем объект QTimeEdit и устанавливаем текущее время
            timeEdit = new QTimeEdit();
            timeEdit->setDisplayFormat("hh:mm:ss");
           timeEdit->setTime(QTime(0, 0, 0)); // Устанавливаем начальное время
            // Подключаем сигнал таймера к слоту, который будет обновлять время в QTimeEdit
            connect(timer, &QTimer::timeout, this, [=]() {
               QTime currentTime = timeEdit->time().addSecs(1);
                timeEdit->setTime(currentTime);
            });

            // Устанавливаем интервал времени для таймера (1 секунда)
            timer->setInterval(1000);
            //Фича,чтобы исключить редактирование таймера вручную
            timeEdit->setReadOnly(true);
            // Запускаем таймер
            timer->start();
            this->timer = timer;
            ui->layout->addWidget(timeEdit);
            isOnSecondPage = false;}
    }

   }
    isOnSecondClick!=isOnSecondClick;
}


void MainWindow::on_pushButton_12_clicked()
{



    if (isOnSecondPage) {
        // Retrieve the current time from QTimeEdit
        QString result = timeEdit->time().toString("hh:mm:ss");

        // Add the result to QListWidget
        ui->listWidget->addItem(result);

        ui->tabWidget->setCurrentIndex(0);
        this->current_picture = "";
        this->difficulte = "";}
    else{
        ui->tabWidget->setCurrentIndex(1);
        this->current_picture = "";
        this->difficulte = "";
    }
    // Toggle the state
    isOnSecondPage = !isOnSecondPage;
}
void MainWindow::restartTimer()
{
    timer->stop();
    QTimeEdit* timeEdit = new QTimeEdit();
    timeEdit->setTime(QTime(0, 0, 0));
    timer->start();

}
void MainWindow::stopTimer()
{
    timer->stop();

}
void MainWindow::MakePuzzle()
{
   ui->tabWidget->setCurrentIndex(0);
   return;
}

void MainWindow::MakeField()
{

    QVector<QPixmap> temp;
    std::string path = "picures/" + this->current_picture + "/";
    for (int i = 1; i <= 9; ++i){
        temp.push_back(QPixmap(QString::fromStdString(path + std::to_string(i) + ".png")));
    }
    this->field->SetVectorOfPictures(temp);


}

void MainWindow::on_pushButton_2_clicked()
{
    qApp->quit();
}

/*void MainWindow::onloadout()
{
    if(ui->progressBar->value()==100)  {
        ui->progressBar->hide();
        ui->widget->hide();
    }
    ui->progressBar->setValue(ui->progressBar->value()+1);
}
*/

void MainWindow::on_label_19_mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QLabel* clickedLabel = qobject_cast<QLabel*>(sender());
        if(clickedLabel) {
            QPixmap image = clickedLabel->pixmap(Qt::ReturnByValue);
            if (!image.isNull()) {
                QFrame* frame = new QFrame;
                QHBoxLayout* layout = new QHBoxLayout;
                QLabel* imageLabel = new QLabel;
                imageLabel->setPixmap(image);
                layout->addWidget(imageLabel);
                frame->setLayout(layout);

            }
        }
    }
}




void MainWindow::on_pushButton_7_clicked()
{
    this->difficulte = "Medium";
}


void MainWindow::on_pushButton_3_clicked()
{
    this->current_picture = "bear";
}




void MainWindow::on_pushButton_8_clicked()
{
    this->current_picture = "bird";

}


void MainWindow::on_pushButton_9_clicked()
{
    this->current_picture = "elephant";
}


void MainWindow::on_pushButton_10_clicked()
{
    this->current_picture = "camel";
}


void MainWindow::on_pushButton_11_clicked()
{
    this->current_picture = "cat";
}




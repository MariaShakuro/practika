#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QDebug>
#include<QAction>
#include<QTimeEdit>
#include "puzzlewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();


  //  void onloadout();

    void on_label_19_mousePressEvent(QMouseEvent *event);
    void on_pushButton_7_clicked();


    void on_pushButton_3_clicked();
    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();


    void on_pushButton_12_clicked();

protected:
    void keyPressEvent(QKeyEvent*event)override;
private:
    Ui::MainWindow *ui;
    QTimer*timer;
    void MakePuzzle();
    void MakeField();
    void setInterfaceStyle();
    void restartTimer();
    void stopTimer();
    bool isOnSecondPage = false;
    bool isOnSecondClick = false;
    QString difficulte;
    PuzzleWindow* field;
    std::string  current_picture;
    std::vector<std::string> Animanls;
    QTimeEdit*timeEdit;
    QAction* restartTimerAction;
    QAction* stopTimerAction;
};
#endif // MAINWINDOW_H

#ifndef LOADINGWIDGET_H
#define LOADINGWIDGET_H
#include <QMainwindow>
#include <QWidget>
#include <QProgressBar>
#include <QLabel>
class LoadingWidget : public QWidget
{
public:
    explicit LoadingWidget(QWidget *parent = nullptr);

signals:
    void updateProgress();
    void setProgressBarSize(int width,int height);
    void  resizeEvent(QResizeEvent *event);
 private:
    QProgressBar *progressBar;
    QTimer*timer;
    QMainWindow*w;
};

#endif // LOADINGWIDGET_H

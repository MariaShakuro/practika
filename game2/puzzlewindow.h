#ifndef PUZZLEWINDOW_H
#define PUZZLEWINDOW_H

#include <QMainWindow>

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QVector>
#include <QTime>
#include <random>
#include <QRandomGenerator>
#include <vector>
#include <string>
#include <QWidget>

class PuzzleWindow : public QMainWindow {
    Q_OBJECT

public:
    PuzzleWindow(std::string animal,QWidget *parent = nullptr);
    ~PuzzleWindow();
    void SetPicture(int i, QString file_path);
private slots:
    void onTileClicked();
private:
    void shuffleTiles();
    void updateUI();

    QGridLayout *gridLayout;

    QVector<QPushButton*> tiles;
    QVector<QPixmap> field;

    int emptyTileIndex;
};

#endif // PUZZLEWINDOW_H

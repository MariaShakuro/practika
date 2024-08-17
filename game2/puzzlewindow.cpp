#include "puzzlewindow.h"
#include <QMessageBox>

PuzzleWindow::PuzzleWindow(std::string animal, QWidget *parent)
    : QMainWindow(parent),
    gridLayout(new QGridLayout),
    emptyTileIndex(8) {

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(gridLayout);

    QVector<QPixmap>* temp = &this->field;
    // temp->push_back(QPixmap(":/3on3/3on3/1.png"));
    // temp->push_back(QPixmap(":/3on3/3on3/2.png"));
    // temp->push_back(QPixmap(":/3on3/3on3/3.png"));
    // temp->push_back(QPixmap(":/3on3/3on3/4.png"));
    // temp->push_back(QPixmap(":/3on3/3on3/5.png"));
    // temp->push_back(QPixmap(":/3on3/3on3/6.png"));
    // temp->push_back(QPixmap(":/3on3/3on3/7.png"));
    // temp->push_back(QPixmap(":/3on3/3on3/8.png"));
    // temp->push_back(QPixmap(":/3on3/3on3/9.png"));

    //QVector<QPixmap> temp;
    //:/animals/bear/1.png
    std::string path = ":/animals/" + animal + "/";
    for (int i = 1; i <= 9; ++i){
        temp->push_back(QPixmap(QString::fromStdString(path + std::to_string(i) + ".png")));
    }

    //this->field->SetVectorOfPictures(temp);
    for (int i = 0; i < 9; ++i) {
        QPushButton *button = new QPushButton(this);
        button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        button->setFont(QFont("Arial", 24));
        QSize largerSize = temp->at(i).size() * 2;
        button->setIconSize(largerSize);
        connect(button, &QPushButton::clicked, this, &PuzzleWindow::onTileClicked);
        tiles.append(button);
        gridLayout->addWidget(button, i / 3, i % 3);
    }

    shuffleTiles();

}

PuzzleWindow::~PuzzleWindow() {}

void PuzzleWindow::SetPicture(int i, QString file_path)
{
    /*QPixmap temp(file_path);
    this->tiles[i]->setIcon(temp);
   this->tiles[i]->setIconSize(temp.size());*/

    QPixmap originalPixmap(file_path);
    QSize largerSize = originalPixmap.size() * 2;
    QPixmap scaledPixmap = originalPixmap.scaled(largerSize, Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation); // Масштабируем изображение
    this->tiles[i]->setIcon(scaledPixmap);
    this->tiles[i]->setIconSize(largerSize);
}

void PuzzleWindow::SetVectorOfPictures(QVector<QPixmap> vec_)
{
    field.clear();
    field = vec_;
}

void PuzzleWindow::shuffleTiles() {


    std::vector<int> numbers{0,1,2,3,4,5,6,7,8};

    std::random_device rd;
    std::mt19937 gen(rd());

    // эта строка определяет рандом
    std::shuffle(numbers.begin(), numbers.end(), gen);
     bool isSolved = true;
    for (int i = 0; i < 9; ++i) {
        if (numbers[i] == 0) {
            emptyTileIndex = i;
            qDebug()<<numbers[i] << "nado";
            tiles[i]->setIcon(QIcon());
        }
        else {
            qDebug()<<numbers[i];

           tiles[i]->setIcon(this->field[numbers[i]]);
        }
        // Check if the tiles are in the correct order
        if (numbers[i] != i) {
            isSolved = false;
        }
    }
    // Show QMessageBox if the puzzle is solved
    if (isSolved) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Победа");
        msgBox.setText("Вы собрали пазл!");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}

/*bool PuzzleWindow::isSolved() {
    // for (int i = 0; i < 8; ++i) {
    //     if (tiles[i]->text().toInt() != i + 1)
    //         return false;
    // }
    // return true;
    return false;
}*/

void PuzzleWindow::updateUI() {
    for (int i = 0; i < 9; ++i) {
        if (i == emptyTileIndex)
            tiles[i]->setIcon(QIcon());
        else
            tiles[i]->setIcon(field[i]);
    }
}

void PuzzleWindow::onTileClicked() {
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    int clickedIndex = tiles.indexOf(clickedButton);

    int rowClicked = clickedIndex / 3;
    int colClicked = clickedIndex % 3;
    int rowEmpty = emptyTileIndex / 3;
    int colEmpty = emptyTileIndex % 3;

    if ((rowClicked == rowEmpty && abs(colClicked - colEmpty) == 1) ||
        (colClicked == colEmpty && abs(rowClicked - rowEmpty) == 1)) {
        tiles[emptyTileIndex]->setIcon(clickedButton->icon());
        clickedButton->setIcon(QIcon());
        emptyTileIndex = clickedIndex;

    }
}

/*void PuzzleWindow::checkPuzzleCompletion() {
    bool isComplete = true; // Здесь должна быть ваша логика проверки завершения пазла

    if (isComplete) {
        showVictoryMessage();
    }
}*/

/*void PuzzleWindow::showVictoryMessage() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Победа");
    msgBox.setText("Вы собрали пазл!");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}*/

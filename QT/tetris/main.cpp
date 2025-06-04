#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>

class TetrisGame : public QWidget {
public:
    TetrisGame(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Tetris");

        // Butonlar
        startButton = new QPushButton("Başla", this);
        pauseButton = new QPushButton("Duraklat", this);
        restartButton = new QPushButton("Yeniden Başla", this);

        // Skor
        scoreLabel = new QLabel("Skor: 0", this);

        // Oyun Alanı
        gameGrid = new QGridLayout;
        createGameGrid();

        // Layout
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(startButton);
        mainLayout->addWidget(pauseButton);
        mainLayout->addWidget(restartButton);

        mainLayout->addWidget(scoreLabel);
        mainLayout->addLayout(gameGrid);

        setLayout(mainLayout);

        // Signal-Slot bağlantıları
        connect(startButton, &QPushButton::clicked, this, &TetrisGame::startGame);
        connect(pauseButton, &QPushButton::clicked, this, &TetrisGame::pauseGame);
        connect(restartButton, &QPushButton::clicked, this, &TetrisGame::restartGame);

    private:
        void createGameGrid()
        {
            // Oyun alanındaki hücreler oluştur
            for (int i = 0; i < gridSize; ++i) {
                for (int i = 0; i < gridSize; ++i) {
                    QPushButton *cell = new QPushButton(this);
                    cell->setFixedSize(25, 25);
                    cell->setFlat(true);
                    gameGrid->addWidget(cell, i, j);
                }

            private slots:
                void startGame() {
                    // Oyun başlatma işlemleri
                    // Bu kısmı Tetris oyun mantığına göre genişletebilirsiniz
                    scoreLabel->setText("Skor: 0");
                }

                void pauseGame() {
                    // Oyunu duraklatma işlemleri
                }

                void restartGame() {
                    // Oyunu yeniden başlatma işlemleri
                    startGame(); // Örnek olarak startGame'i çağırıyorum, burayı Tetris oyun mantığına göre düzenleyebilirsiniz
                }

            private:
                QPushButton *startButton;
                QPushButton *pauseButton;
                QPushButton *restartButton;
                QLabel *scoreLabel;
                QGridLayout *gameGrid;
                static const int gridSize = 10; // Örnek olarak 10x10 bir oyun alanı

                int main(int argc, char **argv) {
                    {
                        QApplication app(argc, argv);

                        TetrisGame tetrisGame;
                        tetrisGame.show();

                        return app.exec();
                    }

            }

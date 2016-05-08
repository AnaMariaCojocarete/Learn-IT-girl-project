#include <QPainter>
#include <QDebug>
#include "MainWindow.h"
#include "Racket.h"
#include "Table.h"
#include "Ball.h"


Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ball(BALL_START_X, BALL_START_Y, BALL_SIZE, BALL_SIZE, BALL_SPEED_X, BALL_SPEED_Y)
    , leftRacket(LEFT_RACKET_START_X, LEFT_RACKET_START_Y, LEFT_RACKET_WIDTH, LEFT_RACKET_HEIGHT)
    , rightRacket(RIGHT_RACKET_START_X, RIGHT_RACKET_START_Y, RIGHT_RACKET_WIDTH, RIGHT_RACKET_HEIGHT)
    , table(WINDOW_WIDTH, WINDOW_HEIGHT)

{
    resize(WINDOW_WIDTH, WINDOW_HEIGHT);
    timerId = startTimer(3);
}

void Game::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);

    doPainting();
}

void Game::timerEvent(QTimerEvent *)
{
    moveBall();
    repaint();
}

void Game::doPainting()
{
    QPainter painter(this);

    table.draw(painter);

    leftRacket.draw(painter);
    rightRacket.draw(painter);

    ball.draw(painter);
}

void Game::moveBall()
{
    ball.move(WINDOW_WIDTH, WINDOW_HEIGHT, LEFT_RACKET_WIDTH, leftRacket, rightRacket);
}


void Game::moveRackets(int key)
{
    if (key == Qt::Key_Q)
    {
        leftRacket.positionY -= 50;
        if (leftRacket.positionY <= 0)
        {
            leftRacket.positionY = 1;
        }
    }

    if (key == Qt::Key_A)
    {
        leftRacket.positionY += 50;
        if (leftRacket.positionY >= (WINDOW_HEIGHT - LEFT_RACKET_HEIGHT))
        {
            leftRacket.positionY = (WINDOW_HEIGHT - LEFT_RACKET_HEIGHT);
        }
    }

    if (key == Qt::Key_Up)
    {
        rightRacket.positionY -= 50;
        if (rightRacket.positionY <= 0)
        {
            rightRacket.positionY = 1;
        }
    }

    if (key == Qt::Key_Down)
    {
        rightRacket.positionY += 50;
        if (rightRacket.positionY >= (WINDOW_HEIGHT - RIGHT_RACKET_HEIGHT))
        {
            rightRacket.positionY = (WINDOW_HEIGHT - RIGHT_RACKET_HEIGHT);
        }
    }
}

void Game::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();
    moveRackets(key);

    QWidget::keyPressEvent(e);
    repaint();
}



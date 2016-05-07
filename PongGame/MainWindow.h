#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "Ball.h"
#include "Racket.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *e);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *e);

private:
    void doPainting();
    void moveBall();
    void moveRackets(int key);

    static const int WINDOW_WIDTH            = 1000;
    static const int WINDOW_HEIGHT           = 800;
    static const int BALL_START_X            = 350;
    static const int BALL_START_Y            = 135;
    static const int BALL_SIZE               = 10;
    static const int BALL_SPEED_X            = 2;
    static const int BALL_SPEED_Y            = 2;
    static const int LEFT_RACKET_START_X     = 50;
    static const int LEFT_RACKET_START_Y     = 365;
    static const int LEFT_RACKET_WIDTH       = 20;
    static const int LEFT_RACKET_HEIGHT      = 70;
    static const int RIGHT_RACKET_START_X    = 930;
    static const int RIGHT_RACKET_START_Y    = 365;
    static const int RIGHT_RACKET_WIDTH      = 20;
    static const int RIGHT_RACKET_HEIGHT     = 70;

    int timerId;
    Ball ball ;
    Racket leftRacket;
    Racket rightRacket;

};

#endif // MAINWINDOW_H

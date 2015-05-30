#ifndef FLOCKWIDGET_H
#define FLOCKWIDGET_H

#include <QWidget>
#include "animal.h"
#include <QList>
#include <QTimer>

#define ATT_FACTOR_MIN -100
#define ATT_FACTOR_DEFAULT 35
#define ATT_FACTOR_MAX 150

#define DIST_FACTOR_MIN 10
#define DIST_FACTOR_DEFAULT 250
#define DIST_FACTOR_MAX 1000

#define SPEED_FACTOR_MIN -400
#define SPEED_FACTOR_DEFAULT 500
#define SPEED_FACTOR_MAX 1000

#define JITTER_MIN 0
#define JITTER_DEFAULT 23
#define JITTER_MAX 100

#define PARANOIA_MIN -200
#define PARANOIA_DEFAULT 460
#define PARANOIA_MAX 1000

#define AGG_MIN -100
#define AGG_MAX 500
#define AGG_DEFAULT 75

#define MAX_FOOD_DROPS 10

#define MAX_FOOD_AMOUNT 100

class FlockWidget : public QWidget
{
    Q_OBJECT

public:
    FlockWidget(QWidget *parent = 0);

    QTimer *flockTimer;

    QList<Animal*> friends;
    QList<Animal*> foes;
    QList<Food*> food;

    //Variable settings
    double attractionFactor;
    double distanceFactor;
    double speedFactor;
    double jitterFactor;
    double paranoiaFactor;
    double aggressionFactor;

public slots:
    void updateFlock();

    void drawAnimal(QPainter *painter, Animal *animal);

    void drawFood(QPainter *painter, Food *food);

protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // FLOCKWIDGET_H

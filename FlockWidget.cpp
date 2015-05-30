#include "FlockWidget.h"

#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <QTime>

QColor FOE_COLOR(220,80,50);
QColor FRIEND_COLOR(75,200,60);
QColor FOOD_COLOR(180,180,250);

#define FRAME_TIME 40 //50FPS

#define STARTING_FRIENDS    100
#define STARTING_FOES       3

FlockWidget::FlockWidget(QWidget *parent) : QWidget(parent)
{
    flockTimer = new QTimer(this);
    connect(flockTimer,SIGNAL(timeout()), this, SLOT(updateFlock()));
    flockTimer->start(FRAME_TIME);

    attractionFactor = ATT_FACTOR_DEFAULT;
    distanceFactor = DIST_FACTOR_DEFAULT;
    speedFactor = SPEED_FACTOR_DEFAULT;
    jitterFactor = JITTER_DEFAULT;
    paranoiaFactor = PARANOIA_DEFAULT;
    aggressionFactor = AGG_DEFAULT;
}

void FlockWidget::mousePressEvent(QMouseEvent *event)
{
    if (food.size() < MAX_FOOD_DROPS)
    {
        food.append(new Food(event->x(), event->y(), random(MAX_FOOD_AMOUNT/2, MAX_FOOD_AMOUNT)));
    }
}

void FlockWidget::paintEvent(QPaintEvent *event)
{    
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    painter.fillRect(0,0,width(),height(),QColor(50,50,75));

    //Draw food
    for (int i=0;i<food.count();i++)
    {
        drawFood(&painter, food[i]);
    }

    //Draw all the friendz!
    for (int i=0;i<friends.count();i++)
    {
        drawAnimal(&painter, friends[i]);
    }

    for (int i=0;i<foes.count();i++)
    {
        drawAnimal(&painter, foes[i]);
    }

}

void FlockWidget::drawFood(QPainter *painter, Food *food)
{
    static QPen pen;
    static QBrush brush;

    FOOD_COLOR.setAlpha(190);

    if (painter == NULL || food == NULL) return;

    pen.setColor(FOOD_COLOR);
    pen.setWidthF(1.5);

    brush.setColor(FOOD_COLOR);

    painter->setPen(pen);
    painter->setBrush(brush);

//    painter->drawEllipse(QPoint(food->xPos,food->yPos),food->radius,food->radius);
    painter->drawPie(food->xPos-food->radius,food->yPos-food->radius,2*food->radius,2*food->radius,16*90,16*360*food->amount/(double)MAX_FOOD_AMOUNT);
}

void FlockWidget::drawAnimal(QPainter *painter, Animal *animal)
{
    static QPen pen;
    static QBrush brush;

    if (animal == NULL || painter == NULL) return;

    pen.setColor(animal->color);
    pen.setWidth(2);
    brush.setColor(animal->color);

    painter->setBrush(brush);
    painter->setPen(pen);



    painter->drawEllipse(QPoint(animal->xPos,animal->yPos),animal->size,animal->size);

    double angle = atan2(animal->ySpeed, animal->xSpeed);

    double x2 = 1.45 * animal->size * cos(angle);
    double y2 = 1.45 * animal->size * sin(angle);

    painter->drawLine(animal->xPos, animal->yPos, animal->xPos + x2, animal->yPos + y2);
}

void FlockWidget::updateFlock()
{
    static bool animalsConfigured = false;

    if (!animalsConfigured)
    {
        animalsConfigured = true;

        //Add friends and foes
        for (int i=0;i<STARTING_FRIENDS;i++)
        {
            friends.append(new Animal(random(0,width()),random(0,height()),FRIEND_COLOR));
        }

        for (int i=0;i<STARTING_FOES;i++)
        {
            foes.append(new Animal(random(0,width()),random(0,height()),FOE_COLOR));
        }
    }

    Animal *a;

    //Move friends towards other friends
    for (int i=0;i<friends.count();i++)
    {
        //Add le jitter!
        friends[i]->addJitter(jitterFactor);

        //Move towards food!!
        for (int f=0;f<food.count();f++)
        {
            friends[i]->findFood(food[f],width(),height(),0.05);
        }

        for (int j=0;j<friends.count();j++)
        {
            if (i == j) continue;

            a = friends[j];

            friends[i]->moveTowardsFriend(a->xPos, a->yPos,
                                          a->size,
                                          a->xSpeed, a->ySpeed,
                                          width(), height(),
                                          attractionFactor,
                                          distanceFactor,
                                          speedFactor);
        }

        for (int e=0;e<foes.count();e++)
        {
            a = foes[e];

            friends[i]->fleeFromEnemy(a->xPos, a->yPos,
                                      a->size,
                                      width(), height(),
                                      paranoiaFactor);

            //Also, this enemy chases the 'friend'
            a->chase(friends[i]->xPos,friends[i]->yPos,
                     friends[i]->size,
                     width(), height(),
                     aggressionFactor);
        }
    }


    //Update the friends and foes
    int j =0;
    while (j < friends.count())
    {
        friends[j]->move(3);
        friends[j]->clip(width(), height());

        if (friends[j]->hunger >= ANIMAL_MAX_HUNGER) //starved!! :(
        {
            friends.removeAt(j);
            //Add a new friend
//            friends.append(new Animal(random(0, width()), random(0, height()), FRIEND_COLOR));
            continue;
        }

        j++; //move to the next animal
    }

    for (int i=0;i<foes.count();i++)
    {
        foes[i]->move(3);
        foes[i]->clip(width(), height());
    }

    //remove empty foods
    j = 0;
    while (j < food.count())
    {
        if (food[j]->amount <= FOOD_MIN)
        {
            food.removeAt(j);
            continue;
        }

        j++;
    }

    repaint();
}

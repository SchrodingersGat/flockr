#ifndef ANIMAL_H
#define ANIMAL_H

#include <qmath.h>
#include <math.h>

#include <QColor>
#include <QPainter>

#define PI 3.14159265359

#define ANIMAL_SIZE_MIN 2.4
#define ANIMAL_SIZE_MAX 4.6

#define START_SPEED_MAX 5.1

#define ANIMAL_MAX_HUNGER 250

#define HUNGER_THRESHOLD 35

#define FOOD_MIN 0   //amount of food before a drop gets depleted

#define FOOD_MULTIPLY_FACTOR 14.5    //How much 'hunger' is abated by each food unit
#define ANIMAL_HUNGER_FACTOR 0.0025

#define MAX_FOOD_RADIUS 15
#define MIN_FOOD_RADIUS 50

double random(double a, double b);

class Food
{
public:
    Food(double x, double y, double a);

    double xPos;
    double yPos;

    double amount;

    double radius;

    double eat(double a); //returns true if is expireds
};

class Animal
{
public:
    Animal(double X, double Y, QColor c);

    /* Parameters */

    QColor color;

    //Current position
    double xPos;
    double yPos;

    //Current Speed
    double xSpeed;
    double ySpeed;

    double xAcc;
    double yAcc;

    double size;

    double hunger;

    /* Functions */
    void move(double maxSpeed);
    void clip(int width, int height);
    void addJitter(double jif);

    double hDistance(double x, int w);
    double vDistance(double y, int h);

    void findFood(Food *f, int w, int h, double hungerFactor);

    void moveTowardsFriend(double x, double y, double s, double sx, double sy, int w, int h, double attractionFactor, double offsetFactor, double speedFactor);

    void fleeFromEnemy(double x, double y, double s, int w, int h, double paranoia);

    void chase(double x, double y, double s, int w, int h, double aggression);
};

#endif // ANIMAL_H

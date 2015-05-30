#include "animal.h"
#include <QPointF>
#include <QDebug>
#include <QTime>

double random(double a, double b)
{
    double r = (double) qrand() / RAND_MAX;

    r *= (b - a);

    r += a;

    return r;
}

Food::Food(double x, double y, double a)
{
    xPos = x;
    yPos = y;

    amount = a;

    radius = random(MIN_FOOD_RADIUS, MAX_FOOD_RADIUS);
}

double Food::eat(double a)
{

    if (a < 0) return 0;

    if (amount > (a + FOOD_MIN))
    {
        amount -= a;
        return a;
    }
    else if (amount > FOOD_MIN)
    {
        a = amount - FOOD_MIN;
        amount = FOOD_MIN;
        return a;
    }
    else
    {
        return 0;
    }
}

Animal::Animal(double X, double Y, QColor c)
{
    color = c;

    xPos = X;
    yPos = Y;

    xSpeed = random(-START_SPEED_MAX,START_SPEED_MAX);
    ySpeed = random(-START_SPEED_MAX,START_SPEED_MAX);

    xAcc = 0;
    yAcc = 0;

    hunger = 0;

    size = random(ANIMAL_SIZE_MIN, ANIMAL_SIZE_MAX);
}

/* Update the position */
void Animal::move(double maxSpeed)
{
    //Update the speed
    xSpeed += xAcc;
    ySpeed += yAcc;

    //Reduce the max speed based on how hungry we are!!

    double speedReduction = ANIMAL_MAX_HUNGER / hunger;

    if (speedReduction >  1) speedReduction = 1;
    if (speedReduction <= 0) speedReduction = 1;

    maxSpeed *= speedReduction;

    double angle = 0;
    double speed = xSpeed * xSpeed + ySpeed * ySpeed;

    if (speed > (maxSpeed * maxSpeed))
    {
        speed = sqrt(speed);

        if (speed < -maxSpeed) speed = -maxSpeed;
        if (speed >  maxSpeed) speed =  maxSpeed;

        angle = atan2(ySpeed, xSpeed);

        xSpeed = speed * cos(angle);
        ySpeed = speed * sin(angle);
    }

    //Update the position
    xPos += xSpeed;
    yPos += ySpeed;

    xAcc = 0;
    yAcc = 0;

    //Update hunger (based on size and how far we moved
    hunger += speed * size * ANIMAL_HUNGER_FACTOR;

    //Clip hunger
    if (hunger > ANIMAL_MAX_HUNGER) hunger = ANIMAL_MAX_HUNGER;

    if (hunger < 0) color.setAlpha(0xFF);
    else color.setAlpha(0xFF - hunger);
}

void Animal::clip(int width, int height)
{
    //Clip the position to the screen boundaries

    if (xPos < 0) xPos += width;
    if (xPos > width) xPos -= width;

    if (yPos < 0) yPos += height;
    if (yPos > height) yPos -= height;
}

void Animal::addJitter(double jif)
{
    jif /= 10;

    jif *= random(0.9,1.1);

    jif /= size; //little ones wiggle moar

    //jif = Jitter Factor
    xSpeed += random(-jif, jif);
    ySpeed += random(-jif, jif);
}

double Animal::hDistance(double x, int w)
{
    double dx = x - xPos;

    if (dx > w/2)
    {
        dx -= w;
    }
    if (dx <= -w/2)
    {
        dx += w;
    }

    return dx;
}

double Animal::vDistance(double y, int h)
{
    double dy = y - yPos;

    if (dy > h/2)
    {
        dy -= h;
    }
    if (dy < -h/2)
    {
        dy += h;
    }

    return dy;
}

void Animal::moveTowardsFriend(double x, double y, double s, double sx, double sy, int w, int h, double attractionFactor, double offsetFactor, double speedFactor)
{
    double dx = hDistance(x,w);
    double dy = vDistance(y,h);

    double dd = dx * dx + dy * dy;

    double angle = atan2(dy,dx);

    //Size ratio
    double sr = s / size;

    sr -= 0.5;

    offsetFactor /= 10;

    if (dd < (offsetFactor * offsetFactor))
    {
        dd = -(offsetFactor * offsetFactor);
    }

    attractionFactor *= random(0.95,1.05);

    double force = attractionFactor / dd;

    double xF = force * cos(angle);
    double yF = force * sin(angle);

    xAcc += xF;
    yAcc += yF;

    speedFactor /= 20;

    speedFactor *= random(0.9,1.1);

    xAcc += speedFactor * sx / dd;
    yAcc += speedFactor * sy / dd;
}

void Animal::fleeFromEnemy(double x, double y, double s, int w, int h, double paranoia)
{
    double dx = hDistance(x, w);
    double dy = vDistance(y, h);

    double dd = dx*dx + dy*dy;

    double dr = s / size;

    dr *= dr;

    double force = -1 * paranoia * dr / dd;

    double angle = atan2(dy,dx);

    xAcc += force * cos(angle);
    yAcc += force * sin(angle);
}

void Animal::findFood(Food *f, int w, int h, double hungerFactor)
{
    //Move towards food depending on overall hunger factor and my own hunger

    double dx = hDistance(f->xPos, w);
    double dy = vDistance(f->yPos, h);

    double dd = dx*dx + dy*dy;

    double force;

    if (hunger < HUNGER_THRESHOLD)
    {
        force = 0;
    }
    else
    {
        force = hunger * hunger * f->amount * hungerFactor / dd;
    }

    double angle = atan2(dy, dx);

    xAcc += force * cos(angle);
    yAcc += force * sin(angle);

    //Are we below the food radius??
    if (hunger > HUNGER_THRESHOLD && dd < (f->radius * f->radius) && hunger > 0)
    {
        hunger -= FOOD_MULTIPLY_FACTOR * f->eat(0.1 * hunger * size);
    }
}

void Animal::chase(double x, double y, double s, int w, int h, double aggression)
{
    double dx = hDistance(x, w);
    double dy = vDistance(y, h);

    double dd = dx*dx + dy*dy;

    double sr = (size / s);

    aggression /= 3;

    aggression *= random(0.98,1.02);

    //larger ones are more aggressive
    double force = aggression * size * sr / dd;

    double angle = atan2(dy,dx);

    xAcc += force * cos(angle);
    yAcc += force * sin(angle);
}

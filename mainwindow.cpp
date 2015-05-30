#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Flockr");

    ui->distanceFactor->setMinimum(DIST_FACTOR_MIN);
    ui->distanceFactor->setMaximum(DIST_FACTOR_MAX);
    ui->distanceFactor->setValue(DIST_FACTOR_DEFAULT);

    ui->attractionFactor->setMinimum(ATT_FACTOR_MIN);
    ui->attractionFactor->setMaximum(ATT_FACTOR_MAX);
    ui->attractionFactor->setValue(ATT_FACTOR_DEFAULT);

    ui->speedFactor->setMinimum(SPEED_FACTOR_MIN);
    ui->speedFactor->setMaximum(SPEED_FACTOR_MAX);
    ui->speedFactor->setValue(SPEED_FACTOR_DEFAULT);

    ui->jitter->setMinimum(JITTER_MIN);
    ui->jitter->setMaximum(JITTER_MAX);
    ui->jitter->setValue(JITTER_DEFAULT);

    ui->paranoia->setMinimum(PARANOIA_MIN);
    ui->paranoia->setMaximum(PARANOIA_MAX);
    ui->paranoia->setValue(PARANOIA_DEFAULT);

    ui->aggression->setMinimum(AGG_MIN);
    ui->aggression->setMaximum(AGG_MAX);
    ui->aggression->setValue(AGG_DEFAULT);

    connect(ui->distanceFactor,SIGNAL(valueChanged(int)),this,SLOT(sliderChanged(int)));
    connect(ui->attractionFactor,SIGNAL(valueChanged(int)),this,SLOT(sliderChanged(int)));
    connect(ui->speedFactor,SIGNAL(valueChanged(int)),this,SLOT(sliderChanged(int)));
    connect(ui->jitter,SIGNAL(valueChanged(int)),this,SLOT(sliderChanged(int)));
    connect(ui->paranoia,SIGNAL(valueChanged(int)),this,SLOT(sliderChanged(int)));
    connect(ui->aggression,SIGNAL(valueChanged(int)),this,SLOT(sliderChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sliderChanged(int val)
{
    int sender = (int) QObject::sender();

    FlockWidget *flock = ui->flockWidget;

    if (sender == (int) ui->attractionFactor) flock->attractionFactor = val;
    if (sender == (int) ui->speedFactor) flock->speedFactor = val;
    if (sender == (int) ui->distanceFactor) flock->distanceFactor = val;
    if (sender == (int) ui->jitter) flock->jitterFactor = val;
    if (sender == (int) ui->paranoia) flock->paranoiaFactor = val;
    if (sender == (int) ui->aggression) flock->aggressionFactor = val;
}

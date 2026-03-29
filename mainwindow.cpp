#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "graphwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    GraphWidget *graph = new GraphWidget(this);

    setCentralWidget(graph);
}

MainWindow::~MainWindow()
{
    delete ui;
}

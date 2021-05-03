#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_barchart_clicked()
{
    barchart = new BarChart(this);
    barchart->show();
}

void MainWindow::on_stackedbarchart_clicked()
{
    stackedbarchart = new StackedBarChart(this);
    stackedbarchart->show();
}

void MainWindow::on_piechart_clicked()
{
    piechart = new PieChart(this);
    piechart->show();
}

void MainWindow::on_donutchart_clicked()
{
    donutchart = new DonutChart(this);
    donutchart->show();
}

void MainWindow::on_linechart_clicked()
{
    linechart = new LineChart(this);
    linechart->show();
}

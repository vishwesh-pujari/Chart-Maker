#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "barchart.h"
#include "stackedbarchart.h"
#include "piechart.h"
#include "donutchart.h"
#include "linechart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_barchart_clicked();

    void on_stackedbarchart_clicked();

    void on_piechart_clicked();

    void on_donutchart_clicked();

    void on_linechart_clicked();

private:
    Ui::MainWindow *ui;

    BarChart *barchart;
    StackedBarChart *stackedbarchart;
    PieChart *piechart;
    DonutChart *donutchart;
    LineChart *linechart;
};
#endif // MAINWINDOW_H

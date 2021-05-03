#ifndef BARCHART_H
#define BARCHART_H

#include <QMainWindow>
#include "barchartdisplay.h"

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>

namespace Ui {
class BarChart;
}

class BarChart : public QMainWindow
{
    Q_OBJECT

public:
    explicit BarChart(QWidget *parent = nullptr);
    ~BarChart();

private slots:
    void on_dataTypeCombo_currentTextChanged(const QString &arg1);

    void on_bars_currentTextChanged(const QString &arg1);

    void on_draw_clicked();

private:
    Ui::BarChart *ui;
    void categoriesHandling(QStringList &categories);
    void barsHandling();
    BarChartDisplay *barchartdisplay;
};

#endif // BARCHART_H

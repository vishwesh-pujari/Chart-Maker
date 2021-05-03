#ifndef PIECHART_H
#define PIECHART_H

#include <QMainWindow>
#include "piechartdisplay.h"

// Widget used to display charts
#include <QtCharts/QChartView>

// Used to draw bars representing data provided
// grouped into categories
#include <QtCharts/QBarSeries>

// Represents 1 set of bars in a bar chart
#include <QtCharts/QBarSet>

// Displays the color used to represent each
// QBarSet
#include <QtCharts/QLegend>

// Adds categories to the charts axes
#include <QtCharts/QBarCategoryAxis>

// Used to create stacked bar charts
#include <QtCharts/QHorizontalStackedBarSeries>

// Used to create a line chart
#include <QtCharts/QLineSeries>

// Used to change names on axis
#include <QtCharts/QCategoryAxis>

// Used to make Pie Charts
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

namespace Ui {
class PieChart;
}

class PieChart : public QMainWindow
{
    Q_OBJECT

public:
    explicit PieChart(QWidget *parent = nullptr);
    ~PieChart();

private slots:
    void on_draw_clicked();

private:
    Ui::PieChart *ui;
    PieChartDisplay *piechartdisplay;
};

#endif // PIECHART_H

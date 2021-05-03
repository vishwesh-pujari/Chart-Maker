#ifndef STACKEDBARCHART_H
#define STACKEDBARCHART_H

#include <QMainWindow>
#include "stackedbarchartdisplay.h"

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
class StackedBarChart;
}

class StackedBarChart : public QMainWindow
{
    Q_OBJECT

public:
    explicit StackedBarChart(QWidget *parent = nullptr);
    ~StackedBarChart();

private slots:
    void on_dataTypeCombo_currentTextChanged(const QString &arg1);

    void on_bars_currentTextChanged(const QString &arg1);

    void on_draw_clicked();

private:
    Ui::StackedBarChart *ui;
    void categoriesHandling(QStringList &categories);
    void barsHandling();
    StackedBarChartDisplay *stackedbarchartdisplay;
};

#endif // STACKEDBARCHART_H

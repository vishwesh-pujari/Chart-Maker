#ifndef LINECHART_H
#define LINECHART_H

#include <QMainWindow>
#include "linechartdisplay.h"

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
class LineChart;
}

class LineChart : public QMainWindow
{
    Q_OBJECT

public:
    explicit LineChart(QWidget *parent = nullptr);
    ~LineChart();

private slots:
    void on_draw_clicked();

    void on_dataTypeCombo_currentTextChanged(const QString &arg1);

private:
    Ui::LineChart *ui;
    LineChartDisplay *linechartdisplay;
};

#endif // LINECHART_H

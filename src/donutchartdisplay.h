#ifndef DONUTCHARTDISPLAY_H
#define DONUTCHARTDISPLAY_H

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPrinter>
#include <QPrintDialog>

namespace Ui {
class DonutChartDisplay;
}

class DonutChartDisplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit DonutChartDisplay(QWidget *parent = nullptr, QChartView *chartview = NULL);
    ~DonutChartDisplay();

private slots:
    void on_actionPrint_triggered();

private:
    Ui::DonutChartDisplay *ui;
};

#endif // DONUTCHARTDISPLAY_H

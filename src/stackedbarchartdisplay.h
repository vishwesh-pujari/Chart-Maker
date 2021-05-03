#ifndef STACKEDBARCHARTDISPLAY_H
#define STACKEDBARCHARTDISPLAY_H

#include <QMainWindow>

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPrinter>
#include <QPrintDialog>

namespace Ui {
class StackedBarChartDisplay;
}

class StackedBarChartDisplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit StackedBarChartDisplay(QWidget *parent = nullptr, QChartView* chartview=NULL);
    ~StackedBarChartDisplay();

private slots:
    void on_actionPrint_triggered();

private:
    Ui::StackedBarChartDisplay *ui;
};

#endif // STACKEDBARCHARTDISPLAY_H

#ifndef BARCHARTDISPLAY_H
#define BARCHARTDISPLAY_H

#include <QMainWindow>

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPrinter>
#include <QPrintDialog>

namespace Ui {
class BarChartDisplay;
}

class BarChartDisplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit BarChartDisplay(QWidget *parent = nullptr, QChartView* chartview=NULL);
    ~BarChartDisplay();

private slots:
    void on_actionPrint_triggered();

private:
    Ui::BarChartDisplay *ui;
};

#endif // BARCHARTDISPLAY_H

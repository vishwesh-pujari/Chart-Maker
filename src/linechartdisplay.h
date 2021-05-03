#ifndef LINECHARTDISPLAY_H
#define LINECHARTDISPLAY_H

#include <QMainWindow>

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPrinter>
#include <QPrintDialog>

namespace Ui {
class LineChartDisplay;
}

class LineChartDisplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit LineChartDisplay(QWidget *parent = nullptr, QChartView* chartview=NULL);
    ~LineChartDisplay();

private slots:
    void on_actionPrint_triggered();

private:
    Ui::LineChartDisplay *ui;
};

#endif // LINECHARTDISPLAY_H

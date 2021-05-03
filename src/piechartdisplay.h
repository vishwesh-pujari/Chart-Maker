#ifndef PIECHARTDISPLAY_H
#define PIECHARTDISPLAY_H

#include <QMainWindow>
#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPrinter>
#include <QPrintDialog>

namespace Ui {
class PieChartDisplay;
}

class PieChartDisplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit PieChartDisplay(QWidget *parent = nullptr, QChartView* chartview=NULL);
    ~PieChartDisplay();

private slots:
    void on_actionPrint_triggered();

private:
    Ui::PieChartDisplay *ui;
};

#endif // PIECHARTDISPLAY_H

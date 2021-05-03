#include "linechartdisplay.h"
#include "ui_linechartdisplay.h"

LineChartDisplay::LineChartDisplay(QWidget *parent, QChartView *chartview) :
    QMainWindow(parent),
    ui(new Ui::LineChartDisplay)
{
    ui->setupUi(this);
    this->setCentralWidget(chartview);
}

LineChartDisplay::~LineChartDisplay()
{
    delete ui;
}

void LineChartDisplay::on_actionPrint_triggered()
{
    // while printing
    // maximise the screen -> select Preferences in Print Dialog -> Choose Landscape -> Choose A3 -> Print
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle("Print BarChart");
    dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);

    if (dialog.exec() != QDialog::Accepted)
        return;
    this->render(&printer);
}

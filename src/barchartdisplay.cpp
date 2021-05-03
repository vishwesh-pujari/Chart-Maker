#include "barchartdisplay.h"
#include "ui_barchartdisplay.h"

BarChartDisplay::BarChartDisplay(QWidget *parent, QChartView *chartview) :
    QMainWindow(parent),
    ui(new Ui::BarChartDisplay)
{
    ui->setupUi(this);
    this->setCentralWidget(chartview);
}

BarChartDisplay::~BarChartDisplay()
{
    delete ui;
}

void BarChartDisplay::on_actionPrint_triggered()
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

#include "piechartdisplay.h"
#include "ui_piechartdisplay.h"

PieChartDisplay::PieChartDisplay(QWidget *parent, QChartView *chartview) :
    QMainWindow(parent),
    ui(new Ui::PieChartDisplay)
{
    ui->setupUi(this);
    this->setCentralWidget(chartview);
}

PieChartDisplay::~PieChartDisplay()
{
    delete ui;
}

void PieChartDisplay::on_actionPrint_triggered()
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

#include "stackedbarchartdisplay.h"
#include "ui_stackedbarchartdisplay.h"

StackedBarChartDisplay::StackedBarChartDisplay(QWidget *parent, QChartView *chartview) :
    QMainWindow(parent),
    ui(new Ui::StackedBarChartDisplay)
{
    ui->setupUi(this);
    this->setCentralWidget(chartview);
}

StackedBarChartDisplay::~StackedBarChartDisplay()
{
    delete ui;
}

void StackedBarChartDisplay::on_actionPrint_triggered()
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

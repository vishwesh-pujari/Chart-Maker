#include "donutchartdisplay.h"
#include "ui_donutchartdisplay.h"

DonutChartDisplay::DonutChartDisplay(QWidget *parent, QChartView *chartview) :
    QMainWindow(parent),
    ui(new Ui::DonutChartDisplay)
{
    ui->setupUi(this);
    this->setCentralWidget(chartview);
}

DonutChartDisplay::~DonutChartDisplay()
{
    delete ui;
}

void DonutChartDisplay::on_actionPrint_triggered()
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

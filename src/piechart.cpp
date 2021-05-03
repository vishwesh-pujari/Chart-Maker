#include "piechart.h"
#include "ui_piechart.h"
#include <QDebug>

using namespace QtCharts;

PieChart::PieChart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PieChart)
{
    ui->setupUi(this);
}

PieChart::~PieChart()
{
    delete ui;
}

void PieChart::on_draw_clicked()
{
    // 4. Pie Chart Example
    // Define slices and percentage of whole they take up

    QString labels, values;
    if (ui->lineEdit_2->text() != "")
        labels = ui->lineEdit_2->text();
    else
        labels = ui->lineEdit_2->placeholderText();

    if (ui->lineEdit_3->text() != "")
        values = ui->lineEdit_3->text();
    else
        values = ui->lineEdit_3->placeholderText();

    QStringList labelList = labels.split(" ");
    QStringList valuesList = values.split(" ");

    int i;
    QPieSeries *series = new QPieSeries();
    int size = valuesList.size();

    for (i = 0; i < size; i++)
        series->append(labelList.at(i), valuesList.at(i).toFloat() / 100);

//    QPieSeries *series = new QPieSeries();
//    series->append("Vegetables",.40);
//    series->append("Beans",.20);
//    series->append("Fruits",.15);
//    series->append("Seeds/Nuts",.10);
//    series->append("Whole Grains",.15);

    // Add label to 1st slice
    QPieSlice **slices = new QPieSlice*[size];
    for (i = 0; i < size; i++) {
        slices[i] = series->slices().at(i);
        slices[i]->setLabelVisible();
        if (i == 1)
            slices[1]->setExploded();
    }

//    QPieSlice *slice0 = series->slices().at(0);
//    slice0->setLabelVisible();

//    // Add label, explode and define brush for 2nd slice
//    QPieSlice *slice1 = series->slices().at(1);
//    slice1->setExploded();
//    slice1->setLabelVisible();
//    slice1->setPen(QPen(Qt::darkGreen, 2));
//    slice1->setBrush(Qt::green);

//    // Add labels to rest of slices
//    QPieSlice *slice2 = series->slices().at(2);
//    slice2->setLabelVisible();
//    QPieSlice *slice3 = series->slices().at(3);
//    slice3->setLabelVisible();
//    QPieSlice *slice4 = series->slices().at(4);
//    slice4->setLabelVisible();

    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and hide legend
    chart->addSeries(series);
    if (ui->lineEdit->text() != "")
        chart->setTitle(ui->lineEdit->text());
    else
        chart->setTitle(ui->lineEdit->placeholderText());
    //chart->legend()->hide();
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTheme(QChart::ChartThemeBlueCerulean);

    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404040));
    qApp->setPalette(pal);
    //this->setCentralWidget(chartView);
    piechartdisplay = new PieChartDisplay(this, chartView);
    piechartdisplay->show();
}

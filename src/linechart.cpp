#include "linechart.h"
#include "ui_linechart.h"

using namespace QtCharts;

LineChart::LineChart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LineChart)
{
    ui->setupUi(this);
}

LineChart::~LineChart()
{
    delete ui;
}

void LineChart::on_draw_clicked()
{
    QLineSeries *series = new QLineSeries();

    QString l1;

    if (ui->l1->text() != "")
        l1 = ui->l1->text();
    else
        l1 = ui->l1->placeholderText();

    QStringList l1list = l1.split(" ");
    int i, size = l1list.size();
    for (i = 0; i < size; i++)
        series->append(i, l1list.at(i).toFloat());
//    series->append(0, 16);
//    series->append(1, 25);
//    series->append(2, 24);
//    series->append(3, 19);
//    series->append(4, 33);
//    series->append(5, 25);
//    series->append(6, 34);

    // Create chart, add data, hide legend, and add axis
    QChart *chart = new QChart();
    //chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();

    // Customize the title font
    QFont font;
    font.setPixelSize(18);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::black));
    if (ui->graphTitle->text() == "")
        chart->setTitle(ui->graphTitle->placeholderText());
    else
        chart->setTitle(ui->graphTitle->text());

    // Change the line color and weight
    QPen pen(QRgb(0x000000));
    pen.setWidth(5);
    series->setPen(pen);

    chart->setAnimationOptions(QChart::AllAnimations);

    // Change the x axis categories
    QCategoryAxis *axisX = new QCategoryAxis();
//    axisX->append("1986",0);
//    axisX->append("1987",1);
//    axisX->append("1988",2);
//    axisX->append("1989",3);
//    axisX->append("1990",4);
//    axisX->append("1991",5);
//    axisX->append("1992",6);
    QString datavalues;
    if (ui->dataValues->text() != "")
        datavalues = ui->dataValues->text();
    else
        datavalues = ui->dataValues->placeholderText();
    QStringList datavallist = datavalues.split(" ");

    if (ui->dataTypeCombo->currentText() == "Data Labels" || ui->dataTypeCombo->currentText() == "Data Values") {
        size = datavallist.size();
        for (i = 0; i < size; i++)
            axisX->append(datavallist.at(i), i);
    } else { // Data Range
        int num1 = datavallist.at(0).toInt();
        int num2 = datavallist.at(1).toInt();
        int j = 0;

        if (num1 < num2) {
            for (i = num1, j = 0; i <= num2; i++, j++)
                axisX->append(QString::number(i), j);
        } else {
            for (i = num1, j = 0; i >= num2; i--, j++)
                axisX->append(QString::number(i), j);
        }
    }
    if (ui->hLabel->text() == "")
        axisX->setTitleText(ui->hLabel->placeholderText());
    else
        axisX->setTitleText(ui->hLabel->text());
    chart->setAxisX(axisX, series);

//    QCategoryAxis *axisY = new QCategoryAxis();
//    axisY->setTitleText("Y Axis");
//    chart->setAxisY(axisY, series);
    QValueAxis *axisY = new QValueAxis();
    if (ui->vLabel->text() == "")
        axisY->setTitleText(ui->vLabel->placeholderText());
    else
        axisY->setTitleText(ui->vLabel->text());
    chart->setAxisY(axisY, series);

    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404040));
    qApp->setPalette(pal);
    //this->setCentralWidget(chartView);
    linechartdisplay = new LineChartDisplay(this, chartView);
    linechartdisplay->show();
}

void LineChart::on_dataTypeCombo_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Data Labels")
        ui->dataValues->setPlaceholderText("name_1 name_2 name_3 name_4 ...");
    else if (arg1 == "Data Values")
        ui->dataValues->setPlaceholderText("1 2 3 4 ...");
    else if (arg1 == "Data Range")
        ui->dataValues->setPlaceholderText("1 4");
}

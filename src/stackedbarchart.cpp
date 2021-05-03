#include "stackedbarchart.h"
#include "ui_stackedbarchart.h"
#include <QDebug>

QLineEdit *arr1[14];

StackedBarChart::StackedBarChart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StackedBarChart)
{
    ui->setupUi(this);
    arr1[0] = ui->l1;
    arr1[1] = ui->l2;
}

StackedBarChart::~StackedBarChart()
{
    delete ui;
}

void StackedBarChart::on_dataTypeCombo_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Data Labels")
        ui->dataValues->setPlaceholderText("name_1 name_2 name_3 name_4 ...");
    else if (arg1 == "Data Values")
        ui->dataValues->setPlaceholderText("1 2 3 4 ...");
    else if (arg1 == "Data Range")
        ui->dataValues->setPlaceholderText("1 4");
}

void StackedBarChart::on_bars_currentTextChanged(const QString &arg1)
{
    int bars = arg1[0].unicode() - '0';
    //ui->lineEdit_7->setText(QString::number(bars));
    //qDebug() << bars;

    int i, j;
    QLabel *label, *label1;
    QLineEdit *lineEdit, *lineEdit1;
    QString string;

    int rowCount = ui->formLayout->rowCount();
    //qDebug() << rowCount;
    for (i = rowCount - 1; i >= 12; i--) { // deleting the rows uptil row 13
        ui->formLayout->removeRow(i);
    }

    for (i = 1, j = 0; i <= 2*bars; i=i+2, j++) { // inserting rows
        label = new QLabel();
        string.sprintf("Bar%d data values", j+1);
        label->setText(string);
        lineEdit = new QLineEdit();
        lineEdit->setPlaceholderText("300 500 100 200");
        string.sprintf("l%d", j+1);
        lineEdit->setObjectName(string);
        ui->formLayout->addRow(label, lineEdit);
        arr1[i-1] = lineEdit;
        label1 = new QLabel();
        string.sprintf("Bar%d Name", j+1);
        label1->setText(string);
        lineEdit1 = new QLineEdit();
        string.sprintf("Bar%d", j+1);
        lineEdit1->setPlaceholderText(string);
        string.sprintf("l%d", j+1);
        lineEdit1->setObjectName(string);
        ui->formLayout->addRow(label1, lineEdit1);
        arr1[i] = lineEdit1;
        //qDebug() << lineEdit1->objectName();
    }

}

void StackedBarChart::on_draw_clicked()
{
    int bars = ui->bars->currentText()[0].unicode() - '0';
    qDebug() << bars;
    QBarSet **sets = new QBarSet*[bars];
    QString datavalues;

    int i, j, k;
    for (i = 0, k = 0; i < 2*bars; i=i+2, k++) {
        if (arr1[i+1]->text() != "") {
            sets[k] = new QBarSet(arr1[i+1]->text());
            qDebug() << arr1[i+1]->text();
        }else {
            sets[k] = new QBarSet(arr1[i+1]->placeholderText());
            qDebug() << arr1[i+1]->placeholderText();
        }

        QString *string = new QString();

        if (arr1[i]->text() != "")
            datavalues = arr1[i]->text();
        else
            datavalues = arr1[i]->placeholderText();

        for (j = 0; datavalues[j].unicode(); j++) {
            if (datavalues[j].unicode() == ' ') {
                *sets[k] << string->toInt();
                delete string;
                string = new QString();
            } else {
                *string += datavalues[j];
            }
        }
        *sets[k] << string->toInt();
        delete string;
        qDebug() << k;
        qDebug() << i;
    }

//    QBarSet *set0 = new QBarSet("Bob");
//    QBarSet *set1 = new QBarSet("Tom");
//    QBarSet *set2 = new QBarSet("John");
//    QBarSet *set3 = new QBarSet("Doe");
//    QBarSet *set4 = new QBarSet("Ahmed");

    //*sets[0] << 30 << 40 << 10 << 20 << 10 << 60;
    //        *sets[1] << 10 << 30 << 42 << 15 << 81 << 75;
    //        *sets[2] << 80 << 100 << 70 << 13 << 60 << 20;
    //        *sets[3] << 30 << 10 << 80 << 70 << 60 << 45;
    //        *sets[4] << 100 << 40 << 70 << 30 << 16 << 42;

    QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();

    for (i = 0; i < bars; i++)
        series->append(sets[i]);

//    series->append(sets[0]);
//    series->append(sets[1]);
//    series->append(sets[2]);
//    series->append(sets[3]);
//    series->append(sets[4]);

    QChart *chart = new QChart();
    chart->addSeries(series);
    if (ui->graphTitle->text() == "")
        chart->setTitle(ui->graphTitle->placeholderText());
    else
        chart->setTitle(ui->graphTitle->text());
    chart->setAnimationOptions(QChart::AllAnimations);

    QStringList categories;
    //categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "June";
//    categories << "Jan";
//    categories << "Feb";
//    categories << "Mar";
//    categories << "Apr";
//    categories << "May";
//    categories << "Jun";
    categoriesHandling(categories);


    // add the categories to the axis
//    QBarCategoryAxis *axis = new QBarCategoryAxis();
//    axis->append(categories);
//    axis->setTitleText("X axis");
//    chart->createDefaultAxes();
//    chart->setAxisX(axis, series);

    QBarCategoryAxis *axisY = new QBarCategoryAxis();
    axisY->append(categories);
    if (ui->vLabel->text() == "")
        axisY->setTitleText(ui->vLabel->placeholderText());
    else
        axisY->setTitleText(ui->vLabel->text());
    chart->setAxisY(axisY, series);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisX = new QValueAxis();
    if (ui->hLabel->text() == "")
        axisX->setTitleText(ui->hLabel->placeholderText());
    else
        axisX->setTitleText(ui->hLabel->text());
    chart->setAxisX(axisX, series);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404040));
    qApp->setPalette(pal);
    //this->setCentralWidget(chartview);
    stackedbarchartdisplay = new StackedBarChartDisplay(this, chartview);
    stackedbarchartdisplay->show();
}

void StackedBarChart:: categoriesHandling(QStringList &categories) {
    QString datavalues;
    int i;
    if (ui->dataValues->text() != "")
        datavalues = ui->dataValues->text();
    else
        datavalues = ui->dataValues->placeholderText();

    if (ui->dataTypeCombo->currentText() == "Data Labels" || ui->dataTypeCombo->currentText() == "Data Values") {
        QString *string = new QString();

        for (i = 0; datavalues[i].unicode(); i++) {
            if (datavalues[i].unicode() == ' ') {
                categories << *string;
                delete string;
                string = new QString();
            } else {
                *string += datavalues[i];
            }
        }
        categories << *string;
        delete string;

    } else if (ui->dataTypeCombo->currentText() == "Data Range") {
        QString *string = new QString();
        int num1, num2;

        for (i = 0; datavalues[i].unicode() != ' '; i++)
            *string += datavalues[i];
        qDebug() << *string;

        num1 = string->toInt();

        delete string;
        string = new QString();

        for (i = i + 1; datavalues[i].unicode(); i++)
            *string += datavalues[i];

        qDebug() << *string;
        num2 = string->toInt();

        delete string;

        if (num1 < num2)
            for (i = num1; i <= num2; i++)
                categories << QString::number(i);
        else
            for (i = num1; i >= num2; i--)
                categories << QString::number(i);

    }
}

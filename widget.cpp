#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)),
                     this, SLOT(compute_sum()));
    QObject::connect(ui->spinBox_2, SIGNAL(valueChanged(int)),
                     this, SLOT(compute_sum()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::compute_sum() const
{
    int hw1 = ui->spinBox_1->value();
    int hw2 = ui->spinBox_2->value();
    int hw3 = ui->spinBox_3->value();
    int hw4 = ui->spinBox_4->value();
    int hw5 = ui->spinBox_5->value();
    int hw6 = ui->spinBox_6->value();
    int hw7 = ui->spinBox_7->value();
    int hw8 = ui->spinBox_8->value();

    int mt1 = ui->spinBox_mt1->value();
    int mt2 = ui->spinBox_mt2->value();
    int fin = ui->spinBox_fin->value();

    double hwAvg = (hw1 + hw2 + hw3 + hw4 + hw5 + hw6 + hw7 + hw8) / 8;

    double totalP = 0;

    if (ui->radioButtonA)
    {
        double hwP = hwAvg * 0.25;
        double mt1P = mt1 * 0.2;
        double mt2P = mt2 * 0.2;
        double finP = fin * 0.35;

        totalP = hwP + mt1P + mt2P + finP;
    }

    else if (ui->radioButtonB)
    {
        double hwP = hwAvg * 0.25;
        double mtP = 0;

        if (mt1 > mt2)
            mtP = mt1 * 0.3;
        else if (mt2 > mt1)
            mtP = mt2 * 0.3;

        double finP = fin * 0.44;

        totalP = hwP + mtP + finP;
    }

    QString text(QString::number(totalP));

    ui->score->setText(text);
}

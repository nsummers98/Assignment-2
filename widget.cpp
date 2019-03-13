#include "widget.h"
#include "ui_widget.h"
#include <string>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QObject::connect(ui->spinBox_1, SIGNAL(valueChanged(int)),
                     this, SLOT(compute_sum()));
    QObject::connect(ui->spinBox_2, SIGNAL(valueChanged(int)),
                     this, SLOT(compute_sum()));
    QObject::connect(ui->spinBox_3, SIGNAL(valueChanged(int)),
                     this, SLOT(compute_sum()));
    QObject::connect(ui->spinBox_4, SIGNAL(valueChanged(int)),
                     this, SLOT(compute_sum()));
    QObject::connect(ui->spinBox_5, SIGNAL(valueChanged(int)),
                     this, SLOT(compute_sum()));
    QObject::connect(ui->spinBox_6, SIGNAL(valueChanged(int)),
                     this, SLOT(compute_sum()));
    QObject::connect(ui->spinBox_7, SIGNAL(valueChanged(int)),
                     this, SLOT(compute_sum()));
    QObject::connect(ui->spinBox_8, SIGNAL(valueChanged(int)),
                     this, SLOT(compute_sum()));
    QObject::connect(ui->spinBox_mt1, SIGNAL(valueChanged(int)),
                     this, SLOT(compute_sum()));
    QObject::connect(ui->spinBox_mt2, SIGNAL(valueChanged(int)),
                     this, SLOT(compute_sum()));
    QObject::connect(ui->spinBox_fin, SIGNAL(valueChanged(int)),
                     this, SLOT(compute_sum()));

    Widget::link(ui->spinBox_1, ui->horizontalSlider_1);
    Widget::link(ui->spinBox_2, ui->horizontalSlider_2);
    Widget::link(ui->spinBox_3, ui->horizontalSlider_3);
    Widget::link(ui->spinBox_4, ui->horizontalSlider_4);
    Widget::link(ui->spinBox_5, ui->horizontalSlider_5);
    Widget::link(ui->spinBox_6, ui->horizontalSlider_6);
    Widget::link(ui->spinBox_7, ui->horizontalSlider_7);
    Widget::link(ui->spinBox_8, ui->horizontalSlider_8);
    Widget::link(ui->spinBox_mt1, ui->horizontalSlider_mt1);
    Widget::link(ui->spinBox_mt2, ui->horizontalSlider_mt2);
    Widget::link(ui->spinBox_fin, ui->horizontalSlider_fin);
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

    if (ui->radioButtonA->isChecked())
    {
        double hwP = hwAvg * 0.25;
        double mt1P = mt1 * 0.2;
        double mt2P = mt2 * 0.2;
        double finP = fin * 0.35;

        totalP = hwP + mt1P + mt2P + finP;
    }

    else if (ui->radioButtonB->isChecked())
    {
        double hwP = hwAvg * 0.25;
        double mtP = 0;

        if (mt1 > mt2 || mt1 == mt2)
            mtP = mt1 * 0.3;
        else if (mt2 > mt1)
            mtP = mt2 * 0.3;

        double finP = fin * 0.44;

        totalP = hwP + mtP + finP;
    }

    QString text(QString::number(totalP));

    ui->score->setText(text);
}

void Widget::on_radioButtonA_clicked()
{
    this->compute_sum();
    return;
}

void Widget::on_radioButtonB_clicked()
{
    this->compute_sum();
    return;
}

void Widget::link(const QObject* spinBox, const QObject* hSlider)
{
    QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                     hSlider, SLOT(setValue(int)));
    QObject::connect(hSlider, SIGNAL(valueChanged(int)),
                     spinBox, SLOT(setValue(int)));
}

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void link(const QObject* spinBox, const QObject* hSlider);
    void disable(const QLayout* obj);

private slots:
    void compute_sum() const;

    void on_radioButtonA_clicked();

    void on_radioButtonB_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);



private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

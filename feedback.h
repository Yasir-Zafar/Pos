#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <QWidget>

namespace Ui {
class feedback;
}

class feedback : public QWidget
{
    Q_OBJECT

public:
    explicit feedback(QWidget *parent = nullptr);
    ~feedback();

private slots:

    void on_pushButton_clicked();

private:
    Ui::feedback *ui;
};

#endif // FEEDBACK_H

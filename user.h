#ifndef USER_H
#define USER_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

class User : public QWidget
{
    Q_OBJECT
public:
    explicit User(QWidget *parent = nullptr);
    void addLabel(const QString &text);

private:
    QHBoxLayout *horizontalLayout ;
};

#endif // USER_H

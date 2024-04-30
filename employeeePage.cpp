#include "employeePage.h"
#include "sidebar.h"

EmployeePage::EmployeePage(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QLabel* titleLabel = new QLabel("Employee Page", this);
    titleLabel->setFont(QFont("Arial", 20, QFont::Bold));
    mainLayout->addWidget(titleLabel);

    setLayout(mainLayout);
}

#include "../include/settings.h"

Settings::Settings(QWidget *parent) : QWidget(parent)
{
    setupUI();
}

void Settings::setupUI()
{
    mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignCenter);
    setLayout(mainLayout);

    QFrame *frame = new QFrame(this);
    frame->setObjectName("settingsFrame");

    frame->setStyleSheet("QFrame#settingsFrame {"
                         "    background-color: #f9f9f9;"
                         "    border-radius: 10px;"
                         "}");

    QVBoxLayout *frameLayout = new QVBoxLayout(frame);

    shutdownButton = new QPushButton("Shutdown", this);
    shutdownButton->setObjectName("shutdownButton");
    shutdownButton->setFixedSize(200, 50);
    shutdownButton->setStyleSheet("QPushButton#shutdownButton {"
                                  "background-color: #ff6347;"
                                  "border-radius: 15px;"
                                  "color: white;"
                                  "font-size: 18px;"
                                  "padding: 10px;"
                                  "}");

    connect(shutdownButton, &QPushButton::clicked, this, &Settings::shutdownApp);
    connect(shutdownButton, &QPushButton::clicked, this, &Settings::shutdownApp);

    updateInventoryButton = new QPushButton("Update Inventory", this);
    updateInventoryButton->setObjectName("updateInventoryButton");
    updateInventoryButton->setFixedSize(200, 50);
    updateInventoryButton->setStyleSheet("QPushButton#updateInventoryButton {"
                                         "background-color: #28A4A6;"
                                         "border-radius: 15px;"
                                         "color: white;"
                                         "font-size: 18px;"
                                         "padding: 10px;"
                                         "}");

    frameLayout->addWidget(updateInventoryButton);
    frameLayout->addWidget(shutdownButton);

    frameLayout->setContentsMargins(10, 10, 10, 10);

    mainLayout->addWidget(frame);

    mainLayout->setContentsMargins(20, 20, 20, 20);
}

void Settings::shutdownApp()
{
    qApp->exit();
}


void Settings::handleEmployeeLogin()
{
    shutdownButton->hide();
}

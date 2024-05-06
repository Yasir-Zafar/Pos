// settings.cpp
#include "settings.h"

Settings::Settings(QWidget *parent) : QWidget(parent)
{
    setupUI();
}

void Settings::setupUI()
{
    // Main layout
    mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignCenter);
    setLayout(mainLayout);

    // Frame for styling
    QFrame *frame = new QFrame(this);
    frame->setObjectName("settingsFrame");

    // CSS for the frame
    frame->setStyleSheet("QFrame#settingsFrame {"
                         "    background-color: #f9f9f9;"
                         "    border-radius: 10px;"
                         "}");

    // Layout for buttons
    QVBoxLayout *frameLayout = new QVBoxLayout(frame);

    // Shutdown button
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

    // Connect shutdown button signal
    connect(shutdownButton, &QPushButton::clicked, this, &Settings::shutdownApp);
    connect(shutdownButton, &QPushButton::clicked, this, &Settings::shutdownApp);

    // Update inventory button
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

    // Add buttons to frame layout
    frameLayout->addWidget(updateInventoryButton);
    frameLayout->addWidget(shutdownButton);

    // Set margins for the frame layout
    frameLayout->setContentsMargins(10, 10, 10, 10);

    // Add frame to main layout
    mainLayout->addWidget(frame);

    // Set main layout margins
    mainLayout->setContentsMargins(20, 20, 20, 20);
}

void Settings::shutdownApp()
{
    // Close the entire application
    qApp->exit();
}


void Settings::handleEmployeeLogin()
{
    shutdownButton->hide();
}

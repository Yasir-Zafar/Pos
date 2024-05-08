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
                         "    background-color: #f0f0f0;"
                         "    border-radius: 10px;"
                         "}");

    QVBoxLayout *frameLayout = new QVBoxLayout(frame);

    shutdownButton = new QPushButton("Shutdown", this);
    shutdownButton->setObjectName("shutdownButton");
    shutdownButton->setFixedSize(300, 75);
    shutdownButton->setStyleSheet("QPushButton#shutdownButton {"
                                  "background-color: #28A4A6;"
                                  "border-radius: 15px;"
                                  "color: white;"
                                  "font-size: 18px;"
                                  "padding: 10px;"
                                  "}");

    connect(shutdownButton, &QPushButton::clicked, this, &Settings::shutdownApp);

    frameLayout->addWidget(shutdownButton);
    frameLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->addWidget(frame);
    mainLayout->setContentsMargins(20, 20, 20, 20);
}

// Function to perform backup of SQL files
void Settings::backupSQLFiles() {
    QString backupDir = "/home/boi/Projects/PosBack";

    // Loop through each database file and perform backup
    QStringList dbFiles = { "admin.db", "employees_2.db", "products.db", "invetory.db", "feedback.db", "sales.db" };
    for (const QString& dbFile : dbFiles) {
        QFile sourceFile("/home/boi/Projects/C++/Uni/Pos/Sql/" + dbFile);
        QString backupFile = backupDir + "/" + dbFile;

        if (sourceFile.exists()) {
            if (QFile::copy(sourceFile.fileName(), backupFile)) {
                // Backup successful
                qDebug() << "Backup of" << dbFile << "successful.";
            } else {
                // Backup failed
                qDebug() << "Backup of" << dbFile << "failed.";
            }
        } else {
            // Source file does not exist
            qDebug() << "Source file" << dbFile << "does not exist.";
        }
    }
}

void Settings::shutdownApp()
{
    backupSQLFiles();
    qApp->exit();
}

void Settings::handleEmployeeLogin()
{
    shutdownButton->hide();
}

#include "sidebar.h"
#include "mainwindow.h"
#include <QPalette>

Sidebar::Sidebar(QWidget* parent) : QWidget(parent) {
    setStyleSheet("QWidget { background-color: #f9f9f9; border-radius: 20px; }");
    setupUI();
}

void Sidebar::setupUI() {
    frame = new QFrame(this);
    frame->setStyleSheet("background-color: #f9f9f9; color: #333333; border-radius: 20px;");
    frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    frame->setContentsMargins(0, 0, 0, 0);

    sidebarLayout = new QVBoxLayout(frame);
    sidebarLayout->setContentsMargins(0, 0, 0, 0);

    QPalette palette;
    palette.setColor(QPalette::Window, Qt::red);
    setFixedWidth(150);
    QSize buttonSize(75, 75);
    QString hoverStyleSheet = "QPushButton { background-color: #f9f9f9; } QPushButton:hover { background-color: #ECECEC; }";

    QLabel* logoLabel = new QLabel;
    logoLabel->setText("POS");
    QFont font = logoLabel->font();
    font.setPointSize(26);
    font.setBold(true);
    logoLabel->setFont(font);
    logoLabel->setStyleSheet("background-color: #f9f9f9; color: #28A4A6;");
    logoLabel->setFixedSize(buttonSize);

    sidebarLayout->addSpacing(40);
    sidebarLayout->addWidget(logoLabel, 0, Qt::AlignHCenter);
    sidebarLayout->addSpacing(40);

    QPushButton* button1 = createSidebarButton("/home/boi/Projects/C++/Uni/OOP/Pos/img/shopping-bag.png", buttonSize, hoverStyleSheet);
    QPushButton* button2 = createSidebarButton("/home/boi/Projects/C++/Uni/OOP/Pos/img/pie-chart.png", buttonSize, hoverStyleSheet);
    QPushButton* button3 = createSidebarButton("/home/boi/Projects/C++/Uni/OOP/Pos/img/user.png", buttonSize, hoverStyleSheet);
    QPushButton* button4 = createSidebarButton("/home/boi/Projects/C++/Uni/OOP/Pos/img/settings.png", buttonSize, hoverStyleSheet);

    sidebarLayout->addSpacing(40);
    sidebarLayout->addWidget(button1, 0, Qt::AlignHCenter);
    sidebarLayout->addSpacing(40);

    sidebarLayout->addSpacing(40);
    sidebarLayout->addWidget(button2, 0, Qt::AlignHCenter);
    sidebarLayout->addSpacing(40);

    sidebarLayout->addSpacing(40);
    sidebarLayout->addWidget(button3, 0, Qt::AlignHCenter);
    sidebarLayout->addSpacing(40);

    sidebarLayout->addStretch();

    sidebarLayout->addSpacing(40);
    sidebarLayout->addWidget(button4, 0, Qt::AlignHCenter);
    sidebarLayout->addSpacing(40);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(frame);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(mainLayout);
}

QPushButton* Sidebar::createSidebarButton(const QString& iconPath, const QSize& buttonSize, const QString& hoverStyleSheet) {
    QPushButton* button = new QPushButton;
    button->setIcon(QIcon(iconPath));
    button->setIconSize(QSize(60, 60));
    button->setStyleSheet(hoverStyleSheet);
    button->setFixedSize(buttonSize);
    return button;
}


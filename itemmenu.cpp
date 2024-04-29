#include "itemmenu.h"

void setupCheckoutBar(QWidget* checkoutBar) {
    // Create a vertical layout for the checkout bar
    QVBoxLayout* checkoutLayout = new QVBoxLayout(checkoutBar);
    checkoutBar->setFixedWidth(350);

    QLabel* checkoutLabel = new QLabel("Checkout");
    checkoutLabel->setAlignment(Qt::AlignHCenter);
    QFont font = checkoutLabel->font();
    font.setPointSize(22);
    font.setBold(true);
    checkoutLabel->setFont(font);

    checkoutLayout->addWidget(checkoutLabel);
    checkoutLayout->addStretch();
    checkoutBar->setLayout(checkoutLayout);

    checkoutBar->setStyleSheet("background-color: #f0f0f0;");
}

void setupSidebar(QWidget* sidebar) {
    QVBoxLayout* sidebarLayout = new QVBoxLayout(sidebar);
    sidebar->setFixedWidth(20);
    sidebar->setStyleSheet("background-color: #f9f9f9; color: #333333; border-radius: 20px;");
    QSize buttonSize(75, 75);
    QString hoverStyleSheet = "QPushButton:hover { background-color: #ECECEC; }";

    QLabel* logoLabel = new QLabel;
    logoLabel->setText("POS");
    QFont font = logoLabel->font();
    font.setPointSize(25);
    font.setBold(true);
    logoLabel->setFont(font);
    logoLabel->setStyleSheet("color: #28A4A6;");
    logoLabel->setFixedSize(buttonSize);

    sidebarLayout->addSpacing(40);
    sidebarLayout->addWidget(logoLabel, 0, Qt::AlignHCenter);
    sidebarLayout->addSpacing(40);

    QPushButton* button1 = new QPushButton;
    button1->setIcon(QIcon("/home/boi/Projects/C++/Uni/OOP/Pos/img/shopping-bag.png"));
    button1->setIconSize(QSize(60, 60));
    QVBoxLayout* layout1 = new QVBoxLayout;
    layout1->addWidget(button1);

    QPushButton* button2 = new QPushButton;
    button2->setIcon(QIcon("/home/boi/Projects/C++/Uni/OOP/Pos/img/pie-chart.png"));
    button2->setIconSize(QSize(60, 60));
    QVBoxLayout* layout2 = new QVBoxLayout;
    layout2->addWidget(button2);

    QPushButton* button3 = new QPushButton;
    button3->setIcon(QIcon("/home/boi/Projects/C++/Uni/OOP/Pos/img/user.png"));
    button3->setIconSize(QSize(60, 60));
    QVBoxLayout* layout3 = new QVBoxLayout;
    layout3->addWidget(button3);

    QPushButton* button4 = new QPushButton;
    button4->setIcon(QIcon("/home/boi/Projects/C++/Uni/OOP/Pos/img/settings.png"));
    button4->setIconSize(QSize(60, 60));
    QVBoxLayout* layout4 = new QVBoxLayout;
    layout4->addWidget(button4);

    button1->setStyleSheet(hoverStyleSheet);
    button2->setStyleSheet(hoverStyleSheet);
    button3->setStyleSheet(hoverStyleSheet);
    button4->setStyleSheet(hoverStyleSheet);

    button1->setFixedSize(buttonSize);
    button2->setFixedSize(buttonSize);
    button3->setFixedSize(buttonSize);
    button4->setFixedSize(buttonSize);

    sidebarLayout->addLayout(layout1);
    sidebarLayout->addLayout(layout2);
    sidebarLayout->addLayout(layout3);
    sidebarLayout->addLayout(layout4);

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

    sidebar->setLayout(sidebarLayout);
}

void setupMenu(QWidget* menu) {
    QVBoxLayout* menuLayout = new QVBoxLayout(menu);
    menu->setStyleSheet("background-color: #ECECEC; border-radius: 20px;");

    // Create top and bottom widgets
    QWidget* topWidget = new QWidget;
    QWidget* bottomWidget = new QWidget;

    // Set background colors for clarity
    topWidget->setStyleSheet("background-color: lightblue;");
    bottomWidget->setStyleSheet("background-color: lightgreen;");

    // Set fixed size for the top widget (one-third of the total height)
    int totalHeight = menu->height();
    int topWidgetHeight = totalHeight / 2;
    topWidget->setFixedHeight(350);

    // Add widgets to the layout
    menuLayout->addWidget(topWidget);
    menuLayout->addWidget(bottomWidget);

    menu->setLayout(menuLayout);
}

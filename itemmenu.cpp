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

    QWidget* topWidget = new QWidget;
    QVBoxLayout* topLayout = new QVBoxLayout(topWidget);
    topLayout->setContentsMargins(20, 20, 20, 20);

    QHBoxLayout* labelsAndSearchLayout = new QHBoxLayout;
    QVBoxLayout* labelsLayout = new QVBoxLayout;

    QLabel* welcomeLabel = new QLabel;
    welcomeLabel->setText("Welcome");
    QFont welcomeFont = welcomeLabel->font();
    welcomeFont.setPointSize(18);
    welcomeFont.setBold(true);
    welcomeLabel->setFont(welcomeFont);
    welcomeLabel->setFixedSize(230, 40);
    welcomeLabel->setStyleSheet("color: #333333;");

    QLabel* discoverLabel = new QLabel;
    discoverLabel->setText("Discover any items you need");
    QFont discoverFont = discoverLabel->font();
    discoverFont.setPointSize(12);
    discoverLabel->setFont(discoverFont);
    discoverLabel->setContentsMargins(0, 0, 0, 0);
    discoverLabel->setStyleSheet("color: #878383;");

    welcomeLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    discoverLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    labelsLayout->addWidget(welcomeLabel);
    labelsLayout->addWidget(discoverLabel);

    QLineEdit* searchBar = new QLineEdit;
    searchBar->setStyleSheet("border: 2px solid #CCCCCC; border-radius: 10px; padding: 5px;");
    searchBar->setPlaceholderText("Slave auction search");

    labelsAndSearchLayout->addLayout(labelsLayout);
    labelsAndSearchLayout->addStretch();
    labelsAndSearchLayout->addWidget(searchBar, 0, Qt::AlignTop | Qt::AlignRight);

    topLayout->addLayout(labelsAndSearchLayout);

    QLabel* categoriesLabel = new QLabel("Categories");
    categoriesLabel->setFont(QFont("Arial", 16, QFont::Bold));
    categoriesLabel->setContentsMargins(0, 40, 0, 0);
    topLayout->addWidget(categoriesLabel, 0, Qt::AlignTop | Qt::AlignLeft);

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->setContentsMargins(0, 0, 0, 0);
    // Button 1
    QPushButton* button1 = new QPushButton;
    QIcon icon1("/home/boi/Projects/C++/Uni/OOP/Pos/img/n.png");
    button1->setIcon(icon1);
    button1->setIconSize(QSize(40, 40));
    button1->setStyleSheet("QPushButton { border: 2px solid #333333; padding: 10px; }");

    QVBoxLayout* buttonLayout1 = new QVBoxLayout;
    buttonLayout1->setAlignment(Qt::AlignCenter);
    buttonLayout1->addWidget(button1);
    QLabel* captionLabel1 = new QLabel("Caption 1");
    captionLabel1->setStyleSheet("font-size: 10px; color: #333333;");
    captionLabel1->setAlignment(Qt::AlignCenter);
    buttonLayout1->addWidget(captionLabel1);

    // Button 2
    QPushButton* button2 = new QPushButton;
    QIcon icon2("/home/boi/Projects/C++/Uni/OOP/Pos/img/pie-chart.png");
    button2->setIcon(icon2);
    button2->setIconSize(QSize(50, 50));
    button2->setStyleSheet("QPushButton { border: 2px solid #333333; padding: 10px; }");

    QVBoxLayout* buttonLayout2 = new QVBoxLayout;
    buttonLayout2->setAlignment(Qt::AlignCenter);
    buttonLayout2->addWidget(button2);
    QLabel* captionLabel2 = new QLabel("Caption 2");
    captionLabel2->setStyleSheet("font-size: 10px; color: #333333;");
    captionLabel2->setAlignment(Qt::AlignCenter);
    buttonLayout2->addWidget(captionLabel2);

    // Button 3
    QPushButton* button3 = new QPushButton;
    QIcon icon3("/home/boi/Projects/C++/Uni/OOP/Pos/img/pie-chart.png");
    button3->setIcon(icon3);
    button3->setIconSize(QSize(50, 50));
    button3->setStyleSheet("QPushButton { border: 2px solid #333333; padding: 10px; }");

    QVBoxLayout* buttonLayout3 = new QVBoxLayout;
    buttonLayout3->setAlignment(Qt::AlignCenter);
    buttonLayout3->addWidget(button3);
    QLabel* captionLabel3 = new QLabel("Caption 3");
    captionLabel3->setStyleSheet("font-size: 10px; color: #333333;");
    captionLabel3->setAlignment(Qt::AlignCenter);
    buttonLayout3->addWidget(captionLabel3);

    // Button 4
    QPushButton* button4 = new QPushButton;
    QIcon icon4("/home/boi/Projects/C++/Uni/OOP/Pos/img/pie-chart.png");
    button4->setIcon(icon4);
    button4->setIconSize(QSize(50, 50));
    button4->setStyleSheet("QPushButton { border: 2px solid #333333; padding: 10px; }");

    QVBoxLayout* buttonLayout4 = new QVBoxLayout;
    buttonLayout4->setAlignment(Qt::AlignCenter);
    buttonLayout4->addWidget(button4);
    QLabel* captionLabel4 = new QLabel("Caption 4");
    captionLabel4->setStyleSheet("font-size: 10px; color: #333333;");
    captionLabel4->setAlignment(Qt::AlignCenter);
    buttonLayout4->addWidget(captionLabel4);

    // Button 5
    QPushButton* button5 = new QPushButton;
    QIcon icon5("/home/boi/Projects/C++/Uni/OOP/Pos/img/pie-chart.png");
    button5->setIcon(icon5);
    button5->setIconSize(QSize(50, 50));
    button5->setStyleSheet("QPushButton { border: 2px solid #333333; padding: 10px; }");

    QVBoxLayout* buttonLayout5 = new QVBoxLayout;
    buttonLayout5->setAlignment(Qt::AlignCenter);
    buttonLayout5->addWidget(button5);
    QLabel* captionLabel5 = new QLabel("Caption 5");
    captionLabel5->setStyleSheet("font-size: 10px; color: #333333;");
    captionLabel5->setAlignment(Qt::AlignCenter);
    buttonLayout5->addWidget(captionLabel5);

    buttonsLayout->addLayout(buttonLayout1);
    buttonsLayout->addLayout(buttonLayout2);
    buttonsLayout->addLayout(buttonLayout3);
    buttonsLayout->addLayout(buttonLayout4);
    buttonsLayout->addLayout(buttonLayout5);

    topLayout->addLayout(buttonsLayout);

    topWidget->setLayout(topLayout);
    menuLayout->addWidget(topWidget);

    QWidget* bottomWidget = new QWidget;
    bottomWidget->setStyleSheet("background-color: lightgreen;");

    int totalHeight = menu->height();
    int topWidgetHeight = totalHeight / 2;
    topWidget->setFixedHeight(350);

    menuLayout->addWidget(topWidget);
    menuLayout->addWidget(bottomWidget);

    menu->setLayout(menuLayout);
}

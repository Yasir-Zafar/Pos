#include "user.h"

User::User(QWidget *parent)
    : QWidget{parent}
{
    horizontalLayout = new QHBoxLayout(this);
    setStyleSheet("background-color: #ECECEC; border-radius: 20px;");

    QVBoxLayout* verticalLayout = new QVBoxLayout;

    QLabel* welcomeLabel = new QLabel;
    welcomeLabel->setText("Nigger");
    welcomeLabel->setFont(QFont("Arial Rounded", 29, QFont::Bold));
    welcomeLabel->setFixedHeight(350);
    welcomeLabel->setStyleSheet("color: #333333;");

    welcomeLabel->setAlignment(Qt::AlignCenter);

    // Set size policy to expand both vertically and horizontally
    verticalLayout->setAlignment(Qt::AlignTop); // Align content to the top
    verticalLayout->setSizeConstraint(QLayout::SetMinimumSize); // Ensure the layout can't shrink below its minimum size
    verticalLayout->setSpacing(0); // Set spacing between items to 0

    verticalLayout->setContentsMargins(0, 0, 0, 0); // Set margins to 0

    verticalLayout->setSpacing(0); // Set spacing between items to 0
    verticalLayout->setContentsMargins(0, 0, 0, 0); // Set margins to 0

    verticalLayout ->addWidget(welcomeLabel);
    verticalLayout ->addStretch();

    horizontalLayout->addLayout(verticalLayout);

    setLayout(horizontalLayout);
}

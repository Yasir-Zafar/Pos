#include "analysis.h"
#include "qboxlayout.h"

Analysis::Analysis(QWidget *parent)
    : QWidget(parent) {
    setupUi();
}

void Analysis::setupUi()
{
    setStyleSheet("Analysis { background-color: #ECECEC; border-radius: 20px; }");

    QFont commonFont("Arial Rounded", 20, 700);
    QPalette commonPalette;
    commonPalette.setColor(QPalette::WindowText, QColor("#4ACCB1"));

    QFrame *frame = new QFrame(this);
    frame->setObjectName("frame");
    frame->setStyleSheet("QFrame#frame { background-color: #ECECEC; border-radius: 20px; }");
    frame->setContentsMargins(25, 25, 25, 25);
    QVBoxLayout *mainLayout = new QVBoxLayout(frame);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    QLabel *titleLabel = new QLabel("Analytics");
    titleLabel->setFont(QFont("Arial Rounded", 19, QFont::Bold));
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setFixedHeight(35);
    titleLabel->setAlignment(Qt::AlignLeft);
    mainLayout->addWidget(titleLabel);

    QVBoxLayout *topLayout = new QVBoxLayout;
    QVBoxLayout *leftTopLayout = new QVBoxLayout;
    QVBoxLayout *rightTopLayout = new QVBoxLayout;
    QHBoxLayout *TopLayout = new QHBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QVBoxLayout *bottomLayout = new QVBoxLayout;

    label = new QLabel();
    label->setObjectName(QString::fromUtf8("label"));
    label->setStyleSheet("color: #55EBE6;"
                         "background-color: #FFFFFF;"
                         "border-radius: 14px;");
    label->setFont(commonFont);
    label->setFixedSize(400, 150);
    label->setAlignment(Qt::AlignCenter);

    label_2 = new QLabel("Total Revenue");
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setStyleSheet("text-align: center;");
    label_2->setFont(commonFont);
    label_2->setPalette(commonPalette);
    label_2->setFixedHeight(60); // Set fixed height for label_2
    label_2->setAlignment(Qt::AlignCenter); // Center labels vertically

    leftTopLayout->addWidget(label_2);
    leftTopLayout->addWidget(label);

    label_3 = new QLabel();
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setStyleSheet("border-radius: 14px;"
                           "background-color: #FFFFFF;");
    label_3->setFont(commonFont);
    label_3->setPalette(commonPalette);
    label_3->setFixedSize(400, 150); // Set fixed size for label_3
    label_3->setAlignment(Qt::AlignCenter); // Center labels vertically

    label_4 = new QLabel("Items Sold");
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setStyleSheet("text-align: center;");
    label_4->setFont(commonFont);
    label_4->setPalette(commonPalette);
    label_4->setFixedHeight(60); // Set fixed height for label_4
    label_4->setAlignment(Qt::AlignCenter); // Center labels vertically

    topLayout->addWidget(label_4);
    topLayout->addWidget(label_3);

    label_5 = new QLabel();
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setStyleSheet("border-radius: 14px;"
                           "background-color: #FFFFFF;");
    label_5->setFont(commonFont);
    label_5->setPalette(commonPalette);
    label_5->setFont(commonFont);
    label_5->setPalette(commonPalette);
    label_5->setFixedSize(400, 150); // Set fixed size for label_
    label_5->setAlignment(Qt::AlignCenter); // Center labels vertically

    label_6 = new QLabel("Inventory");
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setStyleSheet("text-align: center;");
    label_6->setFont(commonFont);
    label_6->setPalette(commonPalette);
    label_6->setFixedHeight(60); // Set fixed height for label_4
    label_6->setAlignment(Qt::AlignCenter); // Center labels vertically

    rightTopLayout->addWidget(label_6);
    rightTopLayout->addWidget(label_5);

    TopLayout->addLayout(leftTopLayout);
    TopLayout->addSpacing(100); // Center labels vertically
    TopLayout->addLayout(topLayout);
    TopLayout->addSpacing(100);
    TopLayout->addLayout(rightTopLayout);
    TopLayout->setContentsMargins(0, 20, 20, 20);
    TopLayout->setAlignment(Qt::AlignCenter);

    DisplayGraph = new QPushButton("Display Graph");
    DisplayGraph->setObjectName(QString::fromUtf8("DisplayGraph"));
    DisplayGraph->setStyleSheet("background-color: #4ACCB1;"
                                "border-radius:20px;");
    DisplayGraph->setFixedSize(400, 100);
    DisplayGraph->setFont(commonFont);

    pushButton = new QPushButton("LOAD");
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setStyleSheet("background-color: #4ACCB1;"
                              "border-radius:20px;");
    pushButton->setFixedSize(400, 100);
    pushButton->setFont(commonFont);

    buttonLayout->addWidget(DisplayGraph);
    buttonLayout->addWidget(pushButton);
    buttonLayout->setContentsMargins(0, 60, 20, 10);

    listWidget = new QListWidget();
    listWidget->setObjectName(QString::fromUtf8("listWidget"));
    listWidget->setStyleSheet("background-color: #F9F9F9;"
                              "color: #4ACCB1;"
                              "border-radius:20px;");
    listWidget->setFixedSize(1650, 400);

    label_7 = new QLabel("Top 3 Products");
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setFont(commonFont);
    label_7->setPalette(commonPalette);
    label_7->setContentsMargins(0, 0, 0, 0);

    bottomLayout->addWidget(label_7);
    bottomLayout->addWidget(listWidget);
    bottomLayout->setContentsMargins(20, 20, 20, 20);

    mainLayout->addLayout(TopLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addLayout(bottomLayout,1);

    QVBoxLayout *frameLayout = new QVBoxLayout(this);
    frameLayout->addWidget(frame);
    frameLayout->setContentsMargins(10, 10, 10, 10);

    setLayout(frameLayout);
}

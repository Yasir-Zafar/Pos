#include "analysis.h"
#include "qboxlayout.h"

Analysis::Analysis(QWidget *parent)
    : QWidget(parent) {
    setupUi();
    setStyleSheet("background-color: #ECECEC; border-radius: 20px;");
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
    QVBoxLayout *mainLayout = new QVBoxLayout(frame);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    QLabel *titleLabel = new QLabel("Analytics");
    titleLabel->setStyleSheet("font: bold 24pt Arial Rounded;");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setContentsMargins(0, 0, 0, 20);
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

    label_2 = new QLabel("Total Revenue");
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setStyleSheet("text-align: center;");
    label_2->setFont(commonFont);
    label_2->setPalette(commonPalette);

    leftTopLayout->addWidget(label_2);
    leftTopLayout->addWidget(label);

    label_3 = new QLabel();
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setStyleSheet("border-radius: 14px;"
                           "background-color: #FFFFFF;");
    label_3->setFont(commonFont);
    label_3->setPalette(commonPalette);

    label_4 = new QLabel("Items Sold");
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setStyleSheet("text-align: center;");
    label_4->setFont(commonFont);
    label_4->setPalette(commonPalette);

    topLayout->addWidget(label_4);
    topLayout->addWidget(label_3);

    label_5 = new QLabel();
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setStyleSheet("border-radius: 14px;"
                           "background-color: #FFFFFF;");
    label_5->setFont(commonFont);
    label_5->setPalette(commonPalette);

    label_6 = new QLabel("Inventory");
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setStyleSheet("text-align: center;");
    label_6->setFont(commonFont);
    label_6->setPalette(commonPalette);

    rightTopLayout->addWidget(label_6);
    rightTopLayout->addWidget(label_5);

    TopLayout->addLayout(leftTopLayout);
    TopLayout->addLayout(topLayout);
    TopLayout->addLayout(rightTopLayout);

    DisplayGraph = new QPushButton("Display Graph");
    DisplayGraph->setObjectName(QString::fromUtf8("DisplayGraph"));
    DisplayGraph->setStyleSheet("background-color: #4ACCB1;"
                                "border-radius:14px;");

    pushButton = new QPushButton("LOAD");
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setStyleSheet("background-color: #4ACCB1;"
                              "border-radius:14px;");

    buttonLayout->addWidget(DisplayGraph);
    buttonLayout->addWidget(pushButton);

    listWidget = new QListWidget();
    listWidget->setObjectName(QString::fromUtf8("listWidget"));
    listWidget->setStyleSheet("background-color: #F9F9F9;"
                              "color: #4ACCB1;"
                              "border-radius:20px;");
    listWidget->setMaximumHeight(200);

    label_7 = new QLabel("Top 3 Products");
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setFont(commonFont);
    label_7->setPalette(commonPalette);

    bottomLayout->addWidget(label_7);
    bottomLayout->addWidget(listWidget);

    mainLayout->addLayout(TopLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addLayout(bottomLayout,1);

    QVBoxLayout *frameLayout = new QVBoxLayout(this);
    frameLayout->addWidget(frame);
    frameLayout->setContentsMargins(0, 0, 0, 0);

    setLayout(frameLayout);
}

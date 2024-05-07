#include "../../include/Analysis/analysis.h"
#include "../../include/Analysis/linechart.h"

Analysis::Analysis(QWidget *parent)
    : QWidget(parent) {
    setupUi();
    on_pushButton_clicked();
    setupDb();
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
    frame->setContentsMargins(30, 30, 30, 30);
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
    label->setStyleSheet("background-color: #FFFFFF;"
                         "border-radius: 14px;");
    label->setFont(commonFont);
    label->setPalette(commonPalette);
    label->setFixedSize(400, 150);
    label->setAlignment(Qt::AlignCenter);

    label_2 = new QLabel("Total Revenue");
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setStyleSheet("text-align: center;");
    label_2->setFont(commonFont);
    label_2->setPalette(commonPalette);
    label_2->setFixedHeight(60);
    label_2->setAlignment(Qt::AlignCenter);

    leftTopLayout->addWidget(label_2);
    leftTopLayout->addWidget(label);

    label_3 = new QLabel();
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setStyleSheet("border-radius: 14px;"
                           "background-color: #FFFFFF;");
    label_3->setFont(commonFont);
    label_3->setPalette(commonPalette);
    label_3->setFixedSize(400, 150);
    label_3->setAlignment(Qt::AlignCenter);

    label_4 = new QLabel("Items Sold");
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setStyleSheet("text-align: center;");
    label_4->setFont(commonFont);
    label_4->setPalette(commonPalette);
    label_4->setFixedHeight(60);
    label_4->setAlignment(Qt::AlignCenter);

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
    label_5->setFixedSize(400, 150);
    label_5->setAlignment(Qt::AlignCenter);

    label_6 = new QLabel("Inventory");
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setStyleSheet("text-align: center;");
    label_6->setFont(commonFont);
    label_6->setPalette(commonPalette);
    label_6->setFixedHeight(60);
    label_6->setAlignment(Qt::AlignCenter);

    rightTopLayout->addWidget(label_6);
    rightTopLayout->addWidget(label_5);

    TopLayout->addLayout(leftTopLayout);
    TopLayout->addSpacing(100);
    TopLayout->addLayout(topLayout);
    TopLayout->addSpacing(100);
    TopLayout->addLayout(rightTopLayout);
    TopLayout->setContentsMargins(0, 20, 20, 20);
    TopLayout->setAlignment(Qt::AlignCenter);

    DisplayGraph = new QPushButton("Display Graph");
    DisplayGraph->setObjectName(QString::fromUtf8("DisplayGraph"));
    DisplayGraph->setStyleSheet("background-color: #4ACCB1;"
                                "border-radius:20px;");
    DisplayGraph->setFixedSize(400, 80);
    DisplayGraph->setFont(commonFont);
    connect(DisplayGraph, &QPushButton::clicked, this, &Analysis::on_DisplayGraph_clicked);

    pushButton = new QPushButton("Update");
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setStyleSheet("background-color: #4ACCB1;"
                              "border-radius:20px;");
    pushButton->setFixedSize(400, 80);
    pushButton->setFont(commonFont);
    connect(pushButton, &QPushButton::clicked, this, &Analysis::on_pushButton_clicked);

    buttonLayout->addWidget(DisplayGraph);
    buttonLayout->addWidget(pushButton);
    buttonLayout->setContentsMargins(0, 60, 20, 10);

    listWidget = new QListWidget();
    listWidget->setObjectName(QString::fromUtf8("listWidget"));
    listWidget->setStyleSheet("background-color: #F9F9F9;"
                              "color: #4ACCB1;"
                              "border-radius:20px;");

    QFont font;
    font.setPointSize(24);

    listWidget->setFont(font);
    listWidget->setFixedSize(1500, 400);

    label_7 = new QLabel("Top 3 Products");
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setFont(commonFont);
    label_7->setPalette(commonPalette);
    label_7->setContentsMargins(0, 0, 0, 0);

    bottomLayout->addWidget(label_7);
    bottomLayout->addWidget(listWidget, 0, Qt::AlignHCenter);
    bottomLayout->setContentsMargins(20, 20, 20, 20);

    mainLayout->addLayout(TopLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addLayout(bottomLayout,1);

    QVBoxLayout *frameLayout = new QVBoxLayout(this);
    frameLayout->addWidget(frame);
    frameLayout->setContentsMargins(10, 10, 10, 10);

    setLayout(frameLayout);
}

void Analysis::on_pushButton_clicked()
{
    DB_connection.open();

    QSqlDatabase :: database().transaction();
    QSqlQuery sumdata(DB_connection);

    QString sum ;
    sumdata.prepare("SELECT SUM(totalAmount) FROM checkout");
    sumdata.exec();
    if(sumdata.next())
        sum = sumdata.value(0).toString();

    qDebug() << "sum=" << sum;
    label->setText("Rs. " + sum);

    DB_connection_2 = QSqlDatabase ::addDatabase("QSQLITE");
    DB_connection_2.setDatabaseName("/home/boi/Projects/C++/Uni/Pos/Sql/products.db");
    if(DB_connection_2.open())
        qDebug() << "Database is connected";
    else
        qDebug() << "Database is not connected";

    QSqlQuery solditems(DB_connection_2);
    QString itemssold;
    solditems.prepare("SELECT SUM(quantity) FROM info;");
    if(!solditems.exec())
        itemssold = "error";
    if(solditems.next())
        itemssold = solditems.value(0).toString();

    label_3-> setText(itemssold);
    if(DB_connection_2.open())
        qDebug() << "Database is connected";
    else
    {
        qDebug() << "Database is not connected";
        qDebug() << "Error:" << DB_connection_2.lastError();
    }

    QSqlQuery readinventory(DB_connection_2);
    QString inventory;
    readinventory.prepare("SELECT SUM(Inventory) FROM products");
    readinventory.exec();
    if(readinventory.next())
        inventory = readinventory.value(0).toString();
    label_5-> setText(inventory);

    QSqlQuery readmaximum(DB_connection_2);
    QString m1 ;
    readmaximum.prepare("SELECT MAX(Sold) FROM products ");
    if(readmaximum.exec())
        m1 = "error query";
    if(readmaximum.next())
        m1 = readmaximum.value(0).toString();

    QString max1;
    QSqlQuery readmaxname(DB_connection_2);
    readmaxname.prepare("SELECT Name FROM products WHERE Sold =" + m1);
    if(readmaxname.exec())
        max1 = "error query";
    if(readmaxname.next())
        max1 = readmaxname.value(0).toString();

    listWidget->addItem("1. "+max1);
    listWidget->addItem("");

    QSqlQuery readmaximum2(DB_connection_2);
    QString m2 ;
    readmaximum.prepare("SELECT MAX(Sold) FROM products Where Sold != " + m1);
    if(!readmaximum.exec())
        m2 = "error query";
    if(readmaximum.next())
        m2 = readmaximum.value(0).toString();
    qDebug() << m2;

    QString max2;
    QSqlQuery readmaxname2(DB_connection_2);
    readmaxname2.prepare("SELECT Name FROM products WHERE Sold =" + m2);
    if(!readmaxname2.exec())
        max2 = "error query";
    if(readmaxname2.next())
    {
        max2 = readmaxname2.value(0).toString();
    }
    listWidget->addItem("2. "+max2);
    listWidget->addItem("");

    QSqlQuery readmaximum3(DB_connection_2);
    QString m3 ;
    readmaximum3.prepare("SELECT MAX(Sold) FROM products WHERE Sold !=" + m1 +" AND Sold !=" + m2 + ";");
    if(!readmaximum3.exec())
        m3 = "error query";
    if(readmaximum3.next())
        m3 = readmaximum3.value(0).toString();

    qDebug() << m3;
    QString max3;
    QSqlQuery readmaxname3(DB_connection_2);
    readmaxname3.prepare("SELECT Name FROM products WHERE Sold =" + m3);
    if(!readmaxname3.exec())
        max3 = "error query";
    if(readmaxname3.next())
        max3 = readmaxname3.value(0).toString();
    listWidget->addItem("3. "+max3);

    QSqlDatabase::database().commit();

    // DB_connection.close();
    DB_connection_2.close();
}

void Analysis::setupDb(){
    DB_connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_connection.setDatabaseName("/home/boi/Projects/C++/Uni/Pos/Sql/products.db");
    if(DB_connection.open())
        qDebug() << "Database is connected";
    else
    {
        qDebug() << "Database is not connected";
        qDebug() << "Error:" << DB_connection.lastError();
    }
}

void Analysis::on_DisplayGraph_clicked()
{
    LineChart *newlinechart = new LineChart;
    newlinechart->show();
}

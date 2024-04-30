#ifndef ITEMMENU_H
#define ITEMMENU_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QGridLayout>
#include <QScrollArea>

void setupSidebar(QWidget* sidebar);
void setupMenu(QWidget* menu);
void setupCheckoutBar(QWidget* checkoutBar);
void setupCards(QWidget* bottomWidget, QObject* eventFilter);

#endif // ITEMMENU_H

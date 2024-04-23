#include "Items.h"
#include <iostream>
#include <sqlite3.h>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

void Items::addItem() {
	cout << "Enter ID: ";
	cin >> id;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter price: ";
	cin >> price;
	cout << "Enter quantity: ";
	cin >> quantity;
	cout << "Product Added!\n";
}
void Items::removeItem(vector <Items> itms) {
	cout << "Enter the ID of the Product to be deleted: ";
	int trgt;
	cin >> trgt;
	int i;
	for (i = 0; i < itms.size(); i++) {
		if (trgt == itms[i].id) {
			break;
		}
	}
	itms.erase(itms.begin() + i);
	cout << "Item Removed!\n";
}
void Items::updateItem(vector <Items> itms) {
	cout << "Enter the ID of the Product to be updated: ";
	int trgt;
	cin >> trgt;
	int i;
	for (i = 0; i < itms.size(); i++) {
		if (trgt == itms[i].id) {
			cout << "Enter new ID: ";
			cin >> itms[i].id;
			cout << "Enter new name: ";
			cin >> itms[i].name;
			cout << "Enter new price: ";
			cin >> itms[i].price;
			cout << "Enter new quantity: ";
			cin >> itms[i].quantity;
			cout << "Product Updated!\n";
			break;
		}
	}
}

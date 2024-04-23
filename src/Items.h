#pragma once
#include "user.h"
class Items : public user
{
private:
	int id;
	string name;
	float price;
	int quantity;
public:
	Items();
	void addItem();
	void removeItem(vector <Items> itms);
	void updateItem(vector <Items> itms);
};

#include <iostream>
using namespace std;

class item
{
private:
	int price;
	int stock;
	int discount;
public:
	item () {}
	item(int price, int stock) { this->price = price; this->stock = stock; discount = 0; }
	int getprice() { return price; }
	int getstock() { return stock; }
	int getdiscount() { return discount; }
	void addstock(int num) { this->stock += num; }
	void sell_item(int num) { this->stock -= num; }
	void setdiscount(int num) { discount = num; }
};

class Pen : public item
{
public:
	Pen() {}
	Pen(int _price, int _stock) : item(_price, _stock) {
		
	}
};
class Pencil : public item
{
public:
	Pencil() {}
	Pencil(int _price, int _stock) : item(_price, _stock) {

	}

};
class Eraser : public item
{
public:
	Eraser() {}
	Eraser(int _price, int _stock) : item(_price, _stock) {

	}
};

int main()
{
	int input = 0, num = 0, count = 0, total = 0;
	float Pen_per = 1, Pencil_per = 1, Eraser_per = 1;
	Pen Pen(600, 100);
	Pencil Pencil(1200, 100);
	Eraser Eraser(500, 100);
	string str;
	
	cout << "====================" << endl << "---------Pen--------" << endl;
	cout << "Price : " << Pen.getprice() << endl << "Stock : " << Pen.getstock() << endl << "Discount : " << Pen.getdiscount() << "%"  << endl;
	cout << "--------------------" << endl << "--------Pencil------" << endl;
	cout << "Price : " << Pencil.getprice() << endl << "Stock : " << Pencil.getstock() << endl << "Discount : " << Pencil.getdiscount() << "%" << endl;
	cout << "--------------------" << endl << "--------Eraser------" << endl;
	cout << "Price : " << Eraser.getprice() << endl << "Stock : " << Eraser.getstock() << endl << "Discount : " << Eraser.getdiscount() << "%" << endl;
	cout << "--------------------" << endl;


	while (input != 4)
	{
		cout << "===================" << endl << "Enter Any Command(0 : Sell, 1 : AddStock, 2 : Disocunt, 3 : Print, 4 : Quit) :";
		count = 0;
		cin >> input;

		switch (input) {
		case 0:
			cin >> str >> num;
			if (str == "Pen") {
				while (count != 3) {
					Pen.sell_item(num);
					count++;
				}
				total += Pen.getprice() * num * Pen_per;
				cout << "===================" << endl << "Sales : " << total << endl;
 			}
			else if (str == "Pencil") {
				while (count != 12) {
					Pencil.sell_item(num);
					count++;
				}
				total += Pencil.getprice() * num * Pencil_per;
				cout << "===================" << endl << "Sales : " << total << endl;
			}
			else if (str == "Eraser") {
				while (count != 1) {
					Eraser.sell_item(num);
					count++;
				}
				total += Eraser.getprice() * num * Eraser_per;
				cout << "===================" << endl << "Sales : " << total << endl;
			}
			break;
		case 1:
			cin >> str >> num;
			if (str == "Pen") {
				Pen.addstock(num);
				count++;
				cout << "===================" << endl << "Sales : " << total << endl;
			}
			else if (str == "Pencil") {
				Pencil.addstock(num);	
				cout << "===================" << endl << "Sales : " << total << endl;
			}
			else if (str == "Eraser") {
				Eraser.addstock(num);
				cout << "===================" << endl << "Sales : " << total << endl;
			}
			break;
		case 2:
			cin >> str >> num;
			if (str == "Pen") {
				Pen.setdiscount(num);
				Pen_per = 1 - (float)num / 100;
				cout << "===================" << endl << "Sales : " << total << endl;
			}
			else if (str == "Pencil") {
				Pencil.setdiscount(num);
				Pencil_per = 1 - (float)num / 100;
				cout << "===================" << endl << "Sales : " << total << endl;
			}
			else if (str == "Eraser") {
				Eraser.setdiscount(num);
				Eraser_per = 1 - (float)num / 100;
				cout << "===================" << endl << "Sales : " << total << endl;
			}
			break;
		case 3:
			cout << "====================" << endl << "---------Pen--------" << endl;
			cout << "Price : " << Pen.getprice() << endl << "Stock : " << Pen.getstock() << endl << "Discount : " << Pen.getdiscount() << "%" << endl;
			cout << "--------------------" << endl << "--------Pencil------" << endl;
			cout << "Price : " << Pencil.getprice() << endl << "Stock : " << Pencil.getstock() << endl << "Discount : " << Pencil.getdiscount() << "%" << endl;
			cout << "--------------------" << endl << "--------Eraser------" << endl;
			cout << "Price : " << Eraser.getprice() << endl << "Stock : " << Eraser.getstock() << endl << "Discount : " << Eraser.getdiscount() << "%" << endl;
			cout << "--------------------" << endl << "===================" << endl;
			cout << "===================" << endl << "Sales : " << total << endl;
			break;
		}
			
	}
}
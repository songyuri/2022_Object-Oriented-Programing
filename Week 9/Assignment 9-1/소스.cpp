#include <iostream>
using namespace std;

class TwoPoint
{
public:
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;

	TwoPoint() {};
	TwoPoint(int _x1, int _y1, int _x2, int _y2)
	{
		x1 = _x1;
		x2 = _x2;
		y1 = _y1;
		y2 = _y2;
	}
	virtual void print() {
		cout << "Point 1 : " << x1 << "," << y1 << endl << "Point 2 : " << x2 << "," << y2 << endl;
	}

};

class Equation : public TwoPoint
{
public:

	Equation() {};
	Equation(int _x1, int _y1, int _x2, int _y2)
	{
		this->x1 = _x1 ;
		this->y1 = _y1;
		this->x2 = _x2;
		this->y2 = _y2;
	}

	void print() {
		float a = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
		float b = float(y1) - a * float(x1);

		if (b < 0) {
			cout << "Equation : y = " << a << "x" << b << endl;
		}
		else 
			cout << "Equation : y = " << a << "x + " << b << endl;
	}
};

int main()
{
	class TwoPoint* A = new TwoPoint(2, 4, 7, 8);
	class TwoPoint* B = new Equation(2, 4, 7, 8);
	A->print();
	B->print();
	delete A;
	delete B;
	return 0;
}
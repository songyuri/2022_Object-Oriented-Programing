#include <iostream>
#include <cmath>
using namespace std;

class Polygon
{
private:
	int Area;
	int Perimeter;
public:
	Polygon(int a, int b, int c)
	{
		Area = sqrt( ((a + b + c) / 2) * ((a + b + c) / 2 - a) * ((a + b + c) / 2 - b) * ((a + b + c) / 2 - c) );
		Perimeter = a + b + c;
	}
	Polygon(int a, int b)
	{
		Area = a * b;
		Perimeter = 2 * (a + b);
	}
	void print_Area()
	{
		cout << "Area is " << Area << endl;
	}
	void print_Perimeter()
	{
		cout << "Perimeter is " << Perimeter << endl;
	}
};
class Triangle :public Polygon
{
private:
	int A;
	int B;
	int C;
public:
	Triangle(int _A, int _B, int _C):Polygon(_A, _B, _C)
	{
		A = _A;
		B = _B;
		C = _C;
	}
};
class Square :public Polygon
{
private: 
	int A;
	int B;
public:
	Square(int _A, int _B):Polygon(_A, _B)
	{
		A = _A;
		B = _B;
	}
};

int main()
{
	class Square A(5, 4);
	class Triangle B(13, 14, 15);

	cout << "----------Square----------" << endl;
	A.print_Area();
	A.print_Perimeter();
	cout << "--------------------------" << endl;
	cout << "---------Triangle---------" << endl;
	B.print_Area();
	B.print_Perimeter();
	cout << "--------------------------" << endl;

}
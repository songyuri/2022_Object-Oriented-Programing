#include <iostream>
using namespace std;

class Person {
	friend ostream& operator<<(ostream& output, const Person& P)
	{
		output << "이름 :" << P.name << endl << "나이 :" << P.age << endl << "거주지 :" << P.local << endl;
		return output;
	}
	friend istream& operator>>(istream& input, Person& P)
	{
		input >> P.name >> P.age >> P.local;
		return input;
	}
private:
	int age;
	string name, local;

public:
	Person(void) {};
	Person(string _name, int _age, string _local) {
		age = _age;
		name = _name;
		local = _local;
	}
};

int main()
{
	Person P;
	cin >> P;
	cout << P;
	return 0;
}
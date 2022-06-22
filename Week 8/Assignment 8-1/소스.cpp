#include <iostream>
using namespace std;

class Person {
	friend ostream& operator<<(ostream& output, const Person& P)
	{
		output << "�̸� :" << P.name << endl << "���� :" << P.age << endl << "������ :" << P.local << endl;
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
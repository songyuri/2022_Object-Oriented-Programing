#include <iostream>

using namespace std;

int main()
{
	char name[20] = "\0", num[15] = "\0", major[20] = "\0";

	cout << "�̸� : ";
	cin >> name;
	cout << "�й� : ";
	cin >> num;
	cout << "���� : ";
	cin >> major;

	cout << major << " " << num << " " << name << endl;

	return 0;
}
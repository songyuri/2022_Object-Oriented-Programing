#include <iostream>

using namespace std;

int main()
{
	char name[20] = "\0", num[15] = "\0", major[20] = "\0";

	cout << "이름 : ";
	cin >> name;
	cout << "학번 : ";
	cin >> num;
	cout << "전공 : ";
	cin >> major;

	cout << major << " " << num << " " << name << endl;

	return 0;
}
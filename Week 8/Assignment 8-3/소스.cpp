#include <iostream>
#include <string.h>
using namespace std;

class mystring
{
private:
	char* string = new char[1000]{'\0'};
public:
	mystring() { };
	void operator+=(char* _string);
	void operator-=(char _string);
	void operator--(void);
	void operator&&(char _string);
	mystring(char* _string)
	{
		strcpy(string, _string);
	}
	void print()
	{
		cout << string << endl;
	}
};
void mystring::operator+=(char* _string)
{
	strcat(string, _string);
}
void mystring::operator-=(char _string)
{
	int cnt = 0;
	char temp[1000] = { '\0' };
	for (int i = 0; string[i] != NULL; i++) {
		if (string[i] == _string) {
			i++;
			cnt++;
		}
		if (cnt >= 1) temp[i - cnt] = string[i];
		else temp[i] = string[i];
	}
	strcpy(string, temp);
}
void mystring::operator--(void)
{
	int len = strlen(string);

	if (len > 0 || string[len - 1] != '0') {
		string[len - 1] = NULL;
	}
}
void mystring::operator&&(char _string)
{
	
	for (int i = 0; string[i] != NULL; i++) {
		if (string[i] == _string) {
			string[i] = _string;
		}
		else string[i] = '0';
	}
}

int main()
{
	int num = 0, count  = 0;
	char* string1 = new char[1000]{'\0'};
	char* string2 = new char[100]{ '\0' };
	char word = '0';
	mystring a;
	mystring b;

	while (num != 6)
	{
		cout << "Please Enter command (1 : add, 2: delete_char, 3 : delete_lastchar, 4 : and_operator, 5 : print, 6 : exit) : ";
		cin >> num;
		switch (num)
		{
		case 1:
			if (count == 0) {
				cin >> string1;
				a.operator+=(string1);
				count++;
			}
			else {
				cin >> string2;
				a.operator+=(string2);
			}
			break;
		case 2:
			cin >> word;
			a.operator-=(word);
			break;
		case 3:
			a.operator--();
			break;
		case 4:
			cin >> word;
			a.operator&&(word);
			break;
		case 5:
			a.print();
			break;
		
		}

	}
}
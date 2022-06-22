#include <iostream>
#include <string.h>
using namespace std;

class Student
{
private:
	char name[20];
	int Score;
public:
	Student (){}
	Student(char* name, int score) 
	{
		strcpy(this->name, name);
		Score = score;
	}
	void print()
	{
		cout << name << Score << endl;
	}
	char* getName() {
		return name;

	}
	void setScore(int score) {
		Score = score;
	}
	int getScore() {
		return Score;
	}
};

int main()
{
	char* name = new char[20];
	int score = 0, tmp = 0, cmp = 0, a = 0, i = 0;
	Student stu[100];

	while (1)
	{
		cout << "Please Enter Command(1:insert, 2:sort by name, 3:sort by score, 4:quit) ";
		cin >> a;

		if (a == 4) break;
		switch (a)
		{
		case 1:
			cout << "Name :";
			cin >> name;
			cout << "Score :";
			cin >> score;
			stu[i] = Student(name, score);
			i++;
			break;
		case 2:
			if (i > 1)
			{
				for (int j = 0; j < i - 1; j++) {
					for (int k = 0; k < i - 1 - j; k++) {
						if (strcmp(stu[k].getName(), stu[k + 1].getName()) > 0)
						{
							strcpy(name, stu[k].getName());
							cmp = stu[k].getScore();
							strcpy(stu[k].getName(), stu[k + 1].getName());
							tmp = stu[k + 1].getScore();
							stu[k].setScore(tmp);
							strcpy(stu[k + 1].getName(), name);
							stu[k + 1].setScore(cmp);
						}
					}
				}
				for (int j = 0; j < i; j++) {
					stu[j].print();
				}
			}
			break;
		case 3:
			if (i > 1)
			{
				for (int j = 0; j < i - 1; j++) {
					for (int k = 0; k < i - 1 - j; k++) {
						if (stu[k].getScore() > stu[k + 1].getScore())
						{
							strcpy(name, stu[k].getName());
							cmp = stu[k].getScore();
							strcpy(stu[k].getName(), stu[k + 1].getName());
							tmp = stu[k + 1].getScore();
							stu[k].setScore(tmp);
							strcpy(stu[k + 1].getName(), name);
							stu[k + 1].setScore(cmp);
						}
					}
				}
				for (int j = 0; j < i; j++) {
					stu[j].print();
				}
			}
			break;
		}
	}
	delete[] name;
	return 0;
}
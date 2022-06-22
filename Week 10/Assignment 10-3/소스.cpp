#include <iostream>
#include <fstream>
using namespace std;

class Node
{
public:
	int min = 0;
	char* menu = new char[20];
	Node* next = NULL;
	Node() {}
	Node(char* _menu, int _min) {
		menu = _menu;
		min = _min;
	}
	bool serach(char* _menu) {
		if (strcmp(menu, _menu) == 0) return true;
		else return false;
	}
};

class Queue {
public:
	Node* front = NULL; // pointer to front node
	Node* rear = NULL;
	int counter = 0;
	int num = 1, time = 1;
	/*~Queue() { // destructor
		double value;
		while (!IsEmpty()) Dequeue(value);
	}*/
	bool IsEmpty() { //jack jon bob이 모두 끝났는지
		Node* currNode = front;
		if (currNode == NULL) return 0;
		else return 1;
	}
	void Enqueue(char* _menu, int _min) {
		Node* newNode = new Node;
		newNode->menu = _menu;
		newNode->min = _min;

		if (front == NULL) {
			front = newNode;
			rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
		counter++;
	}
	void Dequeue(void) {
		if (counter == 0) {
			cout << "Error: the queue is empty." << endl;
		}
		Node* nextNode = front->next;
		delete front;
		front = nextNode;
		counter--;
	}
	int JackPrint() {
		Node* currNode = front;
		int minute = 0;
		if (currNode == NULL) {
			cout << "\t\t\t";
			return 0;
		}
			if (currNode->min - time != 0) {
				cout << "\tCooking(" << currNode->menu << currNode->min - time << "/" << currNode->min << ")\t";
				time++;
				return 0;
			}
			else {
				cout << "\tDone!(" << currNode->menu << ")\t\t";
				time = 1;
				minute = currNode->min;
				Dequeue();
				return minute;
			}
	}
	int JohnPrint() {
		Node* currNode = front;
		int minute = 0;
		if (currNode == NULL) {
			cout << "\t\t\t";
			return 0;
		}
		if (currNode->min - time != 0) {
			cout << "\t\tCooking(" << currNode->menu << currNode->min - time << "/" << currNode->min << ")\t\t";
			time++;
			return 0;
		}
		else {
			cout << "  \t\tDone!(" << currNode->menu << ")\t\t\t";
			time = 1;
			minute = currNode->min;
			Dequeue();
			return minute;
		}
	}
	int BobPrint() {
		Node* currNode = front;
		int minute = 0;

		if (currNode == NULL) {
			cout << endl;
			return 0;
		}
			if (currNode->min - time != 0) {
				cout << "\t\tCooking(" << currNode->menu << currNode->min - time << "/" << currNode->min << ")\t";
				cout << endl;
				time++;
				return 0;
			}
			else {
				cout << "  \t\tDone!(" << currNode->menu << ")\t" << endl;
				minute = currNode->min;
				time = 1;
				Dequeue();
				return minute;
			}
	}
};

int main()
{
	int count1 = 0, count2 = 0, jack = 0, bob = 0, john = 0, jacktime = 0, johntime = 0, bobtime = 0, k = 0;
	char temp, name[10] = {'0'};
	Queue QJack; //큐
	Queue QBob;
	Queue QJohn;

	ifstream file1("Assignment3-3-3-1.txt");
	while (!file1.eof()) {
		file1.get(temp);
		if (temp == '\n' || temp == ' ')
			count1++;
	}
	count1++;
	file1.close();
	char** str1 = new char* [count1];
	for (int i = 0; i < count1; i++) {
		str1[i] = new char[50];
	}
	ifstream file1_1("Assignment3-3-3-1.txt");
	if (!file1_1) {
		cout << "Unable to open" << endl;
	}
	for (int i = 0; i < count1; i++) {
		file1_1 >> str1[i];
		if (strcmp(str1[i], "Jack") == 0) jack++;
		else if (strcmp(str1[i], "Bob") == 0) bob++;
		else if (strcmp(str1[i], "John") == 0) john++;
	}

	Node* Jack = new Node[jack];
	Node* Bob = new Node[bob];
	Node* John = new Node[john];

	for (int i = 0; i < jack; i++) {
		Jack[i] = Node(str1[3 * i + 1], atoi(str1[3 * i + 2]));
	}
	for (int i = 0; i < bob; i++) {
		Bob[i] = Node(str1[3 *i + 22], atoi(str1[3 * i + 23]));
	}
	for (int i = 0; i < john; i++) {
		John[i] = Node(str1[3 * i + 43], atoi(str1[3 * i + 44]));
	}

	ifstream file2("Assignment3-3-3-2.txt");
	temp = '0';
	while (!file2.eof()) {
		file2.get(temp);
		if (temp == ' ')
			count2++;
	}
	count2++;
	file2.close();

	char** str2 = new char* [count2];
	for (int i = 0; i < count2; i++) {
		str2[i] = new char[50];
	}
	ifstream file2_1("Assignment3-3-3-2.txt");
	if (!file2_1) {
		cout << "Unable to open" << endl;
	}
	for (int i = 0; i < count2; i++) {
		file2_1 >> str2[i];
	}

	while (k != count2) { //오류: 재입력시 다음 메뉴로 넘어가게 됨. -> 완료
		cout << "New order : " << str2[k] << endl;
		cout << "Pick cooker : ";
		cin >> name;
		if (strcmp(name, "Jack") == 0) {
			for (int j = 0; j < jack + 1; j++) {
				if (j == jack) {
					cout << "Please enter it again" << endl;
					break;
				}
				else if (Jack[j].serach(str2[k]) == true && j <= jack) {
					QJack.Enqueue(str2[k], Jack[j].min);
					k++;
					break;
				}
			}
		}
		else if (strcmp(name, "Bob") == 0) {
			for (int j = 0; j < bob + 1; j++) {
				if (j == bob) {
					cout << "Please enter it again" << endl;
					break;
				}
				else if (Bob[j].serach(str2[k]) == true && j <= bob) {
					QBob.Enqueue(str2[k], Bob[j].min);
					k++;
					break;
				}
			}
		}
		else if (strcmp(name, "John") == 0) {
			for (int j = 0; j < john + 1; j++) {
				if (j == john) {
					cout << "Please enter it again" << endl;
					break;
				}
				else if (John[j].serach(str2[k]) == true && j <= john) {
					QJohn.Enqueue(str2[k], John[j].min);
					k++;
					break;
				}
			}
		}
		else {
			while (strcmp(name, "Jack") != 0 && strcmp(name, "John") != 0 && strcmp(name, "Bob") != 0) {
				cout << "Please enter it again" << endl;
				break;
			}
		}
	}
	cout << "\t\tJack\t\t\t" << "\t\tJohn\t\t\t" << "\t\tBob\t\t\t" << endl;

	while(1) {
		jacktime = jacktime + QJack.JackPrint();
		johntime = johntime + QJohn.JohnPrint();
		bobtime = bobtime + QBob.BobPrint();
		if (QJack.IsEmpty() == 0 && QJohn.IsEmpty() == 0 && QBob.IsEmpty() == 0) {
			if (jacktime > johntime) {
				if (jacktime > bobtime) {
					cout << "Total Time is :" << jacktime;
					break;
				}
				else cout << "Total Time is :" << bobtime;
				break;
			}
			else if (johntime > bobtime) {
				cout << "Total Time is :" << johntime;
				break;
			}
			else {
				cout << "Total Time is :" << bobtime;
				break;
			}
		}
	}
	return 0;
}
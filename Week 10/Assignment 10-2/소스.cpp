#include <iostream>
#include <fstream>
using namespace std;

class oneNode
{
public:
	oneNode* next = NULL;
	oneNode* prev = NULL;
	char* station = new char[30];
	~oneNode() { delete[] station; }
};
class twoNode
{
public:
	twoNode* next = NULL;
	twoNode* prev = NULL;
};
class oneList
{
public:
	oneNode* head = NULL;
	oneNode* tail = NULL;
	int flag;

	void insert(char* _station)
	{
		oneNode* currNode = head;
		oneNode* newNode = new oneNode;
		newNode->station = _station;

		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			while (currNode)
			{
				if (currNode->next != NULL) {
					currNode = currNode->next;
				}
				else {
					currNode->next = newNode;
					newNode->prev = currNode;
					tail = newNode;
					break;
				}
			}
		}
	}
	int find(int _num, char* _station)
	{
		oneNode* currNode = head;
		flag = -1;
		if (strcmp(_station, "도봉") == 0) flag = 1;

		while (strcmp(currNode->station, _station) != 0)
		{	
			if (_num == 0) {
				currNode = currNode->next;
				flag++;
				if (currNode == NULL && flag == 25) { // 2호선 거르기
					flag = -1;
					break;
				}
			}
			else { //1, 2호선 갈렸을 때
				if (strcmp(currNode->station, "시청") == 0) { //시청이 먼저 걸리면 시청보다 앞에 있는 역이므로 정방향 출력
					return 0;								 // 다른 역이 먼저 걸리면 시청보다 뒤에 있는 역이니까 역방향 출력
				}
				else {
					currNode = currNode->next;
					flag++;
				}
			}
		}
		return flag;
	}
	void print_forward(char* _input1, char* _input2)
	{
		oneNode* currNode = tail;
		while (1)
		{
			if (strcmp(currNode->station, _input1) == 0) {
				while (1) {
					if (strcmp(currNode->station, _input2) == 0) {
						if (strcmp(_input2, "시청") == 0) cout << currNode->station;
						else cout << currNode->station;
						break;
					}
					else {
						cout << currNode->station << "->";
						currNode = currNode->prev;
					}
				}
				break;
			}
			else {
				currNode = currNode->prev;
			}
		}
	}
	void print_back(char* _input1, char* _input2)
	{
		oneNode* currNode = head;
		while (1)
		{
			if (strcmp(currNode->station, _input1) == 0) {
				while (1) {
					if (strcmp(currNode->station, _input2) == 0) {
						if (strcmp(_input2, "시청") == 0) cout << currNode->station;
						else cout << currNode->station;
						break;
					}
					else {
						cout << currNode->station << "->";
						currNode = currNode->next;
					}
				}
				break;
			}
			else {
				currNode = currNode->next;
			}
		}
	}
};
class twoList
{
public:
	oneNode* head = NULL;
	oneNode* tail = NULL;
	int count = 0, flag= 0;

	void insert(int _count, char* _station)
	{
		oneNode* currNode = head;
		oneNode* newNode = new oneNode;
		newNode->station = _station;

		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			while (currNode)
			{
				if (currNode->next != NULL) {
					currNode = currNode->next;
				}
				else if (count == _count) {
					tail->next = head;
					head->prev = tail;
					tail = tail->next;
				}
				else {
					currNode->next = newNode;
					newNode->prev = currNode;
					tail = newNode;
					count++;
					break;
				}
			}
		}
	}
	void link()
	{
		tail->next = head;
		head->prev = tail;
		tail = tail->next;
	}
	int find_forward(char* _input1, char* _input2)
	{
		oneNode* currNode = head;
		flag = 0;
		while (1)
		{
			if (strcmp(currNode->station, _input1) == 0) {
				while (1) {
					if (strcmp(currNode->station, _input2) == 0) {
						flag++;
						break;
					}
					else {
						currNode = currNode->next;
						flag++;
					}
				}
				break;
			}
			else {
				currNode = currNode->next;
			}
		}
		return flag;
	}
	int find_back(char* _input1, char* _input2)
	{
		oneNode* currNode = head;
		flag = 0;
		while (1)
		{
			if (strcmp(currNode->station, _input1) == 0) {
				while (1) {
					if (strcmp(currNode->station, _input2) == 0) {
						flag++;
						break;
					}
					else {
						currNode = currNode->prev;
						flag++;
					}
				}
				break;
			}
			else {
				currNode = currNode->next;
			}
		}
		return flag;
	}
	void print_forward(char* _input1, char* _input2)
	{
		oneNode* currNode = tail;
		while (1)
		{
			if (strcmp(currNode->station, _input1) == 0) {
				while (1) {
					if (strcmp(currNode->station, _input2) == 0) {
						if (strcmp(_input2, "시청") == 0) currNode = currNode->prev;
						else cout << currNode->station;
						break;
					}
					else {
						cout << currNode->station << "->";
						currNode = currNode->prev;
					}
				}
				break;
			}
			else {
				currNode = currNode->prev;
			}
		}
	}
	void print_back(char* _input1, char* _input2)
	{
		oneNode* currNode = head;
		while (1)
		{
			if (strcmp(currNode->station, _input1) == 0) {
				while (1) {
					if (strcmp(currNode->station, _input2) == 0) {
						cout << currNode->station;
						break;
					}
					else {
						if (strcmp(currNode->station, "시청") == 0) currNode = currNode->next;
						else {
							cout << currNode->station << "->";
							currNode = currNode->next;
						}
					}
				}
				break;
			}
			else {
				currNode = currNode->next;
			}
		}
	}
};
int main()
{
	int count1 = 0, count2 = 0, cnt = 0;
	ifstream file1("Assignment3-3-2-1.txt");
	char temp, flag[50] = { '0' }, cityhall[10] = { "시청" };
	char* input1 = new char[20];
	char* input2 = new char[20];
	oneList onelist;
	twoList twolist;

	while (!file1.eof()) {
		file1.get(temp);
		if (temp == '\n')
			count1++;
	}
	count1++;
	file1.close();

	char** str1 = new char* [count1];
	for (int i = 0; i < count1; i++) {
		str1[i] = new char[50];
	}
	ifstream file1_1("Assignment3-3-2-1.txt");
	if (!file1_1) {
		cout << "Unable to open" << endl;
	}
	for (int i = 0; i < count1; i++) {
		file1_1 >> str1[i];
	}
	for (int i = 0; i < count1; i++) {
		onelist.insert(str1[i]);
	}

	ifstream file2("Assignment3-3-2-2.txt");
	temp = '0';
	while (!file2.eof()) {
		file2.get(temp);
		if (temp == '\n')
			count2++;
	}
	count2++;
	file2.close();

	char** str2 = new char* [count2];
	for (int i = 0; i < count2; i++) {
		str2[i] = new char[50];
	}
	ifstream file2_1("Assignment3-3-2-2.txt");
	if (!file2_1) {
		cout << "Unable to open" << endl;
	}
	for (int i = 0; i < count2; i++) {
		file2_1 >> str2[i];
	}
	for (int i = 0; i < count2; i++) {
		twolist.insert(cnt, str2[i]);
		cnt++;
	}
	twolist.link();

	cout << "출발역 : ";
	cin >> input1;
	cout << "도착역 : ";
	cin >> input2;

	if (onelist.find(0, input1) >= 0 && onelist.find(0, input2) >= 0) {
		if (onelist.find(0, input1) > onelist.find(0, input2)) //정방향 역방향 결정
			onelist.print_forward(input1, input2); //프린트 함수로 들어가서 input2일때까지 돌다가 input1 만나면 그때부터 출력
		else
			onelist.print_back(input1, input2); //프린트 함수로 들어가서 input2일때까지 돌다가 input1 만나면 그때부터 출력
	}
	else if (onelist.find(0, input1) >= 0 && onelist.find(0, input2) < 0) { //1호선, 2호선
		if (onelist.find(1, input1) > 0) { //1호선 정방향
			onelist.print_back(input1, cityhall);
			if (twolist.find_forward(input2, cityhall) > twolist.find_back(input2, cityhall)) {
				cout << "->";
				twolist.print_back(cityhall, input2);
			}
			else twolist.print_forward(cityhall, input2); //완료
		}
		else {
			onelist.print_forward(input1, cityhall); //1호선 역방향
			if (twolist.find_forward(input2, cityhall) > twolist.find_back(input2, cityhall)) {
				cout << "->";
				twolist.print_back(cityhall, input2); //설역->홍입
			}
			else twolist.print_forward(cityhall, input2); //완료
		}
	}
	else if (onelist.find(0, input1) < 0 && onelist.find(0, input2) >= 0) { //2호선 1호선
		if (twolist.find_forward(input1, cityhall) > twolist.find_back(input1, cityhall)) {
			twolist.print_forward(input1, cityhall);
			if (onelist.find(1, input2) > 0) {
				onelist.print_forward(cityhall, input2); //완료
			}
			else onelist.print_back(cityhall, input2);

		}
		else {
			twolist.print_back(input1, cityhall);
			if (onelist.find(1, input2) > 0) {
				onelist.print_forward(cityhall, input2);
			}
			else onelist.print_back(cityhall, input2);
		}
	}
	else if (onelist.find(0, input1) < 0 && onelist.find(0, input2) < 0) {
		if (twolist.find_forward(input1, input2) > twolist.find_back(input1, input2)) { // 앞, 뒤 비교했을 때 리턴된 카운트 크기비교
			twolist.print_forward(input1, input2);
		}
		else {
			twolist.print_back(input1, input2); 
		}
	}
}
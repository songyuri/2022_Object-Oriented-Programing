#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public: 
	string data;
	Node* next;
};
class List {
private: Node* head;
public:
	List(void) { head = NULL; };
	~List(void) {
		Node* currNode = head, * nextNode = NULL;

		while (currNode != NULL)
		{
			nextNode = currNode->next;
			delete currNode;
			currNode = nextNode;
		}
	}
	Node* insert(int index, string str) {
		if (index < 0) return NULL;

		int currIndex = 1;
		Node* currNode = head;
		while (currNode && index > currIndex) {
			currNode = currNode->next;
			currIndex++;
		}
		if (index > 0 && currNode == NULL) return NULL;

		Node* newNode = new Node;
		newNode->data = str;
		if (index == 0) {
			newNode->next = head;
			head = newNode;
		}
		else {
			newNode->next = currNode->next;
			currNode->next = newNode;
		}
		return newNode;
	}
	bool check(string str)
	{
		Node* currNode = head;
		int currIndex = 1;

		while (currNode && tolower(currNode->data) != tolower(str)) {
			//if(currNode->data)
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode) return 0;
		else return 1;
	}

	string tolower(string str) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= 65 && str[i] <= 90)  // 대문자이면
				str[i] += 32;
		}
		return str;
	}
	void Listprint(void)
	{
		Node* currNode = head;

		while (currNode != NULL) {
			cout << currNode->data << "->" ;
			currNode = currNode->next;
		}
		cout << endl;
	}
};

int main()
{
	List li;
	string str;
	string prvstr;
	int i = 0, flag = 0, prvcount = 0;
	while (1)
	{
		cout << "CMD(Word/exit)>>";
		cin >> str;

		if (str == "exit") break;
		if (li.check(str) == 0) {
			cout << "Already Exists" << endl;
			li.Listprint();
		}
		else if ((flag == 0) || (str[0] == prvstr[prvcount - 1]) || (str[0] == prvstr[prvcount - 1] - 32) || (str[0] == prvstr[prvcount - 1] + 32) )
		{
			li.insert(i, str);
			li.Listprint();
			i++;
			prvstr = str;
			prvcount = prvstr.length();
		}
		else {
			cout << "Not Chained" << endl;
			li.Listprint();
		}
		flag++;
	}
	return 0;
}
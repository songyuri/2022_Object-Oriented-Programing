#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Node
{
public:
	Node* next = NULL;
	Node* down = NULL;
	char alpha;
	char* word = new char[50];

	Node(){}
	Node(char* _word)
	{
		strcpy(word, _word);
	}
	~Node() {
		delete[] word;
	}
};
class List
{
private:
	Node* head;
public:
	int count = 0;
	List() { head = NULL; }
	~List()
	{
		int count = 0;
		Node* prevNode = NULL;
		Node* currNode = head;
		while (currNode) {
			currNode = currNode->next;
			while (currNode) {
				prevNode = currNode;
				currNode = currNode->next;
				delete prevNode;
			}
			currNode = head;
			count++;
			for (int i = 0; i < count; i++) {
				currNode = currNode->down;
			}
		}
		currNode = head;
		for (int i = 0; i < count; i++) {
			prevNode = currNode;
			currNode = currNode->down;
			delete prevNode;
		}
	}

	void insert(char* _str) {

		Node* newNode = new Node;
		Node* currNode = head;
		newNode->word = _str;

		if (head == NULL) {
			Node* alphaNode = new Node;
			alphaNode->alpha = _str[0];
			if (alphaNode->alpha > 90) {
				alphaNode->alpha -= 32;
			}
			head = alphaNode;
			alphaNode->next = newNode;
		}
		else {
			while (currNode) {
				if (currNode->alpha == _str[0] || currNode->alpha + 32 == _str[0]) {
					while (currNode) {
						if (currNode->next == NULL) {
							currNode->next = newNode;
							break;
						}
						currNode = currNode->next;
					}
					break;
				}
				else
				{
					if (currNode->down == NULL) {
						Node* alphaNode = new Node;
						alphaNode->alpha = _str[0];
						if (alphaNode->alpha > 90) {
							alphaNode->alpha -= 32;
						}
						currNode->down = alphaNode;
						currNode = currNode->down;
						while (currNode) {
							if (currNode->next == NULL) {
								currNode->next = newNode;
								break;
							}
							currNode = currNode->next;
						}
						break;
					}
					else {
						currNode = currNode->down;
					}
				}
			}
		}
	}
	void print()
	{
		int count = 0;
		Node* currNode = head;
		while (currNode)
		{
			cout << currNode->alpha;
			currNode = currNode->next;
			while (currNode)
			{
				if (currNode) {
					cout << " -> " << currNode->word;
					currNode = currNode->next;
				}
			}
			cout << endl;
			count++;
			currNode = head;
			for (int i = 0; i < count; i++) {
				currNode = currNode->down;
			}
		}
	}
};

int main()
{
	int count = 0;
	ifstream file1("Assignment.txt.txt");
	List li;
	char temp, flag[50] = {"0"};

	while (!file1.eof()) {
		file1.get(temp);
		if (temp == '\n')
			count++;
	}
	count++;
	file1.close();

	char** str = new char*[count];
	for (int i = 0; i < count; i++) {
		str[i] = new char[50];
	}
	ifstream file2("Assignment.txt.txt");

	if (!file2) {
		cout << "Unable to open" << endl;
	}
	for (int i = 0; i < count; i++) {
		file2 >> str[i];
	}
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - 1 - i; j++) {
			if (stricmp(str[j], str[j + 1]) > 0) {
				strcpy(flag, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], flag);
			}
		}
	}
	for (int i = 0; i < count; i++) {
		li.insert(str[i]);
	}

	li.print();

	return 0;
}
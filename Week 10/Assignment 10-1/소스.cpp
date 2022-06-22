#include <iostream>
using namespace std;

class Node
{
public:
	int Value = 0;
	Node* left = NULL;
	Node* right = NULL;
	Node() {}
};
class BTS
{
public:
	Node* head = NULL;
	Node* root;
	BTS() { root = NULL; }

	void insert(int _num) {

		Node* newNode = new Node;
		Node* currNode = root;
		newNode->Value = _num;

		if (root == NULL) {
			root = newNode;
		}
		else {
			while (currNode) {

				if (currNode->Value > _num && currNode->left == NULL) {
					currNode->left = newNode;
					break;
				}
				else if (currNode->Value > _num && currNode->left != NULL) {
					currNode = currNode->left;
				}
				else if (currNode->Value < _num && currNode->right == NULL) {
					currNode->right = newNode;
					break;
				}
				else if (currNode->Value < _num && currNode->right != NULL) {
					currNode = currNode->right;

				}
				else
					break;
			}
		}
	}
	void find(int _num) {
		Node* currNode = root;

		while (1) {
			if (currNode->Value > _num && currNode->left != NULL) {
				currNode = currNode->left;
			}
			else if (currNode->Value < _num && currNode->right != NULL) {
				currNode = currNode->right;
			}
			else if (currNode->Value == _num) {
				currNode = root;
				cout << "Path : ";
				cout << currNode->Value;
				while (currNode->Value != _num) {
					if (currNode->Value > _num && currNode->left != NULL) {
						currNode = currNode->left;
						cout << "->" << currNode->Value;
					}
					else if (currNode->Value < _num && currNode->right != NULL) {
						currNode = currNode->right;
						cout << "->" << currNode->Value;
					}
				}
				break;
			}
			else break;
		}
	}
	void _delete(int  _num) {
		Node* currNode = root;// root = 맨꼭대기
		Node* prevNode = root;
		Node* pprevNode = root;

		while (currNode) {
			if (currNode->Value > _num && currNode->left != NULL) { //왼쪽으로 가
				prevNode = currNode;
				currNode = currNode->left;
				if (currNode->Value == _num && currNode->left == NULL && currNode->right == NULL) { //가지가 없어
					delete currNode;
					prevNode->left = nullptr;
					currNode = NULL;
				}
				else if (currNode->Value == _num && currNode->left == NULL && currNode->right != NULL) { //왼가지 없 오른가지 있
					prevNode->left= currNode->right;
					delete currNode;
					currNode = NULL;
				}
				else if (currNode->Value == _num && currNode->left != NULL && currNode->right == NULL) { //왼가지있 오른가지없
					prevNode->left = currNode->left;
					delete currNode;
					currNode = NULL;
				}
				else if (currNode->Value == _num && currNode->left != NULL && currNode->right != NULL) { //둘다 있음
					head = currNode;
					currNode = currNode->left;
					while (currNode)
					{
						pprevNode = prevNode;
						prevNode = currNode;
						currNode = currNode->right;
					}
					head->Value = prevNode->Value;
					currNode = head;
					if (prevNode->left != NULL) {
						pprevNode->right = prevNode->left;
					}
					delete prevNode;
					prevNode = NULL;
					break;
				}
			}
			else if (currNode->Value < _num && currNode->right != NULL) { //오른쪽으로 가
				prevNode = currNode;
				currNode = currNode->right;
				if (currNode->Value == _num && currNode->left == NULL && currNode->right == NULL) {
					delete currNode;
					prevNode->right = nullptr;
					break;
				}
				else if (currNode->Value == _num && currNode->left == NULL && currNode->right != NULL) {
					prevNode->right = currNode->right;
					delete currNode;
					break;
				}
				else if (currNode->Value == _num && currNode->left != NULL && currNode->right == NULL) {
					prevNode->right = currNode->left;
					delete currNode;
					break;
				}
				else if (currNode->Value == _num && currNode->left != NULL && currNode->right != NULL) {
					head = currNode;
					currNode = currNode->left;
					while (currNode)
					{
						pprevNode = prevNode;
						prevNode = currNode;
						currNode = currNode->right;
					}
					head->Value = prevNode->Value;
					currNode = head;
					if (prevNode->left != NULL) {
						pprevNode->right = prevNode->left;
					}
					delete prevNode;
					break;
				}
			}
			else if (currNode->Value == _num) { //처음부터 같아
				prevNode = currNode;
				currNode = currNode->left;
				while (currNode)
				{
					pprevNode = prevNode;
					prevNode = currNode;
					currNode = currNode->right;
				}
				root->Value = prevNode->Value;
				if (prevNode->left != NULL) {
					pprevNode->right = prevNode->left;
				}
				delete prevNode;
			}
		}
	}
};

int main()
{
	int num = 0, command = 0;
	BTS bts;

	while (command != 4) {
		cout << "Enter Any Command(1:insert, 2:Delete, 3:Find, 4:Exit): ";
		cin >> command;

		if (command == 1) {
			cin >> num;
			bts.insert(num);
		}
		else if (command == 2) {
			cin >> num;
			bts._delete(num);
		}
		else if (command == 3) {
			cin >> num;
			bts.find(num);
			cout << endl;
		}
	}
}
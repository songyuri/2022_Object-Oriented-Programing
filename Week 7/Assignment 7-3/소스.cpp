#include <iostream>
#include <string.h>
using namespace std;

class node {
public:
    int data;
    node* next;
};
class list {
private: node* head;
public:
    list(void) { head = NULL; };
    ~list(void) {
        node* currNode = head, * nextnode = NULL;

        while (currNode != NULL)
        {
            nextnode = currNode->next;
            delete currNode;
            currNode = nextnode;
        }
    }

    node* _insert(int index, int x) {
        if (index < 0) return NULL;

        int currIndex = 1;
        node* currNode = head;
        while (currNode && index > currIndex) {
            currNode = currNode->next;
            currIndex++;
        }
        if (index > 0 && currNode == NULL) return NULL;

        node* newnode = new node;
        newnode->data = x;
        if (index == 0) {
            newnode->next = head;
            head = newnode;
        }
        else {
            newnode->next = currNode->next;
            currNode->next = newnode;
        }
        return newnode;
    }
    int _find(int x) {
        node* currNode = head;
        int currIndex = 1;
        int cnt = 0;

        while (1) {
            if (currNode->data == x)
            {
                cout << "Found Index:" << currIndex << endl;
                cnt++;
            }
            currNode = currNode->next;
            currIndex++;
            if (currNode == NULL) break;
        }
        return cnt;
    }
    int _delete(int i, int x) {
        int count = 0;

        for (int j = 0; j < i; j++) {
            node* prevNode = NULL;
            node* currNode = head;
            int currIndex = 1;

            while (currNode && currNode->data != x) {
                prevNode = currNode;
                currNode = currNode->next;
                currIndex++;
            }
            if (currNode) {
                if (prevNode) {
                    prevNode->next = currNode->next;
                    delete currNode;
                    count++;
                }
                else {
                    head = currNode->next;
                    delete currNode;
                    count++;
                }
            }
        }
        return count;
    }
    void _print(void) {
        int num = 0;
        node* currNode = head;

        while (currNode != NULL) {
            cout << currNode->data << endl;
            currNode = currNode->next;
            num++;
        }
        cout << "Number of nodes in the list: " << num << endl;
    }
};

int main()
{
    string str;
    int num = 0, i = 0, cmp = 0;
    list li;

    while (1) {
        cout << "Please Enter Command(1:insert, 2:find, 3:delete, 4:print, 5:quit)";
        cin >> str;

        if (str == "insert") {
            cin >> num;
            li._insert(i, num);
            i++;
        }
        else if (str == "find") {
            cin >> num;
            cmp = li._find(num);
        }
        else if (str == "delete") {
            cin >> num;
            i = i - li._delete(i, num);
        }
        else if (str == "print") {
            li._print();
        }
        else if (str == "quit") {
            break;
        }

    }
    return 0;
}
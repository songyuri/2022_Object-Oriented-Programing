#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Node
{
public:
    int id;
    string name;
    Node* next;
    Node* prev;
    Node(int _id, string _name, Node* _next, Node* _prev) {
        id = _id;
        name = _name;
        next = _next;
        prev = _prev;
    }
    Node() {
        this->next = nullptr;
        this->prev = nullptr;
        id = 0;
    };
};
class doublylinkedlist
{
public:
    int num = 0, count = 0;
    Node* head;
    Node* tail;

    doublylinkedlist()
    {
        head = NULL;
        tail = NULL;
    }
    int _insert(int x, string _name)
    {
        Node* newNode = new Node;
        Node* currNode = head;
        newNode->id = x;
        newNode->name = _name;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            while (currNode) {
                if (currNode->id == x) {
                    break;
                }
                if (currNode->id > x) {
                    if (currNode == head) {
                        head->prev = newNode;
                        newNode->next = head;
                        head = newNode;
                        num++;
                        break;
                    }
                    else {
                        newNode->prev = currNode->prev;
                        newNode->next = currNode;
                        currNode->prev->next = newNode;
                        currNode->prev = newNode;
                        num++;
                        break;
                    }
                }
                else if (tail->id < x) {
                    tail->next = newNode;
                    newNode->prev = tail;
                    tail = newNode;
                    num++;
                    break;
                }
                else currNode = currNode->next;
            }
        }
        return num;
    }
    void _print()
    {
        Node* currNode = head;
        while (currNode != NULL)
        {
            cout << currNode->id << " " << currNode->name << endl;
            currNode = currNode->next;
        }
    }
    void _print_reserve()
    {
        Node* currNode = tail;
        while (currNode != NULL)
        {
            cout << currNode->id << " " << currNode->name << endl;
            currNode = currNode->prev;
        }
    }
    void _sort_by_name()
    {
        string tmp;
        int number = 0;
        Node* currNode = head;
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num - i; j++) {
                if (currNode->name.compare(currNode->next->name) > 0) {
                    tmp = currNode->name;
                    number = currNode->id;
                    currNode->name = currNode->next->name;
                    currNode->id = currNode->next->id;
                    currNode->next->name = tmp;
                    currNode->next->id = number;
                }
                currNode = currNode->next;
            }
            currNode = head;
        }
    }
    void _sort_by_id()
    {
        string tmp;
        int number;
        Node* currNode = head;
        for (int i = 0; i < num - 1; i++) {
            for (int j = 0; j < num - 1 - i; j++) {
                if (currNode->id > currNode->next->id) {
                    tmp = currNode->name;
                    number = currNode->id;
                    currNode->name = currNode->next->name;
                    currNode->id = currNode->next->id;
                    currNode->next->name = tmp;
                    currNode->next->id = number;
                }
                currNode = currNode->next;
            }
            currNode = head;
        }
    }
    int _delete(int x)
    {
        Node* currNode = head;
        Node* prevNode = NULL;
        count = 0;

       while (currNode) {
               if (currNode->id == x) {
                   if (currNode == head) {
                       if (head->next == nullptr) {
                           delete head;
                           head = nullptr;
                           break;
                       }
                       currNode = currNode->next;
                       head = currNode;
                       delete currNode->prev;
                       currNode->prev = NULL;
                       count++;
                       break;
                   }
                   else if (currNode == tail) {
                       tail = tail->prev;
                       delete tail->next;
                       tail->next = NULL;
                       break;
                   }
                    else {
                       currNode->prev->next = currNode->next;
                       currNode->next->prev = currNode->prev;

                       delete currNode;
                       count++;
                       break;
                    }
               }
               else {
                   prevNode = currNode;
                   currNode = currNode->next;
               }
       }
       return count;
    }
};

int main()
{
    int num = 0, id = 0, cmp = 0, i = 0;
    string name;
    doublylinkedlist li;

    while (num != 7) {
        cout << "Please Enter Command(1 : insert, 2 : print, 3 : print_reverse, 4 : sort_by_name, 5:sort_by_ID, 6: delete, 7 : exit) : ";
        cin >> num;

        if (num == 1) {
            cin >> id >> name;
            i = li._insert(id, name);
        }
        else if (num == 2) {
            li._print();
        }
        else if (num == 3) {
            li._print_reserve();
        }
        else if (num == 4) {
            li._sort_by_name();
            li._print();
        }
        else if (num == 5) {
            li._sort_by_id();
            li._print();
        }
        else if (num == 6) {
            cin >> id;
            i = i - li._delete(id);

        }
    }
    return 0;
}
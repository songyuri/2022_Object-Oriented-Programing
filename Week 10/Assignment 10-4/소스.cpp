#include <iostream>
#include <fstream>
using namespace std;

class Node
{
public:
    char* major = new char[50];
    char* name = new char[20];
    int year;
    Node* next;
    Node* down;
    Node* left;
    Node* right;
    Node() {
        next = NULL;
        down = NULL;
        left = NULL;
        right = NULL;
    };
};
class BST
{
public:
    Node* root; 
    Node* head;
    BST() {
        root = NULL;
        head = NULL;
    }
    int _delete(Node* node, char* _name) {
        root = node;
        Node* currNode = root;// root = �ǲ����
        Node* prevNode = root;
        Node* pprevNode = root;

        while (currNode) {
            if (stricmp(currNode->name, _name) > 0 && currNode->left != NULL) { //�������� ��
                prevNode = currNode;
                currNode = currNode->left;
                if (stricmp(currNode->name, _name) == 0 && currNode->left == NULL && currNode->right == NULL) { //������ ����
                    delete currNode;
                    prevNode->left = nullptr;
                    cout << "Delete_name : " << _name << endl;
                    if (root == NULL)return 1;
                    else return 0;
                }
                else if (stricmp(currNode->name, _name) == 0 && currNode->left == NULL && currNode->right != NULL) { //�ް��� �� �������� ��
                    prevNode->left = currNode->right;
                    delete currNode;
                    currNode = nullptr;
                    cout << "Delete_name : " << _name << endl;
                    if (root == NULL)return 1;
                    else return 0;
                }
                else if (stricmp(currNode->name, _name) == 0 && currNode->left != NULL && currNode->right == NULL) { //�ް����� ����������
                    prevNode->left = currNode->left;
                    delete currNode;
                    currNode = nullptr;
                    cout << "Delete_name : " << _name << endl;
                    if (root == NULL)return 1;
                    else return 0;
                }
                else if (stricmp(currNode->name, _name) == 0 && currNode->left != NULL && currNode->right != NULL) { //�Ѵ� ����
                    head = currNode;
                    currNode = currNode->left;
                    while (currNode)
                    {
                        pprevNode = prevNode;
                        prevNode = currNode;
                        currNode = currNode->right;
                    }
                    head->name = prevNode->name;
                    currNode = head;
                    if (prevNode->left != NULL) {
                        pprevNode->right = prevNode->left;
                    }
                    delete prevNode;
                    prevNode = nullptr;
                    cout << "Delete_name : " << _name << endl;
                    if (root == NULL) return 1;
                    else return 0;
                    break;
                }
            }
            else if (stricmp(currNode->name, _name) < 0 && currNode->right != NULL) { //���������� ��
                prevNode = currNode;
                currNode = currNode->right;
                if (stricmp(currNode->name, _name) == 0 && currNode->left == NULL && currNode->right == NULL) {
                    delete currNode;
                    prevNode->right = nullptr;
                    cout << "Delete_name : " << _name << endl;
                    if (root == NULL)return 1;
                    else return 0;
                }
                else if (stricmp(currNode->name, _name) == 0 && currNode->left == NULL && currNode->right != NULL) {
                    prevNode->right = currNode->right;
                    delete currNode;
                    currNode = nullptr;
                    cout << "Delete_name : " << _name << endl;
                    if (root == NULL)return 1;
                    else return 0;
                }
                else if (stricmp(currNode->name, _name) == 0 && currNode->left != NULL && currNode->right == NULL) {
                    prevNode->right = currNode->left;
                    delete currNode;
                    currNode = nullptr;
                    cout << "Delete_name : " << _name << endl;
                    if (root == NULL)return 1;
                    else return 0;
                }
                else if (stricmp(currNode->name, _name) == 0 && currNode->left != NULL && currNode->right != NULL) {
                    head = currNode;
                    currNode = currNode->left;
                    while (currNode)
                    {
                        pprevNode = prevNode;
                        prevNode = currNode;
                        currNode = currNode->right;
                    }
                    head->name = prevNode->name;
                    currNode = head;
                    if (prevNode->left != NULL) {
                        pprevNode->right = prevNode->left;
                    }
                    delete prevNode;
                    prevNode = nullptr;
                    cout << "Delete_name : " << _name << endl;
                    if (root == NULL)return 1;
                    else return 0;
                }
            }
            else if (stricmp(currNode->name, _name) == 0) { //ó������ ����
                prevNode = currNode;
                currNode = currNode->left;
                while (currNode)
                {
                    pprevNode = prevNode;
                    prevNode = currNode;
                    currNode = currNode->right;
                }
                root->name = prevNode->name;
                if (prevNode->left != NULL) {
                    pprevNode->right = prevNode->left;
                }
                delete prevNode;
                cout << "Delete_name : " << _name << endl;
                root = nullptr;
                if (root == NULL)return 1;
                else return 0;
            }
        }
    }
};
class LinkedList
{
public:
    Node* root;
    Node* head;
    BST bst;
    LinkedList() {
        root = NULL;
        head = NULL;
    }
    void insert(char* _major, int _year, char* _name) {
        Node* newNode = new Node;
        Node* currNode = head;
        Node* rowprevNode = head;
        Node* colprevNode = head;
        Node* nameNode = new Node;
        Node* top = NULL;
        strcpy(nameNode->name, _name);
        strcpy(nameNode->major, _major);
        nameNode->year = _year;
        newNode->year = _year;
        int count = 0;
        if (head == NULL) {
            Node* majorNode = new Node;
            majorNode->major = _major;
            head = majorNode;
            majorNode->next = newNode;
            newNode->down = nameNode;
        }
        else {
            while (currNode) { //�Ʒ��� ���� �ݺ���
                if (stricmp(currNode->major, _major) == 0) {
                    currNode = currNode->next;
                    top = currNode;
                    while (currNode) { //������ ���� �ݺ���
                        if (currNode->year == _year) { //��ġ �ϴ� �й��� �ִٸ�
                            currNode = currNode->down;
                            while (currNode) {
                                if (stricmp(currNode->name, _name) > 0 && currNode->left == NULL) { // ���� ���� ���ڰ� �� �տ�
                                    currNode->left = nameNode;
                                    break;
                                }
                                else if (stricmp(currNode->name, _name) > 0 && currNode->left != NULL) {
                                    currNode = currNode->left;
                                }
                                else if (stricmp(currNode->name, _name) < 0 && currNode->right == NULL) { //���� ���� ���ڰ� �ڿ�
                                    currNode->right = nameNode;
                                    break;
                                }
                                else if (stricmp(currNode->name, _name) < 0 && currNode->right != NULL) {
                                    currNode = currNode->right;
                                }
                            }
                        }
                        else if (currNode->year > _year) { //���� ���� �й��� �տ�
                            if (currNode == top) { // �� ��
                                head->next = newNode;
                                newNode->next = currNode;
                                newNode->down = nameNode;
                                currNode = NULL;
                                break;
                            }
                            else if (currNode->next != NULL) { // ���
                                rowprevNode->next = newNode;
                                newNode->next = currNode;
                                newNode->down = nameNode;
                                break;
                            }
                            else if (currNode->next == NULL) { //��
                                rowprevNode->next = newNode;
                                newNode->next = currNode;
                                newNode->down = nameNode;
                                break;
                            }
                        }
                        else if (currNode->next == NULL) {
                            currNode->next = newNode;
                            newNode->down = nameNode;
                            currNode = NULL;
                            break;
                        }
                        colprevNode = currNode;
                        currNode = currNode->next;
                    }
                }
                else if (stricmp(currNode->major, _major) > 0) { //���� ���� ���ڰ� �տ�
                    if (currNode == head) { // �� ��
                        Node* majorNode = new Node;
                        majorNode->major = _major;
                        majorNode = head;
                        majorNode->down = currNode;
                        majorNode->next = newNode;
                        newNode->down = nameNode;
                        count++;
                        break;
                    }
                    else if (currNode->down != NULL) { // ���
                        Node* majorNode = new Node;
                        majorNode->major = _major;
                        colprevNode->down = majorNode;
                        majorNode->down = currNode;
                        majorNode->next = newNode;
                        newNode->down = nameNode;
                        count++;
                        break;
                    }
                    else if (currNode->down == NULL) {
                        Node* majorNode = new Node;
                        majorNode->major = _major;
                        colprevNode->down = majorNode;
                        majorNode->down = currNode;
                        majorNode->next = newNode;
                        newNode->down = nameNode;
                        count++;
                        break;
                    }
                }
                else if (currNode->down == NULL) {
                    Node* majorNode = new Node;
                    majorNode->major = _major;
                    majorNode->next = newNode;
                    newNode->down = nameNode;
                    currNode->down = majorNode;
                    colprevNode = currNode;
                    count++;
                    break;
                }
                else {
                    colprevNode = currNode;
                    currNode = currNode->down;
                }
            }
        }
    }
    void _delete(char* _major, int _year, char* _name) {
        Node* currNode = head;
        Node* colprevNode = head;
        Node* rowprevNode = head;
        Node* row_move_prevNode = head;
        int return_name = 0;
        while (currNode) { // �Ʒ���
            if (stricmp(currNode->major, _major) == 0) {
                rowprevNode = currNode;
                row_move_prevNode = currNode;
                currNode = currNode->next;
                while (currNode) //������
                {
                    if (currNode->year == _year) {
                        return_name = bst._delete(currNode->down, _name);
                        if (return_name == 0) { //������ �����ִ� ���
                            currNode = NULL;
                        }
                        else {
                            if (currNode->next == NULL && row_move_prevNode != rowprevNode) { //���̰� �а��� �й��� �����ִ°��
                                cout << "Delete_Year : " << _year << endl;
                                currNode->next = nullptr;
                                delete currNode;
                                currNode = nullptr;
                            }
                            else if (currNode == rowprevNode->next && currNode->next->year > 0) { //�� ù�κ��̰� �ڿ� �� ����.
                                cout << "Delete_Year : " << _year << endl;
                                rowprevNode->next = currNode->next;
                                delete currNode;
                                currNode = nullptr;
                            }
                            else if (currNode != rowprevNode->next) { //�����
                                cout << "Delete_year : " << _year << endl;
                                row_move_prevNode->next = currNode->next;
                                delete currNode;
                                currNode = nullptr;
                            }
                            else { //�ϳ��ۿ� ����
                                cout << "Delete_Year : " << _year << endl;
                                delete currNode;
                                currNode = nullptr;
                                rowprevNode->next = nullptr;
                            }
                        }
                    }
                    else {
                        row_move_prevNode = currNode;
                        currNode = currNode->next;
                    }
                }
            }
            else {
                colprevNode = currNode;
                currNode = currNode->down;
            }
            if (rowprevNode->next == NULL && rowprevNode == head && rowprevNode->down != NULL) { // �а��� ���� �Ӹ��̸� �� �ƴ�
                head = rowprevNode->down;
                delete rowprevNode;
                cout << "Delete_Major : " << _major << endl;
                rowprevNode = nullptr;
            }
            else if (rowprevNode->next == NULL && rowprevNode != head && rowprevNode->down != NULL) {// �а��� ���� �߰��̸� ���� �ƴ�
                colprevNode->down = rowprevNode->down;
                delete rowprevNode;
                cout << "Delete_Major : " << _major << endl;
                rowprevNode = nullptr;
            }
            else if (rowprevNode->next == NULL && rowprevNode != head && rowprevNode->down == NULL) {// �а��� ���� �߰��̸� ���� ���
                delete rowprevNode;
                cout << "Delete_Major : " << _major << endl;
                rowprevNode = nullptr;
            }
            else if (rowprevNode->next == NULL && rowprevNode == head && rowprevNode->down == NULL) { // �а� ���� �Ӹ��鼭 ��
                delete rowprevNode;
                cout << "Delete_Major : " << _major << endl;
                rowprevNode = nullptr;
            }
        }
    }
    void print_all()
    {
        Node* currNode = head;
        int count = 0;
        while (currNode) //������
        {
            currNode = currNode->next;
            while (currNode) //������
            {
                circuit(currNode->down);
                currNode = currNode->next;
            }
            count++;
            currNode = head;
            for (int i = 0; i < count; i++) {
                currNode = currNode->down;
            }
        }
    }
    void print_major(char* _major) {
        Node* currNode = head;
        int count = 0;
        while (currNode) //������
        {
            if (stricmp(currNode->major, _major) == 0) {
                currNode = currNode->next;
                while (currNode) //������
                {
                    circuit(currNode->down);
                    currNode = currNode->next;
                }
                count++;
            }
            else {
                currNode = currNode->down;
            }
        }
    }
    void print_year(int _year) {
        Node* currNode = head;
        int count = 0;
        while (currNode) //������
        {
            currNode = currNode->next;
            while (currNode) {
                if (currNode->year == _year) {
                    circuit(currNode->down);
                    break;
                }
                else currNode = currNode->next;
            }
            count++;
            currNode = head;
            for (int i = 0; i < count; i++) {
                currNode = currNode->down;
            }
        }
    }
    void print_name(char* _name) {
        Node* currNode = head;
        Node* column = head;
        Node* point = NULL;
        int count = 0, tmp = 0;
        while (currNode) //������
        {
            tmp = 1;
            currNode = currNode->next;
            while (currNode) //������
            {
                if (find(currNode->down, _name) == true) {
                    currNode = point;
                    for (int i = 0; i < count + 1; i++) {
                        cout << column->major << "->";
                        column = column->down;
                    }
                    for (int i = 0; i < tmp; i++) {
                        currNode = currNode->next;
                        cout << currNode->year << "->";
                    }
                    find_print(currNode->down, _name);
                    cout << endl;
                    break;
                }
                else {
                    currNode = currNode->next;
                    tmp++;
                }
            }
            count++;
            currNode = head;
            for (int i = 0; i < count; i++) {
                currNode = currNode->down;
                point = currNode;
            }
        }
    }
    bool find(Node* node, char* _name) {
        Node* currNode = node;
        while (1) {
            if (stricmp(currNode->name, _name) > 0 && currNode->left != NULL) { //���� �̸��� �� �տ� ����
                currNode = currNode->left;
            }
            else if (stricmp(currNode->name, _name) < 0 && currNode->right != NULL) {
                currNode = currNode->right;
            }
            else if (stricmp(currNode->name, _name) == 0) {
                return true;
            }
            else return false;
        }
    }
    void find_print(Node* node, char* _name) {
        Node* currNode = node;
        while (1) {
            if (stricmp(currNode->name, _name) > 0 && currNode->left != NULL) { //���� �̸��� �� �տ� ����
                currNode = currNode->left;
            }
            else if (stricmp(currNode->name, _name) < 0 && currNode->right != NULL) {
                currNode = currNode->right;
            }
            else if (stricmp(currNode->name, _name) == 0) {
                currNode = node;
                cout << currNode->name;
                while (stricmp(currNode->name, _name) != 0) {
                    if (stricmp(currNode->name, _name) > 0 && currNode->left != NULL) {
                        currNode = currNode->left;
                        cout << "->" << currNode->name;
                    }
                    else if (stricmp(currNode->name, _name) < 0 && currNode->right != NULL) {
                        currNode = currNode->right;
                        cout << "->" << currNode->name;
                    }
                }
                break;
            }
            else break;
        }
    }
    void insert_print(char* _major, int _year, char* _name) { //���� �� ��� ���
        Node* currNode = head;
        while (currNode) {
            if (stricmp(currNode->major, _major) == 0) {
                cout << currNode->major << "->";
                currNode = currNode->next;
                while (currNode) //������
                {
                    if (currNode->year == _year) {
                        cout << currNode->year << "->" << _name << endl;
                        currNode = NULL;
                        break;
                    }
                    else {
                        cout << currNode->year << "->";
                        currNode = currNode->next;
                    }
                }
            }
            else {
                currNode = currNode->down;
            }
        }
    }
    void circuit(Node* node) {
        if (node == nullptr) return;
        circuit(node->left);
        cout << node->major << " " << node->year << " " << node->name << endl;
        circuit(node->right);
    }
};

int main()
{
    int count = 0, k = 0, num = 0, year = 0;
    char temp, name[10] = { '0' }, major[50] = { '0' };
    LinkedList li;

    ifstream file1("Assignment3-3-4.txt");
    while (!file1.eof()) {
        file1.get(temp);
        if (temp == '\n' || temp == ' ')
            count++;
    }
    count++;
    file1.close();
    char** str = new char* [count];
    for (int i = 0; i < count; i++) {
        str[i] = new char[50];
    }
    ifstream file1_1("Assignment3-3-4.txt");
    if (!file1_1) {
        cout << "Unable to open" << endl;
    }
    for (int i = 0; i < count; i++) {
        file1_1 >> str[i];
    }
    for (int i = 0; i < count; i = i + 3) {
        li.insert(str[i], atoi(str[i + 1]), str[i + 2]);
    }
    while (num != 7)
    {
        cout << "Enter Any Command(1:Insert, 2:Delete, 3:Print_all, 4:Print_major, 5:Print_id, 6:Print_Name, 6:Exit): ";
        cin >> num;
        switch (num) {
        case 1:
            cin >> major >> year >> name;
            li.insert(major, year, name);
            li.insert_print(major, year, name);
            break;
        case 2:
            cin >> major >> year >> name;
            li._delete(major, year, name);
            break;
        case 3:
            li.print_all();
            break;
        case 4:
            cin >> major;
            li.print_major(major);
            break;
        case 5:
            cin >> year;
            li.print_year(year);
            break;
        case 6:
            cin >> name;
            li.print_name(name);
            break;
        }
    }
}
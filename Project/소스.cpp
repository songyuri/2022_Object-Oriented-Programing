#include <iostream>
#include <fstream>
using namespace std;

class Node
{
public:
    Node* right;
    Node* left;
    Node* up;
    Node* down;
    Node* front;
    Node* back;
    Node* tleft;
    Node* tright;
    Node* center;
    int  z = 0, y = 0, x = 0;
    char* word = new char[20];
    Node() {
        right = NULL;
        left = NULL;
        up = NULL;
        down = NULL;
        front = NULL;
        back = NULL;
    }
};
class BST
{
private:
    Node* head = nullptr;
    Node* root = nullptr;
    int count = 0;
public:
    int _delete(Node* node, char* _word) {
        Node* currNode = node;// node = 맨꼭대기
        Node* prevNode = node;
        Node* pprevNode = node;

        while (currNode) {
            if (currNode == NULL) return 0;
            if (stricmp(currNode->word, _word) > 0 && currNode->left != NULL) { //왼쪽으로 가
                prevNode = currNode;
                currNode = currNode->left;
                if (stricmp(currNode->word, _word) == 0 && currNode->left == NULL && currNode->right == NULL) { //가지가 없어
                    delete currNode;
                    prevNode->left = nullptr;
                    if (root == NULL)return 1;
                    else return 0;
                }
                else if (stricmp(currNode->word, _word) == 0 && currNode->left == NULL && currNode->right != NULL) { //왼가지 없 오른가지 있
                    prevNode->left = currNode->right;
                    delete currNode;
                    currNode = nullptr;
                    if (root == NULL)return 1;
                    else return 0;
                }
                else if (stricmp(currNode->word, _word) == 0 && currNode->left != NULL && currNode->right == NULL) { //왼가지있 오른가지없
                    prevNode->left = currNode->left;
                    delete currNode;
                    currNode = nullptr;
                    if (root == NULL)return 1;
                    else return 0;
                }
                else if (stricmp(currNode->word, _word) == 0 && currNode->left != NULL && currNode->right != NULL) { //둘다 있음
                    head = currNode;
                    currNode = currNode->left;
                    while (currNode)
                    {
                        pprevNode = prevNode;
                        prevNode = currNode;
                        currNode = currNode->right;
                    }
                    head->word = prevNode->word;
                    currNode = head;
                    if (prevNode->left != NULL) {
                        pprevNode->right = prevNode->left;
                    }
                    delete prevNode;
                    prevNode = nullptr;
                    if (root == NULL) return 1;
                    else return 0;
                    break;
                }
            }
            else if (stricmp(currNode->word, _word) < 0 && currNode->right != NULL) { //오른쪽으로 가
                prevNode = currNode;
                currNode = currNode->right;
                if (stricmp(currNode->word, _word) == 0 && currNode->left == NULL && currNode->right == NULL) {
                    delete currNode;
                    prevNode->right = nullptr;
                    if (root == NULL)return 1;
                    else return 0;
                }
                else if (stricmp(currNode->word, _word) == 0 && currNode->left == NULL && currNode->right != NULL) {
                    prevNode->right = currNode->right;
                    delete currNode;
                    currNode = nullptr;
                    if (root == NULL)return 1;
                    else return 0;
                }
                else if (stricmp(currNode->word, _word) == 0 && currNode->left != NULL && currNode->right == NULL) {
                    prevNode->right = currNode->left;
                    delete currNode;
                    currNode = nullptr;
                    if (root == NULL)return 1;
                    else return 0;
                }
                else if (stricmp(currNode->word, _word) == 0 && currNode->left != NULL && currNode->right != NULL) {
                    head = currNode;
                    currNode = currNode->left;
                    while (currNode)
                    {
                        pprevNode = prevNode;
                        prevNode = currNode;
                        currNode = currNode->right;
                    }
                    head->word = prevNode->word;
                    currNode = head;
                    if (prevNode->left != NULL) {
                        pprevNode->right = prevNode->left;
                    }
                    delete prevNode;
                    prevNode = nullptr;
                    if (root == NULL)return 1;
                    else return 0;
                }
            }
            else if (stricmp(currNode->word, _word) == 0) { //처음부터 같아
                prevNode = currNode;
                currNode = currNode->left;
                while (currNode)
                {
                    pprevNode = prevNode;
                    prevNode = currNode;
                    currNode = currNode->right;
                }
                root->word = prevNode->word;
                if (prevNode->left != NULL) {
                    pprevNode->right = prevNode->left;
                }
                delete prevNode;
                root = nullptr;
                if (root == NULL)return 1;
                else return 0;
            }
        }
    }
    bool find(Node* node, char* _word) {
        Node* currNode = node->center;
        while (1) {
            if (currNode == NULL) return false;
            if (stricmp(currNode->word, _word) > 0 && currNode->left != NULL) { //들어온 이름이 더 앞에 있음
                currNode = currNode->left;
            }
            else if (stricmp(currNode->word, _word) < 0 && currNode->right != NULL) {
                currNode = currNode->right;
            }
            else if (stricmp(currNode->word, _word) == 0) {
                return true;
            }
            else return false;
        }
    }
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout <<  node->word << " ";
        inorder(node->right);
    }
    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->word << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->word << " ";
    }
    int print_count(Node* node) {
        int count = 0;
        if (node != nullptr) {
            count = print_count(node->left) + print_count(node->right) + 1;
        }
        return count;
    }
};
class List
{
public:
    Node* head;
    Node* top;
    BST bst;
    int cnt = 1;
    List() {
        head = NULL;
        top = NULL;
    }
    void cubeinsert() {
        int i = 0;
        Node* currNode;
        Node* colNode = head;
        for (int j = 0; j < 3; j++) { // z
            for (int k = 0; k < 3; k++) { // x
                currNode = colNode;
                if (colNode == NULL) {
                    Node* newNode = new Node;
                    newNode->x = k;
                    newNode->y = i;
                    newNode->z = j;
                    if (newNode->z == 0) {
                        head = newNode;
                        top = head;
                        currNode = head;
                    }
                    colNode = newNode;
                    if (newNode->z == 1) {
                        head->down = newNode;
                        newNode->up = head;
                    }
                    if (newNode->z == 2) {
                        head->down->down = newNode;
                        newNode->up = head->down;
                    }
                }
                else {
                    while (currNode) {
                        if (currNode->right == NULL) {
                            Node* newNode = new Node;
                            newNode->x = k;
                            newNode->y = i;
                            newNode->z = j;
                            currNode->right = newNode;
                            newNode->left = currNode;
                            currNode = currNode->right;
                            break;
                        }
                        else currNode = currNode->right;
                    }
                }
            }
            currNode = head;
            while (currNode) {
                if (currNode->down != NULL) {
                    currNode = currNode->down;
                }
                else {
                    colNode = currNode->down;
                    currNode = currNode->down;
                }
            }
        }
        currNode = top;
        cnt = 1;
        while (cnt != 5) {
            if (cnt < 3)  currNode = currNode->right;
            else if (cnt == 3) currNode = currNode->down->left;
            else currNode = currNode->right;
            currNode->down = currNode->left->down->right;
            currNode->left->down->right->up = currNode;
            cnt++;
        }
        i = 1;
        currNode = head;
        for (int j = 0; j < 3; j++) { // z
            for (int k = 0; k < 3; k++) { // x
                currNode = colNode;
                if (colNode == NULL) {
                    Node* newNode = new Node;
                    newNode->x = k;
                    newNode->y = i;
                    newNode->z = j;
                    if (newNode->z == 0) {
                        top = head;
                        head = newNode;
                    }
                    colNode = newNode;
                    if (newNode->z == 1) {
                        head->down = newNode;
                        newNode->up = head;
                    }
                    if (newNode->z == 2) {
                        head->down->down = newNode;
                        newNode->up = head->down;
                    }
                }
                else {
                    while (currNode) {
                        if (currNode->right == NULL) {
                            Node* newNode = new Node;
                            newNode->x = k;
                            newNode->y = i;
                            newNode->z = j;
                            currNode->right = newNode;
                            newNode->left = currNode;
                            currNode = currNode->right;
                            break;
                        }
                        else currNode = currNode->right;
                    }
                }
            }
            currNode = head;
            while (currNode) {
                if (currNode->down != NULL) {
                    currNode = currNode->down;
                }
                else {
                    colNode = currNode->down;
                    currNode = currNode->down;
                }
            }
        }
        currNode = head;
        cnt = 1;
        while (cnt != 5) {
            if (cnt < 3)  currNode = currNode->right;
            else if (cnt == 3) currNode = currNode->down->left;
            else currNode = currNode->right;
            currNode->down = currNode->left->down->right;
            currNode->left->down->right->up = currNode;
            cnt++;
        }
        currNode = top;
        top->back = head;
        head->front = top;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                currNode = currNode->right;
                if (j == 0) {
                    currNode->back = currNode->left->back->right;
                    head->right->front = currNode;
                }
                else {
                    currNode->back = currNode->left->left->back->right->right;
                    head->right->right->front = currNode;
                }
            }
            if (i == 0) {
                currNode = top->down;
                top->down->back = head->down;
                head->down->front = top->down;
            }
            else if (i == 1) {
                currNode = top->down->down;
                top->down->down->back = head->down->down;
                head->down->down->front = top->down->down;
            }
            else continue;
        }
        i = 2;
        for (int j = 0; j < 3; j++) { // z
            for (int k = 0; k < 3; k++) { // x
                currNode = colNode;
                if (colNode == NULL) {
                    Node* newNode = new Node;
                    newNode->x = k;
                    newNode->y = i;
                    newNode->z = j;
                    if (newNode->z == 0) {
                        head = newNode;
                    }
                    colNode = newNode;
                    if (newNode->z == 1) {
                        head->down = newNode;
                        newNode->up = head;
                    }
                    if (newNode->z == 2) {
                        head->down->down = newNode;
                        newNode->up = head->down;
                    }
                }
                else {
                    while (currNode) {
                        if (currNode->right == NULL) {
                            Node* newNode = new Node;
                            newNode->x = k;
                            newNode->y = i;
                            newNode->z = j;
                            currNode->right = newNode;
                            newNode->left = currNode;
                            currNode = currNode->right;
                            break;
                        }
                        else currNode = currNode->right;
                    }
                }
            }
            currNode = head;
            while (currNode) {
                if (currNode->down != NULL) {
                    currNode = currNode->down;
                }
                else {
                    colNode = currNode->down;
                    currNode = currNode->down;
                }
            }
        }
        currNode = head;
        cnt = 1;
        while (cnt != 5) {
            if (cnt < 3)  currNode = currNode->right;
            else if (cnt == 3) currNode = currNode->down->left;
            else currNode = currNode->right;
            currNode->down = currNode->left->down->right;
            currNode->left->down->right->up = currNode;
            cnt++;
        }
        currNode = top->back;
        top->back->back = head;
        head->front = top->back;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                currNode = currNode->right;
                if (j == 0) {
                    currNode->back = currNode->left->back->right;
                    head->right->front = currNode;
                }
                else {
                    currNode->back = currNode->left->left->back->right->right;
                    head->right->right->front = currNode;
                }
            }
            if (i == 0) {
                currNode = top->back->down;
                top->back->down->back = head->down;
                head->down->front = top->back->down;
            }
            else if (i == 1) {
                currNode = top->back->down->down;
                top->back->down->down->back = head->down->down;
                head->down->down->front = top->back->down->down;
            }
            else continue;
        }
    }
    void wordinsert(int _z, int _y, int _x, char* _word) {
        Node* wordNode = new Node;
        strcpy(wordNode->word, _word);
        Node* currNode = top;
        Node* prevNode = top;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) { // z
                for (int k = 0; k < 3; k++) { // x
                    if (currNode->x == _x && currNode->y == _y && currNode->z == _z) {
                        if (currNode->center == NULL) {
                            currNode->center = wordNode;
                            break;
                        }
                        else {
                            currNode = currNode->center;
                            while (currNode) {
                                if (stricmp(currNode->word, _word) > 0 && currNode->left == NULL) { // 새로 들어온 문자가 더 앞에
                                    currNode->left = wordNode;
                                    break;
                                }
                                else if (stricmp(currNode->word, _word) > 0 && currNode->left != NULL) {
                                    currNode = currNode->left;
                                }
                                else if (stricmp(currNode->word, _word) < 0 && currNode->right == NULL) { //새로 들어온 문자가 뒤에
                                    currNode->right = wordNode;
                                    break;
                                }
                                else if (stricmp(currNode->word, _word) < 0 && currNode->right != NULL) {
                                    currNode = currNode->right;
                                }
                                else break;
                            }
                        }
                        currNode = top;
                        break;
                    }
                    else {
                        if (k < 2) currNode = currNode->right;
                        else continue;
                    }
                }
                if (j == 0) currNode = prevNode->down;
                else if (j == 1) currNode = prevNode->down->down;
                else continue;
            }
            if (i == 0) {
                currNode = top->back;
                prevNode = currNode;
            }
            else if (i == 1) {
                currNode = top->back->back;
                prevNode = currNode;
            }
            else continue;
        } 
    }
    void _delete(int _z, int _y, int _x, char* _word) {
        Node* currNode = top;
        Node* prevNode = top;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (currNode->x == _x && currNode->y == _y && currNode->z == _z) {
                        bst._delete(currNode->center, _word);
                        currNode = top;
                        break;
                    }
                    else {
                        if (k < 2) currNode = currNode->right;
                        else continue;
                    }
                }
                if (j == 0) currNode = prevNode->down;
                else if (j == 1) currNode = prevNode->down->down;
                else continue;
            }
            if (i == 0) {
                currNode = top->back;
                prevNode = currNode;
            }
            else if (i == 1) {
                currNode = top->back->back;
                prevNode = currNode;
            }
            else continue;
        }
    }
    void find(char* _word) {
        Node* currNode = top;
        Node* prevNode = top;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (bst.find(currNode, _word) == true) {
                        cout << currNode->z << currNode->y << currNode->x << endl;
                        currNode = currNode->right;
                    }
                    else {
                        if (k < 2) currNode = currNode->right;
                        else continue;
                    }
                }
                if (j == 0) currNode = prevNode->down;
                else if (j == 1) currNode = prevNode->down->down;
                else continue;
            }
            if (i == 0) {
                currNode = top->back;
                prevNode = currNode;
            }
            else if (i == 1) {
                currNode = top->back->back;
                prevNode = currNode;
            }
            else continue;
        }
    }
    void print(int _z, int _y, int _x) {
        Node* currNode = top;
        Node* prevNode = top;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (currNode->x == _x && currNode->y == _y && currNode->z == _z) {
                        cout << "Preorder : ";
                        bst.preorder(currNode->center);
                        cout << endl;
                        cout << "Postorder : ";
                        bst.postorder(currNode->center);
                        cout << endl;
                        cout << "Inorder : ";
                        bst.inorder(currNode->center);
                        cout << endl;
                        break;
                    }
                    else {
                        if (k < 2) currNode = currNode->right;
                        else continue;
                    }
                }
                if (j == 0) currNode = prevNode->down;
                else if (j == 1) currNode = prevNode->down->down;
                else continue;
            }
            if (i == 0) {
                currNode = top->back;
                prevNode = currNode;
            }
            else if (i == 1) {
                currNode = top->back->back;
                prevNode = currNode;
            }
            else continue;
        }
    }
    void print_all() {
        Node* currNode = top;
        Node* prevNode = top;
        int count = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cout << bst.print_count(currNode->center) << "\t";
                    if (k < 2) currNode = currNode->right;
                    else continue;
                }
                if (j == 0) {
                    currNode = prevNode->down;
                    cout << endl;
                }
                else if (j == 1) {
                    currNode = prevNode->down->down;
                    cout << endl;
                }
                else continue;
            }
            if (i == 0) {
                currNode = top->back;
                prevNode = currNode;
                cout << endl << endl;
            }
            else if (i == 1) {
                currNode = top->back->back;
                prevNode = currNode;
                cout << endl << endl;
            }
            else continue;
        }
        cout << endl;
    }
};

int main()
{
	int num = 0, count = 0, x = 0, y = 0, z = 0;
    char temp;
    char word[20] = { '0' };
    List li;

    ifstream file1("WordBook.txt");
    while (!file1.eof()) {
        file1.get(temp);
        if (temp == '\n')
            count++;
    }
    count++;
    count = count * 4;
    file1.close();
    char** str = new char* [count];
    for (int i = 0; i < count; i++) {
        str[i] = new char[100];
    }
    ifstream file1_1("WordBook.txt");
    if (!file1_1) {
        cout << "Unable to open" << endl;
    }
    for (int i = 0; i < count; i++) {
        file1_1 >> str[i];
    }
    file1_1.close();
    /*for (int i = 0; i < count; i++) {
        cout << str[i] << endl;
    }*/
    li.cubeinsert();
    for (int i = 0; i < count; i += 4) {
        li.wordinsert(atoi(str[i]), atoi(str[i + 1]), atoi(str[i + 2]), str[i + 3]);
    }
    while (num != 8) {
        cout << "Enter Any Command(1: Insert, 2: Delete, 3: Find, 4: Print, 5: Print_All, 6: Trun, 7: Exchange, 8: Exit) : ";
        cin >> num;
        switch (num) {
        case 1:
            cin >> z >> y >> x >> word;
            li.wordinsert(z, y, x, word);
            break;
        case 2:
            cin >> z >> y >> x >> word;
            li._delete(z, y, x, word);
            break;
        case 3:
            cin >> word;
            li.find(word);
            break;
        case 4:
            cin >> z >> y >> x;
            li.print(z, y, x);
            break;
        case 5:
            li.print_all();
            break;
        case 6:
            break;
        }
    }
}
#include <iostream>
using namespace std;

class ����
{
private:
    char U_name[20];
    int year;
    char U_StuID[20];
public:
    ����() {}
    ����(char* _U_name, int _year, char* _U_StuID) {
        strcpy(U_name, _U_name);
        year = _year;
        strcpy(U_StuID, _U_StuID);
    }
    char* univ() {
        return U_name;
    }
    int grade() {
        return year;
    }
    char* id() {
        return U_StuID;
    }
    bool find2(char* _U_StuID) {
        if (strcmp(U_StuID, _U_StuID) == 0)
            return true;
        else
            return false;
    }
};
class ��ǻ���������� : public ����
{
private:
    char Object_Oriented_Programing;
    char Digital_Logic_Circuit;
public:
    ��ǻ����������() {   }
    ��ǻ����������(char* _U_name, int _year, char* _U_StuID, char _Object_Oriented_Programing, char _Digital_Logic_Circuit) : ����(_U_name, _year, _U_StuID) {
        Object_Oriented_Programing = _Object_Oriented_Programing;
        Digital_Logic_Circuit = _Digital_Logic_Circuit;
    }
    char oop() {
        return Object_Oriented_Programing;
    }
    char dlc() {
        return Digital_Logic_Circuit;
    }
};
class �л����� : public ��ǻ����������
{
private:
    char Name[10];
    int age;
public:
    �л�����() {}
    �л�����(char* _U_name, int _year, char* _U_StuID, char _Object_Oriented_Programing, char _Digital_Logic_Circuit, char* _Name, int _age) : ��ǻ����������(_U_name, _year, _U_StuID, _Object_Oriented_Programing, _Digital_Logic_Circuit) {
        strcpy(Name, _Name);
        age = _age;
    }
    char* name() {
        return Name;
    }
    int _age() {
        return age;
    }
    bool find1(char* _Name) {
        if (strcmp(Name, _Name) == 0)
            return true;
        else
            return false;
    }
};

int main()
{
    int count = 0, grade = 0, age = 0;
    char school[50] = { "\n" };
    char oop('A');
    char dlc('A');
    char name[20] = { "\n" };
    char id[15] = { "\n" };

    string input;
    �л�����** list = new �л����� * [100];

    while (input != "EXIT")
    {
        cin >> input;

        if (input == "INSERT") {
            cout << "�б� :";
            cin >> school;
            cout << "�й� :";
            cin >> id;
            cout << "�г� :";
            cin >> grade;
            cout << "��ü�������α׷��� ���� :";
            cin >> oop;
            cout << "�����г�ȸ�� ���� :";
            cin >> dlc;
            cout << "�̸� :";
            cin >> name;
            cout << "���� :";
            cin >> age;
            if (count < 100) {
                list[count] = new �л�����(school, grade, id, oop, dlc, name, age);
                count++;
            }
        }
        else if (input == "FIND") {
            cin >> name >> id;
            for (int i = 0; i < count; i++) {
                if (list[i]->find1(name) == true && list[i]->find2(id) == true) {
                    cout << endl << "�б�:" << list[i]->univ() << endl << "�й�:" << list[i]->id() << endl << "�г�:" << list[i]->grade() << endl;
                    cout << "��ü�������α׷��� ����:" << list[i]->oop() << endl << "�����г�ȸ�� ����:" << list[i]->dlc() << endl;
                }

            }
        }
    }
    for (int i = 0; i < count; i++) {
        delete list[i];
    }
    return 0;
}
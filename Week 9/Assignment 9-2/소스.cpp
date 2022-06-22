#include <iostream>
using namespace std;

class 대학
{
private:
    char U_name[20];
    int year;
    char U_StuID[20];
public:
    대학() {}
    대학(char* _U_name, int _year, char* _U_StuID) {
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
class 컴퓨터정보공학 : public 대학
{
private:
    char Object_Oriented_Programing;
    char Digital_Logic_Circuit;
public:
    컴퓨터정보공학() {   }
    컴퓨터정보공학(char* _U_name, int _year, char* _U_StuID, char _Object_Oriented_Programing, char _Digital_Logic_Circuit) : 대학(_U_name, _year, _U_StuID) {
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
class 학생정보 : public 컴퓨터정보공학
{
private:
    char Name[10];
    int age;
public:
    학생정보() {}
    학생정보(char* _U_name, int _year, char* _U_StuID, char _Object_Oriented_Programing, char _Digital_Logic_Circuit, char* _Name, int _age) : 컴퓨터정보공학(_U_name, _year, _U_StuID, _Object_Oriented_Programing, _Digital_Logic_Circuit) {
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
    학생정보** list = new 학생정보 * [100];

    while (input != "EXIT")
    {
        cin >> input;

        if (input == "INSERT") {
            cout << "학교 :";
            cin >> school;
            cout << "학번 :";
            cin >> id;
            cout << "학년 :";
            cin >> grade;
            cout << "객체지향프로그래밍 학점 :";
            cin >> oop;
            cout << "디지털논리회로 학점 :";
            cin >> dlc;
            cout << "이름 :";
            cin >> name;
            cout << "나이 :";
            cin >> age;
            if (count < 100) {
                list[count] = new 학생정보(school, grade, id, oop, dlc, name, age);
                count++;
            }
        }
        else if (input == "FIND") {
            cin >> name >> id;
            for (int i = 0; i < count; i++) {
                if (list[i]->find1(name) == true && list[i]->find2(id) == true) {
                    cout << endl << "학교:" << list[i]->univ() << endl << "학번:" << list[i]->id() << endl << "학년:" << list[i]->grade() << endl;
                    cout << "객체지향프로그래밍 학점:" << list[i]->oop() << endl << "디지털논리회로 학점:" << list[i]->dlc() << endl;
                }

            }
        }
    }
    for (int i = 0; i < count; i++) {
        delete list[i];
    }
    return 0;
}
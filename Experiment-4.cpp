#include <iostream>
using namespace std;
class Person
{
public:
    string name;
    void getPerson()
    {
        cout << "Enter name: ";
        cin >> name;
    }
    void displayPerson()
    {
        cout << "Name: " << name << endl;
    }
};
class Student: public Person
{
public:
    int rollNo;
    void getStudent()
    {
        cout << "Enter Roll number: ";
        cin >> rollNo;
    }
    void displayStudent()
    {
        displayPerson();
        cout << "Roll Number: " << rollNo << endl;
    }
};
class GraduateStudent: public Student
{
public:
    string course;
    void getGraduate()
    {
        cout << "Enter course: ";
        cin >> course;
    }
    void displayGraduate()
    {
        displayStudent();
        cout << "Course: " << course << endl;
    }
};
int main()
{
    GraduateStudent g;
    g.getPerson();
    g.getStudent();
    g.getGraduate();
    cout << "\nStudent Details:\n";
    g.displayGraduate();
    return 0;
}

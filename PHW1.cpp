#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Student
{
    string name;
    int studentID;
    int units;
    float gpa;
    string securityCode;
    Student *next;
};

void addstudent(Student *&head, const string &name, int studentID, int units, float gpa, const string &securityCode)
{
    Student *newStudent = new Student;
    newStudent->name = name;
    newStudent->studentID = studentID;
    newStudent->units = units;
    newStudent->gpa = gpa;
    newStudent->securityCode = securityCode;
    newStudent->next = nullptr;

    if (head == nullptr)
    {
        head = newStudent;
    }
    else
    {
        Student *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newStudent;
    }

    cout << "New student added successfully." << endl;
};
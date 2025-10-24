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

bool deleteStudent(Student *&head, int studentID)
{
    if (head == nullptr)
    {
        cout << "The student list is empty." << endl;
        return false;
    }

    if (head->studentID == studentID)
    {
        Student *temp = head;
        head = head->next;
        delete temp;
        cout << "The student was successfully deleted." << endl;
        return true;
    }

    Student *prev = head;
    Student *curr = head->next;

    while (curr != nullptr)
    {
        if (curr->studentID == studentID)
        {
            prev->next = curr->next;
            delete curr;
            cout << "The student was successfully deleted." << endl;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Student with student number not found." << endl;
    return false;
};

Student *searchStudent(Student *head, int studentID)
{
    Student *temp = head;
    while (temp != nullptr)
    {
        if (temp->studentID == studentID)
            return temp;
        temp = temp->next;
    }
    return nullptr;
};


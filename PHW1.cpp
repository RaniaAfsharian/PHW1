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

bool updateStudent(Student *head, int studentID, int newUnits, float newGPA)
{
    Student *student = searchStudent(head, studentID);
    if (student == nullptr)
    {
        cout << "Student with student number not found." << endl;
        return false;
    }

    student->units = newUnits;
    student->gpa = newGPA;
    cout << "Student information with student number successfully updated." << endl;

    cout << "Security codes updated." << endl;

    return true;
};

void displayAllRecords(Student *head)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Student *temp = head;
    while (temp != nullptr)
    {
        cout << "Name: " << temp->name
             << ", StudentID: " << temp->studentID
             << ", units: " << temp->units
             << ",  gpa: " << temp->gpa
             << ", securityCode: " << temp->securityCode
             << "***************************************"
             << endl;
        temp = temp->next;
    }
};

void displayMenu()
{
    cout << "    Welcom" << endl;
    cout << "    menu" << endl;
    cout << "1. add student" << endl;
    cout << "2. delete student" << endl;
    cout << "3. search student" << endl;
    cout << "4. update student" << endl;
    cout << "5. displayAllRecords" << endl;
    cout << "0. exit" << endl;
}


int main()
{
    Student *studentList = nullptr;
    int n;

    do
    {
        displayMenu();
        cout << "Enter your choice: ";

        if (!(cin >> n))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            n = -1; 
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (n)
        {
        case 1:
        {
            string Sname;
            int SstudentID;
            int Sunits;
            float Sgpa;
            string SsecurityCode;

            cout << "Enter a name:";
            cin >> Sname;
            cout << "Enter studentID:";
            cin >> SstudentID;
            cout << "Enter units:";
            cin >> Sunits;
            cout << "Enter gpa:";
            cin >> Sgpa;
            cout << "Enter securityCode (4 digits):";
            cin >> SsecurityCode; 

            addstudent(studentList, Sname, SstudentID, Sunits, Sgpa, SsecurityCode);
            
            break;
        }

        case 2:
        {
            int SstudentID;

            cout << "Enter StudentID to delete: ";
            cin >> SstudentID;

            deleteStudent(studentList, SstudentID);

            break;
        }

        case 3:
        {
            int SstudentID;

            cout << "Enter StudentID to search: ";
            cin >> SstudentID;

            Student *result = searchStudent(studentList, SstudentID);

            if (result != nullptr)
            {
                cout << "Name: " << result->name
                     << ", StudentID: " << result->studentID
                     << ", units: " << result->units
                     << ",  gpa: " << result->gpa
                     << ", securityCode: " << result->securityCode
                     << endl;
            }
            else
            {
                cout << "Student with student number not found." << endl;
            }

            break;
        }

        case 4:
        {
            int SstudentID;
            int Sunits;
            float Sgpa;

            cout << "Enter studentID to update:";
            cin >> SstudentID;
            cout << "Enter new units:";
            cin >> Sunits;
            cout << "Enter new gpa:";
            cin >> Sgpa;

            updateStudent(studentList, SstudentID, Sunits, Sgpa);

            break;
        }

        case 5:
        {
            displayAllRecords(studentList);

            break;
        }

        case 0:
        {
            break; 
        }

        default:
        {
            cout << "Invalid choice. Please try again or enter 0 to exit." << endl;
            break;
        }
        }

    } while (n != 0); 

    while (studentList != nullptr)
    {
        Student *temp = studentList;
        studentList = studentList->next;
        delete temp; 
    }

    return 0;
}
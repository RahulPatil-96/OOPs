#include<iostream>
#include<string>
using namespace std;

class per_info;

class student
{
private:
    string name, address, year;
    int roll_no;
    static int count;
    long long mobile;
    per_info *obj;

public:
    student()
    {
        count++;
        name = "Rahul";
        address = "Pune";
        year = "SY";
        roll_no = 10;
        mobile = 9322473877;
        obj = nullptr;
    }

    static void incount()
    {
        count++;
    }

    static void showcount()
    {
        cout << "The no. of students: " << count << endl;
    }

    ~student()
    {
        cout << "Student detailed closed..." << endl;
        if (obj != nullptr)
        {
            delete obj;
        }
    }



    student(const student &other);

    void create();
    void display();
};

class per_info
{
private:
    string lic, dob, blood;

public:
    per_info()
    {
        lic = "RAHU2004";
        dob = "15 JAN 2004";
        blood = "B+";
    }

    ~per_info()
    {
        cout << "Personal details closed" << endl;
    }

    friend class student;
};

int student::count = 0;

student::student(const student &other)
{
    this->name = other.name;
    this->address = other.address;
    this->roll_no = other.roll_no;
    this->year = other.year;
    this->mobile = other.mobile;
    this->obj = new per_info(*(other.obj));
}

void student::create()
{
    obj = new per_info();
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter address: ";
    cin >> address;
    cout << "Enter Roll no.: ";
    cin >> roll_no;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter mobile: ";
    cin >> mobile;

    cout << "Enter Lic no.: ";
    cin >> obj->lic;
    cout << "Enter date of birth: ";
    cin >> obj->dob;
    cout << "Enter blood group: ";
    cin >> obj->blood;
}

void student::display()
{
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Roll no.: " << roll_no << endl;
    cout << "Year: " << year << endl;
    cout << "Mobile: " << mobile << endl;
    cout << "Lic no.: " << obj->lic << endl;
    cout << "Date of birth: " << obj->dob << endl;
    cout << "Blood group: " << obj->blood << endl;
}

int main()
{
    int n, ch;
    char ans;
    cout << "Enter no. of students: ";
    cin >> n;
    student *sobj = new student[n];

    cout << "\nMENU\n1.Create database\n2.Display database\n3.Copy constructor\n4.Default constructor\n5.Delete\n";
    do
    {
        cin >> ch;

        switch (ch)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                sobj[i].create();
                student::incount();
            }
            break;

        case 2:
            student::showcount();
            for (int i = 0; i < n; i++)
            {
                sobj[i].display();
            }
            break;

        case 3:
            {
                student obj1;
                obj1.create();
                student obj3(obj1);
                cout << "\nCopy constructor is called\n";
                obj3.display();
            }
            break;

        case 4:
            {
                student obj1;
                cout << "\nDefault constructor is called\n";
                obj1.display();
            }
            break;

        case 5:
            delete[] sobj;
            break;
        }
        cout << "\nWant to continue (y/n): ";
        cin >> ans;
    } while (ans == 'y');

    return 0;
}

#include <iostream>
using namespace std;

class Student
{
protected:
    int roll_number;

public:
    Student(int r)
    {
        roll_number = r;
    }
};

class test : public Student
{
protected:
    int marks[2];

public:
    test(int r, int m1, int m2) : Student(r)
    {
        marks[0] = m1;
        marks[1] = m2;
    }
};

class sports : public Student
{
protected:
    int score;

public:
    sports(int r, int s) : Student(r)
    {
        score = s;
    }
};

class result : public test, public sports
{
private:
    int total;

public:
    result(int r, int m1, int m2, int s) : test(r, m1, m2), sports(r, s)
    {
        total = marks[0] + marks[1] + score;
    }

    void display()
    {
        cout << "Roll number: " << test::roll_number << endl;
        cout << "Marks of two subjects: " << marks[0] << " and " << marks[1] << endl;
        cout << "Score in sports: " << score << endl;
        cout << "Total score: " << total << endl;
    }
};

int main()
{
    result r(101, 80, 90, 50);
    r.display();
    return 0;
}
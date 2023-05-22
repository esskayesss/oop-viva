#include <iostream>

using namespace std;

class Shape
{
protected:
    float dim1, dim2;

public:
    void get_data(float dim1, float dim2)
    {
        this->dim1 = dim1;
        this->dim2 = dim2;
    }
    virtual float area() = 0;
};

class Square : public Shape
{
public:
    float area()
    {
        return dim1 * dim2;
    }
};

class Triangle : public Shape
{
public:
    float area()
    {
        return 0.5 * dim1 * dim2;
    }
};

int main()
{
    Shape *s;
    Triangle t;
    Square sq;

    s = &t;
    s->get_data(10, 20);
    cout << "Area of triangle: " << s->area() << endl;

    s = &sq;
    s->get_data(10, 20);
    cout << "Area of square: " << s->area() << endl;
}
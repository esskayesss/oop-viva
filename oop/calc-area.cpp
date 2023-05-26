#include <iostream>

using namespace std;

class CalculateArea{
    public:
        double area(double dim1, double dim2, char shape = 'r'){
            double ar = dim1 * dim2;
            if(shape == 't') ar *= 0.5;

            return ar;
        }

        double area(double side){
            return side * side;
        }

        double area(double s1, double s2, double height){
            return (s1 + s2) / 2 * height;
        }
};

int main(){
    char ch;
    CalculateArea ca;
    for(;;){
        cout << "menu.\n" << "1. area of rectangle\n2. area of triangle\n3. area of square\n4. area of trapezium\npress q to quit\n";
        cout << "enter your choice: ";
        cin >> ch;
        double a, b, c;
        switch(ch){
            case '1':
                cout << "enter the values for length and breadth: ";
                cin >> a >> b;
                cout << ca.area(a, b) << " is the area" << endl;
                break;
            case '2':
                cout << "enter the values for base and height: ";
                cin >> a >> b;
                cout << ca.area(a, b, 't') << " is the area" << endl;
                break;
            case '3':
                cout << "enter the dimension of any side: ";
                cin >> a;
                cout << ca.area(a) << " is the area" << endl;
                break;
            case '4':
                cout << "enter the dimensions of the two sides and the corresponding height: ";
                cin >> a >> b >> c;
                cout << ca.area(a, b, c) << " is the area" << endl;
                break;
            case 'q':
                cout << "thanks for using the program...\bexiting now.\n";
                exit(0);
                break;
            default:
                cout << "invalid choice!\n";
                break;
        }
    }
}

#include <iostream>

using namespace std;


class Swapper{
    public:
        void swap(int &a, int &b){
            int temp = a;
            a = b;
            b = temp;
        }
};

int main(){
    int num1, num2;
    cout << "enter the two numbers: ";
    cin >> num1 >> num2;

    printf("the numbers before swapping are %d and %d.\n", num1, num2);
    Swapper obj;
    obj.swap(num1, num2);
    printf("the numbers before swapping are %d and %d.\n", num1, num2);
}

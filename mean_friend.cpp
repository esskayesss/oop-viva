#include <iostream>

using namespace std;

class Mean{
    private:
        double num1, num2;

    public:
        Mean(double a, double b){
            num1 = a;
            num2 = b;
        }

        friend double mean(Mean);
};

double mean(Mean m){
    return (m.num1 + m.num2)/2;
}


int main(){
    double a, b;
    cout << "enter the two numbers to calculate mean: ";
    cin >> a >> b;

    Mean m(a, b);
    cout << "the mean of the two numbers is " << mean(m) << endl;
}

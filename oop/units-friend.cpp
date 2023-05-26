#include <iostream>

using namespace std;

class DistanceM;

class DistanceF{
    private:
        double feet, inches;

    public:
        DistanceF(double feet, double inches){
            this->feet = feet;
            this->inches = inches;
        }

        friend double add(DistanceF, DistanceM);
};

class DistanceM{
    private:
        double meters, cm;

    public:
        DistanceM(double meters, double cm){
            this->meters = meters;
            this->cm = cm;
        }

        friend double add(DistanceF, DistanceM);
};

double add(DistanceF df, DistanceM dm){
    return (df.feet * 12 + df.inches) * 2.54 + dm.meters * 100 + dm.cm;
}

int main(){
    double a, b;
    cout << "enter the values for feet and inches: ";
    cin >> a >> b;
    DistanceF df(a, b);

    cout << "enter the values for meters and centimeters: ";
    cin >> a >> b;
    DistanceM dm(a, b);

    cout << "the sum of these distances in centimeters is " << add(df, dm);
}

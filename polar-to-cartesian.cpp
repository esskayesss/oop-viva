#include <iostream>
#include <math.h>
#include <utility>

using namespace std;


template<typename T, typename U>
pair<T, U> operator+(pair<T, U> l, pair<T, U> r){
    return {l.first + r.first, l.second + r.second};
}

class Polar {
    private:
        double radius, angle;

    public:
        Polar(double radius, double angle){
            this->radius = radius;
            this->angle = angle;
        }

        Polar(pair<double, double> data){
            this->radius = data.first;
            this->angle = data.second;
        }

        Polar operator+(Polar other){
            pair<double, double> cartesian_sum = to_cartesian() + other.to_cartesian();
            double a = atan(cartesian_sum.second / cartesian_sum.first);
            double r = sqrt(pow(cartesian_sum.first, 2) + pow(cartesian_sum.second, 2));
            return Polar(r, a);
        }

        pair<double, double> 
        to_cartesian(){
            pair<double, double> coords;
            coords.first = radius * cos(angle);
            coords.second = radius * sin(angle);

            return coords;
        }

        friend ostream& operator<<(ostream& stream, const Polar point);
};

ostream&
operator<<(ostream& stream, const Polar point){
    stream << point.radius << "units, " << point.angle << "radians";
    return stream;
}

int main(){
    double radius, angle;
    cout << "enter the polar radius and angle for first point: ";
    cin >> radius >> angle;
    Polar p1(radius, angle);
    cout << "enter the polar radius and angle for second point: ";
    cin >> radius >> angle;
    Polar p2(radius, angle);

    Polar p3 = p1 + p2;
    cout << p1 << " + " << p2 << " = " << p3 << endl;
}

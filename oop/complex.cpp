#include <iostream>

using namespace std;

class Complex {
    private:
        double real, imag;

    public:
        Complex(double real = 0.0, double imag = 0.0){
            this->real = real;
            this->imag = imag;
        }

        Complex operator+(const Complex other){
            return Complex(this->real + other.real, this->imag + other.imag);
        }

        Complex operator-(const Complex other){
            return Complex(this->real - other.real, this->imag - other.imag);
        }

        Complex operator*(const Complex other){
            return Complex(this->real * other.real - this->imag * other.imag, this->real * other.imag + this->imag * other.real);
        }

        Complex operator/(const Complex other){
            return Complex(
                    (this->real * other.real + this->imag * other.imag)/(other.real * other.real + other.imag * other.imag), 
                    (other.real * this->imag - this->real * other.imag)/(other.real * other.real + other.imag * other.imag)
            );
        }

        friend ostream& operator<<(ostream& stream, const Complex& cmp);

        friend istream& operator>>(istream& stream, Complex& cmp);
};

ostream&
operator<< (ostream& stream, const Complex& cmp){
    stream << cmp.real << " + " << cmp.imag << "i";

    return stream;
}

istream&
operator>> (istream& stream, Complex &cmp){
    stream >> cmp.real >> cmp.imag;
    return stream;
}

int main(){
    printf("enter the real and imaginary values of the first complex number: ");
    Complex c1, c2;
    cin >> c1;
    printf("enter the real and imaginary values of the first complex number: ");
    cin >> c2;

    cout << "addition: " << c1 + c2 << endl;
    cout << "subtraction: " << c1 - c2 << endl;
    cout << "multiplication: " << c1 * c2 << endl;
    cout << "division: " << c1 / c2 << endl;
}

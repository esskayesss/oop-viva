#include <iostream>

using namespace std;

class Number{
    private:
        int val;

    public:
        int get(){
            return val;
        }

        void set(int val){
            this->val = val;
        }

        Number operator + (Number& num2){
            Number res;
            res.set(this->val + num2.get());
            return res;
        }

        Number(int val = 0){
            this->val = val;
        }
};

int main(int argc, char **argv){
    if(argc <= 1){
        cout << "no number passed in command-line args.\n";
        exit(1);
    }

    Number res;
    for(int i = 1; i < argc; i++){
        Number addend (atoi(*(argv + i)));
        res = res + addend;
    }

    cout << res.get() << endl;
}

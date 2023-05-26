#include <iostream>

using namespace std;

class PvtEg {
    private:
        int data;

        void foo(){
            printf("this is the private function, foo! data = %d\n", data);
        }

    public:
        PvtEg(int data){
            this->data = data;
        }

        void bar(){
            printf("this is the public function, bar!\nit will now access the private function, foo and also the private data member, data.\n");
            foo();
            printf("data = %d\n", data);
        }
};

int main(){
    int data;
    printf("enter the value for data: ");
    cin >> data;

    PvtEg obj(data);
    obj.bar();
}

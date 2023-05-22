#include <iostream>

using namespace std;

class Blueprint{
    private:
        static int instances;

    public:
        Blueprint(){
            cout << "instance #" << instances++ << " created.\n";
        }

        int get_instance_count(){
            return instances;
        }
};
int Blueprint::instances = 0;

int main(){
    Blueprint *inst = NULL;
    for(int i = 0; i < 10; i++){
        if(inst) free(inst);
        inst = new Blueprint();
    }

    cout << "the number of instances created from class Blueprint is: " << inst->get_instance_count() << endl;
}

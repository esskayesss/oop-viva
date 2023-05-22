#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv){
    argv++; argc--;

    int *count = (int*)malloc(sizeof(int) * 5);
    int spoilt_count = 0;
    
    int candidate;
    while(argc){
        candidate = atoi(*(argv + argc - 1));
        if(candidate <= 5 && candidate >= 1)
            *(count + candidate - 1) += 1;
        else 
            spoilt_count++;
        argc--;
    }

    cout << "spoilt votes: " << spoilt_count << "\n";

    for(int i = 0; i < 5; i++)
        cout << "candidate " << i + 1 << " has got " << *(count + i) << " votes\n";
}

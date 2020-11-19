#include <math.h>
#include <string>
#include <time.h>
#include <iostream>
int main(){
    srand(time(NULL));
    int vinto = 0;
    int tutti = 0;
    float min = 0.01;
    for(int i = 0; i < 1000; i++){
        //std::cout<<rand()<<std::endl;
        vinto += (rand() % 100 < 1 ? 1:0);
        tutti++;
    }

    std::cout<<vinto<<" "<<tutti;
    return 0;
}
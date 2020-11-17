#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using peoples = vector<int>;
bool to_serve(vector<vector<int>>& queues, vector<int>& seats);
bool want_to_exit(const peoples& seats, int current_floor);
void make_them_exit(peoples& seats, int current_floor);
bool some_can_enter(peoples& current, int current_floor, int direction);
void make_them_enter(peoples& seats, peoples& current, int current_floor, int direction);
/*
Input:
    - queues a list of queues of people for all floors of the building.
        - The height of the building varies
        - 0 = the ground floor
        - Not all floors have queues
        - Queue index [0] is the "head" of the queue
        - Numbers indicate which floor the person wants go to

    - capacity maximum number of people allowed in the lift

Return:
    - A list of all floors that the Lift stopped at (in the order visited!)
*/

const int UP = 1, DOWN = -1;
std::vector<int> the_lift(std::vector<peoples> queues, int capacity) {
    //Return
    vector<int> stopped_at{};
    //Fundamentals
    int floors          = queues.size();
    int direction       = UP;
    int current_floor   = 0;
    peoples seats       {};

    //If i have someone to serve il will iter
    while(to_serve(queues, seats)){
        peoples& current = queues[current_floor];
        if(!current.empty()){
            //Someone in the current floor
            //Exiting
            if(!seats.empty()){
                //Someone on the lift
                if(want_to_exit(seats, current_floor)){
                    //Someone wants to exit
                    make_them_exit(seats, current_floor);
                    stopped_at.push_back(current_floor);
                }else{
                    //Noone want to exit
                    continue;
                }
            }else{
                //Noone on the lift
                continue;
            }
            //Entering
            if(seats.size() < capacity){
                //I can transport someone
                if(some_can_enter(current, current_floor, direction)){
                    //Make him enter
                    make_them_enter(seats, current, current_floor, direction);
                    stopped_at.push_back(current_floor);
                }else{
                    //Cannot enter
                    continue;
                }
            }else{
                //No room for people must skip
                continue;
            }
        }else{
            //Noone in current floor
            continue;
        }
    }

    return stopped_at;
}



bool to_serve(vector<vector<int>>& queues, vector<int>& seats){
    if(!seats.empty()) return true;

    for(auto q : queues)
        if(!q.empty()) 
            return true;

    return false;
}

bool want_to_exit(const peoples& seats, int current_floor){
    for(auto i : seats)
        if(i == current_floor) 
            return true;

    return false;
}

void make_them_exit(peoples& seats, int current_floor){

}

bool some_can_enter(peoples& current, int current_floor, int direction){

}

void make_them_enter(peoples& seats, peoples& current, int current_floor, int direction){

}
int main(){
    return 0;
}
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
bool some_can_enter(peoples& current, int current_floor, 
                    int direction, int capacity,
                    peoples& seats);
void make_them_enter(peoples& seats, peoples& current,
                    int current_floor, int direction, 
                    int capacity);
void exit_peoples(peoples& seats,const int current_floor, 
                    vector<int>& stopped_at);
void entering_peoples(peoples& seats, peoples& current, const int current_floor,
                    const int capacity,const int direction,vector<int>& stopped_at);
void move_or_change_direction(peoples& seats, int& current_floor, 
                    int& direction,
                    const int floors,
                    const vector<vector<int>>& queues);
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
std::vector<int> the_lift(std::vector<peoples> queues,const int capacity) {
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
            exit_peoples(seats, current_floor, stopped_at);
            //Entering
            entering_peoples(seats, current, current_floor, 
                            capacity, direction, stopped_at);
        }else{
            //Noone in current floor
            //Exiting
            exit_peoples(seats, current_floor, stopped_at);
        }

        //Now we need to move
        cout<<"Going to move from: "<<current_floor<<" direction: "<<direction<<endl;
        move_or_change_direction(seats, current_floor, 
                                direction,
                                floors,
                                queues);
        cout<<"Moved to: "<<current_floor<<" direction: "<<direction<<endl;
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
    //Removing
    std::remove_if(
        seats.begin(), 
        seats.end(), 
        [current_floor](int person){
            return person == current_floor;
        }
    );
}

bool some_can_enter(peoples& current, int current_floor,
                    int direction, int capacity,
                    peoples& seats)
{
    if(capacity - seats.size() == 0) return false;

    if(direction == UP){
        for(auto people : current)
            if(people > current_floor) 
                return true;
    }else if(direction == DOWN){
        for(auto people : current)
            if(people < current_floor) 
                return true;
    }

    return false;
}

void make_them_enter(peoples& seats, peoples& current, 
                    int current_floor, int direction, 
                    int capacity)
{
    peoples entered{};
    if(direction == UP){
        for(auto people : current){
            if(people > current_floor && capacity - seats.size() > 0){
                seats.push_back(people);
                entered.push_back(people);
            }
        }
    }else if(direction == DOWN){
        for(auto people : current){
            if(people < current_floor && capacity - seats.size() > 0){
                seats.push_back(people);
                entered.push_back(people);
            }
        }
    }

    //Delete people from flor
    for(auto people : entered){
        bool deleted = false;
        std::remove_if(
            current.begin(), 
            current.end(), 
            [&deleted, &people](int to_del){
                if(!deleted && to_del == people){
                    deleted = true;
                    return true;
                }
                return false;
            }
        );
    }

}

void exit_peoples(peoples& seats,const int current_floor, 
                    vector<int>& stopped_at){
    if(!seats.empty()){
        //Someone on the lift
        if(want_to_exit(seats, current_floor)){
            //Someone wants to exit
            make_them_exit(seats, current_floor);
            stopped_at.push_back(current_floor);
        }else{
            //Noone want to exit
        }
    }else{
        //Noone on the lift
    }
}

void entering_peoples(peoples& seats, peoples& current, 
                    const int current_floor, const int capacity, 
                    const int direction, vector<int>& stopped_at)
{
    if(seats.size() < capacity){
        //I can transport someone
        if(some_can_enter(current, current_floor, direction, capacity, seats)){
            //Make him enter
            make_them_enter(seats, current, current_floor, direction, capacity);
            stopped_at.push_back(current_floor);
        }else{
            //Cannot enter 
        }
    }else{
        //No room for people must skip
    }
}

void move_or_change_direction(peoples& seats, int& current_floor, 
                    int& direction,
                    const int floors,
                    const vector<vector<int>>& queues)
{
    if(direction == UP){
        //Now im going up
        if(current_floor == floors-1){
            //Im in the top
            current_floor--;
            direction = DOWN;
        }else{
            //Im not in the top
            bool there_is_someone = false;
            for(int i = current_floor + 1; i < floors; i++) 
                if(!queues[i].empty()){
                    there_is_someone = true;
                }

            if(there_is_someone){
                //Someone to pickup
                current_floor++;
            }else{
                //Noone to pickup
                direction = DOWN;
                current_floor--;
            }
        }
    }else if(direction == DOWN){
        //Now im going down
        if(current_floor == 0){
            //Im on the floor
            current_floor++;
            direction = UP;
        }else{
            //Im not in the floor
            bool there_is_someone = false;
            for(int i = current_floor - 1; i >= 0; i--) 
                if(!queues[i].empty()){
                    there_is_someone = true;
                    continue;
                }

            if(there_is_someone){
                //Someone to pickup
                current_floor--;
            }else{
                //Noone to pickup
                current_floor++;
                direction = UP;
            }
        }

    }else{
        exit(1);
    }
}



int main(){
    std::vector<std::vector<int>> queues; std::vector<int> result;
    queues = { {}, {}, {5,5,5}, {}, {}, {}, {} };
    result = {0, 2, 5, 0};
    for(auto i : the_lift(queues, 5)){
        cout<<i<<"  ";
    }
    cout<<endl;

    queues = { {}, {}, {1,1}, {}, {}, {}, {} };
    result = {0, 2, 1, 0};        
    for(auto i : the_lift(queues, 5)){
        cout<<i<<"  ";
    }
    cout<<endl;

    queues = { {}, {3}, {4}, {}, {5}, {}, {} };
    result = {0, 1, 2, 3, 4, 5, 0};
    for(auto i : the_lift(queues, 5)){
        cout<<i<<"  ";
    }
    cout<<endl;

    queues = { {}, {0}, {}, {}, {2}, {3}, {} };
    result = {0, 5, 4, 3, 2, 1, 0};
    for(auto i : the_lift(queues, 5)){
        cout<<i<<"  ";
    }
    cout<<endl;
    return 0;
}

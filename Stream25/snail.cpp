#include <vector>
#include <iostream>
using namespace std;
bool can_move(int direction,const vector<vector<int>>& snail, vector<vector<bool>>& crossed, int x, int y){
    bool ret = true;
    int size = snail.size();
    //Controllo se posso continuare
    switch(direction){
        case 0:
            if(x >= 0 && x < size && y >= 0 && y < size){
                if(y + 1 < size && !crossed[x][y + 1]){
                    return true;
                }
                else
                    return false;
            }
            else 
                return false;
        break;
        case 1:
        if(x >= 0 && x < size && y >= 0 && y < size){
                if(x + 1 < size && !crossed[x + 1][y]){
                    return true;
                }
                else
                    return false;
            }
            else 
                return false;
        break;
        case 2:
        if(x >= 0 && x < size && y >= 0 && y < size){
                if(y - 1 >= 0 && !crossed[x][y - 1]){
                    return true;
                }
                else
                    return false;
            }
            else 
                return false;
        break;
        case 3:
        if(x >= 0 && x < size && y >= 0 && y < size){
             if(x - 1 < size && !crossed[x - 1][y]){
                    return true;
                }
                else
                    return false;
            }
            else 
                return false;
        break;
    }
    return ret;
}
std::vector<int> snail(const std::vector<std::vector<int>>& snail_map) {
    if(snail_map[0].empty()) return {};
    
    int direction = 0, size = snail_map.size();
    int x = 0, y = 0;
    vector<int> ret{};
    vector<vector<bool>> crossed{};
    for(int i = 0; i < size; i++){
        crossed.push_back({});
        for(int j = 0; j < size; j++){
            crossed[i].push_back(false);
        }
    }
    while(can_move(direction, snail_map, crossed, x, y)){
        switch(direction){
            case 0:
                while(can_move(direction, snail_map, crossed, x, y)){
                    if(!crossed[x][y]){
                        ret.push_back(snail_map[x][y]);
                        crossed[x][y] = true;
                    }
                    y++;
                }
                direction = 1;
            break;
            case 1:
                 while(can_move(direction, snail_map, crossed, x, y)){
                    if(!crossed[x][y]){
                        ret.push_back(snail_map[x][y]);
                        crossed[x][y] = true;
                    }
                    x++;
                }
                direction = 2;
            break;
            case 2:
                 while(can_move(direction, snail_map, crossed, x, y)){
                    if(!crossed[x][y]){
                        ret.push_back(snail_map[x][y]);
                        crossed[x][y] = true;
                    }
                    y--;
                }
                direction = 3;
            break;
            case 3:
                 while(can_move(direction, snail_map, crossed, x, y)){
                    if(!crossed[x][y]){
                        ret.push_back(snail_map[x][y]);
                        crossed[x][y] = true;
                    }
                    x--;
                }
                direction = 0;
            break;
        }
    }
   ret.push_back(snail_map[x][y]);
    return ret;
}

int main(){

    vector<vector<int>> v{{}};

    v =  {
    {1, 2, 3, 4}, 
    {12,13,14,5}, 
    {11,16,15,6}, 
    {10,9, 8, 7}};
    for(int i : snail(v)){
        cout<<i<<" ";
    }
    cout<<endl;
    v =  {{1,2}, {4,3}};
    for(int i : snail(v)){
        cout<<i<<" ";
    }

    cout<<endl;
    v =  {{1,2,3}, {8,9,4}, {7,6,5}};
    for(int i : snail(v)){
        cout<<i<<" ";
    }


    cout<<endl;
    v =  {{}};
    for(int i : snail(v)){
        cout<<i<<" ";
    }

    return 0;
}

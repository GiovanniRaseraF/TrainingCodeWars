#include <vector>
using namespace std;
bool can_move(int direction,const vector<vector<int>>& snail, vector<vector<bool>>& crossed, int x, int y){
    bool ret = true;
    //Controllo se posso continuare
    switch(direction){
        case 0:
        
        break;
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
    }
    return ret;
}
std::vector<int> snail(const std::vector<std::vector<int>>& snail_map) {
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
    return {};
}

int main(){
    return 0;
}

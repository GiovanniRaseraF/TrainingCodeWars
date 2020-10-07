#pragma one
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
template <class T, class Container = std::vector<T>, class Compare = std::less<typename Container::value_type> > 
class priority_queue{
    private:
    //Container della struttura
    Container heap_vector;
    //Lunghezza massima del vettore e lunghezza corrente
    int max_size;
    int current_size;

    public:
    priority_queue(int max_size) : heap_vector{}{}

    void push(T value){
        heap_vector.push_back(value);
        current_size++;
    }
    void sort(const Compare comp){
        std::sort(heap_vector.begin(), heap_vector.end(), comp);
        for(auto a : heap_vector) std::cout<<a<<" ";
    }
};

int main(){
    priority_queue<int> p(10);
    p.push(12);
    p.sort(std::less<int>());
    return 0;
}
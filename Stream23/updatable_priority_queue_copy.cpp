#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include <mutex>
#include <assert.h>
#include "UpdatableObservable.cpp"
using namespace std;

/*
Implementazione in c++ della coda con priorità aggiornabile
Author:     Giovanni Rasera
Git:        https://github.com/GiovanniRaseraF/updatable-priority-queue
*/
template <
    class T,
    //un qualsiasi tipo di dato

    class Container = std::vector<T>,
    /*
    Un vettore di tipi
    In C# dovrai specificare che sono comparabili
    {ma non sono sicuro}
    */

    class less_then = std::less<typename Container::value_type>,
    //Importante
    /*
    Questa riga della definizione del template definisce la funzione con 
    cui comparo gli elementi ed è ciò che mi permette di astrarre dal tipo
    di dato che inserisco
    */

    >

class updatable_priority_queue{
    private:
    Container heap;
    less_then le_then;
    equal eq;
    std::mutex stop;

    public:
    updatable_priority_queue(less_then& comp, equal& eq): le_then{comp}{
        static_assert(is_base_of<updatable_observable, T>::value);
    }

    int insert(T& element){
        stop.lock();
        this->heap.push_back(element);
        int ret = this->bubble_up(this->heap.size()-1);

        stop.unlock();
        return ret;
    }

    


}
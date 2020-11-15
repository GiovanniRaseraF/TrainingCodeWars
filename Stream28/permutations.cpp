#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct node{
    string key;
    node* left, *right;
};

node* insert(node* root, string key){
    if(root == nullptr) return new node{key, nullptr, nullptr};
    if(key < root->key) {
        root->left = insert(root->left, key);
    }
    if(key > root->key){
        root->right = insert(root->right, key);
    }
    if(root->key == key) return root;
    
    return root;
}

void create_vet(node* root, vector<string>& vet){
    if(root == nullptr) return;
    create_vet(root->left, vet);
    vet.push_back(root->key);
    create_vet(root->right, vet);
    return;
}


unsigned long long fact(int n){
    unsigned long long ret = 1;
    while(n > 0){
        ret *= n;
        n--;
    }
    return ret;
}

vector<string> permutations(string s){
    if(s.length() == 0) return {""};
    if(s.length() == 1) return {s};
    vector<string> ret{};
    node* r = insert(nullptr, s);
    /*
    Mi serve:
        - len per carlocare n
        - n che sarebbe len!
        - alfabeto 
        - numero di occorrenze di ogni lettera dell'alfabeto
    */
    int s_len = s.length();                 //len
    unsigned long long n = fact(s_len);     //len!
    string copy = s, alph = "";             
    std::sort(copy.begin(), copy.end());    
    alph += copy[0];
    for(int i = 1; i < s_len; i++)          //alfabeto
        if(copy[i] != copy[i-1]) alph += copy[i];
    vector<int> app_per_letter{};
    for(char c : alph)                      //numero di occorrenze delle lettere 
        app_per_letter.push_back(std::count(copy.begin(), copy.end(), c));

    unsigned long long den = 1;
    for(int v : app_per_letter)             //denominatore
        den *= fact(v);

    //Calcolo le permutazioni
    unsigned long long n_perm = n / den;
    for(char c : alph){
        int pos_in_s = 0;
        while(s[pos_in_s] != c) pos_in_s++; //trovo la posizione in s
        string sub = s;
        char temp = sub[pos_in_s];
        sub[pos_in_s] = sub[0];
        sub[0] = temp;
        vector<string> sub_res = permutations(sub.substr(1));
        int len_sub_res = sub_res.size();
        for(int i = 0; i < n_perm ; i++){
            string to_add = c + sub_res[i % len_sub_res];
            insert(r, to_add);
        }
    }
    create_vet(r, ret);
    return ret;
}

int main(){
    cout<<permutations("cerjjsx").size();
    /*
    node* a = insert(nullptr, "hello");
    insert(a, "ciao");
    insert(a, "boh");
    insert(a, "ciao");

    vector<string> b{};

    create_vet(a, b);

    for(string s : b){
        cout<<s<<" ";
    }
*/
    return 0;
}




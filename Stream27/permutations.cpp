#include <iostream>
#include <string>
#include <vector>
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


vector<string> permutations(string s) {
    vector<string> ret{};
    node* rr = insert(nullptr, s);
    string copy = s;
    for(int i = 0; i < copy.length(); i++){
        string cs;
        for(int j = 0; j < s.length(); j++){
            char c = s[j];
            s[j] = s[i];
            s[i] = c;
            insert(rr, s);     
            s = copy;
        }
    }

    create_vet(rr, ret);
    return ret;
}

int main(){
    node* a = insert(nullptr, "hello");
    insert(a, "ciao");
    insert(a, "boh");
    insert(a, "ciao");

    vector<string> b{};

    create_vet(a, b);

    for(string s : b){
        cout<<s<<" ";
    }

    return 0;
}




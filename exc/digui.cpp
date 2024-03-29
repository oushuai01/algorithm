#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class  person{
    public:
    void read() const{
        cout << sort;
    }
    private:
    int sort = 10;
};
int f(int x){
    if(x == 0)
    return 0;
    else
    return 2 * f(x - 1) + x * 8;
}
int print_(int x){
    if(x == 1){
    cout << "x" << endl;
    return 1;
    }
    else{
    int size_ = print_(x - 1) + 1;
    for (size_t i = 0; i < size_; i++)
    {
        cout << "x";
    }
    cout << endl;
    return size_;
    }
}

void pr(int x){
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= i; j++){
            cout << "X";
        }
        cout << endl;
    }
}

void priout(int x){
    if(x >= 10){
        priout(x / 10);
    }
    cout << x % 10 ;
}

long long fb(int x){
    if(x < 3){
        return 1;
    }
    return fb(x - 1) + fb(x - 2);
}

void test(){
    vector<int> v(800000);
    for(int i = 0; i < 800000; i++){
        v.push_back(i);
    }
    cout << "cr over" << endl;
    vector<int>::iterator it = v.begin();
    while(it != v.end()){
        v.erase(it);
        if(it != v.end())
        it++;
    }
}
struct Node
{
    int data;
    Node* prev;
    Node* next;
    Node(int data_, Node* prev_, Node* next_){
        data = data_;
        prev = prev_;
        next= next_;
    }
};

int main(){
//   priout(446464642);
//   person p;
//   p.read();
//   string str = "vkmsmkvs";
//   cout << str.length();

//   person* pe = NULL;
//   pe = new person;
//   pe->read();
//   delete pe;
//   int arr[10] = {1,2,3,4};

    // cout << fb(10);
    // vector<int> v1;
    // v1.push_back(50);
    // v1.push_back(40);
    // v1.push_back(30);
    // v1.push_back(10);
    // v1.insert(v1.begin(),25);
    // v1.insert(v1.end(),25);
    // for(int i = 0; i < v1.size(); i++){
    //     cout << v1[i] << " ";
    // }
    // cout << endl;

    // cout << "ks" << endl;
    // test();
    // cout << "over";

    Node* node = new Node(-1,NULL,NULL);
    Node* current_node = node;
    for(int i = 0; i < 10; ++i){
        Node* new_node = new Node(i,current_node,NULL);
        current_node->next = new_node;
        current_node = new_node;
    }
    cout << "crwc" << endl;
    current_node = node;
    while(current_node != NULL){
        cout << current_node->data << " ";
        current_node = current_node->next;
    }




}
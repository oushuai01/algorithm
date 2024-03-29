#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    string A_;
    vector<int> vec;
    vec.push_back(1189);
    vec.push_back(841);
    cin >> A_;
    char type = A_[0];
    int size_ = A_[1] - '0';
    if(A_.size() != 2 || type != 'A' || (size_ > 9 || size_ < 0)) return 0;
    int temp_01;
    int temp_02;
    for(int i = 1; i <= size_; ++i){
        temp_01 = vec[0];
        temp_02 = vec[1];
        vec[0] = min(temp_01,temp_02);
        vec[1] = max(temp_01,temp_02) / 2;
    }
    cout << vec[0] << endl << vec[1];


    return 0;
}
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool cheack(int a, int y_1, int y_2, int r_1, int r_2){
    int mon_ = y_1 * 10 + y_2;
    int data_ = r_1 * 10 + r_2;
    if((mon_ == 4 || mon_ == 6 || mon_ == 9 || mon_ == 11) && data_ <= 30){
        return true;
    }
    if((mon_ == 1 || mon_ == 3 || mon_ == 5 || mon_ == 7 || mon_ == 8 || mon_ == 10 || mon_ == 12) && data_ <= 31){
        return true;
    }
    if(((a % 4 == 0) && (a % 100 != 0))|| (a % 400 == 0)){ 
        if(mon_ == 2 && data_ <= 29)
            return true;
    }
    else{
        if(mon_ == 2 && data_ <= 28) 
        return true;
    }
    return false;
    

}

int main(){
    int data = 20200202;
    int find_ = 0;
    vector<int> vec(8), vec_1(8);
    // cin >> data;
    int year = data / 10000;
    for(int i = year + 1; ; ++i){
        vec[0] = i / 1000;
        vec[1] = i % 1000 / 100;
        vec[2] = i / 10 % 10;
        vec[3] = i % 10;
        vec[4] = i % 10;
        vec[5] = i / 10 % 10;
        vec[6] = i % 1000 / 100;
        vec[7] = i / 1000;
        if(cheack(i,vec[4],vec[5],vec[6],vec[7])){
        if(find_ == 0){
            find_ = 1;
            for(int i = 0; i < 8; ++i)
            vec_1[i] = vec[i];
        }
        if(find_ == 1 && vec[0] == vec[2] && vec[1] == vec[3]){
            break;
        }
        }

    }
    for(int i = 0; i < vec_1.size(); ++i){
        cout << vec_1[i];
    }
    cout << endl;
    for(int i = 0; i < vec.size(); ++i){
        cout << vec[i];
    }
    return 0;
}
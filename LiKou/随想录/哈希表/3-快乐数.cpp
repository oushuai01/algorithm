#include <iostream>
#include <unordered_set>
using namespace std;

int getNum(int n){
    int sum = 0;
    while(n){
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;

}

bool isHappy(int n) {
    int happyNum;
    unordered_set<int> unset;
    while(1){
        happyNum = getNum(n);
        if(happyNum == 1)
        return true;
        if(unset.find(happyNum) != unset.end()){
            return false;
        }else{
            unset.insert(happyNum);
        }
        n = happyNum;
    }

}

int main(){


    return 0;
}
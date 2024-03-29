#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    // map<int,int> map_bills;
    // map_bills.insert(make_pair(5,0));
    // map_bills.insert(make_pair(10,0));
    // map_bills.insert(make_pair(20,0));
    // for(int i = 0; i < bills.size(); ++i){
    //     if(bills[i] == 5)
    //     map_bills[bills[i]]++;
    //     else if(bills[i] == 10){
    //         map_bills[5]--;
    //         map_bills[10]++;
    //     }
    //     else if(bills[i] == 20)
    //     {
    //         if(map_bills[10] != 0){
    //             map_bills[10]--;
    //             map_bills[5]--;
    //         }
    //         else{
    //             map_bills[5]-=3;
    //         }
    //     }
    //     if(map_bills[5] < 0 || map_bills[10] < 0 || map_bills[20] < 0)
    //     return false;
    // }
    // return true;


    int five = 0 , ten = 0, twl = 0;
    for(int i = 0; i < bills.size(); ++i){
        if(bills[i] == 5)
        five++;
        else if(bills[i] == 10){
            five--;
            ten++;
        }
        else if(bills[i] == 20){
            if(ten != 0){
                ten--;
                five--;
                twl++;
            }
            else{
                five-=3;
            }
        }
        if(five < 0 || ten < 0 || twl < 0)
        return false;
    }
    return true;
}

int main(){
    vector<int> bills_ = {5,5,10,10,20};
    cout << lemonadeChange(bills_);

}
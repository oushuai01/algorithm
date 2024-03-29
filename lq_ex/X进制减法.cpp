#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main(){
    int top_bit;
    int size_a , size_b;
    cin >> top_bit;
    cin >> size_a;
    vector<vector<int>> vcc(2,vector<int>(100005,0));
    
    for(int j = 0; j < size_a; j++){
        cin >> vcc[0][j];
    }
    cin >> size_b;

    for(int j = size_a - size_b; j < size_a; j++){
        cin >> vcc[1][j];
    }

    long long sum = 0, weight = 1;
    for(int j = size_a - 1; j >= 0; j--){
      sum = (sum + (vcc[0][j] - vcc[1][j]) * weight) % 1000000007;
      weight = (weight * (max(max(vcc[0][j], vcc[1][j]) + 1 , 2))) % 1000000007 ;
    }
    cout << sum % 1000000007;
  return 0;
}
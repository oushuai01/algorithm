#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){

    int n,k;
    cin >> n >> k;
    long long sum = 1;
    vector<int> vec(n, 0);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        vec[i] = x;
        if(x != 0)
        sum *= x;
    }
    k = pow(10, k);
    int count = 0;
    for(int i = 0; i < n; i++){
        long long sum_temp = 1;
        if(vec[i] == 0) continue;
        for(int j = i; j < n ;j++){
            if(vec[j] != 0)
            sum_temp *= vec[j];
            if((sum / sum_temp) % k == 0){
                count++;
                //cout << i << " " << j << " " << sum / sum_temp << endl;
            }
        }
    }
    cout << count << endl;
}
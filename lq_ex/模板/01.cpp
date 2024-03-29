#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
int sum = 1;
long long tatol_sum = 1;
int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
}

void get_divisors(long long n){
    vector<long long> res;
    for(long long i = 2; i <= n / i; ++i){
        int cnt = 0;
        if(n % i == 0){
            while(n % i == 0){
                n /= i;
                cnt++;
            }
            // cout << cnt << endl;
            sum *= (cnt + 1);
            tatol_sum *= (pow(i,cnt + 1) - 1) / (i - 1);
            res.push_back(i);
            // if(i != n / i) res.push_back(n / i);
        }
    }
    if(n > 1){
        sum *= 2;
        tatol_sum *= (pow(n,2) - 1) / (n - 1);
        res.push_back(n);
    }


    sort(res.begin(), res.end());
    cout << "约数中的质数：";
    for(int j = 0; j < res.size(); ++j){
        cout << res[j] << " ";
    }
    cout << endl;
    cout << "约数个数： " << sum << endl;
    cout << "约数之和： " << tatol_sum << endl;
}
int main(){
    get_divisors(100);


    unordered_map<int,int> mp_;

    for(int i = 10; i > 0; --i){
         mp_[i] = i + 1;;
    }
   for(auto it : mp_){
    cout << it.first << " " << it.second << endl;
   }
   cout << gcd(6,9);
    return 0;
}
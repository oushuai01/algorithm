// #include <iostream>
// #include <vector>
// #include <math.h>
// using namespace std;



// int main(){
//     int n,q;
//     cin >> n >> q;

//     vector<long long> vec(n + 1, 0);
//     long long mod = pow(10,9) + 7;
//     long long sum = 0;


//     for(int i = 1; i <= n; i++){
//         int x;
//         cin >> x;
//         vec[i] = x;
//         sum = (sum + x);
//     }

//     for(int i = 1; i <= q; i++){
//         int y;
//         cin >> y;
//         for(int j = 1; j <= n; j++){
//             if(j != y)
//             vec[j] = (vec[j] * 2);
//         }
//         sum = (sum * 2 - vec[y]);
//     }

//     cout << sum % mod;
// }


#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int mod = pow(10,9) + 7;

void fun_bin(vector<int> &bin_){
    long long num = 1;
    for(int i = 1; i <= bin_.size(); i++){
        num = (num * 2) % mod;
        bin_[i] = num;
    }
}


int main(){
    int n,q;
    cin >> n >> q;

    vector<int> vec(n + 1, 0);
    vector<int> index(n + 1, q);
    vector<int> bin(100001, 1);
    long long sum = 0;


    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        vec[i] = x;
        //sum = (sum + x);
    }

    for(int i = 1; i <= q; i++){
        int y;
        cin >> y;
        index[y]--;
    }
    fun_bin(bin);
    for(int j = 1; j <= n; j++){
        sum = sum + vec[j] * bin[index[j]];
        sum %= mod;
    }




    cout << sum % mod;
}
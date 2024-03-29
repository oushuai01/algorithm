
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<long long>> arr;
    long long sum = 0;
    int count = 0;
    while(n--){
        long long x;
        cin >> x;
        if(x != 0)
        sum += x;
        else
        count++;
    }

    while(q--){
        int left, right;
        long long min_sum = 0;
        long long max_sum = 0;
        cin >> left >> right;

        min_sum = sum + count * left;
        max_sum = sum + count * right;

        arr.push_back({min_sum, max_sum});
    }

    for(int i = 0; i < arr.size(); i++)
    cout << arr[i][0] << " " << arr[i][1] << endl;

    return 0;
}


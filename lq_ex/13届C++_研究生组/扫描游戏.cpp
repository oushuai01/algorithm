#include <iostream>
#include <math.h>
#include <list>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
// 能过69分

// 判断象限
float cheak(vector<long long> &value){
    if(value[0] >=0 && value[1] >= 0)
    return 0;
    else if(value[0] > 0 && value[1] < 0)
    return 0;
    else if(value[0] < 0 && value[1] < 0)
    return 1;
    else if(value[0] < 0 && value[1] > 0)
    return 1;
}
bool cmp(vector<long long> &a,vector<long long> &b){
    float antan_a = (atan2f(a[0],a[1]));
    float antan_b = (atan2f(b[0],b[1]));
    float cheack_a = cheak(a);
    float cheack_b = cheak(b);
    antan_a = (1.5708 * 4) * cheak(a) +  antan_a ;
    antan_b = (1.5708 * 4) * cheak(b) +  antan_b ;
    if(a[0] == b[0] && a[1] == b[1])
    return a[2] < b[2];
    return antan_a < antan_b;
}
int main(){
    long long n,L;
    cin >> n >> L;
    vector<vector<long long>> vec(n,vector<long long>(3,0));
    vector<long long> arr(n,0);
    for(int i = 0; i < n; i++){
        long long x,y,val;
        cin >> x >> y >> val;
        vec[i][0] = x;
        vec[i][1] = y;
        vec[i][2] = val;
    }
    vector<vector<long long>> vec_copy(vec);
    sort(vec_copy.begin(),vec_copy.end(),cmp);
    // for(int i = 0; i < n; i++){
    //     cout << vec_copy[i][0] << "  " << vec_copy[i][1] << "  " << vec_copy[i][2] << "  " <<(atan2f(vec_copy[i][0],vec_copy[i][1])) << endl;
    // }
    float temp = -5;
    int index = 0;
    int count = 0;
    double real_l = 0;
    while(index <= n){
    long long  temp_l = L;
    for(int i = 0; i < n; i++){
        float antan_xy = atan2f(vec_copy[i][0],vec_copy[i][1]);
        if(temp != antan_xy && arr[i] == 0){
            index = count + 1;
        }
        real_l  = vec_copy[i][0] * vec_copy[i][0] + vec_copy[i][1] * vec_copy[i][1];
        // cout << real_l << endl;
        if(L >= sqrt(real_l) && arr[i] == 0){
            arr[i] = index;
            count++;
            L += vec_copy[i][2];
        }
        // cout << vec_copy[i][0] << "_"  << vec_copy[i][1] << "_" << vec_copy[i][2]<< " " << L  << "  " << sqrt((vec_copy[i][0] * vec_copy[i][0] + vec_copy[i][1] * vec_copy[i][1]))  << " "<< arr[i] << endl;
        temp = antan_xy;
    }
    if(temp_l == L){
        // cout << "break";
        break;
    }
    }
    // cout << count << endl;
    if(count != n)
    for(int i = 0; i < n; i++){
        if(arr[i] == 0)
        arr[i] = -1;
        // cout << "index - 1";
    }
    map<string,int> maps;
    for(int i = 0; i < n; i++){
        string str = to_string(vec_copy[i][0]) + to_string(vec_copy[i][1]) + to_string(vec_copy[i][2]);
        maps[str] = arr[i];
        str = "";
    }
    for(int i = 0; i < n; i++){
        string str = to_string(vec[i][0]) + to_string(vec[i][1]) + to_string(vec[i][2]);
        cout << maps[str] << " ";
        str = "";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int N = 100010;
int arr[N];

// 只能过4个
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        scanf("%d",&arr[i]);
    }
    int m;
    cin >> m;
    //存放查询的数据
    vector<vector<int>> vec(m + 1, vector<int>(3,0));
    for(int j = 1; j <= m; ++j){
        for(int jj = 0; jj < 3; jj++)
            cin >> vec[j][jj];
    }
    int cout_count = 0;
    map<int,int> mp_sum;
    for(int j = 1; j <= m; ++j){
        cout_count = 0;
        int left = vec[j][0];
        int right = vec[j][1];
        int count = vec[j][2];
        for(int jj = left; jj <= right; jj++){
            mp_sum[arr[jj]]++;
        }
        for(map<int,int>::iterator it = mp_sum.begin(); it != mp_sum.end(); it++){
            if(it->second == count){
                cout_count++;
            }
            it->second = 0;
        }
        cout << cout_count << endl;
    }



    return 0;
}
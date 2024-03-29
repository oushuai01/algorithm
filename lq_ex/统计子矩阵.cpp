#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main(){
    int N, M, target;
    long long count = 0;
    cin >> N >> M >> target;
    vector<vector<int>> vcc(N + 1,vector<int>(M + 1,0));
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> vcc[i][j];
            vcc[i][j] = vcc[i][j] + vcc[i - 1][j];
        }
    }
     for(int i = 1; i <= N; ++i){
       for(int ii = i; ii <= N; ++ii){
            for(int left = 1, right = 1, sum = 0; right <= M; right++){
                sum += vcc[ii][right] - vcc[i - 1][right];
                while(sum > target){
                    sum -= vcc[ii][left] - vcc[i - 1][left];
                    left++;
                }
                count += right - left + 1;
            }
       }
    }
    cout << count;

  return 0;
}



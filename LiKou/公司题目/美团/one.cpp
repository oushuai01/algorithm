#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<vector<vector<int>>> vec;
    cin >> n;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        int count_0 = 0;
        int count_1 = 0;
        // 得到每一行0和1的前缀和
        vector<vector<int>> temp_vec;
        for(int j = 0; j < n; j++){
            if(str[j] == '0'){
                count_0++;
                temp_vec.push_back({count_0, count_1});
            }else if(str[j] == '1'){
                if(str[j] == '1'){
                count_1++;
                temp_vec.push_back({count_0, count_1});
            }
            }
        }
        vec.push_back(temp_vec);
    }
    // 1 x 1 直接输出 0
    cout << "0" << endl;
    for(int i = 1; i < n; i++){
        // 记录数量
        int count = 0;
            // 横排扫描 扫描 i + 1列
            for(int k = i; k < n; k++){
                // 竖排扫描
                for(int j = 0; j < n - i; j++){
                    int count_0 = 0;
                    int count_1 = 0;
                    // 扫描竖排 i + 1 行
                    for(int up = j; up <= i + j; up++){
                        if(k == i){
                            count_0 += vec[up][k][0];
                            count_1 += vec[up][k][1];
                        }else{
                            count_0 += vec[up][k][0] - vec[up][k - (i + 1)][0];
                            count_1 += vec[up][k][1] - vec[up][k - (i + 1)][1];
                        }
                    }
                    if(count_0 == count_1)
                        count++;
                }
        }
        cout << count << endl;
    }

}

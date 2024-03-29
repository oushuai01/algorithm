#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n,size_str,count = 0;
    cin >> n;
    while(n--){
        vector<int> index_;
        cin >> size_str;
        string str;
        cin >> str;
        // cout << str << endl;
        // 找出与上一个不同的方块   并且反转两个
        for(int i = 1; i < size_str - 1; ++i){
            if(str[i] != str[i - 1]){
                str[i] == 'W' ? str[i] = 'B' : str[i] = 'W';
                str[i + 1] == 'W' ? str[i + 1] = 'B' : str[i + 1] = 'W';
                count++;
                index_.push_back(i + 1);
            }
        }
        // 经过上一个步骤  如果砖块能够全部变成一样的颜色  那我们只需要看最后一个方块是不是和前面一样   如果不是一样
        // 我们反转他前面所有的方块  反转完如果还不能成为一样的颜色  那么就不可能有结果
        for(int i = 1; i < size_str; ++i){
            if(str[i] != str[i - 1] && i == size_str - 1){
                 for(int j = 0; j < size_str - 1; j+=2){
                    str[j] == 'W' ? str[j] = 'B' : str[j] = 'W';
                    str[j + 1 ] == 'W' ? str[j + 1 ] = 'B' : str[j + 1 ] = 'W';
                    count++;
                    index_.push_back(j + 1);
                 }
            }
        }
        // 检测一下是不是都是一样的颜色
        for(int i = 1; i < size_str; ++i){
            if(str[i] == str[i - 1]){
                if(i == size_str - 1){
                    cout << count << endl;
                    if(count > 0){
                        for(int j = 0; j < index_.size(); ++j)
                        cout << index_[j] << " ";
                        cout << endl;
                    }
                }
            }
            else{
                cout << -1 << endl;
                break;
            }
        }
        count = 0;
        index_.clear();
    }

// system("pause");
    return 0;
}
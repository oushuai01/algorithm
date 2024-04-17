#include <iostream>

using namespace std;

// 没考虑10
int main(){
    int n;
    cin >> n;
    string str;
    while(n--){
        char c;
        cin >> c;
        str.push_back(c);
    }
    int flag = 1;
    while(flag){
        string str2;
        flag = 0;
        for(int i = 0; i < str.size(); i++){
            int count = 1;
            str2.push_back(str[i]);
            for(int j = i + 1; j < str.size(); j++){
                if(str[i] != str[j]) break;
                count++;
                if(count == 4) break;
            }

            if(count == 3){
                flag = 1;
                i = i + 2;
                str2.pop_back();
                //break;
            }else if(count == 4){
                flag = 1;
                i = i + count - 1;
                //str2.pop_back();
                //break;
            }
        }
        str = str2;
    }
    if(str.size() == 0) {
        cout << 0;
        return 0;
    }

    for(int i = 0; i < str.size(); i++){
        if(i == str.size() - 1)
        cout << str[i];
        else
        cout << str[i] << " ";
    }

}
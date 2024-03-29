#include <iostream>
#include <vector>
using namespace std;

// 87 分
// 部分超时
int main(){

    string str_cin = "vvvvrrrrrrrrrrrrrmmmmmmmmmbbbbnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnneeeeeeyyyyyyyyyyyyyyyyyxxxxxxxxxxxxxxxxxxxxeeppppppppppppxxxxxxmmmmmmmmmcccccccccccckkguuuuuuzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzhhhhrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrccccccccccccccccccccccccccccccccccccccccctttttttttttttttttttttttttttttjjjjjjjjjjjjjjjjettttttttttttttttttttttzzzzzzzzzzzzzzzzzzzzzzzzzzzzzbbbbbbbbbbbbbbbbbbbuuuuuuyyyyyyyyyyyyyyyykkkkkkkkqqqqqqnnnnnqqqqqqqqqjjjjjwwwwwwwwwiiiiiiittttoooooooooooooooooooooooossooooqqqqqqqqqqqqqqeeeeeeeebxxxxkkkknvvvvwwwwwwwwwfffffffffffffffffffffhhuuuuuuuumrrrrrrrrrrrrrrrrrrhhmmmmmmmmmmmmmmmaddrrrrrrrrrrrrrpppkkkkkkkkuuuuuuuuuuwwwwwwwwwwwxxxxxwkkkkkkvvvvvvwwwwwwwwwwwwwwwiiiiiiihddddddaaxxxxxxxxxxxxxxxxxxeeeeettttttttxxxxxxxxxxxxdrrrrrrrrllllllnnyyyyyyyyyyyiiiiiiiiiiiiiiiiiiiiiiiiiiiiilooorjjjjjjjjjjrrrrrggggggoooooooyyyyzzoooooooooooooooooooofffffffffffffffffjjssssvuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuaaqqqqqqqqqqqqqqqqqqqqqpppkkkkkkkkkkdddddddddttttkkkkkgggggggg";
    string str_temp;
    // cin >> str_cin;
    int str_size = str_cin.size();
    vector<int> str_cout(str_size,1);
    while(1){
        for(int i = 1; i < str_size - 1; ++i){
        if(str_cin[i] == str_cin[i - 1] && str_cin[i] != str_cin[i + 1]){
            str_cout[i + 1] = 0;
            str_cout[i] = 0;
        }
        else if(str_cin[i] != str_cin[i - 1] && str_cin[i] == str_cin[i + 1]){
            str_cout[i - 1] = 0;
            str_cout[i] = 0;
        }
        }
        int p = 0;
        for(int i = 0; i < str_size; ++i){
            if(str_cout[i] == 0){
                str_cin.erase(i - p,1);
                p++;
            }
        }
        if(p == 0){
            for(int j = 0; j < str_cin.size(); ++j)
            cout << str_cin[j];
            break;
        }
        if(str_cin.size() == 0){
            cout << "EMPTY";
            break;
        }
    }
    


    return 0;
}

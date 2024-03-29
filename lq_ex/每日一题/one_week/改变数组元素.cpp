#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int num, options_;
        int cout_sum = 0;
        cin >> num;
        vector<int> vec(num + 10,0);
        
        for(int i = 1; i <= num; ++i){
            cin >> options_;
            if(options_ != 0){
                int bengin_ = (options_ >= i ? 1 : i - options_ + 1);
                // 差分
                vec[bengin_] += 1;
                vec[i + 1] -= 1;
            }
        }
         for(int i = 1; i <= num; ++i){
            cout_sum += vec[i];
            cout << (cout_sum >= 1 ? 1 : 0) << " ";
         }
        cout << endl;
       
    }


    return 0;
}
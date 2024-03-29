#include <iostream>
using namespace std;
const int N = 100010;
long long arr[N];
long long arr_yihuo[N];

//暴力只能40
int main(){
    int n, m;
    long long x;
    cin >> n >> m >> x;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        arr_yihuo[i] = x ^ arr[i];
    }
    int left,right;
    int flag = 0;
    for(int i = 1; i <= m; ++i){
        cin >> left >> right;
        for(int j = left; j <= right; ++j){
            for(int jj = left; jj <= right; ++jj){
                if(arr_yihuo[j] == arr[jj] && jj != j){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                cout << "yes" << endl;
                flag = 0;
                break;
            }
            else if(flag == 0 && j == right)
            cout << "no" << endl;
        }
    }
    return 0;
}



/*


#include <iostream>
#include <map>
using namespace std;
const int N = 100010;
map<long long,int> last;
int G[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);         //这两行 可以使得输入输出变快  用了之后就只能用 cin 和 cout
    long long n, m , x;
    cin >> n >> m >> x;
    for(int i = 1; i <= n; ++i){
        long long a;
        cin >> a;
        // 更新最靠右的数据 使得 G[i]值 为当前最靠右的 b 下标   a ^ b = x  ==>  x ^ a = b ==> x ^ b = a;
        G[i] = max(G[i - 1], last[x ^ a]);
        // 更新下标
        last[a] =  i;
    }
    int left,right;
    for(int i = 1; i <= m; ++i){
        cin >> left >> right;
        // 只要最右边的下标大于left 说明这个区间里面有一对数字 使得 a^b = x;
        if(G[right] >= left) cout << "yes\n";    //不能用 endl  会使得输出变慢  用\n
        else
        cout << "no\n";
    }
    return 0;
}




 */


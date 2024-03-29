#include <iostream>
#include <math.h>
using namespace std;
int n;

bool get_yue(long long x){
    int count = 0;
    int pow_ = 0;
    int sum_pow = 0;
    double x_2 = pow(x, 1.0 / 2);
    if(x_2 * x_2 == x)
    return true;
    double x_3 = pow(x,1.0 / 3);
    if(x_3 * x_3 * x_3 == x)
    return true;
    for(int i = 2; i <= x / i && i <= 4000; ++i){
        pow_ = 0;
        if(x % i == 0){
        while(x % i == 0){
            x /= i;
            pow_++;
        }
        sum_pow += pow_;
        // cout << i << " " << pow_ << endl;
        count++;
        if(pow_ < 2){
            return false;
        }

    }
    }
    if(count == 0)
    return false;
    if(x > 1){
        count++;
        // cout << x;
        if(count >= 2)
        return false;
    }
    if(sum_pow % count == 0)
    return true;
    if(count == 1){
        return true;
    }
    else
    return true;
    
}

int main(){
    scanf("%d",&n);
    while(n--){
        long long x;
        scanf("%lld",&x);
        if(get_yue(x))
        printf("yes\n");
        else
        printf("no\n");
    }
    // cout << get_yue(48672);
    return 0;
}
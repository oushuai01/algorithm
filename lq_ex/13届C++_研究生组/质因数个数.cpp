#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
const long long N = 10e16 + 10;
int main(){
    long long n;
    cin >> n;
    long long count = 0;
    for(long long i = 2; i <= sqrt(n); ++i){
        if(n % i == 0){
            count++;
            while(n % i == 0)
            n /= i;
        }
    }
    if(n != 1)
    count++;
    cout << count;
    return 0;
}
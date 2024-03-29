#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  long long a, b, n;
  cin >> a >> b >> n;
  long long sum = 5 * a + 2 * b;
  long long days = n / sum * 7;
  long long cha_day = n % sum;
  for(int i = 0; i < 5 && cha_day > 0; ++i){
    days++;
    cha_day -= a;
  }
  for(int i = 0; i < 2 && cha_day > 0; ++i){
    days++;
    cha_day -= b;
  }
  cout << days;
}

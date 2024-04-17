#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> set_vec;
    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        set_vec.insert(num);
    }

    for(int num : set_vec){
        cout << num << endl;
    }
}

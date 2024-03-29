#include <vector>

#include <iostream>

using namespace std;

int main(){
    vector<int> vec = {1,2,3,4,5};
    int index = 2;
    vector<int> vec1(vec.begin(), vec.begin() + index);
    vector<int> vec2(vec.begin() + index , vec.end());

    for(int num : vec1)
    cout << num << " ";
    cout << endl;
    for(int num : vec2)
    cout << num << " ";

}
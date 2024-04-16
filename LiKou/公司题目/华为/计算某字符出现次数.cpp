#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<char,int> umap;
    string str;
    getline(cin, str);
    char chart_;
    cin >> chart_;
    int count = 0;
    for(int i = 0; i < str.size(); i++)
    umap[str[i]]++;

    if((chart_ - 'a' < 26 && chart_ - 'a' >= 0) || (chart_ - 'A' < 26 &&  chart_ - 'A' >= 0)) 
    count = umap[chart_] + umap[chart_ - 32] + umap[chart_ + 32];
    else
    count = umap[chart_];
    cout << count;

}
// 64 位输出请用 printf("%lld")
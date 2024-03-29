#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    map<int,int> m;
    vector<int> res;
    for(int i : nums1){
        m[i]++;
    }
    for(int i : nums2){
        if(m.count(i) && m[i]){
            m[i]--;
            res.push_back(i);
        }
    }
    return res;
   
}

int main(){
    vector<int> nums1 = {4,9,5}, nums2 = {9,4,9,8,4};
    vector<int> re = intersect(nums1,nums2);
    for(int i = 0; i < re.size(); i++){
        cout << re[i] << " ";
    }

}
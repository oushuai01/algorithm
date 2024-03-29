#include <vector>
#include <algorithm>
using namespace std;


int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;

    while(left < right){
        max_area = max(max_area, (right - left) * min(height[left], height[right]));
        if(height[left] > height[right])
        right--;
        else
        left++;
    }
    return max_area;
}


int main(){

}
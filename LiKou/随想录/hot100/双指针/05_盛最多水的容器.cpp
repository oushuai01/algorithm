//10.12
#include <vector>
#include <algorithm>
using namespace std;
//题解
//https://leetcode.cn/problems/container-with-most-water/solutions/11491/container-with-most-water-shuang-zhi-zhen-fa-yi-do/?envType=study-plan-v2&envId=top-100-liked
int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;

    while(left < right){
        //若向内 移动短板 ，水槽的短板 min(h[i],h[j])min(h[i], h[j])min(h[i],h[j]) 可能变大，因此下个水槽的面积 可能增大 。
        //若向内 移动长板 ，水槽的短板 min(h[i],h[j])min(h[i], h[j])min(h[i],h[j])​ 不变或变小，因此下个水槽的面积 一定变小 。
        //求此时的面积
        int area = (right - left) * min(height[left], height[right]);
        //找到最大面积
        max_area = max(max_area, area);
        //短板向内移动
        if(height[left] > height[right]) right--;
        else left++;
    }
    return max_area;
}
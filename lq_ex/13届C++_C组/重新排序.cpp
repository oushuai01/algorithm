#include <iostream>
#include <algorithm>
#define N 100005
using namespace std;

int n, m, l, r, a[N], b[N];
long long sum, ans;

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    cin >> m;
    while (m --)
    {
        cin >> l >> r, b[l] ++, b[r + 1] --; // 同时处理差分
    }
    for (int i = 1; i <= n; i ++)
    {                               //这个地方要加 long long 防止数据过大越界
        b[i] += b[i - 1], sum += (long long) a[i] * b[i]; // 先得到数组 c（仍存放在数组 b 中），在顺便统计原来的总和 sum
    }
    sort (a + 1, a + n + 1), sort (b + 1, b + n + 1); // 分别排序
    for (int i = 1; i <= n; i ++)
    {
        ans += (long long) a[i] * b[i]; // 加上依次相乘的和
    }
    cout << ans - sum; // 答案即是依次相乘总和 - sum
    return 0;
}

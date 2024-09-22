#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
(未解决)
### 题目描述：
已知三个vector，分别存储第i个道具的成本，价格，售卖数量限制，k代表售卖总数量限制，求最大利润

### 输入：
- 第一行输入一个整数 `n`，表示道具数量, `k` 表示售卖总数量限制。
- 接下来 `n` 行，每行三个整数 `ci, pi, li`，表示第 `i` 个道具的成本、价格和售卖数量限制。

### 输出：
输出一个整数，表示最大利润。
*/

int main() {
    int n, k;
    cin >> n >> k;
    // 成本
    vector<int> cost(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    // 价格
    vector<int> price(n, 0);
    for(int i = 1; i <= n; i++) {
        cin >> price[i];
    }
    // 售卖数量限制
    vector<int> limit(n, 0);
    for(int i = 1; i <= n; i++) {
        cin >> limit[i];
    }
    
    // dp[i] 表示前i个商品的最大利润
    vector<int> dp(k+1, 0);
    for(int i = 1; i <= n; i++) {
        int profit = price[i] - cost[i];
        if (profit <= 0) {
            continue;        
        }
        // 剩余的商品数量
        int remain = limit[i];
        for(int j = 1; remain > 0; j = min(j,remain)){
            remain -= j;
            for(int l = k; l >= j; l--){
                dp[l] = max(dp[l], dp[l-j] + j * profit);
            }
            j *= 2;
        }
    }
    cout << dp[k] << endl;    
    return 0;
}
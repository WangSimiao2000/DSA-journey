#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int profit;
    int limit;
};

bool cmp(const Item& a, const Item& b) {
    return a.profit > b.profit;
}

int main() {
    int n, k;
    cin >> n >> k;
    // 成本
    vector<int> cost(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    // 价格
    vector<int> price(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }
    // 售卖数量限制
    vector<Item> items(n);
    for(int i = 0; i < n; i++) {
        cin >> items[i].limit;
        items[i].profit = price[i] - cost[i];
    }
    sort(items.begin(),items.end(),cmp);// 按照利润降序排序
    
    int maxProfit = 0;
    while (k > 0) {
        for(int i = 0; i < n; i++) {
            if (items[i].limit == 0) {
                continue;
            }
            if (items[i].limit >= k) {
                maxProfit += k * items[i].profit;
                k = 0;
                break;
            } else {
                maxProfit += items[i].limit * items[i].profit;
                k -= items[i].limit;
            }
        }
    }

    cout << maxProfit << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

/*
无相等元素的情况:
输入一个整数数组, 其中不包含重复元素, 返回所有可能的排列

从回溯算法的角度看, 
我们可以把生成排列的过程想象成一系列选择的结果:
假设输入数组为 [1,2,3], 
如果我们先选择 1, 再选择 2, 最后选择 3, 
则获得排列 [1,2,3];
回退表示撤销一个选择，之后继续尝试其他选择.

从回溯代码的角度看, 
候选集合 choices 是输入数组中的所有元素, 
状态 state 是直至目前已被选择的元素;
请注意, 每个元素只允许被选择一次, 因此 state 中的所有元素都应该是唯一的
*/

/*
重复选择剪枝:
为了实现每个元素只被选择一次, 我们考虑引入一个布尔型数组 selected, 
其中 selected[i] 表示 choices[i] 是否已被选择, 并基于它实现以下剪枝操作:
- 在做出选择 choice[i] 后, 我们就将 selected[i] 赋值为 True, 代表它已被选择
- 遍历选择列表 choices 时, 跳过所有已被选择的节点, 即剪枝。
*/

/* 回溯算法：全排列 I */
void backtrackI(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res) {
    // 当状态长度等于元素数量时，记录解
    if (state.size() == choices.size()) {
        res.push_back(state);
        return;
    }
    // 遍历所有选择
    for (int i = 0; i < choices.size(); i++) {
        int choice = choices[i];
        // 剪枝：不允许重复选择元素
        if (!selected[i]) {
            // 尝试：做出选择，更新状态
            selected[i] = true;
            state.push_back(choice);
            // 进行下一轮选择
            backtrackI(state, choices, selected, res);
            // 回退：撤销选择，恢复到之前的状态
            selected[i] = false;
            state.pop_back();
        }
    }
}

/* 全排列 I */
vector<vector<int>> permutationsI(vector<int> nums) {
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    vector<vector<int>> res;
    backtrackI(state, nums, selected, res);
    return res;
}
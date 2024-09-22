#include <iostream>
#include <vector>

using namespace std;


/*
(未解决)
题目描述：

有一个 \(n \times m\) 的矩阵，矩阵第 \(i\) 行第 \(j\) 列的元素编号为 \((i-1) \times m + j\)。

你需要执行以下几种操作：

1. **操作 1**：将第 \(x\) 行与第 \(y\) 行的元素交换。
2. **操作 2**：将第 \(x\) 行的元素向左移动 \(y\) 格，左边多出来的元素按照原顺序补到右边。
3. **操作 3**：查询当前矩阵中第 \(x\) 行第 \(y\) 列的元素编号。

输入格式：
- 第一行包含三个整数 \(n\)、\(m\)、\(q\)，分别表示矩阵的行数、列数和操作次数。
- 接下来的 \(q\) 行中，每行首先包含一个整数 \(t\) 表示操作类别，随后跟着操作所需的参数 \(x\) 和 \(y\)。

输出格式：
- 对于每个操作 3，输出矩阵中第 \(x\) 行第 \(y\) 列的元素编号。

输入示例：
```
2 3 4
1 1 2
3 1 3
2 1 4
3 1 3
```

输出示例：
```
6
4
```
*/

struct Operation {
    int type; // 1, 2, 3
    int x, y;
};

vector<Operation> operations;
int n, m, q;

int getOriginalNumber(int x, int y){
    --x;
    --y;
    for(int i = operations.size()-1; i>=0; --i){
        const Operation& op = operations[i];
        if (op.type == 1){
           if(op.x - 1 == x){
               x = op.y - 1;
           } else if(op.y - 1 == x){
               x = op.x - 1;
           } 
        } else if(op.type == 2){
            if(op.x - 1 == x){
                y = (y - op.y) % m;
            }
        }
    }

    return x * m + y + 1;
}

int main(){
    cin >> n >> m >> q;
    for(int i = 0; i < q; i++){
        int t, x, y;
        cin >> t >> x >> y;
        operations.push_back({t, x, y});
        if(t == 3){
            cout << getOriginalNumber(x, y) << endl;
        }
    }
    return 0;
}
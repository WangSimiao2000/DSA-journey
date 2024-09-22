#include <iostream>
#include <utility>
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

int n, m, q;
vector<int> row;
vector<int> shift;

void doFunc1(int x, int y){
    x--;
    y--;
    swap(row[x], row[y]);
}

void doFunc2(int x, int y){
    x--;
    shift[x] = (shift[x] + y) % m;
}

void doFunc3(int x, int y){
    x--;
    y--;
    int real_row = row[x];
    int real_col = (y + shift[x]) % m;
    int res = real_row * m + real_col + 1;
    cout << res << endl;
}

int main(){
    // n 行, m 列, q 次调整
    cin >> n >> m >> q;
    row.resize(n);
    shift.resize(n,0);
    for (int i=0; i < n; i++) {
        row[i] = i;
    }
    for(int i = 0; i < q; i++){
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1){
            doFunc1(x, y);
        } else if (t == 2){
            doFunc2(x, y);
        } else if (t == 3){
            doFunc3(x, y);        
        }
    }
    return 0;
}
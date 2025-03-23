#include <iostream>
#include <algorithm> // 用于std::max

using namespace std;

// 回收函数：计算a个空瓶和b个瓶盖最多能换多少瓶水
int g(int a, int b) {
    if (a < 2 && b < 3) {
        return 0; // 无法换水
    } else if (a >= 2 && b < 3) {
        return 1 + g(a - 1, b + 1); // 用2个空瓶换1瓶水
    } else if (a < 2 && b >= 3) {
        return 1 + g(a + 1, b - 2); // 用3个瓶盖换1瓶水
    } else { // a >= 2 && b >= 3
        return max(1 + g(a - 1, b + 1), 1 + g(a + 1, b - 2)); // 选择最大值
    }
}

// 总瓶数函数：计算n元最多能获得多少瓶水
int f(int n) {
    if (n == 0) {
        return 0; // 无钱买水
    } else {
        return n + g(n, n); // 初始n瓶加上回收的瓶数
    }
}

int main() {
    int n;
    cin >> n; // 输入n
    cout << f(n) << endl; // 输出结果
    return 0;
}           
// BOJ1000 A+B
// https://www.acmicpc.net/problem/1000
// 시간 복잡도: O(1)

#include <iostream>

int main() {
    // 선택 근거: A, B가 10 미만이라 합도 int 범위를 넘지 않는다.
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}

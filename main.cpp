//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>

int main() {
    int X;
    std::cin >> X;

    int tens = X / 10;
    int ones = X % 10;

    int total_bills = tens + ones;
    std::cout << total_bills << std::endl;
    return 0;
}

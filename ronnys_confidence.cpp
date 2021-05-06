// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>


int recursiveFunc(int D1, int K1, std::vector<int>& P_K, int **dp) {
    // std::cout << "!!!h1" << std::endl;

    if (K1 <= 0)
        return -1;

    if (D1 < 0)
        return -1;

    if (D1 == 0)
        return 0;

    if (D1 >= 0 && K1 >= 1 && dp[D1][K1] != 0) {
        return dp[D1][K1];
    }

    // if (D1 - P_K[K1] == 0)
    //     return 1;

    // if (D1 - P_K[K1] < 0)
    //     return -1;

    int val1 = recursiveFunc(D1 - P_K[K1], K1, P_K, dp);
    int val2 = recursiveFunc(D1 - P_K[K1 - 1], K1 - 1, P_K, dp);

    // std::cout << "!!!h2" << std::endl;    

    if (val1 == -1 && val2 == -1) {
        dp[D1][K1] = -1;
        return dp[D1][K1];
    }

    // std::cout << "!!!h3" << std::endl;

    if (val1 == -1 || val2 == -1) {
        dp[D1][K1] = 1 + std::max(val1, val2);
        return dp[D1][K1];
    }

    // std::cout << "!!!h4" << std::endl;
    
    dp[D1][K1] = 1 + std::min(val1, val2);
    return dp[D1][K1];
}


int isPrime(int p) {
    // if (p == 2) {
    //     return 0;
    // }

    int rootval = sqrt(p);

    for (int i = 2; i <= rootval; i++) {
        if (p % i == 0) {
            return 1;
        }
    }

    return 0;
}


int main()
{
    int D, K;

    std::cin >> D;
    std::cin >> K;

    // 2d array
    int **dp = new int*[D+1];
    for (int i = 0; i < D+1; i++) {
        dp[i] = new int[K+1];
    }

    // dummy values
    for (int i = 0; i <= D; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = 0;
        }
    }

    // to store K prime numbers
    std::vector<int> P_K;
    P_K.push_back(0); // for index 0

    // fill P_K
    for (int num = 2, i = 0; ;num++) {
        if (isPrime(num) == 0) {
            P_K.push_back(num);

            i++;
            if (i == K) {
                break;
            }
        }
    }

    int i;
    for (i = K; i >= 1; i--) {
        if (P_K[i] <= D) {
            break;
        }
    }

    int ans = recursiveFunc(D, i, P_K, dp);

    std::cout << ans << std::endl;

}

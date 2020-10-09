/*
 * link ==> https://leetcode.com/problems/complement-of-base-10-integer/
 *
 */

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        int n = log2(N) + 1;
        int val = pow(2,n) - 1;
        return val - N;
    }
};

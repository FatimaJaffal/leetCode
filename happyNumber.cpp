class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum+=pow(n%10,2);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int> s;
        s.insert(n);
        int sum = n;
        while(true) {
          sum = getSum(sum);
          if(sum == 1) return true;
          if(s.count(sum)) return false;
          s.insert(sum);
        }
        return true;
    }
};

class Solution {
  public:
    bool isPalindrome(int x) {
      int y = x;
      long long int ans = 0;
      while (y != 0) {
        ans = (ans * 10) + y % 10;
        y = y / 10;
      }
      if (x < 0) {
        ans = (-ans);
      }
      return x == ans;

    }
};
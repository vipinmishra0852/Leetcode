class Solution
{
public:
  int addDigits(int num)
  { ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (num <= 9)
      return num;
    else
    {
      int sum = 0;
      while (num >= 1)
      {
        int q = num % 10;
        sum = sum + q;
        num = num / 10;
      }

      return addDigits(sum);
    }
  }
};
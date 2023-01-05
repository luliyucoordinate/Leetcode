class Solution {
 public:
  int solve(double a, double b, double c) {
    return floor((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
  }

  int maxValue(int n, int index, int maxSum) {
    double left = index;
    double right = n - index - 1.0;
    if (left > right) swap(left, right);

    double upper = left * (1.0 + left) + 1.0 + right;
    if (upper >= maxSum) {
      return solve(1, -2, left + right + 2 - maxSum);
    }

    double x = 1.0 + right;
    upper = (2.0 * x - left - 1.0) * left / 2.0 + (x * (x + 1.0)) / 2;
    if (upper >= maxSum) {
      return solve(0.5, left - 0.5,
                   right + 1.0 - (left + 1.0) * left / 2.0 - maxSum);
    }

    double a = left + right + 1.0;
    double b = (-left * left - left - right * right - right) / 2 - maxSum;
    return floor(-b / a);
  }
};
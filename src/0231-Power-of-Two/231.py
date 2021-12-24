class Solution:
  def isPowerOfTwo(self, n: int) -> bool:
    return False if n < 0 else bin(n).count('1') == 1
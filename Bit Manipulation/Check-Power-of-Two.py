class Solution:
  def solve(self, n):
    if not n:
      return False
    if n == 1:
      return True
    if n & 1:  # n is odd but not 1
      return False
    else:  # n is even
      return self.solve(n >> 1)

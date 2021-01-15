class Solution:
  def solve(self, n):
    current_run, longest_run = 0, 0
    while n:
      if n & 1:  # n is odd, last bit is set
        current_run += 1
      else:
        longest_run = max(longest_run, current_run)
        current_run = 0
      n >>= 1  # remove last bit
    return max(current_run, longest_run)

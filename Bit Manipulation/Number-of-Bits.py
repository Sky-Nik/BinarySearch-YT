class Solution:
  def solve(self, n):
    bit_count = 0
    while n:
      if n & 1:  # n is odd, last bit is set
        bit_count += 1
      n >>= 1  # remove last bit
    return bit_count

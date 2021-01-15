class Solution:
  def solve(self, x, y):
    hamming_distance = 0
    while x or y:
      if x & 1 != y & 1:  # x and y are of different parity, last bits are different
        hamming_distance += 1
      x >>= 1; y >>= 1  # remove last bits
    return hamming_distance

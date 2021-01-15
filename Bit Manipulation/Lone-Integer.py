class Solution:
  def solve(self, nums):
    bits_frequency = [0 for bit in range(30)]
    for num in nums:
      for bit in range(30):
        if num & (1 << bit):
          bits_frequency[bit] += 1

    unique = 0
    for bit in range(30):
      if bits_frequency[bit] % 3 == 1:
        unique |= 1 << bit
    return unique

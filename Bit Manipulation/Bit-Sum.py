class Solution:
  def solve(self, nums, k):
    bits_frequency = [0 for _ in range(30)]
    for num in nums:
      for bit in range(30):
        if num & (1 << bit):
          bits_frequency[bit] += 1

    for bit in range(30):
      off_bits = len(nums) - bits_frequency[bit]
      change = min(off_bits, k)
      bits_frequency[bit] += change
      k -= change

    return sum(bits_frequency[bit] << bit for bit in range(30)) % (10**9 + 7)

class Solution:
  def set_bits_count(self, n):
    bit_count = 0
    while n:
      if n & 1:  # n is odd, last bit is set
        bit_count += 1
      n >>= 1  # remove last bit
    return bit_count

  def solve(self, n):
    initial_set_bits_count = self.set_bits_count(n)

    first_set_bit = -1
    for i in range(32):
      if n & (1 << i):  # i-th bit of n is set
        first_set_bit = i
        break

    n += 1 << first_set_bit

    current_set_bits_count = self.set_bits_count(n)
    for i in range(32):
      if current_set_bits_count < initial_set_bits_count and not (n & (1 << i)):  # i-th bit of n is not set
        current_set_bits_count += 1
        n |= 1 << i  # set i-th bit of n
  
    return n

class Solution:
  def solve(self, start, end):
    bitwise_and = current = start
    while current <= end:
      for bit in range(30):
        if current & (1 << bit):
          current += 1 << bit
          break
      else:
        break

      if current <= end:
        bitwise_and &= current

    return bitwise_and

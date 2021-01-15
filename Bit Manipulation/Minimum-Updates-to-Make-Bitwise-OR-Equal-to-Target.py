class Solution:
  def solve(self, first, second, target):
    def cost(first_bit, second_bit, target_bit):
      if first_bit and second_bit and not target_bit:
        return 2
      if ((first_bit or second_bit) and not target_bit) or \
          (not first_bit and not second_bit and target_bit):
        return 1
      return 0

    return sum(cost(first & (1 << bit), second & (1 << bit), target & (1 << bit)) for bit in range(30))

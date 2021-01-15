class Solution:
  def solve(self, nums):
    possible_numbers = curent_numbers = {0}
    for num in nums:
      curent_numbers = {current_number | num for current_number in curent_numbers}
      curent_numbers.add(0)
      possible_numbers |= curent_numbers

    if 0 not in nums:
      return len(possible_numbers) - 1
    else:
      return len(possible_numbers)

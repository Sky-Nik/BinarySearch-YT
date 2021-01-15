class Solution:
  def solve(self, num):
    answer = 0
    while num:
      answer ^= num
      num >>= 1
    return answer

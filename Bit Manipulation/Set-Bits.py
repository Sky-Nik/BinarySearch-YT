class Solution:
  cached_answers = {0: 0, 1: 1} 

  def solve(self, n):
    if n not in self.cached_answers:
      k = n >> 1
      if n & 1:  # n is odd, n = 2k + 1
        self.cached_answers[n] = 2 * self.solve(k) + k + 1
      else:  # n is even, n = 2k
        self.cached_answers[n] = self.solve(k) + self.solve(k - 1) + k
    return self.cached_answers[n]

class Solution:
  def solve(self, nums, queries):
    prefix_xors = [0];
    for num in nums:
      prefix_xors.append(prefix_xors[-1] ^ num)

    return [prefix_xors[query[1] + 1] ^ prefix_xors[query[0]] for query in queries]

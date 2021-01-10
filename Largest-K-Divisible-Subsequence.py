class Solution:
  def solve(self, array, modulo):
    length = len(array)

    dp = [[-1 for _ in range(modulo)] for _ in range(length + 1)]
    dp[0][0] = 0

    for index in range(length):
      dp[index + 1] = dp[index][:]

      for remainder in range(modulo):
        if dp[index][remainder] != -1:
          dp[index + 1][(remainder + array[index]) % modulo] = \
            max(dp[index + 1][(remainder + array[index]) % modulo],
                dp[index][remainder] + array[index])

    return dp[length][0]

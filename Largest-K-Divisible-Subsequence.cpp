const int kImpossible = -1;

int solve(std::vector<int>& array, int modulo) {
  const int length = array.size();

  // dp[prefix length][remainder] = maximum sum
  //   of a subsequence of a given prefix with given modulo remainder
  std::vector<std::vector<int64_t>> dp(length + 1,
    std::vector<int64_t>(modulo, kImpossible));
  dp[0][0] = 0;

  for (int index = 0; index < length; ++index) {
    // if we do NOT take array[index] into subsequence sum
    std::copy(dp[index].begin(), dp[index].end(), dp[index + 1].begin());

    // if we DO take array[index] into subsequence sum
    for (int remainder = 0; remainder < modulo; ++remainder) {
      if (dp[index][remainder] != kImpossible) {
        dp[index + 1][(remainder + array[index]) % modulo] =
          std::max(dp[index + 1][(remainder + array[index]) % modulo],
                   dp[index][remainder] + array[index]);
      }
    }
  }

  // maximum sum of a subsequence of an entire array divisible by modulo
  return dp[length][0];
}

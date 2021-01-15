std::unordered_map<int, int> cached_answers = {{0, 0}, {1, 1}};

int solve(int n) {
  if (!cached_answers.count(n)) {
    const int k = n >> 1;
    if (n & 1) {  // n is odd, n = 2k + 1
      cached_answers[n] = 2 * solve(k) + k + 1;
    } else {  // n is even, n = 2k
      cached_answers[n] = solve(k) + solve(k - 1) + k;
    }
  }
  return cached_answers[n];
}

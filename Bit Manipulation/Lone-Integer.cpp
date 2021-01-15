int solve(std::vector<int>& nums) {
  std::vector<int> bits_frequency(30);
  for (int num : nums) {
    for (int bit = 0; bit < 30; ++bit) {
      if (num & (1 << bit)) {
        ++bits_frequency[bit];
      }
    }
  }

  int unique = 0;
  for (int bit = 0; bit < 30; ++bit) {
    if (bits_frequency[bit] % 3 == 1) {
      unique |= 1 << bit;
    }
  }
  return unique;
}

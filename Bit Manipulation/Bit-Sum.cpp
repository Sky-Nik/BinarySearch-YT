int solve(std::vector<int>& nums, int k) {
  std::vector<int> bits_frequency(30);
  for (int num : nums) {
    for (int bit = 0; bit < 30; ++bit) {
      if (num & (1 << bit)) {
        ++bits_frequency[bit];
      }
    }
  }

  const int length = nums.size(); 
  for (int bit = 0; bit < 30; ++bit) {
    const int off_bits = length - bits_frequency[bit];
    const int change = std::min(off_bits, k);
    bits_frequency[bit] += change;
    k -= change;
  }

  int64_t sum = 0;
  for (int bit = 0; bit < 30; ++bit) {
    sum += (int64_t)bits_frequency[bit] << bit;
  }
  return sum % 1'000'000'007;
}

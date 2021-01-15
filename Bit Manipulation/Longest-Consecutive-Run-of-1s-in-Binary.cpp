int solve(int n) {
  int current_run = 0, longest_run = 0;
  while (n) {
    if (n & 1) {  // n is odd, last bit is set
      ++current_run;
    } else {
      longest_run = std::max(longest_run, current_run);
      current_run = 0;
    }
    n >>= 1;  // remove last bit
  }
  return std::max(current_run, longest_run);
}

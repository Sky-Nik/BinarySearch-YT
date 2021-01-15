int solve(int n) {
  int bit_count = 0;
  while (n) {
    if (n & 1) {  // n is odd, last bit is set
      ++bit_count;
    }
    n >>= 1;  // remove last bit
  }
  return bit_count;
}

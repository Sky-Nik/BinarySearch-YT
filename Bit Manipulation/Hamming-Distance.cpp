int solve(int first, int second) {
  int hamming_distance = 0;
  while (first || second) {
    if (first & 1 != second & 1) {  // numbers are of different parity, last bits are different
      ++hamming_distance;
    }
    first >>= 1; second >>= 1;  // remove last bits
  }
  return hamming_distance;
}

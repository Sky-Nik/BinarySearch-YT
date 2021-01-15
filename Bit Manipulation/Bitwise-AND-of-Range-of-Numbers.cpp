int solve(int start, int end) {
  int bitwise_and = start, current = start;
  while (current <= end) {
    current += 1 << __builtin_ctz(current);
    if (current <= end) {
      bitwise_and &= current;
    }
  }
  return bitwise_and;
}
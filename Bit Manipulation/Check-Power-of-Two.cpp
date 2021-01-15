bool solve(int n) {
  if (!n) {
    return false;
  } else if (n == 1) {
    return true;
  } else if (n & 1) {  // n is odd but not 1
    return false;
  } else {  // n is even
    return solve(n >> 1);
  }
}

int set_bits_count(int n) {
  int bit_count = 0;
  while (n) {
    if (n & 1) {  // n is odd, last bit is set
      ++bit_count;
    }
    n >>= 1;  // remove last bit
  }
  return bit_count;
}

int solve(int n) {
  const int initial_set_bits_count = set_bits_count(n);

  int first_set_bit = -1;
  for (int i = 0; i < 32; ++i) {
    if (n & (1 << i)) {  // i-th bit of n is set
      first_set_bit = i;
      break;
    }
  }

  n += 1 << first_set_bit;

  int current_set_bits_count = set_bits_count(n);
  for (int i = 0; i < 32; ++i) {
    if (current_set_bits_count < initial_set_bits_count && !(n & (1 << i))) {  // i-th bit of n is not set
      ++current_set_bits_count;
      n |= 1 << i;  // set i-th bit of n
    }
  }

  return n;
}

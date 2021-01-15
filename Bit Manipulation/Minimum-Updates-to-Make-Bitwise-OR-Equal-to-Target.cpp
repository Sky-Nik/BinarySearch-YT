int solve(int first, int second, int target) {
  int updates = 0;

  for (int bit = 0; bit < 30; ++bit) {
    const int first_bit = first & (1 << bit),
      second_bit = second & (1 << bit),
      target_bit = target & (1 << bit);
    
    if (target_bit) {
      if (!first_bit && !second_bit) {
        ++updates;
      }
    } else {
      if (first_bit && second_bit) {
        updates += 2;
      } else if (first_bit || second_bit) {
        ++updates;
      }
    }
  }

  return updates;
}

int solve(int num) {
  int answer = 0;
  while (num) {
    answer ^= num;
    num >>= 1;
  }
  return answer;
}

int solve(std::vector<int>& nums) {
  std::unordered_set<int> possible_numbers = {0}, current_numbers = {0};
  for (int num : nums) {
    std::unordered_set<int> new_numbers = {0};
    for (int current_number : current_numbers) {
      new_numbers.insert(current_number | num);
    }
    current_numbers = new_numbers;
    for (auto current_number : current_numbers) {
      possible_numbers.insert(current_number);
    }
  }

  const int possible_numbers_count = possible_numbers.size();
  if (std::find(nums.begin(), nums.end(), 0) == nums.end()) {
    return possible_numbers_count - 1;
  } else {
    return possible_numbers_count;
  }
}
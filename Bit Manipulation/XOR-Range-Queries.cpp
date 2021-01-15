vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) {
  std::vector<int> prefix_xors = {0};
  prefix_xors.reserve(nums.size() + 1);
  for (int num : nums) {
    prefix_xors.push_back(prefix_xors.back() ^ num);
  }

  std::vector<int> answers;
  answers.reserve(queries.size());
  for (const auto& query : queries) {
    answers.push_back(prefix_xors[query[1] + 1] ^ prefix_xors[query[0]]);
  }
  return answers;
}

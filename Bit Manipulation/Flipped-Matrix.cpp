int solve(std::vector<std::vector<int>>& matrix) {
  int row_count = matrix.size(), column_count = matrix[0].size();

  for (auto& row : matrix) {
    if (!row[0]) {  // leading bit is off
      for (auto& column : row) {
        column ^= 1;  // flip the entire row
      }
    }
  }

  int result = 0;
  for (int column = 0; column < column_count; ++column) {
    result <<= 1;
    int column_sum = 0;
    for (int row = 0; row < row_count; ++row) {
      column_sum += matrix[row][column];
    }
    result += std::max(column_sum, row_count - column_sum);
  }

  return result;
}

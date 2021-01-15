class Solution:
  def solve(self, matrix):
    row_count, column_count = len(matrix), len(matrix[0])

    for row in matrix:
      if not row[0]:  # leading bit is off
        for column in range(column_count):
          row[column] ^= 1  # flip the entire row

    result = 0
    for column in zip(*matrix):  # python-specific trick to get transpose
      result <<= 1
      result += max(sum(column), row_count - sum(column))

    return result


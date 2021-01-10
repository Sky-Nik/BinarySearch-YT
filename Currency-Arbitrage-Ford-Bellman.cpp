template <typename T> 
using Matrix = std::vector<std::vector<T>>;

template <typename DistanceType>
std::vector<DistanceType> FordBellman(const Matrix<DistanceType>& distance_matrix, int source = 0);

bool solve(Matrix<double>& matrix) {
  const int currencies_number = matrix.size();

  // build distance matrix out of negative logarithms
  Matrix<long double> distance_matrix(currencies_number,
                                      std::vector<long double>(currencies_number));
  for (int source_currency = 0; source_currency < currencies_number; ++source_currency) {
    for (int destination_currency = 0; destination_currency < currencies_number;
         ++destination_currency) {
      distance_matrix[source_currency][destination_currency] =
        -std::log(matrix[source_currency][destination_currency]);
    }
  }

  // Ford-Bellman algorithm to find shortest paths from source to all vertices in O(VE)
  const auto shortest_distances = FordBellman(distance_matrix);

  // if we can still improve distances then there is a negative cycle
  for (int source_currency = 0; source_currency < currencies_number; ++source_currency) {
    for (int destination_currency = 0; destination_currency < currencies_number;
         ++destination_currency) {
      if (shortest_distances[destination_currency] >
        shortest_distances[source_currency] +
          distance_matrix[source_currency][destination_currency]) {
        return true;
      }
    }
  }

  // otherwise we can't
  return false;
}

template <typename DistanceType>
std::vector<DistanceType> FordBellman(const Matrix<DistanceType>& distance_matrix, int source) {
  const int vertex_number = distance_matrix.size();
  std::vector<DistanceType> shortest_distances(distance_matrix[0]);

  // iterations
  const int iteration_number = vertex_number;
  bool something_changed = true;
  for (int iteration = 0; iteration < iteration_number && something_changed; ++iteration) {
    something_changed = false;
    for (int source_vertex = 0; source_vertex < vertex_number; ++source_vertex) {
      for (int destination_vertex = 0; destination_vertex < vertex_number; ++destination_vertex) {
        const auto distance = shortest_distances[source_vertex] +
                              distance_matrix[source_vertex][destination_vertex];
        if (shortest_distances[destination_vertex] > distance) {
          shortest_distances[destination_vertex] = distance;
          something_changed = true;
        }
      }
    }
  }

  return shortest_distances;
}

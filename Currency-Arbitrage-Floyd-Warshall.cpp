template <typename T> 
using Matrix = std::vector<std::vector<T>>;

// pass by value because we need it as our initial state
template <typename DistanceType>
Matrix<DistanceType> FloydWarshall(Matrix<DistanceType> distance_matrix);

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

  // Floyd-Warshall algorithm to find shortest paths between all pairs of vertices in O(V^3)
  const auto shortest_distances = FloydWarshall(distance_matrix);

  // check if there is a negative cycle
  for (int currency = 0; currency < currencies_number; ++currency) {
    if (shortest_distances[currency][currency] < 0) {
      return true;
    }
  }
  return false;
}

template <typename DistanceType>
Matrix<DistanceType> FloydWarshall(Matrix<DistanceType> distance_matrix){
  const int vertex_number = distance_matrix.size();

  // iterations
  for (int middle_vertex = 0; middle_vertex < vertex_number; ++middle_vertex) {
    for (int source_vertex = 0; source_vertex < vertex_number; ++source_vertex) {
      for (int destination_vertex = 0; destination_vertex < vertex_number; ++destination_vertex) {
        const auto distance = distance_matrix[source_vertex][middle_vertex] +
                              distance_matrix[middle_vertex][destination_vertex];
        if (distance_matrix[source_vertex][destination_vertex] > distance) {
          distance_matrix[source_vertex][destination_vertex] = distance;
        }
      }
    }
  }

  return distance_matrix;
}

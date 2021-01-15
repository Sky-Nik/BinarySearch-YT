using Vertex = int;
const Vertex kFictitious = -1;
using Edge = std::pair<Vertex, Vertex>;
using Graph = std::vector<std::vector<Vertex>>;

void BridgeDepthFirstSearch(const Graph& graph, std::unordered_set<Vertex>* used_ptr,
                            std::unordered_map<Vertex, int>* time_in_ptr,
                            std::unordered_map<Vertex, int>* func_up_ptr,
                            std::vector<Edge>* bridges_ptr, Vertex vertex, int* timer_ptr,
                            Vertex parent = kFictitious);

std::vector<Edge> FindBridges(const Graph& graph);

int solve(Graph& graph) {
  return FindBridges(graph).size();
}

void BridgeDepthFirstSearch(const Graph& graph, std::unordered_set<Vertex>* used_ptr,
                            std::unordered_map<Vertex, int>* time_in_ptr,
                            std::unordered_map<Vertex, int>* func_up_ptr,
                            std::vector<Edge>* bridges_ptr, Vertex vertex, int* timer_ptr,
                            Vertex parent) {
  used_ptr->insert(vertex);
  (*time_in_ptr)[vertex] = (*func_up_ptr)[vertex] = (*timer_ptr)++;
  for (auto adjacent : graph[vertex]) {
    if (adjacent == parent) {  // tree edge traversed backwards
      continue;
    }

    if (used_ptr->count(adjacent)) {  // back edge
      (*func_up_ptr)[vertex] = std::min((*func_up_ptr)[vertex], (*time_in_ptr)[adjacent]);
    } else {  // tree edge
      BridgeDepthFirstSearch(graph, used_ptr, time_in_ptr, func_up_ptr, bridges_ptr, adjacent,
                             timer_ptr, vertex);
      (*func_up_ptr)[vertex] = std::min((*func_up_ptr)[vertex], (*func_up_ptr)[adjacent]);
      if ((*func_up_ptr)[adjacent] > (*time_in_ptr)[vertex]) {
        bridges_ptr->emplace_back(vertex, adjacent);
      }
    }
  }
}

std::vector<Edge> FindBridges(const Graph& graph) {
  int timer = 0;
  std::unordered_set<Vertex> used;
  std::unordered_map<Vertex, int> time_in;
  std::unordered_map<Vertex, int> func_up;
  /* func_up[vertex] = min (
   *   time_in[vertex], 
   *   time_in[ancestor], for all (vertex, ancestor) - back edge,
   *   func_up[adjacent], for all (vertex, adjacent) - tree edge.
   * )
   */
  std::vector<Edge> bridges;


  const int kVertexNumber = graph.size();
  for (auto vertex = 0; vertex < kVertexNumber; ++vertex) {
    if (!used.count(vertex)) {
      BridgeDepthFirstSearch(graph, &used, &time_in, &func_up, &bridges, vertex, &timer);
    }
  }

  return bridges;
}

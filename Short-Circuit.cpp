using LetterGraph = std::unordered_map<char, std::string>;

void DepthFirstSearch(const LetterGraph& letter_graph,
                      std::unordered_set<char>* visited_letters_ptr, char letter);

bool IsConnected(const LetterGraph& letter_graph);

bool HasEulerianCycle(const LetterGraph& letter_graph);

bool solve(std::vector<std::string>& words) {
  // build letter graph
  LetterGraph letter_graph;
  for (const auto& word : words) {
    const auto length = word.length();
    const auto first_letter = word[0], last_letter = word[length - 1];
    letter_graph[first_letter] += last_letter;
  }

  return HasEulerianCycle(letter_graph);
}

void DepthFirstSearch(const LetterGraph& letter_graph,
                      std::unordered_set<char>* visited_letters_ptr, char letter) {
  visited_letters_ptr->insert(letter);
  if (letter_graph.count(letter)) {
    for (auto adjacent_letter : letter_graph.at(letter)) {
      if (!visited_letters_ptr->count(adjacent_letter)) {
        DepthFirstSearch(letter_graph, visited_letters_ptr, adjacent_letter);
      }
    }
  }
}

bool IsConnected(const LetterGraph& letter_graph) {
  std::unordered_set<char> visited_letters;
  DepthFirstSearch(letter_graph, &visited_letters, letter_graph.begin()->first);
  return visited_letters.size() == letter_graph.size();
}

bool HasEulerianCycle(const LetterGraph& letter_graph) {
  std::unordered_map<char, int> in_degree, out_degree;
  for (const auto& [letter, adjacent_letters] : letter_graph) {
    for (auto adjacent_letter : adjacent_letters) {
      ++out_degree[letter], ++in_degree[adjacent_letter];
    }
  }
  return IsConnected(letter_graph) && in_degree == out_degree;
}

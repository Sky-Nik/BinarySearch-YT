template <unsigned int N = 30> 
class BitTrie {
  private:
    struct Node {
      std::unique_ptr<Node> zero_child, one_child;
    };

  public:
    void Insert(int number, Node* node = nullptr, int offset = N) {
      if (!node) {
        node = root_.get();
      }
      while (offset >= 0) {
        if (number & (1ll << offset)) {
          if (!node->one_child) {
            node->one_child = std::make_unique<Node>();
          }
          node = node->one_child.get();
        } else {
          if (!node->zero_child) {
            node->zero_child = std::make_unique<Node>();
          }
          node = node->zero_child.get();
        }
        --offset;
      }
    }

    int FindMaximumXor(int number, Node* node = nullptr, int offset = N) {
      if (!node) {
        node = root_.get();
      }
      int answer = 0;
      while (offset >= 0) {
        if (number & (1ll << offset)) {
          if (node->zero_child) {
            node = node->zero_child.get();
          } else if (node->one_child) {
            answer |= 1ll << offset;
            node = node->one_child.get();
          } else {
            return -1;
          }
        } else {
          if (node->one_child) {
            node = node->one_child.get();
            answer |= 1ll << offset;
          } else if (node->zero_child) {
            node = node->zero_child.get();
          } else {
            return -1;
          }
        }
        --offset;
      }
      return answer;
    }

  private:
    std::unique_ptr<Node> root_ = std::make_unique<Node>();
};

int solve(std::vector<int>& nums) {
  BitTrie bit_trie;
  for (auto num : nums) {
    bit_trie.Insert(num);
  }
  int max_xor = 0;
  for (auto num : nums) {
    max_xor = std::max(max_xor, num ^ bit_trie.FindMaximumXor(num));
  }
  return max_xor;
}

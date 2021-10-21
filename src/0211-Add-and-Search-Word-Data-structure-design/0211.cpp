#include <memory>
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
  TrieNode() {
    this->child_ = vector<shared_ptr<TrieNode>>(26);
    this->is_end_ = false;
  }

  vector<shared_ptr<TrieNode>> child_;
  bool is_end_;
};

class WordDictionary {
 public:
  WordDictionary() : trie_(make_shared<TrieNode>()) {}

  void addWord(const string& word) {
    auto node = trie_;
    for (auto c : word) {
      if (!node->child_[c - 'a']) {
        node->child_[c - 'a'] = make_shared<TrieNode>();
      }
      node = node->child_[c - 'a'];
    }
    node->is_end_ = true;
  }

  bool search(const string& word) { return dfs(word, 0, trie_); }

  bool dfs(const string& word, uint32_t index,
           const shared_ptr<TrieNode>& node) {
    if (index == word.size()) {
      return node->is_end_;
    }

    char ch = word[index];
    if (ch >= 'a' && ch <= 'z') {
      auto child = node->child_[ch - 'a'];
      if (child && dfs(word, index + 1, child)) {
        return true;
      }
    } else if (ch == '.') {
      for (uint32_t i = 0; i < 26; i++) {
        auto child = node->child_[i];
        if (child && dfs(word, index + 1, child)) {
          return true;
        }
      }
    }
    return false;
  }

 protected:
  shared_ptr<TrieNode> trie_;
};

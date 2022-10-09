#include <string>
#include <vector>

struct TrieNode
{
  bool isEnd;
  std::vector<TrieNode*> children;
  TrieNode()
  {
    isEnd = false;
    children.reserve(26);
  }
};

class Trie
{
  TrieNode* root;
  Trie() { root = new TrieNode(); }

  void insert(std::string s)
  {
    TrieNode* curr = root;
    for (char c : s)
    {
      int idx = c - 'a';
      if (curr->children[idx] == nullptr)
      {
        curr->children[idx] = new TrieNode();
      }
      curr = curr->children[idx];
    }
    curr->isEnd = true;
  }

  bool search(std::string s)
  {
    TrieNode* curr = root;
    for (char c : s)
    {
      int idx = c - 'a';
      if (curr->children[idx] == nullptr)
      {
        return false;
      }
      curr = curr->children[idx];
    }
    return curr->isEnd;
  }

  bool startsWith(std::string s)
  {
    TrieNode* curr = root;
    for (char c : s)
    {
      int idx = c - 'a';
      if (curr->children[idx] == nullptr)
      {
        return false;
      }
      curr = curr->children[idx];
    }
    return true;
  }
};

#include <string>

using namespace std;

#define ALPHABET_SIZE 26

typedef struct trie_node {
    int count;
    trie_node *children[ALPHABET_SIZE];
} *trie;

trie_node *create_trie_node() {
    auto *pNode = new trie_node();
    pNode->count = 0;
    for (auto &i : pNode->children)
        i = nullptr;
    return pNode;
}

void trie_insert(trie root, char *key) {
    trie_node *node = root;
    char *p = key;
    while (*p) {
        if (node->children[*p - 'a'] == nullptr)
            node->children[*p - 'a'] = create_trie_node();
        node = node->children[*p - 'a'];
        ++p;
    }
    node->count += 1;
}

int trie_search(trie root, char *key) {
    trie_node *node = root;
    char *p = key;
    while (*p && node != nullptr) {
        node = node->children[*p - 'a'];
        ++p;
    }
    if (node == nullptr) return 0;
    else return node->count;
}

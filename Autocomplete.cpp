#include "Autocomplete.h"

std::string Autocomplete::toLowerLetters(const std::string& s) {
    std::string t;
    t.reserve(s.size());
    for (char c : s) {
        if (isLetter(c)) t.push_back(std::tolower(static_cast<unsigned char>(c)));
        else return "";
    }
    return t;
}

void Autocomplete::insert(const std::string& word) {
    std::string w = toLowerLetters(word);
    if (w.empty()) return;

    Node* cur = root;
    for (char c : w) {
        int j = idx(c);
        if (!cur->next[j]) cur->next[j] = new Node();
        cur = cur->next[j];
    }
    cur->isWord = true;
}

const Autocomplete::Node* Autocomplete::seek(const std::string& normalizedPrefix) const {
    const Node* cur = root;
    for (char c : normalizedPrefix) {
        int j = idx(c);
        if (j < 0 || j >= 26 || !cur->next[j]) return nullptr;
        cur = cur->next[j];
    }
    return cur;
}

void Autocomplete::collect(const Node* node, std::string& prefix, std::vector<std::string>& out) const {
    if (!node) return;
    if (node->isWord) out.push_back(prefix);
    for (int j = 0; j < 26; ++j) {
        if (node->next[j]) {
            prefix.push_back('a' + j);
            collect(node->next[j], prefix, out);
            prefix.pop_back();
        }
    }
}

std::vector<std::string> Autocomplete::getSuggestions(const std::string& partialWord) const {
    std::vector<std::string> res;
    std::string p = toLowerLetters(partialWord);
    if (p.empty()) return res;

    const Node* node = seek(p);
    if (!node) return res;

    std::string prefix = p;
    collect(node, prefix, res);
    return res;
}

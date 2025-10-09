#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <array>
#include <string>
#include <vector>
#include <cctype>

class Autocomplete {
public:
    void insert(const std::string& word);
    std::vector<std::string> getSuggestions(const std::string& partialWord) const;

private:
    struct Node {
        bool isWord = false;
        std::array<Node*, 26> next;
        Node() { next.fill(nullptr); }
    };

    Node* root = new Node();

    static inline int idx(char c) { return std::tolower(static_cast<unsigned char>(c)) - 'a'; }
    static inline bool isLetter(char c) { c = std::tolower(static_cast<unsigned char>(c)); return c >= 'a' && c <= 'z'; }

    static std::string toLowerLetters(const std::string& s);
    const Node* seek(const std::string& normalizedPrefix) const;
    void collect(const Node* node, std::string& prefix, std::vector<std::string>& out) const;
};

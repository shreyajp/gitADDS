#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <array>
#include <string>

class PrefixMatcher {
public:
    void insert(const std::string& address, int routerNumber);
    int selectRouter(const std::string& networkAddress) const;

private:
    struct Node {
        std::array<Node*, 2> children;
        bool hasRouter = false;
        int routerNumber = -1;
        Node() { children.fill(nullptr); }
    };

    Node* root = new Node();

    static inline bool isBit(char c) { return c == '0' || c == '1'; }
    static inline int bidx(char c) { return c - '0'; }
};

#endif 

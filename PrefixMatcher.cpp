#include "PrefixMatcher.h"

void PrefixMatcher::insert(const std::string& address, int routerNumber) {
    if (address.empty()) return;
    Node* cur = root;
    for (char c : address) {
        if (!isBit(c)) return;
        int j = bidx(c);
        if (!cur->children[j]) cur->children[j] = new Node();
        cur = cur->children[j];
    }
    cur->hasRouter = true;
    cur->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(const std::string& networkAddress) const {
    const Node* cur = root;
    int best = -1;
    if (cur->hasRouter) best = cur->routerNumber;

    for (char c : networkAddress) {
        if (!isBit(c)) break;
        int j = bidx(c);
        if (!cur->children[j]) break;
        cur = cur->children[j];
        if (cur->hasRouter) best = cur->routerNumber;
    }
    return best;
}

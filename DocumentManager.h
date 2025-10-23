#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class DocumentManager {
private:
    struct Document {
        string name;
        int id;
        int licenseLimit;
        int currentBorrowed;
        
        Document() : name(""), id(0), licenseLimit(0), currentBorrowed(0) {}
        Document(string n, int i, int l) : name(n), id(i), licenseLimit(l), currentBorrowed(0) {}
    };
    
    unordered_map<int, Document> documentsById;
    unordered_map<string, int> documentsByName;
    unordered_set<int> patrons;
    unordered_map<int, unordered_set<int>> borrowedBy;

public:
    void addDocument(string name, int id, int license_limit);
    void addPatron(int patronID);
    int search(string name);
    bool borrowDocument(int docId, int patronID);
    void returnDocument(int docId, int patronID);
};

#endif
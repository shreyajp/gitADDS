#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>

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
    void addDocument(string name, int id, int license_limit) {
        Document doc(name, id, license_limit);
        documentsById[id] = doc;
        documentsByName[name] = id;
    }
    
    void addPatron(int patronID) {
        patrons.insert(patronID);
    }
    

    int search(string name) {
        auto it = documentsByName.find(name);
        if (it != documentsByName.end()) {
            return it->second;
        }
        return 0;
    }
    

    bool borrowDocument(int docId, int patronID) {
        if (patrons.find(patronID) == patrons.end()) {
            return false;
        }
        
        if (documentsById.find(docId) == documentsById.end()) {
            return false;
        }
        
        Document& doc = documentsById[docId];
        
        if (borrowedBy[docId].find(patronID) != borrowedBy[docId].end()) {
            return false; 
        }
        
        if (doc.currentBorrowed >= doc.licenseLimit) {
            return false; 
        }
        
        doc.currentBorrowed++;
        borrowedBy[docId].insert(patronID);
        return true;
    }
    
    void returnDocument(int docId, int patronID) {
        if (documentsById.find(docId) == documentsById.end()) {
            return;
        }
        
        if (borrowedBy[docId].find(patronID) == borrowedBy[docId].end()) {
            return; 
        }
        
        Document& doc = documentsById[docId];
        doc.currentBorrowed--;
        borrowedBy[docId].erase(patronID);
    }
};
#include "DocumentManager.h"

void DocumentManager::addDocument(string name, int id, int license_limit) {
    Document doc(name, id, license_limit);
    documentsById[id] = doc;
    documentsByName[name] = id;
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
}

int DocumentManager::search(string name) {
    auto it = documentsByName.find(name);
    if (it != documentsByName.end()) {
        return it->second;
    }
    return 0;
}

bool DocumentManager::borrowDocument(int docId, int patronID) {
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

void DocumentManager::returnDocument(int docId, int patronID) {
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
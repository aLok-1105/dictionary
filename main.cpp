#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class TrieNode {
    public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    string meaning;

    TrieNode() {
        isEndOfWord = false;
        meaning = "";
    }
};

class Trie {
private:
    TrieNode* root;

    void destroyTrie(TrieNode* node) {
        if (node == nullptr) {
            return;
        }

        for (const auto& pair : node->children) {
            destroyTrie(pair.second);
        }

        delete node;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        destroyTrie(root);
    }

    void insert(const string& word, const string& meaning) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
        current->meaning = meaning;
    }

    string search(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return "Word not found!";
            }
            current = current->children[c];
        }
        if (current->isEndOfWord) {
            return current->meaning;
        }
        return "Word not found!";
    }

    void autocompleteHelper(TrieNode* node, string prefix, vector<string>& suggestions) {
        if (node->isEndOfWord) {
            suggestions.push_back(prefix);
        }

        for (const auto& pair : node->children) {
            autocompleteHelper(pair.second, prefix + pair.first, suggestions);
        }
    }

    vector<string> autocomplete(const string& prefix) {
        TrieNode* current = root;
        vector<string> suggestions;

        for (char c : prefix) {
            if (current->children.find(c) == current->children.end()) {
                return suggestions;
            }
            current = current->children[c];
        }

        autocompleteHelper(current, prefix, suggestions);
        return suggestions;
    }

    void remove(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return;
            }
            current = current->children[c];
        }

        current->isEndOfWord = false;
        current->meaning = "";
    }

    void clear() {
        destroyTrie(root);
        root = new TrieNode();
    }

    void collectWordsAndMeanings(TrieNode* node, string currentWord, vector<pair<string, string>>& wordsAndMeanings) {
        if (node->isEndOfWord) {
            wordsAndMeanings.push_back(make_pair(currentWord, node->meaning));
        }

        for (const auto& pair : node->children) {
            collectWordsAndMeanings(pair.second, currentWord + pair.first, wordsAndMeanings);
        }
    }

    TrieNode* getRoot() const {
        return root;
    }
};

const char *longString = R""""(
      __...--~~~~~-._   _.-~~~~~--...__
    //               `V'               \\ 
   //                 |                 \\ 
  //__...--~~~~~~-._  |  _.-~~~~~~--...__\\ 
 //__.....----~~~~._\ | /_.~~~~----.....__\\
====================\\|//====================
                    `---`
)"""";

void displayMenu() {

    cout<<longString<<endl;

    cout << "===== MENU =====" << endl;
    cout << "1. Add word" << endl;
    cout << "2. Remove word" << endl;
    cout << "3. Search word" << endl;
    cout << "4. Autocomplete suggestions" << endl;
    cout << "5. Show dictionary" << endl;
    cout << "6. Clear dictionary" << endl;
    cout << "7. Exit" << endl;
    cout << "================" << endl;
}

void showDictionarySorted(Trie& dictionary) {
    vector<pair<string, string>> wordsAndMeanings;
    dictionary.collectWordsAndMeanings(dictionary.getRoot(), "", wordsAndMeanings);
    sort(wordsAndMeanings.begin(), wordsAndMeanings.end());

    cout << "===== DICTIONARY =====" << endl;
    for (const auto& pair : wordsAndMeanings) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "=======================" << endl;
}

int main() {
    Trie dictionary;

    dictionary.insert("cat", "A small domesticated carnivorous mammal with soft fur, a short snout, and retractable claws.");
    dictionary.insert("dog", "A domesticated mammal of the family Canidae, known for its loyalty and as a popular pet.");
    dictionary.insert("book", "A written or printed work consisting of pages glued or sewn together and bound in covers.");
    dictionary.insert("computer", "An electronic device capable of performing various tasks, such as data processing and calculations.");
    dictionary.insert("tree", "A large perennial plant with a single main stem and many branches, typically found in nature.");

    int choice;
    string word, meaning;
    string prefix;
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the word: ";
                cin >> word;
                cout << "Enter the meaning: ";
                cin.ignore();
                getline(cin, meaning);
                dictionary.insert(word, meaning);
                cout << "Word added successfully!" << endl;
                break;

            case 2:
                cout << "Enter the word to remove: ";
                cin >> word;
                dictionary.remove(word);
                cout << "Word removed successfully!" << endl;
                break;

            case 3:
                cout << "Enter the word to search: ";
                cin >> word;
                cout << "Meaning: " << dictionary.search(word) << endl;
                break;

            case 4:
                cout << "Enter the prefix: ";
                cin >> prefix;
                cout << "Autocomplete suggestions:" << endl;
                {
                    vector<string> suggestions = dictionary.autocomplete(prefix);
                    for (const string& suggestion : suggestions) {
                        cout << suggestion << endl;
                    }
                }
                break;

            case 5:
                showDictionarySorted(dictionary);
                break;

            case 6:
                dictionary.clear();
                cout << "Dictionary cleared successfully!" << endl;
                break;

            case 7:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}

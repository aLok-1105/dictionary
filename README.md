# Dictionary Management System with Trie Data Structure
![C++ Logo](https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/30px-ISO_C%2B%2B_Logo.svg.png) &nbsp;&nbsp;
![VS Code Logo](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9a/Visual_Studio_Code_1.35_icon.svg/30px-Visual_Studio_Code_1.35_icon.svg.png)

## Overview
This project implements a Dictionary Management System using the Trie data structure in C++. The system allows users to add, search, and remove words along with their meanings. It also provides autocomplete suggestions based on a given prefix. The dictionary is stored in memory using the Trie data structure, allowing for efficient insertion, search, and retrieval of words and their meanings.

## Features
#### <li> TrieNode Class:
The TrieNode class represents a node in the Trie data structure.
It contains an unordered map children to store child nodes, each associated with a character.
The isEndOfWord flag indicates whether the node represents the end of a word.
The meaning variable holds the meaning associated with the word (if it is the end of a word).

#### <li> Trie Class:
The Trie class is the main class that utilizes TrieNode to create and manage the Trie structure.
It supports methods for insertion, search, autocomplete suggestions, removal, and clearing of the dictionary.

#### <li> Adding Words and Meanings:
Users can add words and their meanings to the dictionary using the insert method.

#### <li> Searching Words:
Users can search for the meaning of a word in the dictionary using the search method.

#### <li> Autocomplete Suggestions:
The system provides autocomplete suggestions based on a given prefix using the autocomplete method.

#### <li> Removing Words:
Users can remove words and their meanings from the dictionary using the remove method.

#### <li> Clearing the Dictionary:
Users can clear the entire dictionary using the clear method.

#### <li> Displaying the Dictionary:
The dictionary can be displayed in sorted order (lexicographically) using the showDictionarySorted method.

## Usage
```C++
      __...--~~~~~-._   _.-~~~~~--...__
    //               `V'               \\ 
   //                 |                 \\ 
  //__...--~~~~~~-._  |  _.-~~~~~~--...__\\ 
 //__.....----~~~~._\ | /_.~~~~----.....__\\
====================\\|//====================
                    `---`
===== MENU =====
1. Add word
2. Remove word
3. Search word
4. Autocomplete suggestions
5. Show dictionary
6. Clear dictionary
7. Exit
================
Enter your choice:
```

## Contributing
If you wish to contribute to this project, you can:<br>
Optimize the Trie data structure for improved memory or time efficiency.<br>
Implement additional features, such as updating word meanings or supporting multiple languages.<br>
Improve the user interface for a better user experience.

#include <iostream>
#include <string.h>


struct Node {

    char letter;
    bool leaf;
    Node* children[26];

  

    Node(char letter){
       
        this->leaf = false;
        this->letter = letter;

        for(int i = 0; i < 26; i++){
            this->children[i] = nullptr;
        }
        
    } 

};


struct Trie{
    private:
        Node* root;

    public:
        Trie(){
            root = new Node('\0');
        }

        void insert(std::string word){
            Node* temp = root;
            for(char ch : word){
                if(temp->children[ch - 'A'] == NULL){
                    Node* node = new Node(ch);
                    temp->children[ch - 'A'] = node;
                }
                temp = temp->children[ch - 'A'];
            }
            temp->leaf = true;
        }

        bool search(std::string word){
            Node* temp = root;
            for(char ch : word){
                if(temp->children[ch - 'A'] == NULL){
                    return false;
                } else {
                    temp = temp->children[ch-'A'];
                }

            }
            return temp->leaf;
        }
        

        bool searchPrefix(std::string word){
            Node* temp = root;
            for(char ch : word){
                if(temp->children[ch - 'A'] == NULL){
                    return false;
                } else {
                    temp = temp->children[ch-'A'];
                }

            }
            return true;
        }
};

/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
# include <string>
# include <vector>
# include <list>
# include <iostream>
using namespace std;
struct Node{
    char value;
    bool end;
    vector<Node*> children;
};
class WordDictionary {
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* current = root;
        for (auto word_iter=word.begin();word_iter!=word.end();word_iter++){
            auto iter = current->children.begin();
            for(;iter!=current->children.end();iter++){
                if((*iter)->value==*word_iter){
                    break;
                }
            }
            if(iter==current->children.end()){
                Node* newNode = new Node();
                newNode->value = *word_iter;
                if(word_iter == word.end()-1){
                    newNode->end = true;
                }else{
                    newNode->end = false;
                }
                current->children.push_back(newNode);
                current = newNode;
            }
            else{
                if(word_iter == word.end()-1){
                    (*iter)->end = true;
                }
                else{
                    // do nothing because it should follow the previous result
                }
                current = (*iter);
            }
        }
    }
    
    bool search(string word) {
        return search(root, word);
    }
private:
    bool search(Node* node, string word){
        if(word.size()==0 && node->end){
            return true;
        }
        else if(word.size()==0 && !(node->end)){
            return false;
        }
        else{
            for (auto i = node->children.begin();i!=node->children.end();i++){
                if((*i)->value == word[0] || word[0] == '.'){
                    if(search((*i), word.substr(1,word.size()-1))){
                        return true;
                    }
                }
            }
            return false;
        }
    }
private:
    Node* root;
};
// int main(){
//     WordDictionary wo;
//     wo.addWord("a");
//     wo.addWord("ab");
//     cout << wo.search("ab") << endl;
//     cout << wo.search("a") <<endl;
// }

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end


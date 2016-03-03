#ifndef CONVERT_H_INCLUDED
#define CONVERT_H_INCLUDED

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <queue>
#include <map>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> genRadomVector(int len){
    vector<int> ret;
    int tmpInt;
    for (int i=0; i<len; i++){
        tmpInt = rand()%10;
        ret.push_back(tmpInt);
    }
    return ret;
}

//[1,1,1,1]
vector<int> genVectorFromIntString(string input){
    vector<int> ret;
    stringstream ss;
    for (int i=0; i<input.size(); i++){
        if (isdigit(input[i])){
            ss << input[i];
        }
        else {
            //ss是否为空，补上
            if (ss.str() == "") continue;
            int tmpint;
            ss >> tmpint;
            ret.push_back(tmpint);
            ss.clear();
        }
    }
    return ret;
}

vector<vector<int> > genVVFromIntString(string input){
    //去掉开头和结尾的[]
    vector<vector<int> > ret;
    for (int i=1; i<input.size()-2;  i++){
        stringstream ss;
        if (input[i] == ',') continue;
        if (input[i] == '['){
            while (input[i] != ']'){
                ss << input[i];
                ++i;
            }
            ss << ']';
        }
        //只会初始化一次？测试一下
        string tmpstr = ss.str();
        vector<int> tmpvec = genVectorFromIntString(tmpstr);
        //test [] [[]]
        ret.push_back(tmpvec);
    }
    return ret;
}

void printVector(vector<int> input){
    for (int i=0; i<input.size(); i++){
        cout << input[i] << ' ';
    }
    cout << endl;
}

void printVV(vector<vector<int> > input){
    for (int i=0; i<input.size(); i++){
        vector<int> tmp = input[i];
        for (int j=0; j<tmp.size(); j++){
            cout<< tmp[j] << ' ';
        }
        cout << endl;
    }
}

template <typename T>
ListNode * genListNode(vector<T> input){
    ListNode *head = new ListNode(-1);
    ListNode *tmp = head;
    for (int i=0; i<input.size(); i++){
        tmp->next = new ListNode(input[i]);
        tmp = tmp->next;
    }
    ListNode *ret = head->next;
    delete head;
    return ret;
}

ListNode *genListNode(string arg){
    vector<int> tmpvector = genVectorFromIntString(arg);
    return genListNode(tmpvector);
}

void printList(ListNode *head){
    while (head){
        cout << head->val << " ";
        head = head->next;
    }
    cout<<endl;
}

TreeNode * genTreeNode_help(vector<string> &input, int index){
    int len = input.size();
    if(index >= len){
        return NULL;
    }
    if (input[index] == "#"){
        return NULL;
    }
    stringstream ss;
    ss << input[index];
    int tmpint;
    ss >> tmpint;
    ss.clear();
    TreeNode * tmpnode = new TreeNode(tmpint);
    int ls = index*2+1;
    int rs = index*2+2;
    tmpnode->left = ls >= len ? NULL : genTreeNode_help(input, ls);
    tmpnode->right = rs >= len ? NULL : genTreeNode_help(input, rs);
    return tmpnode;
}

vector<string> genVectorTree(string input){
    vector<string> ret;
    stringstream ss;
    for (int i=0; i<input.size(); i++){
        if (isdigit(input[i]) || input[i] == '#' || input[i] == '-'){
            ss << input[i];
        }
        else {
            //ss是否为空，补上
            if (ss.str() == "") continue;
            string tmpint;
            ss >> tmpint;
            ret.push_back(tmpint);
            ss.clear();
        }
    }
    return ret;
}

template <typename T>
TreeNode * genTreeNodeFromV(vector<T> input){
    if (input.size() == 0){
        return NULL;
    }
    TreeNode * head = genTreeNode_help(input, 0);
    return head;
}

TreeNode * genTreeFromString(string input){
    vector<string> tmp = genVectorTree(input);
    return genTreeNodeFromV(tmp);
}

void printTree_help(TreeNode *head, int depth){
    if (head == NULL) return;
    for (int i=0; i<depth-1; i++){
        cout << "|  ";
    }
    if (depth != 0)
        cout<<"|__";
    cout << head->val;
    cout << endl;
    printTree_help(head->left, depth+1);
    printTree_help(head->right, depth+1);
}

void printTree(TreeNode *head){
    printTree_help(head, 0);
}


#endif // CONVERT_H_INCLUDED

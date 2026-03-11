#pragma once

using namespace std;

class TreeNode
{
public:  
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char data);
}; 

class ExpressionTree
{
    stack<TreeNode*>* top;
public:
	ExpressionTree();
   	~ExpressionTree();
    void clear();
    void push(TreeNode* ptr);
    TreeNode* pop();
    TreeNode* peek();
    void insert(char val);
    bool isDigit(char ch);
    bool isOperator(char ch);
    int toDigit(char ch);
    void buildTree(string eqn);
    double evaluate();
    double evaluate(TreeNode* ptr);
    void postfix();
    void postOrder(TreeNode* ptr);
    void infix();
    void inOrder(TreeNode* ptr);
    void prefix();
    void preOrder(TreeNode* ptr);
};


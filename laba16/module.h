#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};
typedef Node* PNode;

class BinaryTree {
private:
    PNode root;
    void insertRec(PNode& p, int val);
    void deleteRec(PNode& p);
    int countRec(PNode p) const;
    void infixCollect(PNode p, vector<int>& out) const;
    void printRec(PNode p, int level) const;
public:
    BinaryTree();
    ~BinaryTree();
    void insert(int val);
    void printTree() const;
    int size() const;
    bool isEmpty() const;
    vector<int> getInfix() const;
    void taskTreeWork8() const;
    void taskTreeWork10(int x);
    void taskTreeWork18() const;
};

class TreeVerifier {
public:
    static void runChecks(const BinaryTree& tree);
};

void inputFromKeyboard(BinaryTree& tree);
void inputFromFile(BinaryTree& tree);
void inputFromRandom(BinaryTree& tree);

void task1();
void task2();
void task3();


#endif
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <stack>


struct ListNode {
    int val;
    ListNode* prev;  //left
    ListNode* next; 
};

ListNode* buildBST(int n, ListNode*& head) {
    if (n <= 0) return nullptr;
    
    ListNode* leftChild = buildBST(n / 2, head);
    
    ListNode* root = head;
    head = head->next;
    
    ListNode* rightChild = buildBST(n - 1 - n / 2, head);
    
    root->prev = leftChild;
    root->next = rightChild;
    
    return root;
}

int countListNodes(ListNode* head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void PrintTree(ListNode* root, int level = 0) {
    if (!root) return;
    PrintTree(root->next, level + 1);
    for (int i = 0; i < level; i++) std::cout << "    ";
    std::cout << root->val << "\n";
    PrintTree(root->prev, level + 1);
}

void clearListTree(ListNode* node) {
    if (!node) return;
    clearListTree(node->prev);
    clearListTree(node->next);
    delete node;
}

void task1() {
    std::cout << "\n=== ЗАДАЧА 1: Список  BST ===" << std::endl;
    
    ListNode* n1 = new ListNode{1, nullptr, nullptr};
    ListNode* n2 = new ListNode{2, nullptr, nullptr};
    ListNode* n3 = new ListNode{3, nullptr, nullptr};
    ListNode* n4 = new ListNode{4, nullptr, nullptr};
    ListNode* n5 = new ListNode{5, nullptr, nullptr};
    
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    
    ListNode* listHead = n1;
    
    std::cout << "Исходный список: ";
    for (ListNode* tmp = listHead; tmp; tmp = tmp->next)
        std::cout << tmp->val << " ";
    std::cout << "\n\n";
    
    int n=countListNodes(listHead);
    ListNode* bstRoot = buildBST(n, listHead);
    
    std::cout << "Дерево:\n";
    PrintTree(bstRoot);
    
    clearListTree(bstRoot);
    std::cout << "  Готово\n" << std::endl;
}


struct TreeNode2 {
    int val;
    TreeNode2* left;
    TreeNode2* right;
    
    TreeNode2(int v) : val(v), left(nullptr), right(nullptr) {}
};

class TreeIterator {
private:
    std::stack<TreeNode2*> stk;
    
    void pushRight(TreeNode2* node) {
        while (node!=nullptr) {
            stk.push(node);
            node = node->right;
        }
    }
    
public:
    TreeIterator(TreeNode2* root) {
        pushRight(root);
    }
    
    bool hasNext() const {
        return !stk.empty();
    }
    
    int next() {
        if (stk.empty()) {
            std::cout<<"No more elements\n";
            return -1;
        }
        
        TreeNode2* current = stk.top();
        stk.pop();
        
        if (current->left != nullptr) {
            pushRight(current->left);
        }
        
        return current->val;
    }
};

void clearTree2(TreeNode2* node) {
    if (!node) return;
    clearTree2(node->left);
    clearTree2(node->right);
    delete node;
}

void task2() {
    std::cout << "\nЗАДАЧА 2: Итератор (право-корень-лево)"<<std::endl;
    
    TreeNode2* root = new TreeNode2(1);
    root->left = new TreeNode2(2);
    root->right = new TreeNode2(3);
    root->left->left = new TreeNode2(4);
    root->left->right = new TreeNode2(5);
    root->right->right = new TreeNode2(6);
    
    TreeIterator it(root);
    
    std::cout << "Обход: ";
    while (it.hasNext()) {
        std::cout << it.next() << " ";
    }
    std::cout << "\n";
    
    clearTree2(root);
    std::cout << "  Готово\n" << std::endl;
}

struct TreeNode3 {
    int val;
    TreeNode3* left;
    TreeNode3* right;
    
    TreeNode3(int v) : val(v), left(nullptr), right(nullptr) {}
};

struct SubtreeInfo {
    std::string serialization;
    int size;
    TreeNode3* node;
    TreeNode3* parent;
    bool isLeft;
};

std::string serialize(TreeNode3* node, int& size) {
    if (!node) {
        size = 0;
        return "#";
    }
    
    int leftSize = 0, rightSize = 0;
    std::string leftSer = serialize(node->left, leftSize);
    std::string rightSer = serialize(node->right, rightSize);
    
    size = 1 + leftSize + rightSize;
    return std::to_string(node->val) + "(" + leftSer + ")(" + rightSer + ")";
}

void collectSubtrees(TreeNode3* node, TreeNode3* parent, bool isLeft,
                     std::map<std::string, std::vector<SubtreeInfo>>& map) {
    if (!node) return;
    
    int size = 0;
    std::string ser = serialize(node, size);
    
    map[ser].push_back({ser, size, node, parent, isLeft});
    
    collectSubtrees(node->left, node, true, map);
    collectSubtrees(node->right, node, false, map);
}

void deleteSubtree3(TreeNode3* node) {
    if (!node) return;
    deleteSubtree3(node->left);
    deleteSubtree3(node->right);
    delete node;
}


bool isDescendant(TreeNode3* root, TreeNode3* target) {
    if (!root) return false;
    if (root == target) return true;
    return isDescendant(root->left, target) || isDescendant(root->right, target);
}


void markProtected(TreeNode3* node, std::set<TreeNode3*>& protectedNodes) {
    if (!node) return;
    protectedNodes.insert(node);
    markProtected(node->left, protectedNodes);
    markProtected(node->right, protectedNodes);
}

void deleteDuplicateSubtrees(TreeNode3*& root) {
    if (!root) return;
    
    std::map<std::string, std::vector<SubtreeInfo>> subtreeMap;
    collectSubtrees(root, nullptr, false, subtreeMap);
    
    std::vector<SubtreeInfo> candidates;
    std::set<TreeNode3*> protectedNodes;
    

    for (auto& pair : subtreeMap) {
        if (pair.second.size() > 1) {
            markProtected(pair.second[0].node, protectedNodes);
            for (size_t i = 1; i < pair.second.size(); i++) {
                candidates.push_back(pair.second[i]);
            }
        }
    }
    

    std::sort(candidates.begin(), candidates.end(),
              [](const SubtreeInfo& a, const SubtreeInfo& b) {
                  return a.size > b.size;
              });
    
    std::set<TreeNode3*> alreadyDeleted;
    
    for (auto& dup : candidates) {
        if (alreadyDeleted.count(dup.node) || protectedNodes.count(dup.node))
            continue;
        

        bool skip = false;
        for (TreeNode3* delRoot : alreadyDeleted) {
            if (isDescendant(delRoot, dup.node)) {
                skip = true;
                break;
            }
        }
        if (skip) continue;
        

        if (dup.parent) {
            if (dup.isLeft) dup.parent->left = nullptr;
            else dup.parent->right = nullptr;
        } else {
            root = nullptr;
        }
        
        // Помечаем все узлы как удалённые
        std::vector<TreeNode3*> stack = {dup.node};
        while (!stack.empty()) {
            TreeNode3* curr = stack.back();
            stack.pop_back();
            if (!curr) continue;
            alreadyDeleted.insert(curr);
            stack.push_back(curr->left);
            stack.push_back(curr->right);
        }
        
        deleteSubtree3(dup.node);
    }
}

void printTree3(TreeNode3* node, int indent = 0) {
    if (!node) {
        std::cout << std::string(indent, ' ') << "NULL\n";
        return;
    }
    std::cout << std::string(indent, ' ') << node->val << "\n";
    printTree3(node->left, indent + 2);
    printTree3(node->right, indent + 2);
}

int countTreeNodes3(TreeNode3* node) {
    if (!node) return 0;
    return 1 + countTreeNodes3(node->left) + countTreeNodes3(node->right);
}

void clearTree3(TreeNode3* node) {
    if (!node) return;
    clearTree3(node->left);
    clearTree3(node->right);
    delete node;
}

void task3() {
    std::cout << "\n=== ЗАДАЧА 3: Удаление дубликатов ===" << std::endl;
    
    TreeNode3* root = new TreeNode3(1);
    root->left = new TreeNode3(2);
    root->right = new TreeNode3(2);
    root->left->left = new TreeNode3(3);
    root->left->right = new TreeNode3(4);
    root->right->left = new TreeNode3(3);
    root->right->right = new TreeNode3(4);
    root->left->left->left = new TreeNode3(5);
    root->left->left->right = new TreeNode3(6);
    
    std::cout << "ИСХОДНОЕ:\n";
    std::cout << "Узлов: " << countTreeNodes3(root) << "\n";
    printTree3(root);
    
    deleteDuplicateSubtrees(root);
    
    std::cout << "\nПОСЛЕ УДАЛЕНИЯ:\n";
    std::cout << "Узлов: " << countTreeNodes3(root) << "\n";
    printTree3(root);
    
    clearTree3(root);
    std::cout << " Готово\n" << std::endl;
}


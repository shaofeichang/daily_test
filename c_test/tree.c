#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int isSymmetric(struct TreeNode* root) {
    // struct TreeNode *tn[100];// = (struct TreeNode(*)[100]) malloc (sizeof(struct TreeNode*) * 100);
    // struct TreeNode *tn[1] = (struct TreeNode(*)[1]) malloc (sizeof(root) * 100);
    struct TreeNode **tn =  (struct TreeNode**) malloc (sizeof(root) * 100);
    for (size_t i = 0; i < 100; i++) {
        tn[i] = (struct TreeNode*) malloc (sizeof(struct TreeNode *));
    }
    
    int index = 0;
    tn[index++] = root;
    tn[index++] = root;
    while(index != 0) {
        struct TreeNode *t1 = tn[--index];
        struct TreeNode *t2 = tn[--index];
        if( t1 == NULL && t2 == NULL) continue;
        if(t1 == NULL || t2 == NULL) return 0;
        if (t1->val != t2->val) return 0;
        tn[index++] = t1->left;
        tn[index++] = t2->right;
        tn[index++] = t1->right;
        tn[index++] = t2->left;
    } 
    return 1;
}
int main()
{
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 123;
    root->left = NULL;
    root->right = NULL;
    isSymmetric(root);
    getchar();
    return 0;
}
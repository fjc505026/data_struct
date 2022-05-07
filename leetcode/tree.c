
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *preorderTraversal(struct TreeNode *root, int *returnSize) {
  int *array = (int *)malloc(100 * sizeof(int));
  struct TreeNode *stk[100];
  int stk_top = -1; // the tree level
  *returnSize = 0;

  while (stk_top > -1 || root != NULL) {
    while (root != NULL) {
      array[(*returnSize)++] = root->val; //***store root value in array
      stk[++stk_top] = root;              // store the root node in stk[0]
      root = root->left;
    }
    root = stk[stk_top--]; // retrieve the root node in diff levels
    root = root->right;
  }

  return array;
}

// recurseive method
void travel(struct TreeNode *root, int *arr, int *size) {
  if (root != NULL) {
    arr[(*size)++] = root->val;
    travel(root->left, arr, size);
    travel(root->right, arr, size);
  }
}

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
  int *arr = (int *)malloc(100 * sizeof(int));
  *returnSize = 0;
  travel(root, arr, returnSize);
  return arr;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *inorderTraversal(struct TreeNode *root, int *returnSize) {
  int *array = (int *)malloc(100 * sizeof(int));
  struct TreeNode *stk[100];
  int stk_top = -1; // the tree level
  *returnSize = 0;

  while (stk_top > -1 || root != NULL) {
    while (root != NULL) {
      stk[++stk_top] = root; // store the root node in stk[0]
      root = root->left;
    }

    root = stk[stk_top--];              // retrieve the root node in diff levels
    array[(*returnSize)++] = root->val; //***store left value in array
    root = root->right;
  }

  return array;
}

// recurseive method
void travel(struct TreeNode *root, int *arr, int *size) {
  if (root != NULL) {
    travel(root->left, arr, size);
    arr[(*size)++] = root->val;
    travel(root->right, arr, size);
  }
}

int *inorderTraversal(struct TreeNode *root, int *returnSize) {
  int *arr = (int *)malloc(100 * sizeof(int));
  *returnSize = 0;
  travel(root, arr, returnSize);
  return arr;
}

/**
 * Note:TODO The returned array must be malloced, assume caller calls free().
 */
int *postorderTraversal(struct TreeNode *root, int *returnSize) {
  int *array = (int *)malloc(100 * sizeof(int));
  struct TreeNode *stk[100];
  int stk_top = -1; // the tree level
  int stk_max = 0;  // the tree level
  *returnSize = 0;

  while (stk_top > -1 || root != NULL) {
    while (root != NULL) {
      stk[++stk_top] = root; // store the root node in stk[0]
      root = root->left;
    }
    root = stk[stk_top--]; // retrieve the root node in diff levels
    root = root->right;
  }

  return array;
}

// recurseive method
void travel(struct TreeNode *root, int *arr, int *size) {
  if (root != NULL) {
    travel(root->left, arr, size);
    travel(root->right, arr, size);
    arr[(*size)++] = root->val;
  }
}

int *postorderTraversal(struct TreeNode *root, int *returnSize) {
  int *arr = (int *)malloc(100 * sizeof(int));
  *returnSize = 0;
  travel(root, arr, returnSize);
  return arr;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

void travel(struct TreeNode *root, int **arr, int *size,
            int **returnColumnSizes) {
  if (root != NULL) {
    travel(root->left, arr, size, returnColumnSizes);
    travel(root->right, arr, size, returnColumnSizes);
    arr[(*size)++] = root->val;
  }
}

int **levelOrder(struct TreeNode *root, int *returnSize,
                 int **returnColumnSizes) {
  int **arr = (int **)malloc(100 * sizeof(int *));
  *returnSize = 0;

  travel(root, arr, returnSize, returnColumnSizes);
  return arr;
}
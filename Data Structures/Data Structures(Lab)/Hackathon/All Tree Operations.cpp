#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// ---------- BST Operations ----------

// Insert into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// Search in BST
bool searchBST(TreeNode* root, int val) {
    if (!root) return false;
    if (root->val == val) return true;
    if (val < root->val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}

// Inorder Traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Preorder Traversal
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Validate BST
bool isValidBST(TreeNode* root, TreeNode* minNode = nullptr, TreeNode* maxNode = nullptr) {
    if (!root) return true;
    if (minNode && root->val <= minNode->val) return false;
    if (maxNode && root->val >= maxNode->val) return false;
    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}

// Find Min in BST
TreeNode* findMin(TreeNode* root) {
    while(root && root->left) root = root->left;
    return root;
}

// Find Max in BST
TreeNode* findMax(TreeNode* root) {
    while(root && root->right) root = root->right;
    return root;
}

// Delete Node in BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// Range Sum of BST
int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0;
    if (root->val < low) return rangeSumBST(root->right, low, high);
    if (root->val > high) return rangeSumBST(root->left, low, high);
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

// Kth smallest element in BST (inorder traversal)
void kthSmallestHelper(TreeNode* root, int& k, int& ans) {
    if (!root) return;
    kthSmallestHelper(root->left, k, ans);
    k--;
    if (k == 0) { ans = root->val; return; }
    kthSmallestHelper(root->right, k, ans);
}
int kthSmallest(TreeNode* root, int k) {
    int ans = -1;
    kthSmallestHelper(root, k, ans);
    return ans;
}

// Lowest Common Ancestor in BST
TreeNode* LCA(TreeNode* root, int p, int q) {
    if (!root) return nullptr;
    if (root->val > p && root->val > q) return LCA(root->left, p, q);
    if (root->val < p && root->val < q) return LCA(root->right, p, q);
    return root;
}

// Convert Sorted Array to BST
TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
    if (l > r) return nullptr;
    int mid = (l + r)/2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = sortedArrayToBST(nums, l, mid-1);
    node->right = sortedArrayToBST(nums, mid+1, r);
    return node;
}

// Trim BST
TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root) return nullptr;
    if (root->val < low) return trimBST(root->right, low, high);
    if (root->val > high) return trimBST(root->left, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}

// ---------- Main function for testing ----------
int main() {
    TreeNode* root = nullptr;

    // Insert elements
    vector<int> vals = {20, 10, 30, 5, 15, 25, 35};
    for(auto v : vals) root = insertBST(root, v);

    cout << "Inorder Traversal: "; inorder(root); cout << endl;
    cout << "Preorder Traversal: "; preorder(root); cout << endl;
    cout << "Postorder Traversal: "; postorder(root); cout << endl;

    cout << "Search 15: " << (searchBST(root, 15) ? "Found" : "Not Found") << endl;
    cout << "Search 40: " << (searchBST(root, 40) ? "Found" : "Not Found") << endl;

    cout << "Is valid BST? " << (isValidBST(root) ? "Yes" : "No") << endl;

    cout << "Min value: " << findMin(root)->val << ", Max value: " << findMax(root)->val << endl;

    cout << "Delete 10" << endl;
    root = deleteNode(root, 10);
    cout << "Inorder after delete: "; inorder(root); cout << endl;

    cout << "Range Sum [15,30]: " << rangeSumBST(root,15,30) << endl;
    cout << "2nd smallest element: " << kthSmallest(root,2) << endl;

    TreeNode* lca = LCA(root,5,15);
    cout << "LCA of 5 and 15: " << lca->val << endl;

    vector<int> sortedArr = {1,2,3,4,5,6,7};
    TreeNode* bstFromArray = sortedArrayToBST(sortedArr,0,sortedArr.size()-1);
    cout << "Inorder of BST from sorted array: "; inorder(bstFromArray); cout << endl;

    cout << "Trim BST to [15,30]" << endl;
    root = trimBST(root,15,30);
    cout << "Inorder after trim: "; inorder(root); cout << endl;

    return 0;
}

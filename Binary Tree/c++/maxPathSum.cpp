#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* left;
    Node* right;


    Node(int initialVal) {
      val = initialVal;
      left = nullptr;
      right = nullptr;
    }
};

int maxPathSum(Node* root) {
  if (root)
  {
    if (!(root->left) && !(root->right))
      return root->val;
    return max(maxPathSum(root->left),maxPathSum(root->right))+root->val;
  }

  return -INT_MAX;
}

int maxPathSum1(Node* root)
{
    if (root == nullptr)
        return std::numeric_limits<int>::min();

    if (root->left == nullptr && root->right == nullptr)
        return root->val;

    return root->val + std::max(
        maxPathSum(root->left),
        maxPathSum(root->right)
    );
}

int main()
{
//    cout<<numeric_limits<int>::min()<<endl;
//    cout<<numeric_limits<int>::max()<<endl;
//    cout<<INT_MAX;
    //https://structy.net/problems/max-root-to-leaf-path-sum
}

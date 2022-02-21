
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        string val;
        Node* left;
        Node* right;

        Node(string initialVal)
        {
            val=initialVal;
            left=nullptr;
            right=nullptr;
        }
};

std::vector<std::string> depthFirstValues(Node* root)
{
    if (root)
    {
        vector<string>re{root->val};
        vector<string>left=depthFirstValues(root->left);
        vector<string>right=depthFirstValues(root->right);
        re.insert(re.end(),left.begin(),left.end());
        re.insert(re.end(),right.begin(),right.end());

        return re;
    }

    return {};
}

bool treeIncludes(Node* root, std::string targetVal)
{
    if (root)
    {
        if (root->val==targetVal) return true;
        if (treeIncludes(root->left,targetVal)) return true;
        if (treeIncludes(root->right,targetVal)) return true;
    }

    return false;
}

int main()
{

}

//https://structy.net/problems/tree-includes

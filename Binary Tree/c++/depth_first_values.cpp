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

std::vector<std::string> depthFirstValues_Stack(Node* root)
{
    if (root)
    {
        vector<string>re;
        stack<Node*>s;
        s.push(root);

        while(s.size())
        {
            Node* current=s.top();
            s.pop();
            re.push_back(current->val);
            if (current->right) s.push(current->right);
            if (current->left) s.push(current->left);
        }

        return re;
    }

    return {};
}

int main()
{

}

//https://structy.net/problems/depth-first-values

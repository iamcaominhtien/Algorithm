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

std::vector<std::string> breadthFirstValues(Node* root)
{
    if (root)
    {
        queue<Node*>q;
        q.push(root);
        vector<string>re;

        while(q.size())
        {
            Node* current=q.front();
            q.pop();
            re.push_back(current->val);
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        return re;
    }

    return {};
}

int main()
{

}

//https://structy.net/problems/breadth-first-values

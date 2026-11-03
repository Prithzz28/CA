#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    int leftCount;
    Node *left, *right;

    Node(int x)
    {
        val = x;
        leftCount = 0;
        left = right = NULL;
    }
};

Node* insert(Node* root, int x)
{
    if (root == NULL)
        return new Node(x);

    Node* cur = root;

    while (true)
    {
        if (x <= cur->val)
        {
            cur->leftCount++;

            if (cur->left == NULL)
            {
                cur->left = new Node(x);
                break;
            }

            cur = cur->left;
        }
        else
        {
            if (cur->right == NULL)
            {
                cur->right = new Node(x);
                break;
            }

            cur = cur->right;
        }
    }

    return root;
}

int getRank(Node* root, int x)
{
    int rank = 0;
    Node* cur = root;

    while (cur != NULL)
    {
        if (x == cur->val)
        {
            rank += cur->leftCount;
            break;
        }
        else if (x < cur->val)
        {
            cur = cur->left;
        }
        else
        {
            rank += cur->leftCount + 1;
            cur = cur->right;
        }
    }

    return rank;
}

int main()
{
    int n;
    cin >> n;

    Node* root = NULL;

    while (n--)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;
        cout << getRank(root, x) << '\n';
    }

    return 0;
}
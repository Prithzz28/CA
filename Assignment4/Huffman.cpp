#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    string name;
    int frequency;

    Node* left;
    Node* right;

    Node(string n, int f)
    {
        name = n;
        frequency = f;
        left = nullptr;
        right = nullptr;
    }
};

struct Compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->frequency > b->frequency;
    }
};

void generateCodes(Node* root, string code)
{
    if(root == nullptr)
        return;

    // Leaf node
    if(root->left == nullptr && root->right == nullptr)
    {
        cout << root->name << " = " << code << endl;
        return;
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

int main()
{
    int n;
    cin >> n;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for(int i = 0; i < n; i++)
    {
        string name;
        int frequency;

        cin >> name >> frequency;

        Node* newNode = new Node(name, frequency);

        pq.push(newNode);
    }

    // Build Huffman tree
    while(pq.size() > 1)
    {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* merged = new Node(
            "",
            left->frequency + right->frequency
        );

        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    Node* root = pq.top();

    cout << "Huffman Codes:" << endl;

    generateCodes(root, "");

    return 0;
}
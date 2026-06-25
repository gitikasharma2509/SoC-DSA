#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
class Stack {
private:
    vector<int> arr;

public:
    void push(int x) {
        arr.push_back(x);
    }

    int pop() {
        int val = arr.back();
        arr.pop_back();
        return val;
    }

    int top() {
        return arr.back();
    }

    bool empty() {
        return arr.empty();
    }

    void display() {
        for(int i = arr.size()-1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
class QueueDS {
private:
    queue<int> q;

public:
    void enqueue(int x) {
        q.push(x);
    }

    int dequeue() {
        int val = q.front();
        q.pop();
        return val;
    }

    int front() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }

    void display() {
        queue<int> temp = q;

        while(!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
};
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insert(int x) {

        Node* newNode = new Node(x);

        if(head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    void traverse() {

        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    int count() {

        int cnt = 0;

        Node* temp = head;

        while(temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }
};
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        data = x;
        left = right = NULL;
    }
};
void preorder(TreeNode* root) {

    if(root == NULL) return;

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}
void inorder(TreeNode* root) {

    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(TreeNode* root) {

    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}
void levelOrder(TreeNode* root) {

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()) {

        TreeNode* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left)
            q.push(curr->left);

        if(curr->right)
            q.push(curr->right);
    }
}
void DFS(int node,
         unordered_map<int, vector<int>>& graph,
         vector<bool>& visited)
{
    visited[node] = true;

    cout << node << " ";

    for(int nbr : graph[node]) {

        if(!visited[nbr])
            DFS(nbr, graph, visited);
    }
}
void BFS(int start,
         unordered_map<int, vector<int>>& graph)
{
    vector<bool> visited(6,false);

    queue<int> q;

    q.push(start);

    visited[start] = true;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int nbr : graph[node]) {

            if(!visited[nbr]) {

                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }
}
int main() {
Stack s;

s.push(10);
s.push(20);
s.push(30);

cout << "Pop: " << s.pop() << endl;

s.push(40);

cout << "Pop: " << s.pop() << endl;

cout << "Final Stack: ";
s.display();
cout << "\nQUEUE\n";

QueueDS q;

q.enqueue(10);
q.enqueue(20);
q.enqueue(30);

cout << "Dequeue: " << q.dequeue() << endl;

q.enqueue(40);

cout << "Dequeue: " << q.dequeue() << endl;

cout << "Final Queue: ";
q.display();
cout << "\nLINKED LIST\n";

LinkedList list;

list.insert(5);
list.insert(10);
list.insert(15);
list.insert(20);

list.traverse();

cout << "Count = " << list.count() << endl;
TreeNode* root = new TreeNode(1);

root->left = new TreeNode(2);
root->right = new TreeNode(3);

root->left->left = new TreeNode(4);
root->left->right = new TreeNode(5);

root->right->right = new TreeNode(6);
cout << "\nPREORDER\n";
preorder(root);

cout << "\n\nINORDER\n";
inorder(root);

cout << "\n\nPOSTORDER\n";
postorder(root);

cout << "\n\nLEVEL ORDER\n";
levelOrder(root);

cout << endl;
unordered_map<int, vector<int> > graph;

graph[1] = {2,3};
graph[2] = {1,4};
graph[3] = {1,4};
graph[4] = {2,3,5};
graph[5] = {4};
cout << "\nDFS\n";

vector<bool> visited(6,false);

DFS(1, graph, visited);

cout << "\n\nBFS\n";

BFS(1, graph);

cout << endl;
}
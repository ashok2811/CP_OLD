/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.
Each node in the graph contains a val (int) and a list (List[Node]) 
of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}

Test case format:
For simplicity sake, each node's value is the same as the node's index (1-indexed). 
For example, the first node with val = 1, the second node with val = 2, and so on. 
The graph is represented in the test case using an adjacency list.
Adjacency list is a collection of unordered lists used to represent a finite graph. 
Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. 
You must return the copy of the given node as a reference to the cloned graph.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<int, Node*> visited;
       return clone_node(node, visited); 
    }
    
    Node* clone_node(Node* node, unordered_map<int, Node*> &visited){
        Node* new_node = new Node(node->val);
        visited.insert({node->val, new_node});
        
        for(auto n : node->neighbors){
            if(visited.find(n->val)==visited.end()){
                Node* cn = clone_node(n, visited);
                new_node-> neighbors.push_back(cn);
            }
            
            else{
                new_node->neighbors.push_back(visited.find(n->val) -> second);
            }
        }
        return new_node;
    }
    
};
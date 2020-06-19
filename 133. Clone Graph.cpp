/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity sake, each node's value is the same as the node's index (1-indexed). For example, the first node with val = 1, the second node with val = 2, and so on. The graph is represented in the test case using an adjacency list.

Adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        queue<Node*> nodes;
        Node* clone_node = NULL;
        if(node==NULL)
            return node;
        nodes.push(node);
        unordered_map<Node*,Node*> old_to_new;
        unordered_set<Node*> vis;
        while(!nodes.empty())
        {
            int n = nodes.size();
            while(n--)
            {
                Node* nod = nodes.front();
                nodes.pop();
                if(vis.count(nod)>0)
                    continue;
                vis.insert(nod);
                Node* temp = new Node(nod->val,nod->neighbors);
                if(clone_node==NULL)
                    clone_node = temp;
                old_to_new[nod] = temp;
                for(auto nei : nod->neighbors)
                    if(vis.count(nei)==0)
                        nodes.push(nei);
            }
        }
        vis.clear();
        nodes.push(clone_node);
        while(!nodes.empty())
        {
            int n = nodes.size();
            while(n--)
            {
                Node* nod = nodes.front();
                nodes.pop();
                if(vis.count(nod)>0)
                    continue;
                vis.insert(nod);
                vector<Node*> adj;
                for(auto nei : nod->neighbors)
                {
                    if(old_to_new.count(nei)>0)
                        adj.push_back(old_to_new[nei]);
                    if(vis.count(old_to_new[nei])==0)
                        nodes.push(old_to_new[nei]);
                }
                nod->neighbors = adj;
            }
        }
        return clone_node;
    }
};

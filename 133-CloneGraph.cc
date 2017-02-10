/*
 * Clone an undirected graph. Each node in the graph contains a label and 
 * a list of its neighbors.
 *
 * OJ's undirected graph serialization:
 *
 * Nodes are labeled uniquely.
 * We use # as a separator for each node, and , as a separator for node 
 * label and each neighbor of the node.
 *
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 * The graph has a total of three nodes, and therefore contains three 
 * parts as separated by #.
 *
 *   First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 *   Second node is labeled as 1. Connect node 1 to node 2.
 *   Third node is labeled as 2. Connect node 2 to node 2 (itself), thus 
 * forming a self-cycle.
 *
 * Visually, the graph looks like the following:
 *
 *      1
 *     / \
 *    /   \
 *   0 --- 2
 *        / \
 *        \_/
 *
 */

#include <vector>
#include <map>
using namespace std;
/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode { 
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution { 
public: 
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int, UndirectedGraphNode *> labelMap;
        if (node == NULL) return NULL;
        return cloneGraph_rec(node, labelMap);
    }

    UndirectedGraphNode *cloneGraph_rec(UndirectedGraphNode *node, map<int, UndirectedGraphNode *> &labelMap) {
       // Whether the node has already been created
       if (labelMap.find(node->label) == labelMap.end()) {
           UndirectedGraphNode * dupNode = new UndirectedGraphNode(node->label);
           labelMap[node->label] = dupNode;
           if (node->neighbors.size() != 0) {
               for(int i = 0;i < (int)node->neighbors.size();i++) {
                   UndirectedGraphNode * dupNeighborNode;
                   dupNeighborNode = cloneGraph_rec(node->neighbors[i], labelMap);
                   dupNode->neighbors.push_back(dupNeighborNode);
               }
           }
           return dupNode;
       }else{
           return labelMap[node->label];
       }
    }
};

#include <iostream>
#include "graph.h"
#include <queue>
#include <algorithm>

// reconstructs path to get the shortest path
std::vector<int> reconstructPath(int start, int end, std::vector<int> prev){
    std::vector<int> path;
    for(int at = end; at != -1; at = prev[at]){
        path.push_back(at);
    }
    std::reverse(path.begin(), path.end());

    if(path[0] == start) return path;
    return std::vector<int>();

}

int main(int args, char **argv)
{
	std::cout<<"Input: ./exe beg csr weight\n";
	if(args!=6){std::cout<<"Wrong input\n"; return -1;}
	
	const char *beg_file=argv[1];
	const char *csr_file=argv[2];
	const char *weight_file=argv[3];
    const int start = std::stoi(argv[4]);
    const int end = std::stoi(argv[5]);


	//template <file_vertex_t, file_index_t, file_weight_t
	//new_vertex_t, new_index_t, new_weight_t>
	graph<long, long, int, long, long, char>
	*ginst = new graph
	<long, long, int, long, long, char>
	(beg_file,csr_file,weight_file);
    
    // Breadth First Search Implementation between start and end node
    int total_nodes = ginst->vert_count;
    // queue to keep track of nodes that will come in priority
    std::queue<int> q;
    // list to store the traversed path
    std::vector<int> traversed;
    // list to check if the node is already visited or not
    // 0 means not visited
    // 1 means visited
    std::vector<int> visited(total_nodes, 0);
    // list to keep track of the previous node for the node in index i
    // -1 means null
    std::vector<int> prev(total_nodes, -1);

    // initialization
    q.push(start);
    traversed.push_back(start);
    visited[start] = 1;
    // traverse until the queue is empty
    while(!q.empty()){
        int node = q.front();
        q.pop();
        int beg = ginst->beg_pos[node];
        int end = ginst->beg_pos[node+1];
        // std::cout << beg << " " << end << std::endl;
        // get all neighbors
        for(int j = beg; j < end; j++){
            int next = ginst->csr[j];
            // std::cout << next << std::endl;
            // if already traversed then don't bother
            if(visited[next] == 0){
                traversed.push_back(next);
                q.push(next);
                visited[next] = 1;
                prev[next] = node;
            }
        }
    }
    // gives the complete BFS traversal
    std::cout << "Complete BFS from starting node" << std::endl;    
    for(int i = 0; i < traversed.size(); i++){
        std::cout << traversed[i] << " ";
    }
    std::cout << std::endl;
    
    // gives the shortest path between two nodes
    // if the nodes are in disjoint graph then it returns empty
    std::cout << "Shortest path between start node: " << start << " and end node "<< end << " " << std::endl;
    std::vector<int> path = reconstructPath(start, end, prev);
    for(int i = 0; i < path.size(); i++){
        std::cout << path[i] << " ";
    }
    std::cout << std::endl;

	return 0;	
}

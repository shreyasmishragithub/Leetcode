class Solution {
public:
    struct Node{
        Node(string v,double r){
            this->variable=v;
            this->result=r;
        }
        string variable;
        double result;
    };
    map<string,vector<Node>>graph;
    void buildGraph(vector<vector<string>>& equations, vector<double>& values){
       
        for(auto e:equations){
            vector<Node>children;
            graph[e[0]]=children;//
        }
        for(int e=0;e<equations.size();e++){
            Node n(equations[e][1],values[e]);
            graph[equations[e][0]].push_back(n);
            Node inverse(equations[e][0],1/values[e]);
            graph[equations[e][1]].push_back(inverse); 
        }
    }
    bool solve(string top,string bottom,double &accum,set<string>&visited){ 
        if(top == bottom && graph.find(top) != graph.end()) {
			return true;
		}

		/* if either top or bottom aren't in the graph, then the equation is unsolvable */
		if(graph.find(top) == graph.end() || graph.find(bottom) == graph.end()) {
			return false;
		}
        visited.insert(top);
        for(auto &child:graph[top]){
            if(visited.find(child.variable)==visited.end()){
                accum=accum*child.result;
                if(child.variable==bottom){
                    return true;
                }
                if(solve(child.variable,bottom,accum,visited)==true){
                    return true;
                }else{
                    accum=accum/child.result;//
                }
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    buildGraph(equations, values);
		vector<double> results;
		for(auto& q : queries) {
			set<string> visited;
			double accum = 1.0;

			bool res = solve(q[0], q[1], accum, visited);
			if(res) {
				results.push_back(accum);   
			} else {
				results.push_back(-1.0);
			}
		}
		return results;
	}
};
#include "graph.h"
#include <queue>

Edge::Edge() : weight_(0), dest_id_(-1) {}

Edge::Edge(int weight, int id, const string& city) : weight_(weight), dest_id_(id), dest_city_(city) {}

int Edge::GetWeight() const {
    return weight_;
}

int Edge::GetDestId() const {
    return dest_id_;
}

void Edge::SetWeight(int weight) {
    weight_ = weight;
}

void Edge::SetDestId(int id) {
    dest_id_ = id;
}

string Edge::GetDestCity() const {
    return dest_city_;
}

Vertex::Vertex() : id_(-1), city_("") {}

Vertex::Vertex(int id, string city) : id_(id), city_(city) {}

int Vertex::GetId() const {
    return id_;
}

string Vertex::GetCity() const {
    return city_;
}

list<Edge>& Vertex::GetList() {
    return edge_list_;
}

void Vertex::SetId(int id) {
    id_ = id;
}

void Vertex::SetCity(string city) {
    city_ = city;
}

bool Graph::HaveVertex(int id) {
    for(auto it = vertices_.cbegin(); it != vertices_.cend(); it++) {
        if(it->GetId() == id) {
            return true;
        }
    }
    return false;
}

void Graph::AddVertex(const Vertex& vertex) {
    if(HaveVertex(vertex.GetId())){
        return;
    }
    vertices_.push_back(vertex);
}

void Graph::AddVertex(int id, string city) {
    if(HaveVertex(id)) {
        return;
    }
    vertices_.emplace_back(id, city);
}

void Graph::RemoveVertex(int remove_id) {                      // deletes vertex from other vertices' edge lists
    if(HaveVertex(remove_id)) {
        int remove_index = 0;
        for(int i = 0; i < vertices_.size(); i++) {
            if(vertices_.at(i).GetId() == remove_id) {      // searching for vertex
                remove_index = i;
                break;
            }
         }
        for(auto it = vertices_.at(remove_index).GetList().begin(); it != vertices_.at(remove_index).GetList().end(); it++) {
            RemoveEdge(it->GetDestId(), remove_id);       // deleting edges incident with vertex with remove_id
        }
        vertices_.erase(vertices_.begin()+remove_index); // deleting vertex
    }
}

bool Graph::IsAdjacent(int id_x, int id_y) {  // enough to check edge list of one vertex
    return HaveEdge(id_x, id_y);
}

vector<Vertex> Graph::Neighbors(int id) {
    int v_id = FindVertex(id);
    vector<Vertex> neighbors;
    for(auto it = vertices_.at(v_id).GetList().begin(); it != vertices_.at(v_id).GetList().end(); it++) {
        neighbors.emplace_back(it->GetDestId(), it->GetDestCity());
    }
    return neighbors;
}

void Graph::AddEdge(int id_x, int id_y, int weight) {
    if(HaveVertex(id_x) && HaveVertex(id_y)) {
        if(HaveEdge(id_x, id_y)) {
            return;
        }
        int x_index = FindVertex(id_x);
        int y_index = FindVertex( id_y);
        vertices_.at(x_index).GetList().emplace_back(weight,id_y, vertices_.at(y_index).GetCity());
        vertices_.at(y_index).GetList().emplace_back(weight,id_x,vertices_.at(x_index).GetCity());
    }
}

void Graph::RemoveEdge(int id_x, int id_y) {
    if(!HaveEdge(id_x,id_y)) {
        return;
    }
    for(int i = 0; i < vertices_.size(); i++) {     // go through all vertices
        if(vertices_.at(i).GetId() == id_x) {    // if found one of vertices
            for(auto it = vertices_.at(i).GetList().begin(); it != vertices_.at(i).GetList().end(); it++) { // go through edges
                if(it->GetDestId() == id_y) {        // check if edge is incident to vertex with id_y
                    vertices_.at(i).GetList().erase(it);   // delete in vertex x edge list
                    break;   // after deleting exit inner loop and search for another vertex
                }
            }
        }
        else if(vertices_.at(i).GetId() == id_y) {
            for(auto it = vertices_.at(i).GetList().begin(); it != vertices_.at(i).GetList().end(); it++) {
                if(it->GetDestId() == id_x) {
                    vertices_.at(i).GetList().erase(it);
                    break;
                }
            }
        }
    }
}

int Graph::FindVertex(int f_id) const {
    int ret_ind = -1;
    for(int i = 0; i < vertices_.size(); i++) {
        if(vertices_.at(i).GetId() == f_id) {
           ret_ind = i;
        }
    }
    return ret_ind;
}

void Graph::Print() {
    for(int i = 0; i < vertices_.size(); i++) {
        std::cout << "id: " << vertices_.at(i).GetId() << "\t " << vertices_.at(i).GetCity() << '\n';
        std::cout << "neighbours: \n";
        for(auto it = vertices_.at(i).GetList().begin(); it != vertices_.at(i).GetList().end(); it++) {
            std::cout << it->GetDestCity() << " DestId: " << it->GetDestId() << " Weight: " << it->GetWeight() << '\n';
        }
    }
}

bool Graph::HaveEdge(int id_x, int id_y){
    int x_index = FindVertex(id_x);
    for(auto it = vertices_.at(x_index).GetList().begin(); it != vertices_.at(x_index).GetList().end(); it++) {
        if(it->GetDestId() == id_y) {
            return true;
        }
    }
    return false;
}

size_t Graph::GraphSize() const {
    return vertices_.size();
}

int Graph::DijkstraAlg(int start, int end) {
    int size = GraphSize();
    vector<int> result_path;
    vector<int> path_vals(size, INT_MAX);
    path_vals[start] = 0;
    std::priority_queue<std::pair<int, int>> q;
    q.push(std::make_pair(0, start));
    while (!q.empty()) {
        int len = q.top().first;
        int vertex = q.top().second;
        q.pop();
        if (len > path_vals[vertex]) {
            continue;
        }
        for (int i = 0; i < size; ++i) {
            int to = i;
            int lenght = Distance(vertex, to);
            if (IsAdjacent(vertex,to) && path_vals[to] > path_vals[vertex] + lenght && lenght >= 0)
            {
                path_vals[to] = path_vals[vertex] + lenght;
                q.push(std::make_pair(path_vals[to], to));
            }
        }
    }
    if (path_vals[end] == INT_MAX) {
        std::cout << "From " << start + 1 << " to " << end + 1 << " does not exist!" << std::endl;
        return INT_MAX;
    }
    else {
        std::cout << "From " << start + 1 << " to " << end + 1 << ": " << path_vals[end] << std::endl;
        return path_vals[end];
    }
}

int Graph::Distance(int from_id, int to_id) {
    if(!HaveEdge(from_id,to_id)) {
        return -1;
    }
    int dist = 0;
    int from_index = FindVertex(from_id);
    for(auto it = vertices_[from_index].GetList().begin(); it != vertices_[from_index].GetList().end(); it++) {
        if(it->GetDestId() == to_id) {
            dist = it->GetWeight();
        }
    }
    return dist;
}

int Graph::MinDistance(const vector<Vertex>& vec, int from_id) {
    int min_dist = INT_MAX;
    int comp;
    for(int i = 0; i < vec.size(); i++) {
        comp = Distance(from_id, vec[i].GetId());
        if(comp < min_dist) {
            min_dist = comp;
        }
    }
    return min_dist;
}

int Graph::NearestVertex(const vector<Vertex> &vec, int to_id) {
    return 0;
}



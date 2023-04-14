#include <stdlib.h>
#include <stdio.h>

typedef struct Con{
    double weight;
    struct Node *node;
} Con;


typedef struct Node {
    int data;
    int num_cons;
    struct Con **connections;
    double dist_from_start;

} Node;



void create_node(int data, Node **p_node) {
    *p_node = malloc(sizeof(Node));
    (*p_node)->data = data;
    (*p_node)->connections = (void *)0;
    (*p_node)->num_cons = 0;
    (*p_node)->dist_from_start = 10000000.0;
}

void add_neighbour(Node *node, Node *neighbour, double weight) {
    node->num_cons++;
    node->connections = realloc(node->connections, node->num_cons * sizeof(Con *));
    node->connections[node->num_cons - 1] = malloc(sizeof(Con));
    node->connections[node->num_cons - 1]->weight = weight;
    node->connections[node->num_cons - 1]->node = neighbour;
}


void add_to_visited(Node ***p_visited, int *p_n_visited, Node *node) { // CHANGED
    Node **visited = *p_visited; // ADDED

    for(int i = 0; i < *p_n_visited; i++) {
        if (visited[i] == node) {
            return;
        }
    }
    (*p_n_visited)++; // CHECK THIS
    visited = realloc(visited, *p_n_visited * sizeof(Node *));
    visited[*p_n_visited - 1] = node;
    //(*visited + *p_n_visited - 1) = node; // CHECK THIS

    *p_visited = visited; // ADDED
}

int was_visited(Node **visited, int n_visited, Node *node) {
    // Complete this function
    for(int i = 0; i < n_visited; i++){
        if(visited[i] == node){
            return 1;
        }
    }
    return 0;
}


void dijkstra(Node *start, Node *end) {
    Node **visited = (void *)0;
    int num_visited = 0;
    Node *current = start;
    current->dist_from_start = 0.0;
    add_to_visited(&visited, &num_visited, current); // CHANGED


    while (current->data != end->data) {
        double min_dist = 1000000000.0;
        Node *min_node = (void *)0;
        for(int i = 0; i < num_visited; i++){
            Node *s = visited[i];
            for(int j = 0; j < s->num_cons; j++) {
                Node *t = s->connections[j]->node;
                double w = s->connections[j]->weight;
                if (was_visited(visited, num_visited, t) == 0) {
                    // if (s->dist_from_start + w < t->dist_from_start) {
                    //     t->dist_from_start = s->dist_from_start + w;
                    // }
                    if (s->dist_from_start + w < min_dist) { // Corrected
                            min_dist = s->dist_from_start + w;
                            min_node = t;
                    }
                }
            }

        }
        current = min_node;
        printf("Current: %d\n", current->data);
        current->dist_from_start = min_dist;
        add_to_visited(&visited, &num_visited, current); // CHANGED
    }
}

int main(){
    //create an array of 5 nodes for testing
    Node **nodes = malloc(5 * sizeof(Node *));
    for(int i = 0; i < 5; i++){
        create_node(i, &nodes[i]);
    }
    
    // add_neighbour(nodes[0], nodes[1], 5);
    // add_neighbour(nodes[0], nodes[2], 5);
    // add_neighbour(nodes[0], nodes[3], 5);
    // add_neighbour(nodes[0], nodes[4], 1000);
    // add_neighbour(nodes[1], nodes[2], 25);
    // add_neighbour(nodes[1], nodes[3], 20);
    // add_neighbour(nodes[2], nodes[3], 0);
    // add_neighbour(nodes[3], nodes[4], 10);

    add_neighbour(nodes[0], nodes[1], 1);
    add_neighbour(nodes[0], nodes[2], 3);
    add_neighbour(nodes[1], nodes[3], 1);
    add_neighbour(nodes[2], nodes[3], 2);
    add_neighbour(nodes[3], nodes[4], 4);


    dijkstra(nodes[0], nodes[4]);
    printf("0-0 %f\n", nodes[0]->dist_from_start);
    printf("0-1 %f\n", nodes[1]->dist_from_start);
    printf("0-2 %f\n", nodes[2]->dist_from_start);
    printf("0-3 %f\n", nodes[3]->dist_from_start);
    printf("0-4 %f\n", nodes[4]->dist_from_start);

}

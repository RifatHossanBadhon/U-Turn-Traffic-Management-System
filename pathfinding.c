typedef struct
{
    int node;
    int cost;
} Edge;

typedef struct
{
    Edge *edges;
    int size;
    int capacity;
} AdjList;

typedef struct
{
    int node;
    int dist;
} PQNode;

typedef struct
{
    char cityName[NAME_LENGTH];
    int trafficLevel; 
    int accidents;    
    int construction; 
} TrafficCondition;

typedef struct
{
    char intersection[NAME_LENGTH];
    int signalState;
    int timer;       
} TrafficSignal;

typedef struct
{
    char location[NAME_LENGTH];
    int priority;  
    int inTransit; // 1 
} EmergencyVehicle;

int compare(const void *a, const void *b)
{
    return ((PQNode *)a)->dist - ((PQNode *)b)->dist;
}

void initAdjList(AdjList *list)
{
    list->edges = (Edge *)malloc(10 * sizeof(Edge));
    list->size = 0;
    list->capacity = 10;
    if (!list->edges)
    {
        fprintf(stderr, "Memory allocation failed for adjacency list\n");
        exit(EXIT_FAILURE);
    }
}
void addEdge(AdjList *list, int node, int cost)
{
    if (list->size == list->capacity)
    {
        list->capacity *= 2;
        Edge *newEdges = (Edge *)realloc(list->edges, list->capacity * sizeof(Edge));
        if (!newEdges)
        {
            fprintf(stderr, "Memory allocation failed for adjacency list\n");
            exit(EXIT_FAILURE);
        }
        list->edges = newEdges;
    }
    list->edges[list->size].node = node;
    list->edges[list->size].cost = cost;
    list->size++;
}
void freeAdjList(AdjList *list)
{
    free(list->edges);
}

void dijkstra(int src, int dest, AdjList adj[], int n, int *dist, int *prev)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    dist[src] = 0;

    PQNode *pq = (PQNode *)malloc(10 * sizeof(PQNode));

    int pqSize = 0, pqCapacity = 10;
    pq[pqSize++] = (PQNode){src, 0};

    while (pqSize > 0)
    {
        qsort(pq, pqSize, sizeof(PQNode), compare);
        PQNode current = pq[0];
        for (int i = 1; i < pqSize; i++)
        {
            pq[i - 1] = pq[i];
        }
        pqSize--;

        int pNode = current.node;

        for (int i = 0; i < adj[pNode].size; i++)
        {
            Edge child = adj[pNode].edges[i];
            int cNode = child.node;
            int cCost = child.cost;

            if (dist[pNode] + cCost < dist[cNode])
            {
                dist[cNode] = dist[pNode] + cCost;
                prev[cNode] = pNode;

                if (pqSize == pqCapacity)
                {
                    pqCapacity *= 2;
                    PQNode *newPq = realloc(pq, pqCapacity * sizeof(PQNode));
                    if (!newPq)
                    {
                        fprintf(stderr, "Memory allocation failed for priority queue\n");
                        free(pq);
                        exit(EXIT_FAILURE);
                    }
                    pq = newPq;
                }

                pq[pqSize++] = (PQNode){cNode, dist[cNode]};
            }
        }
    }

    free(pq);
}
void printPath(int *prev, int dest, char cities[][NAME_LENGTH])
{
    if (prev[dest] == -1)
    {
        printf("%s", cities[dest]);
        return;
    }
    printPath(prev, prev[dest], cities);
    printf(" -> %s", cities[dest]);
}
void loadCitiesAndConnections(const char *filename, AdjList adj[], char cities[][NAME_LENGTH], int *n)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("File not found. Creating a new file: %s\n", filename);
        file = fopen(filename, "w");
        if (!file)
        {
            perror("Error creating file");
            exit(EXIT_FAILURE);
        }

        fprintf(file, "0\n"); // Start with 0 cities
        fclose(file);
        return;
    }

    fscanf(file, "%d", n);
    for (int i = 0; i < *n; i++)
    {
        initAdjList(&adj[i]);
        fscanf(file, "%s", cities[i]);
    }

    char srcCity[NAME_LENGTH], destCity[NAME_LENGTH];
    int cost;
    while (fscanf(file, "%s %s %d", srcCity, destCity, &cost) != EOF)
    {
        int src = getCityIndex(srcCity, cities, n);
        int dest = getCityIndex(destCity, cities, n);

        addEdge(&adj[src], dest, cost);
        addEdge(&adj[dest], src, cost); // For undirected graph
    }

    fclose(file);
}
int getCityIndex(const char *city, char cities[][NAME_LENGTH], int *n)
{
    for (int i = 0; i < *n; i++)
    {
        if (strcmp(cities[i], city) == 0)
        {
            return i;
        }
    }
    strcpy(cities[*n], city);
    return (*n)++;
}
void addNewCities(const char *filename, AdjList adj[], char cities[][NAME_LENGTH], int *n)
{
    int newCitiesCount;
    printf("How many new cities do you want to add? ");
    scanf("%d", &newCitiesCount);

    for (int i = 0; i < newCitiesCount; i++)
    {
        char newCity[NAME_LENGTH];
        printf("Enter name of city %d: ", i + 1);
        scanf("%s", newCity);
        getCityIndex(newCity, cities, n);
    }

    char srcCity[NAME_LENGTH], destCity[NAME_LENGTH];
    int cost;

    printf("Enter connections in format [source destination cost]. Type 'done' to finish.\n");
    while (1)
    {
        printf("Connection: ");
        scanf("%s", srcCity);
        if (strcmp(srcCity, "done") == 0)
            break;

        scanf("%s %d", destCity, &cost);

        int src = getCityIndex(srcCity, cities, n);
        int dest = getCityIndex(destCity, cities, n);

        addEdge(&adj[src], dest, cost);
        addEdge(&adj[dest], src, cost);
    }

    FILE *file = fopen(filename, "w");
    if (!file)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d\n", *n);
    for (int i = 0; i < *n; i++)
    {
        fprintf(file, "%s\n", cities[i]);
    }

    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < adj[i].size; j++)
        {
            fprintf(file, "%s %s %d\n", cities[i], cities[adj[i].edges[j].node], adj[i].edges[j].cost);
        }
    }

    fclose(file);
}
void viewTrafficStatus(TrafficCondition conditions[], int numCities)
{
    printf("Viewing traffic status...\n");
    for (int i = 0; i < numCities; i++)
    {
        printf("City: %s, Traffic Level: %s, Accidents: %d, Construction: %s\n",
               conditions[i].cityName,
               conditions[i].trafficLevel == 0 ? "Light" : (conditions[i].trafficLevel == 1 ? "Moderate" : "Heavy"),
               conditions[i].accidents,
               conditions[i].construction ? "Yes" : "No");
    }
}
void controlTrafficSignals(TrafficSignal signals[], int numSignals)
{
    printf("Controlling traffic signals...\n");
    for (int i = 0; i < numSignals; i++)
    {
        // Simulate signal changes based on traffic conditions (simplified)
        if (signals[i].signalState == 2)
        { // Green
            signals[i].timer--;
            if (signals[i].timer <= 0)
            {
                signals[i].signalState = 0; // Switch to red
                signals[i].timer = 30;      // Reset timer
            }
        }
        else if (signals[i].signalState == 0)
        {
            signals[i].timer--;
            if (signals[i].timer <= 0)
            {
                signals[i].signalState = 1; // Switch to yellow
                signals[i].timer = 5;       // Short timer for yellow
            }
        }
        else if (signals[i].signalState == 1)
        {
            signals[i].timer--;
            if (signals[i].timer <= 0)
            {
                signals[i].signalState = 2; // Switch to green
                signals[i].timer = 45;      // Reset timer for green
            }
        }
        printf("Intersection: %s, Signal State: %s, Timer: %d seconds\n", signals[i].intersection,
               signals[i].signalState == 0 ? "Red" : (signals[i].signalState == 1 ? "Yellow" : "Green"),
               signals[i].timer);
    }
}

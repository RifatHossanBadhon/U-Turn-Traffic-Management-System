#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <limits.h>
#define i_size 60
#define NAME 100
#define PASS 8
#define MAX_CITIES 1000
#define NAME_LENGTH 50
#define MAX_SIGNALS 10

void Time(char tm[])
{
    time_t t;
    struct tm *tmp;
    time(&t);
    tmp = localtime(&t);
    strftime(tm, 50, "%x %I:%M%p", tmp);
}

typedef struct Accident
{
    char time[i_size];
    char accident_type[i_size];
    char vehicle_type[i_size];
    char number_plate[i_size];
    char place[i_size];
} accident;

// need to implement this  .... to all...
void get_input(char *str, size_t size)
{
    if (fgets(str, size, stdin) != NULL)
    {
        str[strcspn(str, "\n")] = '\0';
    }
}

int add_accident()
{
    accident ac;
    FILE *fp = fopen("accident.txt", "ab");
    if (fp == NULL)
    {
        printf("Error while opening the file\n");
        return 0;
    }
    printf("Accident Type: ");
    get_input(ac.accident_type, sizeof(ac.accident_type));
    printf("Vehicle Type: ");
    get_input(ac.vehicle_type, sizeof(ac.vehicle_type));
    printf("Number Plate: ");
    get_input(ac.number_plate, sizeof(ac.number_plate));
    printf("Accident Place: ");
    get_input(ac.place, sizeof(ac.place));
    Time(ac.time);

    fwrite(&ac, sizeof(ac), 1, fp);
    printf("\n\033[1;31m---- Info Is Added Successfully ----\n");
    printf("\n\033[1;32mAccident Type:\033[0m \033[1;33m%s\033[0m", ac.accident_type);
    printf("\n\033[1;32mVehicle Type:\033[0m \033[1;33m%s\033[0m", ac.vehicle_type);
    printf("\n\033[1;32mNumber Plate:\033[0m \033[1;33m%s\033[0m", ac.number_plate);
    printf("\n\033[1;32mAccident Place:\033[0m \033[1;33m%s\033[0m", ac.place);
    printf("\n\033[1;32mAccident Time:\033[0m \033[1;33m%s\033[0m\n", ac.time);
    fclose(fp);
}

void show_accident_list()
{
    FILE *fp = fopen("accident.txt", "rb");
    if (fp == NULL)
    {
        printf("Error while opeing the file\n");
        return;
    }
    // printf("\t\t\tShowing Information List\n");
    accident ac;
    if (fread(&ac, sizeof(ac), 1, fp) == 0)
    {
        printf("The list is empty\n");
        // printf("Press Enter to continue: ");
        // getchar();
        fclose(fp);
        return;
    }
    rewind(fp);
    printf("Occurrence\tVehicle Type\tNumber Plate\tAccident Place\tAccident Time\n");
    printf("----------\t------------\t------------\t--------------\t--------------\n");

    while (fread(&ac, sizeof(ac), 1, fp))
    {
        printf("%-12s\t%-12s\t%-12s\t%-14s\t%-14s\n", ac.accident_type, ac.vehicle_type, ac.number_plate, ac.place, ac.time);
    }

    fclose(fp);
}

typedef struct Vehicle_info
{
    char owner[i_size];
    char vechileType[i_size];
    char registrationNum[i_size];
    char registrationDate[i_size];

} vehicle;

void add_vehicle_info()
{
    vehicle v;
    FILE *fp = fopen("vehicle.txt", "ab");
    if (fp == NULL)
    {
        printf("Error while opening the file\n");
        return;
    }
    printf("\t\tVehicle Entry\n");
    printf("Enter Owner's Name: ");
    get_input(v.owner, sizeof(v.owner));
    printf("Enter Vechile Type: ");
    get_input(v.vechileType, sizeof(v.vechileType));
    printf("Enter Registration Number: ");
    get_input(v.registrationNum, sizeof(v.registrationNum));
    printf("Enter Registration Date (DD/MM/YYYY): ");
    get_input(v.registrationDate, sizeof(v.registrationDate));
    fwrite(&v, sizeof(v), 1, fp);
    printf("Owner's Name\tVehicle Type\tRegistration Number\tRegistration Date\n");
    printf("------------\t------------\t-------------------\t-----------------\n");
    printf("%-15s\t%-15s\t%-20s\t%-15s\n", v.owner, v.vechileType, v.registrationNum, v.registrationDate);

    fclose(fp);
}
void show_vehicle_list()
{

    FILE *fp = fopen("vehicle.txt", "rb");
    if (fp == NULL)
    {
        printf("Error while opeing the file\n");
        return;
    }
    // printf("\tVehicle Information\n");
    vehicle v;
    if (fread(&v, sizeof(v), 1, fp) == 0)
    {
        printf("The list is empty\n");
        // printf("Press Enter to continue: ");
        // getchar();
        fclose(fp);
        return;
    }
    rewind(fp);
    printf("Owner's Name\tVehicle Type\tRegistration Number\tRegistration Date\n");
    printf("------------\t------------\t-------------------\t-----------------\n");
    while (fread(&v, sizeof(v), 1, fp))
    {
        printf("%-15s\t%-15s\t%-20s\t%-15s\n", v.owner, v.vechileType, v.registrationNum, v.registrationDate);
    }

    fclose(fp);
}
// violation...
typedef struct Violation
{
    char owner[i_size];
    char vechileType[i_size];
    char registrationNum[i_size];
    char violation_type[i_size];

} violation;
void add_violation()
{
    violation v;
    FILE *fp = fopen("violation.txt", "ab");
    if (fp == NULL)
    {
        printf("Error while opening the file\n");
        return;
    }
    printf("Enter Owner's Name: ");
    get_input(v.owner, sizeof(v.owner));
    printf("Enter Vechile Type: ");
    get_input(v.vechileType, sizeof(v.vechileType));
    printf("Enter Registration Number: ");
    get_input(v.registrationNum, sizeof(v.registrationNum));
    printf("Enter Violation Type: ");
    get_input(v.violation_type, sizeof(v.violation_type));
    fwrite(&v, sizeof(v), 1, fp);
    printf("\nOwner's Name\tVehicle Type\tRegistration Number\tViolation Type\n");
    printf("------------\t------------\t-------------------\t---------------\n");
    printf("%-15s\t%-15s\t%-20s\t%-15s\n", v.owner, v.vechileType, v.registrationNum, v.violation_type);
    fclose(fp);
}
void show_violation_list()
{

    FILE *fp = fopen("violation.txt", "rb");
    if (fp == NULL)
    {
        printf("Error while opeing the file\n");
        return;
    }

    violation v;
    if (fread(&v, sizeof(v), 1, fp) == 0)
    {
        printf("The list is empty\n");
        // printf("Press Enter to continue: ");
        // getchar();
        fclose(fp);
        return;
    }
    rewind(fp);
    printf("\nOwner's Name\tVehicle Type\tRegistration Number\tViolation Type\n");
    printf("------------\t------------\t-------------------\t---------------\n");
    while (fread(&v, sizeof(v), 1, fp))
    {
        printf("%-15s\t%-15s\t%-20s\t%-15s\n", v.owner, v.vechileType, v.registrationNum, v.violation_type);
    }

    fclose(fp);
}
int delete_vehicle(char *file_name, char *registration_num)
{
    FILE *fp, *fp2;
    fp = fopen(file_name, "rb");
    if (fp == NULL)
    {
        printf("Error while opening %s file\n", file_name);
        return 0;
    }
    fp2 = fopen("copy.txt", "wb");
    if (fp2 == NULL)
    {
        printf("Error while creating the copy file\n");
        return 0;
    }
    int found = 0;
    if (strcmp(file_name, "vehicle.txt") == 0)
    {
        vehicle v;
        while (fread(&v, sizeof(v), 1, fp))
        {
            if (strcmp(v.registrationNum, registration_num) != 0)
            {
                fwrite(&v, sizeof(v), 1, fp2);
            }
            else
            {
                found = 1;
            }
        }
    }
    else if (strcmp(file_name, "accident.txt") == 0)
    {
        accident ac;
        while (fread(&ac, sizeof(ac), 1, fp))
        {
            if (strcmp(ac.number_plate, registration_num) != 0)
            {
                fwrite(&ac, sizeof(ac), 1, fp2);
            }
            else
            {
                found = 1;
            }
        }
    }
    else if (strcmp(file_name, "violation.txt") == 0)
    {
        violation v;
        while (fread(&v, sizeof(v), 1, fp))
        {
            if (strcmp(v.registrationNum, registration_num) != 0)
            {
                fwrite(&v, sizeof(v), 1, fp2);
            }
            else
            {
                found = 1;
            }
        }
    }

    fclose(fp);
    fclose(fp2);
    if (found)
    {
        remove(file_name);
        if (rename("copy.txt", file_name) != 0)
        {
            perror("Error while renaming the file to\n");
        }
        printf("Record with %s deleted successfully!\n", registration_num);
    }
    else
    {
        printf("Record with %s not found in %s\n", registration_num, file_name);
        remove("copy.txt");
    }
}
// adding new code over here

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
    int trafficLevel; // 0: Light, 1: Moderate, 2: Heavy
    int accidents;    // Number of accidents
    int construction; // 1: Construction, 0: No construction
} TrafficCondition;

typedef struct
{
    char intersection[NAME_LENGTH];
    int signalState; // 0: Red, 1: Yellow, 2: Green
    int timer;       // Timer for signal duration (seconds)
} TrafficSignal;

typedef struct
{
    char location[NAME_LENGTH];
    int priority;  // Priority level of the emergency vehicle
    int inTransit; // 1 if in transit, 0 otherwise
} EmergencyVehicle;

void initAdjList(AdjList *list);
void addEdge(AdjList *list, int node, int cost);
void freeAdjList(AdjList *list);
void dijkstra(int src, int dest, AdjList adj[], int n, int *dist, int *prev);
void printPath(int *prev, int dest, char cities[][NAME_LENGTH]);
void loadCitiesAndConnections(const char *filename, AdjList adj[], char cities[][NAME_LENGTH], int *n);
int getCityIndex(const char *city, char cities[][NAME_LENGTH], int *n);
void addNewCities(const char *filename, AdjList adj[], char cities[][NAME_LENGTH], int *n);
void viewTrafficStatus(TrafficCondition conditions[], int numCities);
void controlTrafficSignals(TrafficSignal signals[], int numSignals);
void handleEmergencyVehicles(EmergencyVehicle *emergency, TrafficSignal signals[], int numSignals);
void handleVIPRequest(TrafficSignal signals[], int numSignals);
void menuTrafficManagement(TrafficCondition conditions[], TrafficSignal signals[], EmergencyVehicle *emergency, int numCities, int numSignals);
void menuShortestPath(char cities[][NAME_LENGTH], AdjList adj[], int *n);
void showShortestPath(char cities[][NAME_LENGTH], AdjList adj[], int n);

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
void handleEmergencyVehicles(EmergencyVehicle *emergency, TrafficSignal signals[], int numSignals)
{
    printf("Handling emergency vehicles...\n");
    if (emergency->inTransit)
    {
        printf("Emergency vehicle at %s, Priority: %d\n", emergency->location, emergency->priority);
        // Simulate clearing the path for the emergency vehicle
        for (int i = 0; i < numSignals; i++)
        {
            if (strstr(signals[i].intersection, emergency->location) != NULL)
            {
                signals[i].signalState = 2; // Set to green
                signals[i].timer = 10;      // Short timer to clear the path
                printf("Traffic signal at %s overridden to green for emergency vehicle.\n", signals[i].intersection);
            }
        }
    }
    else
    {
        printf("No emergency vehicle currently in transit.\n");
    }
}
void handleVIPRequest(TrafficSignal signals[], int numSignals)
{
    printf("Handling VIP request...\n");
    char vipDestination[NAME_LENGTH];
    printf("Enter VIP destination: ");
    scanf("%s", vipDestination);

    // Simulate VIP route prioritization
    for (int i = 0; i < numSignals; i++)
    {
        if (strstr(signals[i].intersection, vipDestination) != NULL)
        {
            signals[i].signalState = 2; // Set to green
            signals[i].timer = 20;      // Short timer for VIP passage
            printf("Traffic signal at %s set to green for VIP.\n", signals[i].intersection);
        }
    }
}

// look at here......

void menuShortestPath(char cities[][NAME_LENGTH], AdjList adj[], int *n)
{
    int choice;

    while (1)
    {
        printf("\nShortest Path Menu:\n");
        printf("1. Add new cities and connections\n");
        printf("2. Show shortest path between cities\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addNewCities("cities.txt", adj, cities, n);
            break;
        case 2:
            showShortestPath(cities, adj, *n);
            break;
        case 3:
            return;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void showShortestPath(char cities[][NAME_LENGTH], AdjList adj[], int n)
{
    char startCity[NAME_LENGTH], endCity[NAME_LENGTH];
    printf("Enter the source city: ");
    scanf("%s", startCity);
    printf("Enter the destination city: ");
    scanf("%s", endCity);

    int src = getCityIndex(startCity, cities, &n);
    int dest = getCityIndex(endCity, cities, &n);

    int dist[MAX_CITIES], prev[MAX_CITIES];
    dijkstra(src, dest, adj, n, dist, prev);

    if (dist[dest] == INT_MAX)
    {
        printf("No path exists between %s and %s.\n", startCity, endCity);
    }
    else
    {
        printf("Shortest path: ");
        printPath(prev, dest, cities);
        printf("\nTotal distance: %d\n", dist[dest]);
    }
}

void Admin_panel(char name[])
{

    // testing
    srand(time(NULL)); // Seed random number generator
    TrafficCondition conditions[MAX_CITIES];
    TrafficSignal signals[MAX_CITIES];
    EmergencyVehicle emergency = {"CityB", 5, 1}; // Emergency vehicle in transit at CityB

    // Initialize sample data for traffic conditions and signals
    for (int i = 0; i < 5; i++)
    {
        snprintf(conditions[i].cityName, NAME_LENGTH, "City%d", i + 1);
        conditions[i].trafficLevel = rand() % 3;
        conditions[i].accidents = rand() % 3;
        conditions[i].construction = rand() % 2;
    }

    // Initialize signals
    for (int i = 0; i < 3; i++)
    {
        snprintf(signals[i].intersection, NAME_LENGTH, "Intersection%d", i + 1);
        signals[i].signalState = rand() % 3;
        signals[i].timer = (rand() % 30) + 15;
    }

    // Initialize graph for shortest path
    char cities[MAX_CITIES][NAME_LENGTH];
    AdjList adj[MAX_CITIES];
    int n = 0;

    for (int i = 0; i < MAX_CITIES; i++)
    {
        initAdjList(&adj[i]);
    }

    loadCitiesAndConnections("cities.txt", adj, cities, &n);

    // Cleanup
    for (int i = 0; i < n; i++)
    {
        freeAdjList(&adj[i]);
    }

    // end test
    printf("\033[1;32m%s, Welcome to the control room\n", name);
    while (1)
    {

        printf("1.View Traffic Status\n2.Control Traffic Signals\n3.Shortest Path\n");
        printf("4.Incident Management\n5.Traffic Violations Records\n6.Information Records\n7.Vip request\n8.Exit\n");
        int choice;
        printf("Select Menu: ");

        scanf("%d", &choice);
        system("cls");
        getchar();
        switch (choice)
        {
        case 1:
            viewTrafficStatus(conditions, 5);
            
            break;
        case 2:
            controlTrafficSignals(signals, 3);
            break;
        case 3: // shirt+alt+f

            printf("\033[1;32mShortest Path...\n");
            menuShortestPath(cities, adj, &n);
            break;
        case 4: // will only show here ...
            while (1)
            {
                printf("1.Add Incident\n2.Remove Incident\n3.Show Incident List\n4.Back\n");

                int choice;
                printf("Select Menu: ");
                scanf("%d", &choice);
                getchar();
                if (choice == 1)
                {
                    add_accident();
                    printf("\033[1;32mPress enter to go back: ");
                    // \033[1;32m for green
                    // \033[1;31m for red
                    getchar();
                    system("cls");
                    system("cls");
                }
                if (choice == 2)
                {
                    printf("\tDelete Incident From the list\n");
                    char reg_num[i_size];
                    printf("Enter the registration number: ");
                    get_input(reg_num, sizeof(reg_num));
                    delete_vehicle("accident.txt", reg_num);
                    printf("\033[1;32mPress enter to go back: ");
                    getchar();
                }
                if (choice == 3)
                {
                    show_accident_list();
                    printf("Press enter to go back: ");
                    getchar();
                }
                if (choice == 4)
                {
                    printf("Returning Back....\n");
                    break;
                }
            }
            break;
        case 5:
            show_violation_list();
            printf("Press enter to go back: ");
            getchar();
            break;
        case 6:
            show_vehicle_list();
            printf("Press enter to go back: ");
            getchar();
            break;
        case 7:
            handleVIPRequest(signals, 3);
            printf("Press enter to go back..\n");
            break;
        case 8:
            printf("Returning Back...\n");
            return;
        default:
            puts("Invalid Choice..Returning back...");

            // printf("\033[0m\n");
            break;
        }
    }
}

void Police_panel(char name[])
{
    //testing....

    TrafficSignal signals[MAX_CITIES];
    EmergencyVehicle emergency = {"CityB", 5, 1};

    //ending...
    printf("\033[1;31mTraffic Police %s\n", name);
    while (1)
    {
        printf("1.Emergency request\n2.Report Traffic Violations\n3.Issue Traffic Warnings\n");
        printf("4.Vip request\n5.Report Accident\n6.Register Vehicle info\n7.Eixt\n");
        int choice;

        printf("Select Menu: ");
        scanf("%d", &choice);
        system("cls");
        getchar();

        switch (choice)
        {
        case 1:
            handleEmergencyVehicles(&emergency, signals, 3);
            printf("Press enter to go back: ");
            getchar();
            break;
        case 2:
            while (1)
            {
                printf("1.Add Violation\n2.Remove Violation info\n3.Show Violation  List\n4.Back\n");
                int choice;
                printf("Select Menu: ");
                scanf("%d", &choice);
                getchar();
                if (choice == 1)
                {
                    add_violation();
                    printf("\033[1;31mPress enter to go back: ");
                    getchar();
                    system("cls");
                    system("cls");
                }
                if (choice == 2)
                {
                    printf("\tDelete Violation From the list\n");
                    char reg_num[i_size];
                    printf("Enter the registration number: ");
                    get_input(reg_num, sizeof(reg_num));
                    delete_vehicle("violation.txt", reg_num);
                    printf("\033[1;31mPress enter to go back: "); // add dual color over here
                    getchar();
                }
                if (choice == 3)
                {
                    show_violation_list();
                    printf("Press enter to go back: ");
                    getchar();
                }
                if (choice == 4)
                {
                   printf("Returning Back....\n");
                    break;
                }
            }
            break;
        case 4:
            handleVIPRequest(signals, 3);
            
            break;
        case 5:
            while (1)
            {
                printf("1.Add Accident\n2.Remove Info\n3.Show Accident List\n4.Back\n");
                int choice;
                printf("Select Menu: ");
                scanf("%d", &choice);
                getchar();
                if (choice == 1)
                {
                    add_accident();
                    char c;
                    printf("\033[1;31mPress enter to go back: ");
                    scanf("%c", &c);
                    system("cls");
                    system("cls");
                }
                if (choice == 2)
                {
                    printf("\tDelete Accident From the list\n");
                    char reg_num[i_size];
                    printf("Enter the registration number: ");
                    get_input(reg_num, sizeof(reg_num));
                    delete_vehicle("accident.txt", reg_num);
                    printf("\033[1;31mPress enter to go back: "); // add dual color over here
                    getchar();
                }
                if (choice == 3)
                {
                    show_accident_list();
                    printf("Press enter to go back: ");
                    getchar();
                }
                if (choice == 4)
                {
                    printf("Returning Back....\n");
                    break;
                }
            }

            break;
        case 6:
            while (1)
            {
                printf("1.Add Vehicle\n2.Remove Vehicle Info\n3.Show Vehicle List\n4.Back\n");
                int choice;
                printf("Select Menu: ");
                scanf("%d", &choice);
                getchar();
                if (choice == 1)
                {
                    add_vehicle_info();
                    char c;
                    printf("\033[1;31mPress enter to go back: ");
                    getchar();
                    system("cls");
                    system("cls");
                }
                if (choice == 2)
                {
                    printf("\tDelete Vehicle From the list\n");
                    char reg_num[i_size];
                    printf("Enter the registration number: ");
                    get_input(reg_num, sizeof(reg_num));
                    delete_vehicle("vehicle.txt", reg_num);
                    printf("\033[1;31mPress enter to go back: ");
                    getchar();
                }
                if (choice == 3)
                {
                    show_vehicle_list();
                    printf("Press enter to go back: ");
                    getchar();
                }
                if (choice == 4)
                {
                    printf("Returning Back....\n");
                    break;
                }
            }
            break;
        case 7:
            printf("Returning Back..\n");
            return;
        default:
            puts("Invalid selection. Please try again....");
            // break; // infinite testing...
        }
    }
}

void AddToFile(int choice, char *name, char *pass)
{

    FILE *ft = fopen("traffic.text", "a");
    if (ft == NULL)
    {
        printf("Error while creating the file");
        return;
    }
    fprintf(ft, "%d %s %s\n", choice, name, pass);
    fclose(ft);
}

void signup()
{
    system("cls");
    char name[NAME], password[PASS];
    int choice;
    printf("1. As a Police\n2. As an Admin\n3. Back\n");
    printf("Select Menu: ");
    scanf("%d", &choice);
    getchar();
    if (choice == 1 || choice == 2)
    {
        printf("Enter Name: ");
        get_input(name, sizeof(name));
        printf("Enter Password(8): ");
        get_input(password, sizeof(password));
        AddToFile(choice, name, password);
        system("cls");
        printf("Account is Created Successfully! Returning to the main menu...\n\n");
    }
    else if (choice == 3)
    {
        system("cls");
        printf("Returning Back...\n\n");
    }

    else
    {
        printf("Invalid Selection !. Returning to the main menu...\n\n");
    }
}

int verify(char name[], char pass[])
{
    int choice;
    char fname[NAME];
    char fpass[PASS];
    FILE *ft = fopen("traffic.text", "r");
    if (ft == NULL)
    {
        printf("Error While Opening the File");
    }

    while (fscanf(ft, "%d %s %s", &choice, fname, fpass) != EOF)
    {

        if (strcmp(name, fname) == 0 && strcmp(pass, fpass) == 0)
        {
            fclose(ft);
            return choice;
        }
    }
    fclose(ft);
    return 0;
}

void login()
{
    char name[NAME], password[PASS];
    int choice;
    printf("Enter Name: ");
    get_input(name, sizeof(name));
    printf("Enter Password: ");
    get_input(password, sizeof(password));
    choice = verify(name, password);
    if (choice == 1)
    {
        system("cls");
        printf("\t\t\tLogged In As Police\n");
        Police_panel(name);
    }

    else if (choice == 2)
    {
        system("cls");
        system("cls");
        printf("\t\t\tLogged In As Admin\n");
        Admin_panel(name);
    }
    else
    {
        printf("Invalid Choice Returning to the main Menu...\n\n");
    }
}

void account_creation()
{
    int choice;
    printf("\t\t\t\t\033[1;32mWelcome to the U-Turn Account Section\033[0m\n\n\n");
    while (1)
    {
        printf("\033[1;33m1. Sign-Up\n2. Log-In\n3. Exit\n");
        printf("Select Menu: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            signup();
            break;
        case 2:
            login();
            break;
        case 3:
            printf("Exited Successfully :)");
            exit(1);
            break;
        default:
            system("cls");
            printf("Invalid selection. Please try again.\n\n");

            break;
        }
    }
} 

void print_car(int position)
{
    printf("\033[H\033[J");
    for (int i = 0; i < position; i++)
    {
        printf(" ");
    }
    printf("\e[1;94m   ____\e[0m\n");
    for (int i = 0; i < position; i++)
    {
        printf(" ");
    }
    printf("\e[1;93m  //|\\\\\\\e[0m\e[1;94m_____\e[0m\n");
    for (int i = 0; i < position; i++)
    {
        printf(" ");
    }
    printf("\e[1;91m |\e[1;97m _      _  |\n");
    for (int i = 0; i < position; i++)
    {
        printf(" ");
    }
    printf("\e[1;94m '-()-----()-'\e[0m\n");
}

void print_message(int start_position, const char *message, int length)
{
    for (int i = 0; i < start_position; i++)
    {
        printf(" ");
    }
    printf("\e[32m");
    for (int i = 0; i < length; i++)
    {
        printf("%c", message[i]);
    }
    printf("\e[0m\n");
}

void Car_Animation()
{
    int car_stop_position = 60;
    int total_steps = car_stop_position + strlen("Welcome to U-Turn");
    int duration_in_microseconds = 5000000;
    int delay_per_step = duration_in_microseconds / total_steps;

    const char *message = "\t\t\t\t\t\033[1;32mWelcome to the U-Turn\033[0m\n";
    int message_length = 0;

    struct timespec ts;
    ts.tv_sec = delay_per_step / 1000000;
    ts.tv_nsec = (delay_per_step % 1000000) * 1000;

    for (int position = 0; position < total_steps; position++)
    {
        if (position <= car_stop_position)
        {
            print_car(position);
        }
        else
        {
            print_car(car_stop_position);
        }

        if (position >= 6 && message_length < strlen(message))
        {
            print_message(6, message, message_length);
            message_length++;
        }
        else if (message_length >= strlen(message))
        {
            print_message(6, message, message_length);
        }

        nanosleep(&ts, NULL);
    }
    printf("\033[H\033[J");
}

int main()
{
    Car_Animation();
    account_creation();
    return 0;
}

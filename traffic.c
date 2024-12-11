
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
                    printf("\033[1;31mPress enter to go back: "); 
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
                    printf("\033[1;31mPress enter to go back: "); 
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

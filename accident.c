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

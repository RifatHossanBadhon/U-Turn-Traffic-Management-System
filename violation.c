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

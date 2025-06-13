#define _CRT_SECURE_NO_WARNINGS
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"
#define YELLOW "\x1b[33m"
#define CYAN   "\x1b[36m"
#include<stdio.h>
#include<string.h>
#include <windows.h>

// Function declarations
// ROLES 
void admin();
void doctor();
void patient();
//CREDITS
void showCredits();
// @ ADMIN 
void addPatient();
void addDoctor();
void deletePatient();
void deleteDoctor();
// GENERAL
void changePassword();
// @ DOCTOR
void patientEnquiry();
void makePatReport();
void viewDocDetails(int index);
void modifyDocDetails();

// Global variables
char n[50], diag[100], pres[100], note[200], followUp[50];
int attempt, choiceA, ageP[100], patientCount = 0, doctorCount = 0, ageD[100], exp[100], maxP = 200, index, id, adminPassword = 1234, docPassword = 1234, patPassword = 1234;
char nameP[100][50], diseaseP[100][50], genderP[100][50], more, specialization[100][50], nameD[100][50], genderD[100][50];

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char name[50], password[50];
    int role, attempts = 0;
   // printf(BLUE);
    SetConsoleTextAttribute(hConsole, 3);
    printf("                                   _________                                    \n");
    printf("                                  |  _   _  |                                   \n");
    printf("                                  | | | | | |                                   \n");
    printf("                                  | |_| |_| |                                   \n");
    printf("                                  |  _   _  |                                   \n");
    printf("                                  | | | | | |                                   \n");
    printf("                                  | |_| |_| |                                   \n");
    printf("                                  |    +    |                                   \n");
    printf("                                  |    +    |                                   \n");
    printf("                                  |  +++++  |                                   \n");
    printf("                                  |    +    |                                   \n");
    printf("                              ____|____+____|___                                \n");
    printf("                             |                  |                               \n");
    printf("                             |   @ HOSPITAL @   |                               \n");
    printf("                             |__________________|                               \n");
    printf(RESET);


    printf("***********************************************************************************\n\n");
    printf( "| "CYAN BOLD "                       HOSPITAL MANAGEMENT SYSTEM                               " RESET"|\n\n" );
    printf("-----------------------------------------------------------------------------------\n\n");
    printf(BOLD "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAIN MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" RESET);
    printf("***********************************************************************************\n\n");
    do {
        printf(BOLD "\tENTER YOUR CHOICE (1-4):\n" RESET);
        printf(GREEN "\t1. RECEPTIONIST\n" RESET);
        printf(YELLOW "\t2. DOCTOR\n" RESET);
        printf("\t3. PATIENT\n");
        printf(RED "\t4. EXIT\n" RESET);
        printf("\n\tENTER HERE :");
        scanf("%d", &role);

        if (role == 1)
        {
            int loginSuccess = 0;
            for (int i = 0; i < 3; i++)
            {
                printf("\tEnter username: ");
                scanf("%s", name);
                printf("\tEnter password: ");
                scanf("%s", password);
                if (strcmp(name, "admin") == 0 && strcmp(password, "1234") == 0)
                {
                    
                    printf(GREEN BOLD"\n\t\tLOGIN SUCCESSFUL \n"RESET );
                    admin();
                    loginSuccess = 1;
                    break;
                }
                else
                {
                    printf(YELLOW "\n\t\tINCORRECT USERNAME OR PASSWORD .TRY AGAIN [!]: \n" RESET);
                }
            }
            if (!loginSuccess)
            {
                printf(RED BOLD "\n\t\t   TRIED MANY TIMES \n" RESET);
                showCredits();
                return 0;
            }
        }
        else if (role == 2)
        {
            int loginSuccess = 0;
            for (int i = 0; i < 3; i++)
            {
                printf("\tEnter username: ");
                scanf("%s", name);
                printf("\tEnter password: ");
                scanf("%s", password);
                if (strcmp(name, "doctor") == 0 && strcmp(password, "1234") == 0)
                {
                    printf(GREEN BOLD "\n\t\tLOGIN SUCCESSFUL  [✔]\n" RESET);
                    doctor();
                    loginSuccess = 1;
                    break;
                }
                else
                {
                    printf(YELLOW "\n\t\tINCORRECT USERNAME OR PASSWORD [✗] TRY AGAIN [!]: \n" RESET);
                }
            }
            if (!loginSuccess)
            {
                printf(RED BOLD "\n\t\t TRIED MANY TIMES \n" RESET);
                showCredits();
                return 0;
            }
        }
        else if (role == 3)
        {
            int loginSuccess = 0;
            for (int i = 0; i < 3; i++)
            {
                printf("\tEnter username: ");
                scanf("%s", name);
                printf("\tEnter password: ");
                scanf("%s", password);
                if
                    (strcmp(name, "patient") == 0 && strcmp(password, "1234") == 0) 
                {
                    printf(GREEN BOLD "\n\t\tLOGIN SUCCESSFUL  [✔]\n" RESET);
                    patient();
                    loginSuccess = 1;
                    break;
                }
                else
                {
                    printf(YELLOW "\n\t\tINCORRECT USERNAME OR PASSWORD [✗] TRY AGAIN [!]: \n" RESET);
                }
            }
            if (!loginSuccess)
            {
                printf(RED BOLD "\n\t\t [✗] [✗] [✗]  TRIED MANY TIMES [✗] [✗] [✗]\n" RESET);
                showCredits();
                return 0;
            }
        }
        else if (role == 4)
        {
            printf(RED BOLD "\n\t\t........................EXITING FROM THE SYSTEM ..........................\n" RESET);
            showCredits();
            return 0;
        }
        else
        {
            printf(YELLOW "\n\t\tINVALID CHOICE ENTERED  [✗] TRY AGAIN [!] : \n" RESET);
            attempts++;
        }
    } while (attempts < 3);

    if (attempts >= 3)
    {
        printf(RED BOLD "\n\t\t [✗] [✗] [✗]  TRIED MANY TIMES [✗] [✗] [✗]\n" RESET);
    }
    showCredits();
    return 0;
}
void admin()
{
    int exitAdmin = 0;
    while (!exitAdmin)
    {
        printf(BLUE BOLD "\n\tChoose (1-8):\n" RESET);
        printf("\t1.Add Patient Record\n");
        printf("\t2.Add Doctor Record\n");
        printf("\t3.Delete Patient Record\n");
        printf("\t4.Delete Doctor Record\n");
        printf("\t5.Password change\n");
        printf("\t6.Exit\n");
        printf("\n\tEnter your choice:");
        scanf("%d", &choiceA);
        switch (choiceA)
        {
        case 1:
        {
            addPatient();
            break;
        }
        case 2:
        {
            addDoctor();
            break;
        }
        case 3:
        {
            deletePatient();
            break;
        }
        case 4:
        {
            deleteDoctor();
            break;
        }
        case 5:
        {
            changePassword();
            break;
        }
        case 6:
        {

            printf(CYAN BOLD "\n\t\t............EXITING ADMIN PANEL..........\n" RESET);
            main();
            return;
        }
        default:
        {
            printf(YELLOW "\n\t\tInvalid Choice [✗] ..... Enter Again :  \n" RESET);
            break;
        }
        }
    }
}
void doctor()
{
    int exitDoctor = 0;
    while (!exitDoctor)
    {
        printf(BOLD "\n\tChoose (1-6):\n" RESET);
        printf("\t1.Patient Enquiry\n");
        printf("\t2.Make Patient Report\n");
        printf("\t3.View Doctor Details\n");
        printf("\t4.Password change\n");
        printf("\t5.Exit\n");
        printf("\n\tEnter your choice:");
        scanf("%d", &choiceA);
        switch (choiceA)
        {
        case 1:
        {
            patientEnquiry();
            break;
        }
        case 2:
        {
            makePatReport();
            break;
        }
        case 3:
        {
            viewDocDetails(index);
            break;
        }

        case 4:
        {
            changePassword();
            break;
        }
        case 5:
        {

            printf(CYAN BOLD"\n\t\t........................EXITING DOCTOR PANEL..........................\n" RESET);
            main();
            return;
        }
        default:
        {
            printf(YELLOW "\n\t\tInvalid Choice [✗] ..... Enter Again :  \n" RESET);
            break;
        }
        }
    }
}

void patient()
{
    printf("\n\tYou can see your report here");
    printf("\n\tEnter your ID:");
    scanf("%d", &id);
    if (id <= 0 || id > maxP)
    {
        printf(YELLOW BOLD" \n\t......... Invalid Patient ID [✗] ..... \n" RESET);
        return;
    }
    index = id - 1;
    printf("\n\tPatient ID : %d", id);
    printf("\n\tPatient Name : %s", nameP[index]);
    printf("\n\tPatient Age : %d", ageP[index]);
    printf("\n\tPatient Gender : %d", genderP[index]);
    printf("\n\tDiagnosis : %s", diag);
    printf("\n\tPrescription  : %s", pres);
    printf("\n\tDoctor's Notes  : %s", note);
    printf("\n\tFollow Up Date : %s\n", followUp);
    return;

}

void makePatReport()
{
    int age;
    printf(BLUE BOLD" \n\t @@@@@@@@@------ CREATE PATIENT REPORT ------@@@@@@@@@ " RESET);
    printf("\n\tEnter Patient ID : ");
    scanf("%d", &id);
    if (id <= 0 || id > maxP)
    {
        printf(YELLOW  BOLD" \n\t......... Invalid Patient ID [✗] ..... \n" RESET);
        return;
    }
    getchar();
    index = id - 1;
    printf(CYAN BOLD"\n\t @@@@@@@@@-------- PATIENT DETAILS --------@@@@@@@@@\n\n" RESET);
    printf("\tName   : %s\n", nameP[index]);
    printf("\tAge    : %d\n", ageP[index]);
    printf("\tGender : %s\n", genderP[index]);
    printf("\tDisease: %s\n", diseaseP[index]);
    printf("\n\tEnter Diagnosis: ");
    fgets(diag, sizeof(diag), stdin);
    diag[strcspn(diag, "\n")] = '\0';
    printf("\tEnter Prescription : ");
    fgets(pres, sizeof(pres), stdin);
    pres[strcspn(pres, "\n")] = '\0';
    printf("\tEnter Doctor's Notes : ");
    fgets(note, sizeof(note), stdin);
    note[strcspn(note, "\n")] = '\0';
    printf("\tEnter Follow Up Date (DD/MM/YYYY): ");
    fgets(followUp, sizeof(followUp), stdin);
    followUp[strcspn(followUp, "\n")] = '\0';
    printf("\t----------------------------------------------------------------------------------");
    printf("\n\t----------------------------------------------------------------------------------");
    printf("\n\tPatient ID : %d", id);
    printf("\n\tPatient Name : %s", nameP[index]);
    printf("\n\tPatient Age : %d", ageP[index]);
    printf("\n\tPatient Gender : %d", genderP[index]);
    printf("\n\tDiagnosis : %s", diag);
    printf("\n\tPrescription  : %s", pres);
    printf("\n\tDoctor's Notes  : %s", note);
    printf("\n\tFollow Up Date : %s", followUp);
    printf("\n\t----------------------------------------------------------------------------------");
    printf("\n\t----------------------------------------------------------------------------------");
    printf(GREEN BOLD"\n\tPATIENT REPORT MADE SUCCESSFULLY  \n" RESET);


}
void viewDocDetails(int index)
{
    printf("------------------------------------------------------------------------------------------\n");
    printf("\n------------------------------------------------------------------------------------------\n");
    printf(BLUE  BOLD"\t @@@@@@@@@@@@@@ DOCTOR'S DETAILS @@@@@@@@@@@@@@@  \n" RESET);
    if (doctorCount == 0)
    {
        printf(RED "\n\t........No doctor records found..........\n" RESET);
        return;
    }
    for (int i = 0; i < doctorCount; i++)
    {
        printf(RED"-----------------------------------------\n"RESET);
        printf("\n\tDoctor's ID : %d\n", i + 1);
        printf("Doctor Name  : %s\n", nameD[i]);
        printf("Doctor Age   : %d\n", ageD[i]);
        printf("Doctor Gender  : %s\n", genderD[i]);
        printf("Doctor Specialization  : %s\n", specialization[i]);
        printf("Years of Experience : %d  years\n", exp[i]);
        printf(RED"-----------------------------------------\n"RESET);
    }
    printf("------------------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------------------\n");
}

void patientEnquiry()
{
    int pID;
    printf("\tEnter patient ID: ");
    scanf("%d", &pID);

    if (pID <= 0 || pID > maxP)
    {
        printf(YELLOW BOLD " \n\t......... Invalid Patient ID [✗] ..... \n" RESET);
        return;
    }

    int index = pID - 1;
    printf(BLUE BOLD"\n\t @@@@@@@@@-------- PATIENT DETAILS --------@@@@@@@@@\n\n" RESET);
    printf("\tName  : %s\n", nameP[index]);
    printf("\tAge   : %d\n", ageP[index]);
    printf("\tGender: %s\n", genderP[index]);
    printf("\tHistory: %s\n", diseaseP[index]);

    char symptoms[100], diagnosis[100];
    int medCount = 0, testCount = 0;
    char test[10][50], med[10][50];

    getchar();
    printf("\tEnter Symptoms: ");
    fgets(symptoms, sizeof(symptoms), stdin);
    symptoms[strcspn(symptoms, "\n")] = '\0';

    printf("\tEnter Diagnosis: ");
    fgets(diagnosis, sizeof(diagnosis), stdin);
    diagnosis[strcspn(diagnosis, "\n")] = '\0';

    printf("\tEnter No. of Medicines to prescribe: ");
    scanf("%d", &medCount);
    getchar();
    for (int i = 0; i < medCount; i++)
    {
        printf("\tEnter Medicine %d Name: ", i + 1);
        fgets(med[i], sizeof(med[i]), stdin);
        med[i][strcspn(med[i], "\n")] = '\0';
    }

    printf("\tEnter No. of Medical Tests to prescribe: ");
    scanf("%d", &testCount);
    getchar();
    for (int i = 0; i < testCount; i++)
    {
        printf("\tEnter Medical Test %d Name: ", i + 1);
        fgets(test[i], sizeof(test[i]), stdin);
        test[i][strcspn(test[i], "\n")] = '\0';
    }

    printf(BLUE BOLD "\n\t----- Consultation Summary -----\n" RESET);
    printf("\tSymptoms: %s\n", symptoms);
    printf("\tDiagnosis: %s\n", diagnosis);
    printf("\tMedicines Prescribed: ");
    for (int i = 0; i < medCount; i++)
    {
        printf("%s%s", med[i], i < medCount - 1 ? ", " : "\n");
    }
    printf("\tMedical Tests Prescribed: ");
    for (int i = 0; i < testCount; i++)
    {
        printf("%s%s", test[i], i < testCount - 1 ? ", " : "\n");
    }
    printf(GREEN BOLD "\n\t@@@@@@ - CONSULTATION COMPLETED - @@@@@@\n" RESET);

}

void addPatient()
{
    // NAME
    do
    {
        getchar();
        printf("\n\tEnter Patient's Name:");
        do
        {
            fgets(nameP[patientCount], sizeof(nameP[0]), stdin);
            nameP[patientCount][strcspn(nameP[patientCount], "\n")] = '\0';
            if (strcmp(nameP[patientCount], "") == 0)
            {
                if (id <= 0 || id > maxP)
                {
                    printf(YELLOW " \n\t............. Invalid Patient Name [✗] ......... \n" RESET);
                    return;
                }
            }

        } while (strcmp(nameP[patientCount], "") == 0 ||
            strcmp(nameP[patientCount], " ") == 0);

        // AGE
        printf("\tEnter Patient's age:");
        do
        {
            scanf("%d", &ageP[patientCount]);
            if (ageP[patientCount] <= 0)
            {
                if (id <= 0 || id > maxP)
                {
                    printf(YELLOW " \n\t............. Invalid Patient Age [✗]  Try Again [!]......... \n" RESET);
                    return;
                }
            }
        } while (getchar() != '\n');

        // DISEASE
        printf("\tEnter Patients disease:");
        do
        {
            fgets(diseaseP[patientCount], sizeof(diseaseP[0]), stdin);
            diseaseP[patientCount][strcspn(diseaseP[patientCount], "\n")] = '\0';
            if (strcmp(diseaseP[patientCount], "") == 0)
            {
                printf(YELLOW " \n\t............. Invalid Disease [✗]  Try Again [!]......... \n" RESET);
            }
        } while (strcmp(diseaseP[patientCount], "") == 0 ||
            strcmp(diseaseP[patientCount], " ") == 0);

        // GENDER 
        printf("\tEnter Your Gender  (Male/ Female / Other): ");
        do
        {
            fgets(genderP[patientCount], sizeof(genderP[0]), stdin);
            genderP[patientCount][strcspn(genderP[patientCount], "\n")] = '\0';

            if (!(strcmp(genderP[patientCount], "Female") == 0 ||
                strcmp(genderP[patientCount], "Male") == 0 ||
                strcmp(genderP[patientCount], "Other") == 0))

            {
                printf(YELLOW " \n\t............. Invalid Gender [✗]  Try Again [!]......... \n" RESET);
            }
        } while (strcmp(genderP[patientCount], "") == 0 ||
            strcmp(genderP[patientCount], " ") == 0);

        printf(BLUE "\n\t [Added] ,Patient ID : %d , Name : %s , Age : %d  Disease: %s, Gender : %s" GREEN,
            patientCount + 1,
            nameP[patientCount],
            ageP[patientCount],
            diseaseP[patientCount],
            genderP[patientCount]);


        patientCount++;
        getchar();
        printf(BLUE "\n\t ..................Do you want to add more Patient?  [Y / N]........... " RESET);
        scanf(" %c", &more);
    } while (more == 'y' || more == 'Y');
    if (more == 'n' || more == 'N')
    {
        admin();
    }
}


void addDoctor()
{
    char more;
    do
    {
        // Clear leftover input
        while (getchar() != '\n');

        //NAME 
        do
        {
            printf("\tEnter Doctor's Name: ");
            fgets(nameD[doctorCount], sizeof(nameD[0]), stdin);
            nameD[doctorCount][strcspn(nameD[doctorCount], "\n")] = '\0';

            if (strlen(nameD[doctorCount]) == 0 || strcmp(nameD[doctorCount], " ") == 0)
            {
                printf(YELLOW " \n\t............. Invalid Doctor Name  [✗]  Try Again [!]......... \n" RESET);
            }
        } while (strlen(nameD[doctorCount]) == 0 || strcmp(nameD[doctorCount], " ") == 0);

        // AGE
        do
        {
            printf("\tEnter Doctor's Age: ");
            if (scanf("%d", &ageD[doctorCount]) != 1 || ageD[doctorCount] <= 0)
            {
                printf(YELLOW " \n\t............. Invalid Doctor Age  [✗]  Try Again [!]......... \n" RESET);
                while (getchar() != '\n');
                ageD[doctorCount] = 0;
            }
            else
            {
                while (getchar() != '\n');
                break;
            }
        } while (ageD[doctorCount] <= 0);

        // SPECIALIZATION
        do {
            printf("\tEnter Doctor's Specialization: ");
            fgets(specialization[doctorCount], sizeof(specialization[0]), stdin);
            specialization[doctorCount][strcspn(specialization[doctorCount], "\n")] = '\0';

            if (strlen(specialization[doctorCount]) == 0 || strcmp(specialization[doctorCount], " ") == 0)
            {
                printf(YELLOW " \n\t............. Invalid Specialization  [✗]  Try Again [!]......... \n" RESET);
            }
        } while (strlen(specialization[doctorCount]) == 0 || strcmp(specialization[doctorCount], " ") == 0);

        // GENDER
        do {
            printf("\tEnter Gender (Male / Female / Other): ");
            fgets(genderD[doctorCount], sizeof(genderD[0]), stdin);
            genderD[doctorCount][strcspn(genderD[doctorCount], "\n")] = '\0';

            if (strcmp(genderD[doctorCount], "Male") != 0 &&
                strcmp(genderD[doctorCount], "Female") != 0 &&
                strcmp(genderD[doctorCount], "Other") != 0)
            {
                printf(YELLOW " \n\t............. Invalid Gender  [✗]  Try Again [!]......... \n" RESET);
            }
        } while (strcmp(genderD[doctorCount], "Male") != 0 &&
            strcmp(genderD[doctorCount], "Female") != 0 &&
            strcmp(genderD[doctorCount], "Other") != 0);

        // EXPERIENCE 
        do
        {
            printf("\tEnter Years of Experience: ");
            if (scanf("%d", &exp[doctorCount]) != 1 || exp[doctorCount] <= 0)
            {
                printf(YELLOW " \n\t............. Invalid Years of Experience Added  [✗]  Try Again [!]......... \n" RESET);
                while (getchar() != '\n');
                exp[doctorCount] = 0;
            }
            else {
                while (getchar() != '\n');
                break;
            }
        } while (exp[doctorCount] <= 0);
        printf(GREEN "\n\t [Added] Doctor ID: %d, Name: %s, Age: %d, Specialization: %s, Gender: %s, Experience: %d\n" RESET,
            doctorCount + 1,
            nameD[doctorCount],
            ageD[doctorCount],
            specialization[doctorCount],
            genderD[doctorCount],
            exp[doctorCount]);

        doctorCount++;

        do
        {
            printf(BLUE "\n\t Do you want to add more doctors? [Y/N]: " RESET);
            scanf(" %c", &more);
            while (getchar() != '\n');
            if (more != 'Y' && more != 'y' && more != 'N' && more != 'n')
            {
                printf(YELLOW " \n\t............. Invalid Input  [✗]  Try Again [!]......... \n" RESET);
            }
        } while (more != 'Y' && more != 'y' && more != 'N' && more != 'n');

    } while (more == 'Y' || more == 'y');

    if (more == 'N' || more == 'n')
    {
        return;
    }
}

void deletePatient()
{
    int id;
    printf("\tEnter patient ID:");
    scanf("%d", &id);

    if (id <= 0 || id > patientCount)
    {
        printf(YELLOW " \n\t............. Invalid Patient ID [✗] ......... \n" RESET);
        return;
    }

    for (int i = id - 1; i < patientCount - 1; i++)
    {
        strcpy(nameP[i], nameP[i + 1]);
        ageP[i] = ageP[i + 1];
        strcpy(diseaseP[i], diseaseP[i + 1]);
        strcpy(genderP[i], genderP[i + 1]);
    }
    patientCount--;
    printf(GREEN BOLD"\t..................RECORD DELETED SUCCESSFULLY   [✔]..................\n" RESET);
}

void deleteDoctor()
{
    int id;
    printf("\tEnter Doctor ID:");
    scanf("%d", &id);

    if (id <= 0 || id > doctorCount)
    {
        printf(YELLOW " \n\t............. INVALID DOCTOR ID [✗] ......... \n" RESET);
        return;
    }

    for (int i = id - 1; i < doctorCount - 1; i++)
    {
        strcpy(nameD[i], nameD[i + 1]);
        ageD[i] = ageD[i + 1];
        strcpy(specialization[i], specialization[i + 1]);
        exp[i] = exp[i + 1];
        strcpy(genderD[i], genderP[i + 1]);
    }
    doctorCount--;
    printf(GREEN BOLD"\t..................RECORD DELETED SUCCESSFULLY   [✔]..................\n" RESET);
}

void changePassword()
{
    int passCount = 0, prePassword, newPassword;
    do
    {
        printf("\tEnter previous password:");
        scanf("%d", &prePassword);
        if (prePassword == adminPassword)
        {
            printf("\tEnter new password:");
            scanf("%d", &newPassword);
            printf(CYAN  BOLD"\tPassword updated  [✔].......Your new password is %d" RESET, newPassword);
            adminPassword = newPassword;
            admin();
        }
        if (prePassword == docPassword)
        {
            printf("\tEnter new password:");
            scanf("%d", &newPassword);
            printf(CYAN BOLD "\tPassword updated  [✔].......Your new password is %d" RESET, newPassword);
            docPassword = newPassword;
            doctor();
        }
        if (prePassword == patPassword)
        {
            printf("\tEnter new password:");
            scanf("%d", &newPassword);
            printf(CYAN BOLD "\tPassword updated  [✔].......Your new password is %d" RESET, newPassword);
            patPassword = newPassword;
            patient();
        }

        else
        {
            printf(YELLOW "\n\t\tInvalid Password [✗] ..... Enter Again :  \n" RESET);
            passCount++;
        }
        if (passCount == 1)
        {
            printf(YELLOW "\t [!] [!] You have 2 more chances to enter correct password [!] [!]\n\n" RESET);
        }
        if (passCount == 3)
        {
            printf(RED "\n\t\t [✗] [✗] [✗]  TRIED MANY TIMES [✗] [✗] [✗]\n" RESET);
        }
    } while (passCount < 3);
}
void showCredits()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf(CYAN BOLD"\n\n\t\t================= CREDITS ==================\n" RESET);
    printf("\t\tHospital Management System\n");
    printf(GREEN "\t\tDeveloped by: ABISHA CH - KHANSA ZAEEM - ZARMEEN NAZ\n" RESET);
    SetConsoleTextAttribute(hConsole, 3);
    printf("\t\tRoll No: BSEF24M007 - BSEF24M013 - BSIT24M056 \n");
    SetConsoleTextAttribute(hConsole, 5);
    printf("\t\tClass: B.S SOFTWARE ENGINEERING\n");
    printf(YELLOW "\t\tSpecial thanks to: SIR ANZAR, TA'S, etc.\n" RESET);
    printf("\t\t================================================\n\n");
    exit(0);
}
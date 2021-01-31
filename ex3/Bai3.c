#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "student.h"

void printStudentInfo();
void appendStudentInfo();
void searchStudent();
void printLine();

int main(){
  int choice;
  do {
    printf("\nChuong trinh quan li sinh vien\n");
    printf("------------------------------\n");
    printf("\n1. Xem danh sach sinh vien");
    printf("\n2. Nhap them sinh vien");
    printf("\n3. Tim sinh vien theo ten");
    printf("\n4. Thoat\n\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("| %-30s | %-25s |\n","Name","Grade");
        printLine();
        printStudentInfo();
        break;
      case 2:
        appendStudentInfo();
        break;
      case 3:
        searchStudent();
        break;
      case 4:
        return 0;
      default:
      printf("Invalid choice!\n");
    }
  } while (choice != 4);
  return 0;
}

void printStudentInfo(){
  FILE *inf = fopen("SV2021.dat","r");
  student tmpStudent;
  while (fread(&tmpStudent,sizeof(student),1,inf)){
    printf("| %-30s | %-25.1f |\n",tmpStudent.name,tmpStudent.grade);
    printLine();  
  }
  fclose(inf);
}

void appendStudentInfo(){
  FILE *inf = fopen("SV2021.dat","ab+");
  printf("Enter the number of student to be added: ");
  int n;
  scanf("%d",&n);
  for (int i = 0; i < n; i++){
    getchar();
    student newStudent;
    char newName[200];
    printf("Enter name: ");
    fgets(newName,200,stdin);
    strtok(newName,"\n");
    strcpy(newStudent.name,newName);
    printf("Enter grade: ");
    scanf("%f",&newStudent.grade);
    fwrite(&newStudent,sizeof(student),1,inf);
    }
  printf("\nInput student info successful!\n") ; 
  fclose(inf);
}

void searchStudent(){
  student studentLookup;
  char nameLookup[200];
  printf("Enter the name of student: ");
  fflush(stdin);
  fgets(nameLookup,200,stdin);
  strtok(nameLookup,"\n");
  FILE *inf = fopen("SV2021.dat","r");
  while (fread(&studentLookup,sizeof(student),1,inf)){
    if(strstr(studentLookup.name,nameLookup) != NULL){
      FILE *file = fopen("output.txt","w");
      printf("| %-30s | %-25s |\n","Name","Grade");
      printLine();
      printf("| %-30s | %-25.1f |\n",studentLookup.name,studentLookup.grade);
      fprintf(file,"%s %.1f",studentLookup.name, studentLookup.grade);
      fclose(file);
    }
  }
  fclose(inf);
}

void printLine(){
  for (int i = 0; i < 62; i++){
    printf("-");
  }
  printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
class Student {
    public:
       int mId;
       double mGPA;
};

int main(int argc, char *argv[]) {
    Student *students = new Student[100];
    Student ** studentsPtr = new Student*[100];
    srand(100); // Seed random number generator
    for (int i = 0; i < 100; i++) {
       students[i].mId = i+1;
       // Generate a "random" GPA from 0.0-4.0
       students[i].mGPA = 4 * (((double)rand())/RAND_MAX);
       studentsPtr[i] = students+i;
    }

    // This is Bubble Sort:
    for (int i = 0; i < 100; i++) {
       for (int j = 1; j < 100; j++) {
           // Based on GPA
           if (studentsPtr[j-1]->mGPA > studentsPtr[j]->mGPA) {
                Student *temp = studentsPtr[j];
                studentsPtr[j] = studentsPtr[j-1];
                studentsPtr[j-1] = temp;
            } 
        }
    }

    for (int i = 0; i < 100; i++) {
        students = studentsPtr[i];
    }

    for (int i = 0; i < 100; i++) {
       printf("%f\n", students[i].mGPA);
    }
    return 0; 
}
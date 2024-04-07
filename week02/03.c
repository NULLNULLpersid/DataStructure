#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

// 학생 구조체 선언
struct Student {
    int StudentNumber;
    char Name[MAX_STUDENTS];
    double Marks;
};

// 학생 정보 입력 함수
void inputStudentData(struct Student* s) {
    scanf("%d", &s->StudentNumber);
    scanf("%s", s->Name);
    scanf("%lf", &s->Marks);
}

// 학생 상세 정보 출력 함수
void displayStudentData(const struct Student* s, int i) {
    printf("Details for Student %d:\nStudent_Number: %d\nName: %s\nMarks: %.2lf\n\n", i+1, s->StudentNumber, s->Name, s->Marks);
}

// 학생 점수 평균 계산 함수
float calculateAverageMarks(const struct Student* students, int numStudents) {
    double sum = 0;
    for (int i = 0; i < numStudents; i++) {
        sum += students[i].Marks;
    }
    return sum / numStudents;
}

int main(void) {
    struct Student students[MAX_STUDENTS];
    int numStudents;
    scanf("%d", &numStudents);
    // 학생 정보 입력
    for (int i = 0; i < numStudents; i++) {
        inputStudentData(&students[i]);
    }
    // 학생 상세 정보 출력
    for (int i = 0; i < numStudents; i++) {
        displayStudentData(&students[i], i);
    }
    // 학생들의 점수 평균 계산
    printf("Average Marks of students: %.2lf", calculateAverageMarks(students, numStudents));
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int students = 5;
    int subjects = 5;
    int marks[students][subjects];
    int studentTotal[5] = {0};
    float subjectAverage[5] = {0.0};

    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            cin >> marks[i][j];
            studentTotal[i] += marks[i][j];
            subjectAverage[j] += marks[i][j];
        }
    }

    for (int j = 0; j < subjects; j++) {
        subjectAverage[j] /= students;
    }

    cout << "Total marks for each student:" << endl;
    for (int i = 0; i < students; i++) {
        cout << "Student " << i + 1 << ": " << studentTotal[i] << endl;
    }

    cout << "Average marks for each subject:" << endl;
    for (int j = 0; j < subjects; j++) {
        cout << "Subject " << j + 1 << ": " << subjectAverage[j] << endl;
    }

    return 0;
}

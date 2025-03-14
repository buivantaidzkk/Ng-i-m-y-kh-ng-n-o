#include <iostream>
#include <cstring>

using namespace std;

struct Student {
    char studentID[10];
    char fullName[50];
    int birthYear;
    double gpa;
};

void displayStudents(Student* studentList, int count) {
    cout << "-------------------------------------------\n";
    cout << "ID     | Full Name            | BirthYear | GPA\n";
    cout << "-------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << studentList[i].studentID << " | "
             << studentList[i].fullName << " | "
             << studentList[i].birthYear << " | "
             << studentList[i].gpa << endl;
    }
    cout << "-------------------------------------------\n";
}

void insertionSort(Student* studentList, int count) {
    for (int i = 1; i < count; i++) {
        Student key = studentList[i];
        int j = i - 1;
        while (j >= 0 && studentList[j].gpa > key.gpa) {
            studentList[j + 1] = studentList[j];
            j--;
        }
        studentList[j + 1] = key;
    }
}

void bubbleSort(Student* studentList, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (studentList[j].gpa > studentList[j + 1].gpa) {
                Student temp = studentList[j];
                studentList[j] = studentList[j + 1];
                studentList[j + 1] = temp;
            }
        }
    }
}

void heapify(Student* studentList, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && studentList[left].gpa > studentList[largest].gpa)
        largest = left;

    if (right < n && studentList[right].gpa > studentList[largest].gpa)
        largest = right;

    if (largest != i) {
        Student temp = studentList[i];
        studentList[i] = studentList[largest];
        studentList[largest] = temp;

        heapify(studentList, n, largest);
    }
}

void heapSort(Student* studentList, int count) {
    for (int i = count / 2 - 1; i >= 0; i--)
        heapify(studentList, count, i);

    for (int i = count - 1; i > 0; i--) {
        Student temp = studentList[0];
        studentList[0] = studentList[i];
        studentList[i] = temp;

        heapify(studentList, i, 0);
    }
}

int main() {
    int count = 5;
    Student* studentList = new Student[count]{
        {"ST01", "Nguyen Van Cuong", 2002, 3.2},
        {"ST02", "Tran Thi Ngoc Anh", 2001, 2.9},
        {"ST03", "Le Huu Trac", 2000, 3.8},
        {"ST04", "Pham Thi Tuyet Nhi", 2002, 3.5},
        {"ST05", "Hinh Khac Luy", 2003, 2.7}
    };

    while (true) {
        cout << "\nDanh sach sinh vien hien tai:\n";
        displayStudents(studentList, count);

        cout << "\nChon thuat toan sap xep:\n";
        cout << "1. Sap xep bang chen (Insertion Sort)\n";
        cout << "2. Sap xep noi bot (Bubble Sort)\n";
        cout << "3. Sap xep bang Heap (Heap Sort)\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";

        int choice;
        cin >> choice;

        if (choice == 0) {
            cout << "Dang thoat chuong trinh!\n";
            break;
        }

        Student* sortedList = new Student[count];
        memcpy(sortedList, studentList, count * sizeof(Student));

        switch (choice) {
            case 1:
                insertionSort(sortedList, count);
                cout << "\nDanh sach sau khi sap xep bang chen:\n";
                break;
            case 2:
                bubbleSort(sortedList, count);
                cout << "\nDanh sach sau khi sap xep noi bot:\n";
                break;
            case 3:
                heapSort(sortedList, count);
                cout << "\nDanh sach sau khi sap xep bang Heap:\n";
                break;
            default:
                cout << "Lua chon khong hop le! Vui long thu lai.\n";
                delete[] sortedList;
                continue;
        }

        displayStudents(sortedList, count);
        delete[] sortedList;
    }

    delete[] studentList;
    return 0;
}

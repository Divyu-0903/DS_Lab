#include <iostream>
using namespace std;

class Element {
public:
    int i;
    int j;
    int x;
};

class Sparse {
private:
    int m;
    int n;
    int num;
    Element *ele;

public:
    Sparse(int m, int n, int num) {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }

    void input();
    Sparse add(Sparse &s);
    Sparse transpose();
    void display();
};

void Sparse::input() {
    cout << "Enter non-zero elements (i, j, x):" << endl;
    for (int i = 0; i < num; i++) {
        cin >> ele[i].i >> ele[i].j >> ele[i].x;
    }
}

Sparse Sparse::add(Sparse &s) {
    int i = 0, j = 0, k = 0;
    if (m != s.m || n != s.n)
        return Sparse(0, 0, 0);

    Sparse sum(m, n, num + s.num);

    while (i < num && j < s.num) {
        if (ele[i].i < s.ele[j].i) {
            sum.ele[k++] = ele[i++];
        } else if (ele[i].i > s.ele[j].i) {
            sum.ele[k++] = s.ele[j++];
        } else {
            if (ele[i].j < s.ele[j].j) {
                sum.ele[k++] = ele[i++];
            } else if (ele[i].j > s.ele[j].j) {
                sum.ele[k++] = s.ele[j++];
            } else {
                sum.ele[k] = ele[i];
                sum.ele[k++].x = ele[i++].x + s.ele[j++].x;
            }
        }
    }

    for (; i < num; i++)
        sum.ele[k++] = ele[i];
    for (; j < s.num; j++)
        sum.ele[k++] = s.ele[j];

    sum.num = k;
    return sum;
}

Sparse Sparse::transpose() {
    Sparse trans(n, m, num);

    int *colStart = new int[n];
    int *colCount = new int[n];

    for (int i = 0; i < n; i++)
        colCount[i] = 0;

    for (int i = 0; i < num; i++)
        colCount[ele[i].j]++;

    colStart[0] = 0;

    for (int i = 1; i < n; i++)
        colStart[i] = colStart[i - 1] + colCount[i - 1];

    for (int i = 0; i < num; i++) {
        int j = ele[i].j;
        int k = colStart[j];
        trans.ele[k].i = ele[i].j;
        trans.ele[k].j = ele[i].i;
        trans.ele[k].x = ele[i].x;
        colStart[j]++;
    }

    delete[] colStart;
    delete[] colCount;
    return trans;
}

void Sparse::display() {
    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (ele[k].i == i && ele[k].j == j)
                cout << ele[k++].x << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main() {
    int m, n, num;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;
    cout << "Enter the number of non-zero elements: ";
    cin >> num;

    Sparse A(m, n, num);
    A.input();

    cout << "Matrix A:" << endl;
    A.display();

    Sparse B(m, n, num);
    B.input();

    cout << "Matrix B:" << endl;
    B.display();

    Sparse C = A.add(B);
    cout << "Matrix C (A + B):" << endl;
    C.display();

    Sparse transposed = A.transpose();
    cout << "Transpose of Matrix A:" << endl;
    transposed.display();

    return 0;
}
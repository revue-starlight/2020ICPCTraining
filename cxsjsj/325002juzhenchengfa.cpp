#include<iostream>
using namespace std;
int main() {
    int m;
    int n;
    int r;
    cout << "运算矩阵A和矩阵B相乘" << endl << endl;
    cout << "请输入矩阵A的行数和列数：" << endl << endl;
    cout << "矩阵A的行数：";
    cin >> m;
    cout << "矩阵A的列数：";
    cin >> n;
    cout << "矩阵B的列数：";
    cin >> r;
    cout << endl;

    int a[100][100];
    int b[100][100];
    int c[100][100];
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < r;j++) {
            c[i][j] = 0;
        }
    }

    cout << "请输入矩阵A:" << endl << endl;
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            cin >> a[i][j];
        }
    }

    cout << endl << "请输入矩阵B:" << endl << endl;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < r;j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 0;i < m;i++) {
        for (int j = 0;j < r;j++) {
            for (int k = 0;k < n;k++) {
                c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
            }
        }
    }

    cout << endl << endl << "矩阵A乘以矩阵B的结果：" << endl << endl;
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < r;j++) {
            cout << c[i][j] << "\t";
        }
        cout << endl << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;
class Matrix
{
private:
    int a[3][3];

public:
    void setdata()
    {
        cout << endl
             << "Enter the elements" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> a[i][j];
            }
        }
    }
    void display()
    {
        cout << "Your Matrix is" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    Matrix add(Matrix t)
    {
        Matrix temp;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp.a[i][j] = a[i][j] + t.a[i][j];
            }
        }
        return temp;
    }
    Matrix sub(Matrix t)
    {
        Matrix temp;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp.a[i][j] = a[i][j] - t.a[i][j];
            }
        }
        return temp;
    }
    Matrix multiply(Matrix t)
    {
        Matrix temp;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp.a[i][j] = 0;
                for (int k = 0; k < 3; k++)
                {
                    temp.a[i][j] += a[i][k] * t.a[k][j];
                }
            }
        }
        return temp;
    }
    Matrix transpose()
    {
        Matrix temp;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp.a[i][j] = a[j][i];
            }
        }
        return temp;
    }
    bool is_singular()
    {
        int s;
        s = a[0][0] * (a[1][1] * a[2][2] - a[2][1] * a[1][2]) - a[0][1] * (a[1][0] * a[2][2] - a[2][0] * a[1][2]) + a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
        if (s == 0)
            return true;
        else
            return false;
    }
};
int main()
{
    Matrix m1, m2, m3, m4, m5, m6;
    m1.setdata();
    m1.display();
    m2.setdata();
    m2.display();
    m3 = m1.add(m2);
    m3.display();
    m4 = m1.sub(m2);
    m4.display();
    m5 = m1.multiply(m2);
    m5.display();
    m6 = m1.transpose();
    m6.display();
    if (m1.is_singular() == 1)
    {
        cout << "matrix is singular";
    }
    else
    {
        cout << "matrix is non - singular";
    }
    return 0;
}
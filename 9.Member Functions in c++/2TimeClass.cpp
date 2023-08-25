#include <iostream>
using namespace std;
class Time
{
private:
    int h, m, s;

public:
    void setData(int, int, int);
    void showData();
    void normalize();
    Time add(Time);
    bool is_greater(Time);
};
void Time ::setData(int x, int y, int z)
{
    h = x;
    m = y;
    s = z;
}
void Time ::showData()
{
    cout << "Time = " << h << ":" << m << ":" << s << endl;
}
void Time::normalize()
{
    m += s / 60;
    s %= 60;
    h += m / 60;
    m %= 60;
}
Time Time::add(Time t)
{
    Time temp;
    temp.s = s + t.s;
    temp.m = m + t.m;
    temp.h = h + t.h;
    temp.normalize();
    return temp;
}
bool Time::is_greater(Time T)
{
    if (h > T.h)
        return true;
    else if (h < T.h)
        return false;
    else if (m > T.m)
        return true;
    else if (m < T.m)
        return false;
    else if (s > T.s)
        return true;
    else
        return false;
}
int main()
{
    Time t1, t2, t3;
    t1.setData(10, 50, 1);
    t2.setData(20, 34, 0);
    t1.showData();
    t2.showData();
    t3 = t1.add(t2);
    t3.showData();
    return 0;
}
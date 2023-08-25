#include <iostream>
using namespace std;
class TestResult
{
private:
    int roll_no, right, wrong, net_score;
    static int right_weightage, wrong_weightage;

public:
    void setData(int a, int b, int c, int d)
    {
        roll_no = a;
        right = b;
        wrong = c;
        net_score = d;
    }
    static void setD(int rw, int ww)
    {
        right_weightage = rw;
        wrong_weightage = ww;
    }
    int getRoll_no()
    {
        return roll_no;
    }
    int getRight()
    {
        return right;
    }
    int getWrong()
    {
        return wrong;
    }
    int getNetScore()
    {
        return net_score;
    }
    static int getRightWeightage()
    {
        return right_weightage;
    }
    static int getWrongWeightage()
    {
        return wrong_weightage;
    }
};
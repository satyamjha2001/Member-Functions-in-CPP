#include <iostream>
using namespace std;
class TestResult{
    private:
        int roll_no,right,wrong,net_score;
        static int right_weightage,wrong_weightage;
    public:
        void setRoll_no(int r) { roll_no=r;}
        void setRight(int r) { right=r;}
        void setWrong(int w) { wrong=w;}
        void setNetScore(int n) { net_score=n;}
        static void setRight_weightage(int rw){
            right_weightage=rw;
        }
        static void setWrong_weightage(int rw){
            wrong_weightage=rw;
        }
        int getRoll_no() { return roll_no;}
        int getRight() { return right;}
        int getWrong() { return wrong;}
        int getNetScore(){return net_score;}
        static int getRight_weightage() { return right_weightage;}
        static int getWrong_weightage() { return wrong_weightage;}
};
int TestResult::right_weightage;
int TestResult::wrong_weightage;

void setTestResult(TestResult &t,int r,int right,int wrong)
{
    t.setRoll_no(r);
    t.setRight(right);
    t.setWrong(wrong);
    t.setNetScore(t.getRight()*TestResult::getRight_weightage()+t.getWrong()*TestResult::getWrong_weightage());
}
void sortByNetScore(TestResult tr[],int size)
{
    int round,i;
    TestResult temp;
    for(round=1;round<size;round++)
    {
        for(i=0;i<=size-1-round;i++)
        {
            if(tr[i].getNetScore()<tr[i+1].getNetScore())
            {
                temp=tr[i];
                tr[i]=tr[i+1];
                tr[i+1]=temp;
            }
        }
    }
}
void showTestResults(TestResult tr[],int size){
    cout<<endl;
    cout<<"--------------------------------------";
    cout<<endl;
    cout<<"Roll No  Right  Wrong  Net Score";
    for(int i=0;i<size;i++)
    {
        cout<<endl;
        cout<<tr[i].getRoll_no()<<"  ";
        cout<<tr[i].getRight()<<"  ";
        cout<<tr[i].getWrong()<<"  ";
        cout<<tr[i].getNetScore()<<"  ";


    }
};
int main()
{
    int r,right,wrong;
    TestResult tr[5];
    TestResult::setRight_weightage(3);
    TestResult::setWrong_weightage(-1);
    for(int i=0;i<5;i++)
    {
        cout<<"Enter details for test result "<<i+1<<endl;
        cout<<"Enter rollno: ";
        cin>>r;
        cout<<"Enter number of right answers: ";
        cin>>right;
        cout<<"Enter number of wrong answers: ";
        cin>>wrong;
        setTestResult(tr[i],r,right,wrong);

    }
    sortByNetScore(tr,5);
    showTestResults(tr,5);
    cout<<endl;
    return 0;
}
#include<iostream>
using namespace std;
class Complex
{
    private:
    int a,b;
    public:
    void setData(int,int);
    void showData();
    Complex add(Complex);
    Complex subtract(Complex);
    Complex multiply(Complex);
};
void Complex::setData(int x,int y)
{
    a=x;
    b=y;
}
void Complex::showData()
{
    cout<<"\na= "<<a<<" b= "<<b<<endl;
}
Complex Complex::add(Complex C)
{
 Complex temp;
 temp.a=a+C.a;   
 temp.b=b+C.b;
 return temp;   
}
Complex Complex::subtract(Complex C)
{
 Complex temp;
 temp.a=C.a-a;   
 temp.b=C.b-b;
 return temp;   
}
Complex Complex::multiply(Complex C)
{
 Complex temp;
 temp.a=a*C.a-b*C.b;   
 temp.b=a*C.b+b*C.a;
 return temp;   
}
int main() {
Complex c1,c2,c3,c4,c5;
c1.setData(4,5);
c2.setData(2,3);
c3=c1.add(c2);
c4=c1.subtract(c2);
c5=c1.multiply(c2);
cout<<"First complex number:"<<endl;
c1.showData();
cout<<"Second complex number:"<<endl;
c2.showData();
cout<<"Addition of complex number:"<<endl;
c3.showData();
cout<<"Subtration of complex number:"<<endl;
c4.showData();
cout<<"Multiplication of complex number:"<<endl;
c5.showData();
return 0;
}
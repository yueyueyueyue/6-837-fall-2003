#include <iostream>
using namespace std;
class Complex{
public:
   Complex(double r=0.0,double i=0.0){
       real=r;
       image=i;
   }
   //friend Complex operator+(const Complex&,const Complex&);
   Complex operator+(const Complex& b)
   {return Complex(this->real+b.real, this->image+b.image);}
   void display();
private:
   double real;
   double image;
};
 
//Complex operator+(const Complex &c1,const Complex &c2){
//   return Complex(c1.real+c2.real,c1.image+c2.image);
//}
 
void Complex::display(){
   cout<<"("<<real<<","<<image<<"i)"<<endl;
}
 
int main(){
   Complex c1(3,4),c2(5,-10),c3(1,1),c4;
   c4=c1+c2+c3;
   cout<<"c1=";c1.display();
   cout<<"c2=";c2.display();
   cout<<"c3=";c3.display();
   //cout<<"c1+c2=";c3.display();
   //c3 = c1+c2+c1;
   cout<<"c1+c2+c3=";c4.display();
   system("pause");
   return 0;
}
#include <iostream>
#include <cmath>
#include <stack>
#include <iomanip>

using namespace std;
class Point{
private:
    double x,y,z;
    int dim;
public:
    Point(){
        x=0;
        y=0;
        z=0;
    }
    Point(double X2,double Y2){
        x=X2;
        y=Y2;
        z=0;
        dim=2;
    }
    Point(double X3,double Y3, double Z3){
        x=X3;
        y=Y3;
        z=Z3;
        dim=3;
    }
    double getX(){
        return x ;
    }
    double getY(){
        return y;
    }
    double getZ(){
        return z;
    }
    int getDim()
    {
        return dim;
    }

    double getRadius(){
        double rad;
        rad= sqrt(getX()* getX() + getY() * getY() + getZ() * getZ());
        return rad;
    }
    double getPhi(){
        double phi;
        phi= atan2(getY(),getX())*180/M_PI;
        if (phi<0)
            phi=360+phi;
        return phi;
    }
    double getTheta(){
        double thet;
        thet=acos(getZ()/getRadius())*180/M_PI;
        return thet;
    }
};

int main() {
    stack<Point> stiva;

    double x,y,z;
    while(scanf("%lf;%lf",&x , &y)!=EOF)
    {
        if(scanf(";%lf",&z)!=0)
        {
            stiva.push(Point(x,y,z));
        }
        else stiva.push(Point(x,y));
    }
    while(stiva.empty()==0)
    {
        if (stiva.top().getDim()==3) {
            cout <<fixed<<"r="<<setprecision(3) << stiva.top().getRadius() << "; " <<"phi="<<setprecision(3)<< stiva.top().getPhi() <<"; "<<"th="<<setprecision(3) <<stiva.top().getTheta()<<endl;
        }
        else {
            cout <<fixed<<"r="<<setprecision(3)<< stiva.top().getRadius()<< "; " <<"phi="<<setprecision(3)<< stiva.top().getPhi()<<endl;
        }
        stiva.pop();
    }
    return 0;
}
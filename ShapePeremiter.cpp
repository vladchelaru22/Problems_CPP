#include <bits/stdc++.h>
using namespace std;

class Point{
private:
    double x,y;
public:
    Point(){
        x=0;
        y=0;
    }

    Point(double X, double Y){
        x=X;
        y=Y;
    }
    double getX() const{
        return x;
    }
    double getY() const{
        return y;
    }
    void setX(double X){
        x=X;
    }
    void setY(double Y){
        y=Y;
    }
    Point operator -(const Point& minus) const{
        double rezX,rezY;
        rezX=abs(x-minus.x);
        rezY=abs(y-minus.y);
        Point rez(rezX,rezY);
        return rez;
    }
};

class Shape{
protected:
    Point mFirst;
    Point mSecond;
    string mName;
public:
    Shape(){
        mFirst.setX(0);
        mFirst.setY(0);
        mSecond.setX(0);
        mSecond.setY(0);
    }
    Shape(Point X,Point Y){
        mFirst=X;
        mSecond=Y;
    }
    Point getFirst() const{
        return mFirst;
    }
    Point getSecond() const{
        return mSecond;
    }
    void setFirst(Point X){
        mFirst=X;
    }
    void setSecond(Point Y){
        mSecond=Y;
    }
    string getName() const{
        return mName;
    }
    void setName(string nume){
        mName=nume;
    }
    virtual double getPerimeter()const=0;
    virtual double getArea()const=0;
};

class Quadrilateral: public Shape{
public:
    Quadrilateral(){
        mName="Unknown";
        mFirst.setX(0);
        mFirst.setY(0);
        mSecond.setY(0);
        mSecond.setX(0);
    }
    Quadrilateral(Point X, Point Y,string nume){
        mFirst=X;
        mSecond=Y;
        mName=nume;
    }
    double getLength() const{
        return abs(mFirst.getX()-mSecond.getX());
    }
    double getWidth() const{
        return abs(mFirst.getY()-mSecond.getY());
    }
    double getPerimeter()const override{
        return 2*getLength()+2*getWidth();
    }
    double getArea()const override{
        return getLength()*getWidth();
    }
};

class Circle: public Shape{
private:
    double mRadius;
public:
    Circle(){
        mName="Unknown";
        mRadius=0;
        mFirst.setY(0);
        mFirst.setX(0);
        mSecond.setX(0);
        mSecond.setY(0);
    }
    Circle(Point centru,double raza){
        mFirst=centru;
        mRadius=raza;
        mName="cerc";
    }
    double getRadius()const{
        return mRadius;
    }
    void setRadius(double raza){
        mRadius=raza;
    }
    double getPerimeter()const override{
        return 2*mRadius*M_PI;
    }
    double getArea()const override{
        return M_PI*mRadius*mRadius;
    }
};
int cmp(const void *a,const void *b){
    Shape*A=(Shape*)a;
    Shape*B=(Shape*)b;
    if(A->getArea()<B->getArea())
        return 1;
    else if(A->getArea()>B->getArea())
        return 0;
    else{
        if(A->getPerimeter()<B->getPerimeter())
          return 1;
        else return 0;
    }
    
}

int main() {
    vector<Shape*> forme;
    int n;
    double min,max,x1,y1,x2,y2,cx,cy,r;
    string forma;
    cin>>n>>min>>max;
    if(n<1 || n>500 || min>max )
    {
        cout<<"Valoare de intrare invalida";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin>>forma;
        if(forma=="cerc"){
            cin>>cx>>cy>>r;
            Point pct(cx,cy);
            if(r>0 && r<=1000 && pct.getX()>=-1000 && pct.getX()<=1000 && pct.getY()>=-1000 && pct.getY()<=1000){
            Shape*p1 = new Circle(pct,r);
            forme.push_back(p1);}
            else{
                cout<<"Valoare de intrare invalida";
                return 0;
            }
        }
        else{
            cin>>x1>>y1>>x2>>y2;
            Point pct1(x1,y1);
            Point pct2(x2,y2);
            if(pct1.getX()>=-1000 && pct1.getX()<=1000 && pct1.getY()>=-1000 && pct1.getY()<=1000 && pct2.getX()>=-1000 && pct2.getX()<=1000
            && pct2.getY()>=-1000 && pct2.getY()<=1000)
            {Shape*p2=new Quadrilateral(pct1,pct2,forma);
            forme.push_back(p2);}
            else{
                cout<<"Valoare de intrare invalida";
                return 0;
            }
        }
    }
    std::sort(forme.begin(), forme.end(),cmp);
    for (int i = 0; i < n; ++i) {
        cout<<forme[i]->getName()<<" ";
        printf("%.6lf %.6lf\n",forme[i]->getArea(),forme[i]->getPerimeter());
    }

    return 0;
}
#include <bits/stdc++.h>

    using namespace std;
    class Shape{
    protected:
        string mShape;
        float mArea;
    public:
        virtual void print()=0;
        virtual void calculateArea()=0;
        float  getArea(){
            return mArea;
        }
    };

    class Square:public Shape{
    private:
        float mLength;
    public:
        Square(){
            mShape="nedefinit";
            mLength=0;
            mArea=0;
        }
        Square(float lenght){
            mLength=lenght;
            mShape="patrat";
        }
        void print() override{
            cout<<mShape<<" ";
            printf("%.2f",mLength);
        }
        void calculateArea() override{
            mArea=mLength*mLength;
        }
    };
    class Rectangle:public Shape{
    private:
        float mLength;
        float mWidth;
    public:
        Rectangle(){
            mShape="nedefinit";
            mLength=0;
            mWidth=0;
            mArea=0;
        }
        Rectangle(float length,float width){
            mLength=length;
            mWidth=width;
            mShape="dreptunghi";
        }
        void print() override{
            cout<<mShape<<" ";
            printf("%.2f %.2f",mLength, mWidth);
        }
        void calculateArea() override{
            mArea=mLength*mWidth;
        }
    };
    class Circle:public Shape{
    private:
        float mRadius;
    public:
        Circle(){
            mRadius=0;
            mArea=0;
            mShape="nedefinit";
        }
        Circle(float radius){
            mRadius=radius;
            mShape="cerc";
        }
        void print() override{
            cout<<mShape<<" ";
            printf("%.2f",mRadius);
        }
        void calculateArea() override{
            mArea=M_PI*mRadius*mRadius;
        }
    };
    bool comp(Shape *s1, Shape *s2){
        if(s1->getArea()>s2->getArea())
            return 1;
        return 0;
    }
    int main() {
        int n;
        cin>>n;
        vector <Shape*> forme;
        string forma;
        float l,l1,l2,r;
        for (int i = 0; i < n; ++i) {
            cin>>forma;
            if(forma=="patrat")
            {scanf("%f", &l);
                forme.push_back(new Square (l));
                forme[i]->calculateArea();
            }
            else if(forma=="dreptunghi")
            {
                scanf("%f %f", &l1, &l2);
                forme.push_back(new Rectangle(l1,l2));
                forme[i]->calculateArea();
            }
            else if(forma=="cerc")
            {scanf("%f", &r);
            forme.push_back(new Circle(r));
                forme[i]->calculateArea();}
        }
        sort(forme.begin(),forme.end(),comp);
        for (int i = 0; i < n; ++i) {
            forme[i]->print();
            cout<<endl;
        }

        return 0;
}
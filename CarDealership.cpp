#include <iostream>
#include <string.h>
using namespace std;

class Car{
protected:
    string mType;
    float mConsume;

public:
    virtual void print()=0;
    virtual void calculateConsume()=0;
    float getConsume()
    {
        return mConsume;
    }
};

class Gas : public Car
{
private:
    float mGas;
public:
    Gas()
    {
    mType="nedefinit";
    mGas=0;
    mConsume=0;
    }

    Gas(float gas) {
        mGas=gas;
        mType="benzina";  
    }

    void print() override{
        cout<<mType<<" ";
        printf("%.2f\n",mGas);
    }

    void calculateConsume() override{
        mConsume=mGas*5.8;
    }

};

class Hybrid : public Car
{
private:
    float mGas, mBattery;
public:

    Hybrid()
    {
        mGas=0;
        mBattery=0;
        mConsume=0;
        mType="nedefinit";
    }

    Hybrid(float gas, float battery)
    {
        mGas=gas;
        mBattery=battery;
        mType="hibrid";
    }

    void print() override{
        cout<<mType<<" ";
        printf("%.2f %.2f\n",mGas, mBattery);
    }
    void calculateConsume() override{
        mConsume=mGas*5.8+mBattery;
    }
};

class Diesel : public Car{
private:
    float mDiesel;
public:
    Diesel()
    {
        mDiesel=mConsume=0;
        mType="nedefinit";
    }

    Diesel(float diesel)
    {
        mDiesel=diesel;
        mType="diesel";
    }

    void print() override{
        cout<<mType<<" ";
        printf("%.2f\n",mDiesel);
    }
    void calculateConsume() override{
        mConsume=mDiesel*6;
    }
};


int main() {

    int n,i;
    cin>>n;
    Car** cars=new Car*[n];

    for(i=0;i<n;i++)
    {
        char type[10];
        float consum,energie;
        scanf("%s", type);
        if(strcmp(type,"benzina")==0)
        { scanf("%f", &consum);
            cars[i]=new Gas(consum);
            cars[i]->calculateConsume();
        }
        else if(strcmp(type,"hibrid")==0)
        { scanf("%f %f", &consum, &energie);
            cars[i]=new Hybrid(consum, energie);
            cars[i]->calculateConsume();
        }

        else {
            scanf("%f", &consum);
            cars[i]=new Diesel(consum);
            cars[i]->calculateConsume();
        }
    }

    for(i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        {
            if(cars[i]->getConsume()>cars[j]->getConsume())
            {
                Car* aux;
                aux=cars[i];
                cars[i]=cars[j];
                cars[j]=aux;
            }
        }

    for(i=0;i<n;i++)
        cars[i]->print();

    delete[] cars;
    return 0;
}

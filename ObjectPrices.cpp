#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
using namespace std;
class Object{
private:
    string valuable;
    float price;
public:
    Object()=default;
    Object(string v, float p)
    {
        valuable=v;
        price=p;
    }
    string getValuable()
    {
     return valuable;
    }
    float getPrice()
    {
        return price;
    }
};

class House{
private:
    string street,city;
    uint32_t number;
    vector <Object> valuables;
public:
    House()=default;
    House(string s,string c,uint32_t num)
    {
        street=s;
        city=c;
        number=num;
    }
    string getStreet(){
        return street;
    }
    string getCity(){
        return city;
    }
    uint32_t getNumber(){
        return number;
    }
    uint32_t getValuablesSize()
    {
       return valuables.size();
    }

    Object getValuable(uint32_t index)
    {
        return valuables[index];
    }
    void add(Object object)
    {
        valuables.push_back(object);
    }
};
float getTotalPrice(House obj){
    float s=0;
    for (int i = 0; i < obj.getValuablesSize(); ++i) {
        s=s+obj.getValuable(i).getPrice();
    }
    return s;
};


int main() {
    vector<House> Case;
    string street, city;
    uint32_t number, dim = 0;

    while (getline(cin,street,' ')) {
        getline(cin,city, ' ');
        scanf("%d",&number);
        House h(street, city, number);
        Case.push_back(h);
        uint32_t size;
        scanf("%d", &size);
        for (int i = 0; i < size; ++i) {
            string numeObiect;
            float pret;
            cin>>numeObiect;
            scanf("%f", &pret);
            Object obiect(numeObiect, pret);
            h.add(obiect);
        }
        dim++;
    }
    for (int i = 0; i < dim - 1; ++i) {
        for (int j = i + 1; j < dim; j++) {
            if (Case[i].getStreet() >= Case[j].getStreet()) {
                House aux;
                aux = Case[i];
                Case[i] = Case[j];
                Case[j] = aux;
            }
        }
    }

    int i=0;
    float sum_strazi_egale=0;
    while(i<dim) {
        if(i==0)
        { sum_strazi_egale= getTotalPrice(Case[0]);}
        else {
            if(Case[i].getStreet()== Case[i+1].getStreet() && Case[i].getCity()==Case[i+1].getCity())
                sum_strazi_egale=sum_strazi_egale+getTotalPrice(Case[i]);
            else {
                sum_strazi_egale = sum_strazi_egale + getTotalPrice(Case[i - 1]);
                cout<<Case[i - 1].getStreet()<<" "<<Case[i - 1].getCity();
                sum_strazi_egale = getTotalPrice(Case[i]);
                printf(" - %f", sum_strazi_egale);
            }

        }
        i++;
    }
    cout<<Case[i - 1].getStreet()<<" "<< Case[i - 1].getCity()<< " - ";
    cout<<sum_strazi_egale;

    return 0;
}


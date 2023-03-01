#include <bits/stdc++.h>
using namespace std;

class Policy{
protected:
    bool isChecked;
public:
    virtual void check (const string &parola)=0;
    bool getCheck() const{
        return isChecked;
    }
};


class LengthPolicy:public Policy{
private:
    uint16_t minLength,maxLength;
public:
    LengthPolicy(uint16_t minim) {
        minLength=minim;
        maxLength=255;
    }
    LengthPolicy(uint16_t minim,uint16_t maxim){
        minLength=minim;
        maxLength=maxim;
    }
    void check (const string &parola) override{
        if(parola.length()>=minLength && parola.length()<=maxLength)
            isChecked= true;
        else isChecked= false;
    }
};


class ClassPolicy:public Policy{
private:
    uint16_t minClassCount;
public:
    ClassPolicy(uint16_t count){
        minClassCount=count;
    }
    void check(const string &parola) override{
        uint16_t policies;
        int litMica=0, litMare=0, cifra=0, alte=0;
        for (int i = 0; i < parola.length(); ++i) {
            if(islower(parola[i]))
                litMica=1;
            else if(isupper(parola[i]))
                litMare=1;
            else if(isdigit(parola[i]))
                cifra=1;
            else alte=1;
        }
        policies=litMica+litMare+cifra+alte;
        if(policies>=minClassCount && policies>0 && policies<5)
            isChecked=true;
        else isChecked=false;
    }
};


class IncludePolicy: public Policy{
private:
    char characterType;
public:
    IncludePolicy(char caracter){
        characterType=caracter;
    }
    void check(const string &parola) override{
        if(characterType=='A'){
            int ok=0;
            for (int i = 0; i < parola.length(); ++i) {
                if(isupper(parola[i]))
                    ok=1;
            }
            if(ok==1)
                isChecked=true;
            else isChecked=false;
        }
        else if(characterType=='a'){
            int ok=0;
            for (int i = 0; i < parola.length(); ++i) {
                if(islower(parola[i]))
                    ok=1;
            }
            if(ok==1)
                isChecked=true;
            else isChecked=false;
        }
        else if(characterType=='0') {
            int ok=0;
            for (int i = 0; i < parola.length(); ++i) {
                if(isdigit(parola[i]))
                    ok=1;
            }
            if(ok==1)
                isChecked=true;
            else isChecked=false;
            
        }
        else {
            int ok=1;
            isChecked=false;
            for (int i = 0; i < parola.length() && ok; ++i) {
             if(islower(parola[i])==0 && isupper(parola[i])==0 && isdigit(parola[i])==0)
                 {isChecked=true;
                 ok=0;
                 }
            }
        }
    }
};


class NotIncludePolicy:public Policy{
private:
    char characterType;
public:
    NotIncludePolicy(char caracter){
        characterType=caracter;
    }
    void check(const string &parola) override{
        int litMica=0, litMare=0, cifra=0;
        if(characterType=='A'){
            for (int i = 0; i < parola.length(); ++i) {
                if(isupper(parola[i]))
                    litMare=1;
                if(litMare==1)
                    isChecked= false;
                else isChecked= true;
            }
        }
        else if(characterType=='a'){
            for (int i = 0; i < parola.length(); ++i) {
                if(islower(parola[i]))
                    litMica=1;
                if(litMica==1)
                    isChecked= false;
                else isChecked= true;
            }
        }
        else if(characterType=='0') {
            for (int i = 0; i < parola.length(); ++i) {
                if(isdigit(parola[i]))
                    cifra=1;
                if(cifra==1)
                    isChecked= false;
                else isChecked= true;
            }
        }
        else {
            for (int i = 0; i < parola.length(); ++i) {
                if(islower(parola[i])!=0 && isupper(parola[i])!=0 && isdigit(parola[i])!=0)
                    isChecked= false;
                else isChecked= true;
            }
        }
    }
};


class RepetitionPolicy:public Policy{
private:
    uint16_t maxCount;
public:
    RepetitionPolicy(uint16_t maxim){
        maxCount=maxim;
    }
    void check(const string &parola) override{
        int ok=0;
        for (int i = 0; i < parola.length();++i) {
            if(parola[i]==parola[i+1]){
                ok++;
            }
        }
        if(ok>maxCount)
            isChecked= false;
        else isChecked= true;
    }
};


class ConsecutivePolicy:public Policy{
private:
    uint16_t maxCount;
public:
    ConsecutivePolicy(uint16_t count){
        maxCount=count;
    }
    void check(const string &parola) override{
        int ok=0;
        for (int i = 0; i < parola.length(); ++i) {
            if(parola[i]+1==parola[i+1]){
                ok++;
            }
        }
        if(ok>=maxCount)
            isChecked=false;
        else isChecked= true;
    }
};

string checkPassword(string parola, vector<Policy*> politici){
   string s="OK";
    for (int i = 0; i < politici.size(); ++i)
        {
            politici[i]->check(parola);
            if(politici[i]->getCheck()==0)
            {s="NOK";
            break;
            }
        }
        return s;
}


int main() {
    int n;
    string cuvant,parola;
    vector<Policy*> politici;
    cin>>n;

    for (int i = 0; i < n; ++i) {
        cin>>cuvant;
        if(cuvant=="length"){

           uint16_t min,max;
           string a,b;
            Policy* p;
            cin>>a;
            min=stoi(a);
            char c=getchar();
            if(c=='\n') {
                p = new LengthPolicy(min);
            }
            else
            {
                cin>>b;
                max=stoi(b);
                p = new LengthPolicy(min,max);
            }
            politici.push_back(p);
        }
        else if(cuvant=="class")
        {
            int nrpol;
            cin>>nrpol;
            Policy *p=new ClassPolicy(nrpol);
            politici.push_back(p);
        }
        else if(cuvant=="include"){
            char caracter;
            cin>>caracter;
            Policy *p=new IncludePolicy(caracter);
            politici.push_back(p);
        }
        else if(cuvant=="ninclude"){
            char caracter;
            cin>>caracter;
            Policy *p=new NotIncludePolicy(caracter);
            politici.push_back(p);
        }
        else if(cuvant=="repetition"){
            int repetitii;
            cin>>repetitii;
            Policy *p=new RepetitionPolicy(repetitii);
            politici.push_back(p);
        }
        else{
            int cons;
            cin>>cons;
            Policy *p=new ConsecutivePolicy(cons);
            politici.push_back(p);
        }
    }
    while(cin>>parola){
        cout<<checkPassword(parola,politici)<<endl;
    }
    return 0;
}

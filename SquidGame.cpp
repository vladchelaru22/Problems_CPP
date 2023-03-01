#include <iostream>
#include <string>
#include <vector>
class om{
private:
    std::string nume,ocupatie;
    int numar, varsta;
    float greutate;
public:
    om(){
        nume="";
        ocupatie="";
        numar=0;
        varsta=0;
        greutate=0;
    }
    om(const std::string &othnume, const int &othnumar, const int &othvarsta, const float &othgreutate, const std::string &othocupatie)  {
        nume=othnume;
        ocupatie=othocupatie;
        greutate=othgreutate;
        numar=othnumar;
        varsta=othvarsta;
    }

    std::string get_nume() const {
        return nume;
    }

    std::string get_ocupatie() const {
        return ocupatie;
    }

    int get_numar() const {
        return numar;
    }

    int get_varsta() const {
        return varsta;
    }

    float get_greutate() const {
        return greutate;
    }

    void print(){
        std::cout << "Concurent:"<<numar<<"-"<<nume<<";"<<ocupatie<<"de"<<varsta<<"ani";
    }
};

class joc{
private:
    std::string nume;
    int numar_concurenti_initial;
protected:
    std::vector<om>participanti;
public:
    joc(){
        nume="";
        numar_concurenti_initial=0;
        participanti.clear();
    }
    joc(const std::string &numjoc, std::vector<om>part){
        nume=numjoc;
        numar_concurenti_initial=part.size();
    }
    virtual std::vector<om> joaca()=0;
};

class jocul_miscarii: public joc{
public:
    jocul_miscarii(std::vector<om>part) : joc("jocul_miscarii", participanti){
        }

    std::vector<om> joaca() override{
        std::vector<om> jucatori_ramasi;
        int ok=1;
        int suprafata,numar;
        int lim_jucator[10];
        int lim_runda[10];
        int suma_distanta_jucator=0;
        std::cin>>suprafata;
            for (int i = 0; i < 10; ++i) {
                std::cin>>lim_runda[i];
            }
            for (int i = 0; i < participanti.size(); ++i) {
                for (int j = 0; j < 10; ++j) {
                    std::cin>>lim_jucator[j];
                    suma_distanta_jucator=suma_distanta_jucator+lim_jucator[j];
                    if(lim_jucator[j]>lim_runda[j])
                        ok=0;
                }
                if(suma_distanta_jucator>suprafata || suma_distanta_jucator<suprafata)
                    ok=0;
                if(ok==1)
                    jucatori_ramasi.push_back(participanti[i]);
            }
            return jucatori_ramasi;
    }
};


class jocul_decuparii:public joc{
public:
    jocul_decuparii(std::vector<om>part): joc("jocul_decuparii", participanti){
    }
    std::vector<om> joaca() override{
        std::vector<om>part_ramasi;
        std::string forma;
        int contor,numar;
        std::cin>>forma;
        if(forma=="triunghi"){
            int a,b,c;
            for (int i = 0; i < participanti.size(); ++i) {
                std::cin>>a>>b>>c;
                if(a+b>c && a+c>b && b+c>a)
                    part_ramasi.push_back(participanti[i]);
            }
        }
        else if(forma=="patrat"){
            for (int i = 0; i < participanti.size(); ++i) {
                int a,b,c,d;
                std::cin>>a>>b>>c>>d;
                if(a==b==c==d)
                    part_ramasi.push_back(participanti[i]);
            }
        }
        else {
            for (int i = 0; i < participanti.size(); ++i) {
                int a, b, c, d, e;
                std::cin >> a >> b >> c >> d >> e;
                if (a == b == c == d == e)
                    part_ramasi.push_back(participanti[i]);
            }
        }
        return part_ramasi;
    }
};

class jocul_sforii:public joc{
public:
    jocul_sforii(std::vector<om>part): joc("jocul_sforii", participanti){
    }
    std::vector<om> joaca() override{
        std::vector<om> part_ramasi;
        std::vector<std::vector<om>> echipa;
        std::vector<int>sume_greutati_echipe;
        int a;
        std::cin>>a;
        return part_ramasi;
    }
};


int main() {

    return 0;
}
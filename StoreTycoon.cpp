  #include <bits/stdc++.h>

    using namespace std;
    class Person{
    public:
        string mName;
        string mProducts;
        double mSalary;
        Person(){
            mName="None";
            mProducts="";
            mSalary=0;
        }
        Person(string nume,string produs, double salariu){
            mName=nume;
            this->mSalary=salariu;
            this->mProducts=produs;
        }
        bool operator ==(const Person& pers) const{
            if(mName==pers.mName && mSalary==pers.mSalary)
                return true;
            else return false;
        }
        bool operator <(const Person& pers) const{
            if(mName<pers.mName)
                return true;
            else return false;
        }
    };

    class Product{
    public:
        string mName;
        string mType;
        double mPrice;
        Product() {
            mName = "None";
            mType = "";
            mPrice = 0;
        }
        Product(string nume,string tip,double pret)
        {
            mName=nume;
            mPrice=pret;
            mType=tip;
        }
        bool operator ==(const Product& prod) const{
            if(mName==prod.mName && mPrice==prod.mPrice)
                return true;
            else return false;
        }
        bool operator <(const Product& prod) const{
            if(mName<prod.mName)
                return true;
            else return false;
        }
    };

    class Store{
    protected:
        string mStoreName;
        string mType;
        vector<Person> mBuyers;
        vector<Product> mProducts;
    public:
        Store(string nume, string tip){
            mStoreName=nume;
            mType=tip;
        }
        virtual void add(const Person& oth)=0;
        virtual void remove(const Person& oth)=0;
        virtual void addProduct(const Product& oth) =0;
        virtual void removeProduct(const Product& oth)=0;
        virtual  Store* operator +(){
            return this;
        }
        virtual Store* operator -(const Person& oth){
            return this;
        }
        string getStoreName()const{
            return mStoreName;
        }
        string getType()const{
            return mType;
        }
        uint16_t getBuyersSize() const{
            return mBuyers.size();
        }
        uint16_t getProductsSize() const{
            return mProducts.size();
        }
        Person getBuyers(uint16_t indpers)const{
            return mBuyers[indpers];
        }
        Product getProducts(uint16_t indprod)const{
            return mProducts[indprod];
        }
    };
    class MiniMarket : public Store{
    public:
        MiniMarket(string nume):Store (nume,"MiniMarket")
        {
            mProducts.clear();
            mBuyers.clear();
        }
        virtual  Store* operator +() {
            return this;
        }
        virtual Store* operator -(const Person& oth) {
            return this;
        }
        void add(const Person& oth){
            mBuyers.push_back(oth);
        }
        void remove(const Person& oth){
            std::remove(mBuyers.begin(), mBuyers.end(), oth);
        }
        void addProduct(const Product& oth){
            mProducts.push_back(oth);
        }
        void removeProduct(const Product& oth){
            std::remove(mProducts.begin(), mProducts.end(), oth);
        }
    };
    class Market : public Store {
    public:
        Market(string nume):Store (nume,"Market")
        {
            mProducts.clear();
            mBuyers.clear();
        }
        virtual  Store* operator +() {
            return this;
        }
        virtual Store* operator -(const Person& oth) {
            return this;
        }
        void add(const Person& oth){
            mBuyers.push_back(oth);
        }
        void remove(const Person& oth){
            std::remove(mBuyers.begin(), mBuyers.end(), oth);
        }
        void addProduct(const Product& oth){
            mProducts.push_back(oth);
        }
        void removeProduct(const Product& oth){
            std::remove(mProducts.begin(), mProducts.end(), oth);
        }
    };
    class SuperMarket : public Store {
    public:
        SuperMarket(string nume):Store (nume,"SuperMarket")
        {
            mProducts.clear();
            mBuyers.clear();
        }
        virtual  Store* operator +() {
            return this;
        }
        virtual Store* operator -(const Person& oth) {
            return this;
        }
        void add(const Person& oth){
            mBuyers.push_back(oth);
        }
        void remove(const Person& oth){
            std::remove(mBuyers.begin(), mBuyers.end(), oth);
        }
        void addProduct(const Product& oth){
            mProducts.push_back(oth);
        }
        void removeProduct(const Product& oth){
            std::remove(mProducts.begin(), mProducts.end(), oth);
        }
    };
    class Mall : public Store {
    public:
        Mall(string nume):Store (nume,"Mall")
        {
            mProducts.clear();
            mBuyers.clear();
        }
        virtual  Store* operator +() {
            return this;
        }
        virtual Store* operator -(const Person& oth) {
            return this;
        }
        void add(const Person& oth){
            mBuyers.push_back(oth);
        }
        void remove(const Person& oth){
            std::remove(mBuyers.begin(), mBuyers.end(), oth);
        }
        void addProduct(const Product& oth){
            mProducts.push_back(oth);
        }
        void removeProduct(const Product& oth){
            std::remove(mProducts.begin(), mProducts.end(), oth);
        }
    };
    int main() {
        int nrMM = 0, nrM = 0, nrSM = 0, nrMall = 0, saleMM = 0, saleM = 0, saleSM = 0, saleMall = 0;
        double avgMM = 0, avgM = 0, avgSM = 0, avgMall = 0;
        int cMM = 0, cM = 0, cSM = 0, cMall = 0;
        int ok = 0;

        vector<Store *> stores;
        string action;

        while (cin >> action) {
            string object, nume, salariu;
            if (action == "add") {
                cin >> object;
                if (object == "MiniMarket") {
                    cin >> nume;
                    Store *p = new MiniMarket(nume);
                    stores.push_back(p);
                    nrMM++;
                } else if (object == "Market") {
                    cin >> nume;
                    Store *p = new Market(nume);
                    stores.push_back(p);
                    nrM++;
                } else if (object == "SuperMarket") {
                    cin >> nume;
                    Store *p = new SuperMarket(nume);
                    stores.push_back(p);
                    nrSM++;
                } else if (object == "Mall") {
                    cin >> nume;
                    Store *p = new Mall(nume);
                    stores.push_back(p);
                    nrMall++;
                } else if (object == "buyer") {
                    ok = 1;
                    Person cumparator;
                    cin >> cumparator.mName >> cumparator.mProducts >> cumparator.mSalary;
                    if (cumparator.mSalary < 500) {
                        for (int i = 0; i < stores.size(); ++i) {
                            if (stores[i]->getType() == "MiniMarket") {
                                stores[i]->add(cumparator);
                                cMM++;
                            }
                        }
                    } else if (cumparator.mSalary >= 500 && cumparator.mSalary < 1000) {
                        for (int i = 0; i < stores.size(); ++i) {
                            if (stores[i]->getType() == "Market"){
                                stores[i]->add(cumparator);
                                cM++;
                            }
                        }
                    } else if (cumparator.mSalary >= 1000 && cumparator.mSalary < 2000) {
                        for (int i = 0; i < stores.size(); ++i) {
                            if (stores[i]->getType() == "SuperMarket"){
                                stores[i]->add(cumparator);
                                cSM++;
                            }
                        }
                    } else {
                        for (int i = 0; i < stores.size(); ++i) {
                            if (stores[i]->getType() == "Mall"){
                                stores[i]->add(cumparator);
                                cMall++;
                            }
                        }
                    }
                } else {
                    ok = 1;
                    Product produs;
                    cin >> produs.mName >> produs.mType >> produs.mPrice >> nume;
                    for (int i = 0; i < stores.size(); ++i) {
                        if (nume == stores[i]->getStoreName())
                            stores[i]->addProduct(produs);
                    }
                }
            }
        }



        for (int i = 0; i < stores.size(); ++i) {
            for (int j = 0; j < stores[i]->getBuyersSize(); ++j) {
                string produs = stores[i]->getBuyers(j).mProducts;
                for (int k = 0; k < stores[i]->getProductsSize(); ++k) {
                    if (stores[i]->getType() == "MiniMarket") {
                        cMM++;
                        avgMM += stores[i]->getBuyers(j).mSalary;
                        if (produs == stores[i]->getProducts(k).mName)
                            saleMM++;
                    } else if (stores[i]->getType() == "Market") {
                        cM++;
                        avgM += stores[i]->getBuyers(j).mSalary;
                        if (produs == stores[i]->getProducts(k).mName)
                            saleM++;
                    } else if (stores[i]->getType() == "SuperMarket") {
                        cSM++;
                        avgSM += stores[i]->getBuyers(j).mSalary;
                        if (produs == stores[i]->getProducts(k).mName)
                            saleSM++;
                    } else {
                        cMall++;
                        avgMall += stores[i]->getBuyers(j).mSalary;
                        if (produs == stores[i]->getProducts(k).mName)
                            saleMall++;
                    }
                }
            }
        }
        for (int i = 0; i < stores.size(); ++i) {
            for (int j = 0; j < stores[i]->getBuyersSize(); ++j) {
                if (stores[i]->getType() == "MiniMarket") {
                    avgMM += stores[i]->getBuyers(j).mSalary;
                }
                else if (stores[i]->getType() == "Market") {
                    avgM += stores[i]->getBuyers(j).mSalary;
                }
                else if (stores[i]->getType() == "SuperMarket") {
                    avgSM += stores[i]->getBuyers(j).mSalary;
                }
                else {
                    avgMall += stores[i]->getBuyers(j).mSalary;
                }
            }
        }
                        cout<<"Number of MiniMarkets: "<<nrMM<<endl;
                        cout<<"Number of Markets: "<<nrM<<endl;
                        cout<<"Number of SuperMarkets: "<<nrSM<<endl;
                        cout<<"Number of Malls: "<<nrMall<<endl;
                        cout<<"Average Salary for MiniMarkets "<<avgMM/cMM<<endl;
                        cout<<"Average Salary for Markets "<<avgM/cM<<endl;
                        cout<<"Average Salary for SuperMarkets "<<avgSM/cSM<<endl;
                        cout<<"Average Salary for Malls "<<avgMall/cMall<<endl;
                        cout<<"Products Sale in MiniMarkets "<< saleMM<<endl;
                        cout<<"Products Sale in Markets "<<saleM<<endl;
                        cout<<"Products Sale in SuperMarkets "<<saleSM<<endl;
                        cout<<"Products Sale in Malls "<<saleMall<<endl;
                        return 0;
                    }
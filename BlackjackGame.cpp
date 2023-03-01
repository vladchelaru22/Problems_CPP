#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

class LcgGenerator{
private:
    uint16_t mA, mC, mCurrentX, mM;
public:
    LcgGenerator(uint16_t arg_mA, uint16_t arg_mC, uint16_t arg_mCurrent, uint16_t arg_mM){
        mA = arg_mA;
        mC = arg_mC;
        mCurrentX = arg_mCurrent;
        mM = arg_mM;
    }
    uint16_t next(){
        mCurrentX = (mCurrentX * mA + mC) % mM;
        return mCurrentX;
    }
};


class Card{
private:
    string mSuite;
    uint16_t mValue;
public:
    Card(){
        mValue=0;
        mSuite="";
    }
    Card(const string& arg_mSuite, uint16_t arg_mValue){
        mSuite = arg_mSuite;
        mValue = arg_mValue;
    }
    bool operator == (const Card & card) const{
        if(card.mValue == mValue && card.mSuite==mSuite) {
            return true;
        }
        return false;
    }
    string toString() const {
        return to_string(mValue) + "," + mSuite;
    }
   bool isFake() const {
        if(mValue >= 2 && mValue <= 14 && (mSuite=="rosu" || mSuite=="negru" || mSuite=="romb" || mSuite=="trefla")){
            return false;
        }
        return true;
    }
    uint16_t getBlackjackValue() const {
        if(mValue >= 10){
            return 10;
        }
        else return mValue;
    }
};


class CardPack{
private:
    uint16_t mCurrentIndex;
    vector<Card> mCards;
public:
    CardPack()=default;
    CardPack(bool empty){
        if(empty){
            mCurrentIndex=0;
            mCards.clear();
        }
        else {
            mCurrentIndex=0;
            
                for (int j = 2; j <= 14; ++j) {
                    if(j == 11)
                        continue;
                    else {
                        Card carte("rosu", j);
                        mCards.push_back(carte);
                    }
                }
                for (int j = 2; j <= 14; ++j) {
                    if(j == 11)
                        continue;
                    else {
                        Card carte("negru", j);
                        mCards.push_back(carte);
                    }
                }
                for (int j = 2; j <= 14; ++j) {
                    if(j == 11)
                        continue;
                    else {
                        Card carte("romb", j);
                        mCards.push_back(carte);
                    }
                }
                for (int j = 2; j <= 14; ++j) {
                    if(j == 11)
                        continue;
                    else {
                        Card carte("trefla", j);
                        mCards.push_back(carte);
                    }
                }
            
        }
    }
     bool goodForBackjack() const{
        for (int i=0;i<mCards.size();i++) {
            if(mCards[i].isFake())
                return false;
        }
        return true;
    }
    bool ok() const {
        if (mCards.size() != 52 || !goodForBackjack()){
            return false;
        }
        return true;
    }
    void addCard(const Card &carte){
        mCards.push_back(carte);
    };
    void shuffle(uint16_t a1,uint16_t c1,uint16_t x01,uint16_t a2,uint16_t c2,uint16_t x02){
        mCurrentIndex=0;
        uint16_t ux1,ux2;
        LcgGenerator gen1(a1,c1,x01,mCards.size());
        LcgGenerator gen2(a2,c2,x02,mCards.size());
        for(int i=0;i<50;i++){
            ux1=gen1.next();
            ux2=gen2.next();
            swap(mCards[ux1],mCards[ux2]);}
    }
    void printPack() const{
        vector<string> cartiString;
        for (const auto & mCard : mCards) {
            cartiString.push_back(mCard.toString());
        }
        for (auto & i : cartiString) {
            cout<<i<<endl;
        }

    }
    Card nextCard(){
        return mCards[mCurrentIndex];
        mCurrentIndex++;
    }
};


class Player{
private:
    string mName;
    uint16_t mMoney,mPoints;
public:
    Player(){
        mName="Dealer";
        mMoney=0;
        mPoints=0;
    }
    Player(string num,uint16_t bani){
        mName=num;
        mMoney=bani;
    }
    string toString() const{
        return mName + ": " + to_string(mMoney);
    }
    void pick(const Card &alegere){
        mPoints=mPoints+alegere.getBlackjackValue();
    }
    void play(CardPack &pachet){
        while(mPoints<17){
            pick(pachet.nextCard());
        }
    }
    void newRound(){
        mPoints=0;
    }
    bool lostRound() const{
        if(mPoints>21){
            return true;
        }
        return false;
    }
    uint16_t getPoints() const{
        return mPoints;
    }
    void operator --(){
        mMoney=mMoney-10;
    }
    void operator ++(){
        mMoney=mMoney+10;
    }
    bool lostGame()const{
        if(mMoney<10){
            return true;}
        return false;
    }
};


int main(){
    string comanda,semn;
    bool tip_pachet;
    char comma;
    uint16_t numar,contor=0;
    cin>>comanda;
    if(comanda=="check_cards") {
        tip_pachet= true;
        CardPack pachet(tip_pachet);
        while (cin >>numar>>comma>>semn) {
            contor++;
            Card carte(semn, numar);
            if (carte.isFake()) {
                cout << "Pachet masluit"<<endl;
                return 0;
            }
            else {
                pachet.addCard(carte);
            }
        }
        if(contor==52)
        {
            cout<<"Pachet OK"<<endl;}
        else if(pachet.goodForBackjack())
            cout<<"Pregatit pentru Blackjack"<<endl;
    }


    else if(comanda=="shuffle_cards"){
        int a1,c1,X01,a2,c2,X02;
        tip_pachet=true;
        CardPack pachet(tip_pachet);
        cin>>a1>>c1>>X01>>a2>>c2>>X02;
        while(cin >>numar>>comma>>semn){
            Card carte(semn, numar);
            pachet.addCard(carte);
        }
        pachet.shuffle(a1,c1,X01,a2,c2,X02);
        pachet.printPack();
    }
    
   else{
        uint16_t n,bani;
        CardPack pachet(false);
        vector<Player>jucatori;
        string nume;
        cin>>n;
        for (int i = 0; i < n; ++i) {
            cin>>nume>>bani;
            Player jucator(nume,bani);
            jucatori.push_back(jucator);
        }
        Player dealer("Dealer", 0);
        int a1,c1,X01,a2,c2,X02;
        while(cin>>a1>>c1>>X01>>a2>>c2>>X02) {
            dealer.newRound();
            for (int i = 0; i < jucatori.size(); ++i) {
                jucatori[i].newRound();
            }
            pachet.shuffle(a1, c1, X01, a2, c2, X02);
            for (int i = 0; i < jucatori.size(); ++i) {
                jucatori[i].pick(pachet.nextCard());
                jucatori[i].pick(pachet.nextCard());
            }
            dealer.pick(pachet.nextCard());
            dealer.pick(pachet.nextCard());
            for (int i = 0; i < jucatori.size(); ++i) {
                jucatori[i].play(pachet);
            }
            dealer.play(pachet);
            for (int i = 0; i < jucatori.size(); ++i) {
                if(dealer.lostRound() && !jucatori[i].lostRound()) 
                    ++jucatori[i];
                    
                 else if(dealer.getPoints()<jucatori[i].getPoints())
                  { if(!jucatori[i].lostRound())
                             ++jucatori[i];
                             else if(jucatori[i].lostGame()==0 )
                                --jucatori[i];
                  }
                    
                    else if(dealer.getPoints()>jucatori[i].getPoints() && dealer.lostRound()==0)
                     {
                     if(jucatori[i].lostGame()==0 )
                    --jucatori[i];
                    }
                
            }
        }
        for (int i = 0; i < jucatori.size(); ++i) {
            if(jucatori[i].lostGame())
                continue;
            else cout<<jucatori[i].toString()<<endl;
        }
    }
    return 0;
}
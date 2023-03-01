#include <bits/stdc++.h>
using namespace std;

class Spaceship
{
private:
    string mName;
    int mAttack, mShield;

public:
    Spaceship() {
    mName="nedefinit";
    mAttack=0;
    mShield=0;
    }

    Spaceship(string  name, int attack, int shield)
    {
        mName=name;
        mAttack=attack;
        mShield=shield;
    }

    Spaceship(const Spaceship & other)
    {
        mName=other.mName;
        mAttack=other.mAttack;
        mShield=other.mShield;
    }


    void setName(string  name)
    {
        mName=name;
    }

    void setAttack(int attack)
    {
        mAttack=attack;
    }

    void setShield(int shield)
    {
        mShield=shield;
    }

    string getName() const
    {
        return mName;
    }

    int getAttack() const
    {
        return mAttack;
    }


    int getShield() const
    {
        return mShield;
    }

    Spaceship operator=(const Spaceship & ship)
    {
        this->mName=ship.mName;
        this->mAttack=ship.mAttack;
        this->mShield=ship.mShield;
        return (*this);

    }

    Spaceship operator+=(const Spaceship & ship)
    {
        this->mAttack+=ship.mAttack;
        this->mShield+=ship.mShield;
        return (*this);

    }


    Spaceship operator-=(const Spaceship & ship)
    {
        this->mShield-=ship.mAttack;
        return (*this);

    }

    bool operator<(const Spaceship & ship)
    {
        if(this->mAttack+this->mShield>ship.mAttack+ship.mShield)
            return true;
        return false;
    }

    Spaceship operator^(const Spaceship & ship)
    {
        Spaceship attacked, attacker;
        attacked=(*this);
        attacker=ship;

        while(attacked.mShield>0 && attacker.mShield>0) {
            attacked -= attacker;
            if (attacked.mShield>0)
               attacker -= attacked;
            else return attacker;

            if(attacker.mShield<0)
                return attacked;
        }

    }


};

int main() {

   int nr_nave,i,atac,scuturi;
    string nume;
    vector< Spaceship>  winners;
    cin>>nr_nave;
    //Spaceship *nave=new Spaceship[nr_nave];
    vector<Spaceship> nave;
    /*for(i=0;i<nr_nave;i++)
        Spaceship nave[i];
*/
    nave.resize(nr_nave);

    for(i=0;i<nr_nave;i++)
    {
        cin>>nume;
        cin>>atac>>scuturi;

       nave[i].setAttack(atac);
       nave[i].setShield(scuturi);
       nave[i].setName(nume);
       cin.ignore();
    }

    int k;
    cin>>k;
    string comanda,nava1,nava2;
    int nava1_index,nava2_index;
    for(int j=0;j<k;j++) {
        cin >> comanda;
        cin >> nava1;
        cin >> nava2;
        cin.ignore();

        for (i = 0; i < nr_nave; i++) {
            if (nava1 == (nave[i].getName()))
                nava1_index = i;
            else if (nava2 == (nave[i].getName()))
                nava2_index = i;
        }
            if (comanda == "fight") {
                ///folosim operatorul ^
                Spaceship winner(nave[nava1_index] ^ nave[nava2_index]);
                if (winner.getName() == nave[nava1_index].getName()) {
                    nave[nava1_index] = winner;
                    nave[nava2_index].setShield(0);
                } else {
                    nave[nava2_index] = winner;
                    nave[nava1_index].setShield(0);
                }

            } else if(comanda=="transfer"){
                ///folosim operatorul +
                nave[nava1_index] += nave[nava2_index];
                nave[nava2_index].setShield(0);
            }
        }


    if(k==0)
        for(i=0;i<nr_nave;i++)
            winners.push_back(nave[i]);

    else {
        for(i=0;i<nr_nave;i++)
        {
            if(nave[i].getShield()>0)
                winners.push_back(nave[i]);
        }
    }

    int len =(int) winners.size();
    int j;
        for (i = 0; i < len - 1; i++)
            for (j = i + 1; j < len; j++)
                if ((winners[i] < winners[j]) == false) {
                    Spaceship aux;
                    aux = winners[i];
                    winners[i] = winners[j];
                    winners[j] = aux;
                }




    for(i=0;i<len;i++)
        cout<<winners[i].getName()<<endl;

    return 0;
}

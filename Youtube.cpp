#include <bits/stdc++.h>
using namespace std;
class Video{
private:
    string mVideoId;
    uint32_t mLikes,mDislikes,mViews;
protected:
    Video(const std::string & ID, uint32_t laik, uint32_t dislaik, uint32_t viuz ){
        mVideoId=ID;
        mLikes=laik;
        mDislikes=dislaik;
        mViews=viuz;
    }

public:
    string getId() const{
        return mVideoId;
    }
    uint32_t getDislikes() const{
        return mDislikes;
    }
    double getSimpleScore() const{
        double  x=(1.0*mLikes)/(1.0*mDislikes)+1;
        double y=(1.0/mViews);
        return x-y;
    }
    virtual double getAdvancedScore() const=0;
    void print(bool simple) const{
        cout<<mVideoId<<" ";
        if(simple)
        printf("%.2lf\n", getSimpleScore());
        else printf("%.2lf\n",getAdvancedScore());
    }
};

class StudyVideo:public Video{
public:
    StudyVideo(const std::string & ID, uint32_t laik, uint32_t dislaik, uint32_t viuz): Video(ID,laik,dislaik,viuz){

    }
    double getAdvancedScore() const override{
        return getSimpleScore()*2;
    }
};

class AnimalVideo:public Video{
public:
    AnimalVideo(const std::string & ID, uint32_t laik, uint32_t dislaik, uint32_t viuz):Video(ID,laik,dislaik,viuz){

    }
    double getAdvancedScore() const override{
        return getSimpleScore()*0.75;
    }
};

class SportsVideo:public Video{
public:
    SportsVideo(const std::string & ID, uint32_t laik, uint32_t dislaik, uint32_t viuz): Video(ID,laik,dislaik,viuz){

    }
    double getAdvancedScore() const override{
        return getSimpleScore()*0.5;
    }
};

class VideoFactory:public Video{
public:
    VideoFactory()=delete;
    static Video* createVideo(const std::string & id, const std::string & type, uint32_t likes, uint32_t dislikes, uint32_t views){
        if(type=="Studiu"){
            Video *StudVid= new StudyVideo(id,likes,dislikes,views);
            return StudVid;
        }
        else if(type=="Animale"){
            Video *AnimVid=new AnimalVideo(id,likes,dislikes,views);
            return AnimVid;
        }
        else if(type=="Sport"){
            Video *SportVid=new SportsVideo(id,likes,dislikes,views);
            return SportVid;
        }
        else throw invalid_argument("EROARE");
    }
};
int cmp(const void *a, const void *b){
    Video *A=(Video*)a;
    Video *B=(Video*)b;
    if(A->getSimpleScore()<B->getSimpleScore())
        return 1;
    else return 0;
}
int cmpA(const void *a, const void *b){
    Video *A=(Video*)a;
    Video *B=(Video*)b;
    if(A->getAdvancedScore()<B->getAdvancedScore())
        return 1;
    else return 0;
}


int main() {
    uint32_t n,views,likes,dislikes;
    string id,type;
    char cerinta;
    vector<Video*> vids;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin >> id >> type >> views >> likes >> dislikes;
        try{
        Video *ptr = VideoFactory::createVideo(id, type, likes, dislikes, views);
        vids.push_back(ptr);
        }
        catch (invalid_argument& err)
        {
            cout << err.what() << endl;
            return 0;
        }
    }
    cin>>cerinta;
    if(cerinta=='a'){
        sort(vids.begin(),vids.end(), cmp);
        for (int i = 0; i < vids.size(); ++i) {
        vids[i]->print(true);
        }
    }
    else if (cerinta == 'b') {
        double suma = 0;
        double medie;
        for (int i = 0; i < vids.size(); ++i) {
            suma = suma + vids[i]->getSimpleScore();
        }
        medie=suma/n;
        for (int i = 0; i < vids.size(); ++i) {
            if(vids[i]->getSimpleScore()>medie)
                vids[i]->print(true);
        }
    }
    else if(cerinta=='c'){
        while(cin >> id >> type >> views >> likes >> dislikes){
             int k=0;
            Video *ptr = VideoFactory::createVideo(id, type, likes, dislikes, views);
            for (int i = 0; i < vids.size(); ++i) {
                if(vids[i]->getId()==id){
                    vids[i]=ptr;
                    k++;}
            }
            if(k==0)
                vids.push_back(ptr);
        }
        sort(vids.begin(), vids.end(), cmp);
        for (int i = 0; i < vids.size(); ++i) {
            vids[i]->print(true);
        }
    }
    else {
        sort(vids.begin(), vids.end(), cmpA);
        for (int i = 0; i < vids.size(); ++i) {
            vids[i]->print(false);
        }

    }
        return 0;
}


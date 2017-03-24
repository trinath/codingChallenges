// author: trinath 
// Designing a parking lot having 3 types of parking spaces. a) Handicapped b) Regular and c) Compact
#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

enum Status{
    EMPTY,
    NORMAL,
    FULL
};

class Observer{
    public:
        virtual void update(int count) = 0;
};

class Subject{
    private:
        vector<Observer*> observerList;
    public:
        void registerObserver(Observer* ob){
            observerList.push_back(ob);
        }
        void removeObserver(Observer* ob){
            int index = -1;
            for(int i = 0; i < observerList.size(); i++){
                if(observerList[i] == ob){
                    index = i; 
                }
            }
            if(index >= 0) observerList.erase(observerList.begin()+index);
        }
        void notifyObservers(int count){
            for(Observer* ob: observerList){
                ob->update(count);
            }
        }
        
};

class ParkingLotSign{
    public:
        ParkingLotSign(){
            state = EMPTY;
        }
        void Empty(){
            state = EMPTY;
        }
        void Full(){
            state = FULL;
        }
        void Normal(){
            state = NORMAL;
        }
        Status getState(){
            return state;
        }
        void Show(){
            switch(state){
                case EMPTY:
                    cout << "Sign: Empty" << endl;
                    break;
                case NORMAL:
                    cout << "Sign: Normal" << endl;
                    break;
                case FULL:
                    cout << "Sign: Full" << endl;
                    break;     
            }
        }
    private:
        Status state;
};

class ParkingSpace: public Subject{
    public:
        ParkingSpace(int dis){
            state = false;
            distance = dis;
        }
        void take(){
            state = true;
            notifyObservers(1);
        }
        void vacate(){
            state = false;
            notifyObservers(-1);
        }
        bool getState(){
            return state;
        }
        int getDistance(){
            return distance;
        }
        virtual void setCost() = 0;
        virtual ~ParkingSpace() {}
    private:
        int distance;
        bool state;
    protected:    
        int cost;
};

class HandicappedParkingSpace: public ParkingSpace{
    public:
        HandicappedParkingSpace(int dis):ParkingSpace(dis){

        }
        void setCost(){
            cost = 100;
        }
};

class RegularParkingSpace: public ParkingSpace{
    public:
        RegularParkingSpace(int dis):ParkingSpace(dis){

        }
        void setCost(){
            cost = 80;
        }
};

class CompactParkingSpace: public ParkingSpace{
    public:
        CompactParkingSpace(int dis):ParkingSpace(dis){

        }
        void setCost(){
            cost = 50;
        }
};

class ParkingLot: public Observer{
    private:
        ParkingLotSign sign;
        vector<ParkingSpace*> regularParking;
        vector<ParkingSpace*> compactParking;
        vector<ParkingSpace*> handicappedParking;
        int total;
    public:
        ParkingLot(){
            total = 0;
        }
        ~ParkingLot(){
            for(ParkingSpace* ps: regularParking){
                delete ps;
            }
            for(ParkingSpace* ps: compactParking){
                delete ps;
            }
            for(ParkingSpace* ps: handicappedParking){
                delete ps;
            }
            regularParking.resize(0);
            compactParking.resize(0);
            handicappedParking.resize(0);
        }
        ParkingSpace *getNearestParking(vector<ParkingSpace*> &parking){
            ParkingSpace *output = NULL;
            int minDistance = INT_MAX;
            for(ParkingSpace* ps: parking){
                if(ps->getState() == false && ps->getDistance() < minDistance){
                    minDistance = ps->getDistance();
                    output = ps;
                }
            }
            if(output == NULL){
                cout << "No Parking Available" << endl;
            }
            output->registerObserver(this);
            return output;
        }
        ParkingSpace *getNearestParking(string type){
            if(type == "handicapped"){
                return getNearestParking(handicappedParking);
            } else if (type == "regular"){
                return getNearestParking(regularParking);
            } else {
                return getNearestParking(compactParking);
            }
        }
        void addParking(string type, int distance){
            if(type == "handicapped"){
                handicappedParking.push_back(new HandicappedParkingSpace(distance));
            } else if (type == "regular"){
                regularParking.push_back(new RegularParkingSpace(distance));
            } else {
                compactParking.push_back(new CompactParkingSpace(distance));
            }
        }
        void update(int count){
            total += count;
            if(total == 0){
                sign.Empty();
            } else if( total == handicappedParking.size() + regularParking.size() + compactParking.size()){
                sign.Full();
            } else {
                sign.Normal();
            }
        }
        bool isAvailable(){
            if(sign.getState() != FULL){
                return true;
            }
            return false;
        }
        void showSign(){
            sign.Show();
        }
};

class Car{
    private:
        ParkingSpace *carParking;
        string type;
        ParkingLot *lot;
    public:
        Car(){

        }
        Car(ParkingLot *parkLot, string pType){
            lot = parkLot;
            type = pType;
        }
        void setParkingSpace(ParkingSpace *space){
            carParking = space;
        }
        bool park(){
            setParkingSpace(lot->getNearestParking(type));
            if(!carParking){
                cout << "Not Available" << endl;
                return false;
            }
            carParking->take();
            return true;
        }
        bool unpark(){
            carParking->vacate();
            return true;
        }
};

int main(){
    ParkingLot firstFloor;
    int distance[5] = {10, 20, 30, 40, 50};
    string type;
    for(int i = 0; i < 5; i++){
        firstFloor.addParking("compact", distance[i]);
        firstFloor.addParking("regular", distance[i]);
        firstFloor.addParking("handicapped", distance[i]);
    }
    vector<Car*> carList;
    carList.push_back(new Car(&firstFloor, "regular"));
    carList.push_back(new Car(&firstFloor, "compact"));
    carList.push_back(new Car(&firstFloor, "handicapped"));
    for(Car* it: carList){
        it->park();
        firstFloor.showSign();
    }
    for(Car* it: carList){
        it->unpark();
        firstFloor.showSign();
    }
    return 0;
}
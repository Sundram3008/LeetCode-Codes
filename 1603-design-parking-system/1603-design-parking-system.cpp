class ParkingSystem {
public:
    int t1, t2, t3;
    ParkingSystem(int big, int medium, int small) {
        t1= big;
        t2= medium;
        t3= small;
    }
    
    bool addCar(int carType) {
        if(carType ==1){
            if(t1>0){
                t1--;
                return true;
            }else return false;
        }else if(carType==2){
            if(t2>0){
                t2--;
                return true;
            }else return false;
        }else{
            if(t3>0){
                t3--;
                return true;
            }else return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
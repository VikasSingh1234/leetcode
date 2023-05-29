class ParkingSystem {
public:
    vector<int> slots{0,0,0};
    ParkingSystem(int big, int medium, int small) {
        slots[0] = big;
        slots[1] = medium;
        slots[2] = small;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            if(slots[0]>0){
                slots[0]--;
                return true;
            }
            return false;
        }
        else if(carType==2){
            if(slots[1]>0){
                slots[1]--;
                return true;
            }
            return false;
        }
        else{
            if(slots[2]>0){
                slots[2]--;
                return true;
            }
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
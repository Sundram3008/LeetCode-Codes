class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkInmp;
    unordered_map<string, pair<double,int>> pathDt;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInmp[id]= {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string path= checkInmp[id].first+ "->" + stationName;
        double duration = t- checkInmp[id].second;
        double totalDuration= pathDt[path].first+ duration;
        int trips= pathDt[path].second + 1;
        pathDt[path] = {totalDuration, trips};
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto details= pathDt[startStation + "->" + endStation];
        return details.first/ details.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
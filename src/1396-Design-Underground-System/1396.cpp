class UndergroundSystem {
public:
    void checkIn(int id, string startStation, int timeIn) {
        check_in[id] = {startStation, timeIn};
    }
    
    void checkOut(int id, string endStation, int timeOut) {
        const auto &[startStation, timeIn] = check_in[id];
        auto &[avg, cnt] = check_out[startStation + ">" + endStation];
        avg += timeOut - timeIn;
        ++cnt;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto [avg, cnt] = check_out[startStation + ">" + endStation];
        return (double)avg / cnt;
    }
private:
    unordered_map<int, pair<string, int>> check_in;
    unordered_map<string, pair<int, int>> check_out;
};
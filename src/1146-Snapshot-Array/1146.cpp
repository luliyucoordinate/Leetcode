class SnapshotArray 
{
public:
    SnapshotArray(int length) {}
    
    void set(int index, int val) 
    {
        dif[index] = val;
    }
    
    int snap() 
    {
        snaps.push_back(dif);
        return snaps.size() - 1;
    }
    
    int get(int index, int snap_id) 
    {
        if (snaps[snap_id].count(index)) return snaps[snap_id][index];
        return 0;
    }
private:
    unordered_map<int, int> dif;
    vector<unordered_map<int, int>> snaps;
};
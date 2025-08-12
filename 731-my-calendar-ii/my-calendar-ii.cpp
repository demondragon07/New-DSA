class MyCalendarTwo {
public:
 map<int,int>mp;

    MyCalendarTwo() {
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        int sum=0;
        for(auto x:mp){
            sum+=x.second;
            if(sum>2){
                mp[startTime]--;
                mp[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
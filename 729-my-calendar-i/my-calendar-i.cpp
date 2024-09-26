class MyCalendar {
public:
    vector<pair<int, int>> v;

    MyCalendar() {}

    bool book(int start, int end) 
    {
        for (const auto& interval : v) 
        {
            if (!(interval.second <= start || interval.first >= end)) 
            {
                return false;
            }
        }
        v.push_back({start, end});
        return true;
    }
};
class MyCalendar {
public:
    vector<pair<int, int>> v;

    MyCalendar() {}

    bool book(int start, int end) 
    {
        for (const auto& i : v) 
        {
            if (!(i.second <= start || i.first >= end)) 
            {
                return false;
            }
        }
        v.push_back({start, end});
        return true;
    }
};
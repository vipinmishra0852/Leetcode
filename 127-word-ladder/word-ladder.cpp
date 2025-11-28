class Solution {
public:
    bool dekho(string beginWord,string isse)
    {
        int count = 0;
       
        for(int i = 0 ; i < beginWord.size() ; i++)
        {
            if(beginWord[i] != isse[i]) count++;
        }
        
        if(count >= 2) return false;
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
    queue<string>q;
    set<string>visited;
    int count = 1;
    q.push(beginWord);
    visited.insert(beginWord);
    while(!q.empty())
    {
        int sz = q.size();
        while(sz--)
        {
        string str = q.front();
        q.pop();
        for(string yewala:wordList)
        {
            
            if(dekho(str,yewala) && visited.find(yewala) == visited.end())
            {
                visited.insert(yewala);
                q.push(yewala);
                if(yewala == endWord) return count+1;
            }
        }
        }
        count++;    
    }
    return 0;   
    }
};
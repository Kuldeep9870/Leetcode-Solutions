class Solution {
private:
    bool check(string s,int i)
    {
        if(s[i]=='a'|| s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            return true;
        else if(s[i]=='A'|| s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            return true;
        else
            return false;
    }
public:
    string reverseVowels(string s) {
        int strt,end;
        strt=0;
        end=s.length()-1;
        while(strt<end)
        {
            while(strt<end && check(s,strt)==false)
            {
                strt++;
            }
            while(strt<end && check(s,end)==false)
            {
                end--;
            }
            //cout<<strt<<" "<<end;
            if(strt<end)
            swap(s[strt],s[end]);
            strt++;
            end--;
        }
        return s;
        
    }
};
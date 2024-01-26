class Solution {
public:
    vector<string> words;
    int maxWidth;

    string CenterAlign(int begin, int end, int sum)
    {
        string str;
        int spaces = maxWidth - sum;
        
        if(end - begin == 1) return LeftAlign(begin, end, sum);
        
        int ds = spaces / (end - begin - 1);
        int spare = spaces % (end - begin - 1);
        
        for(int j = begin; j < end; j++)
        {
            str = str + words[j];
            if(j == end-1) break;

            for(int k = 0; k < ds; k++)
                str.push_back(' ');
            str.push_back(' ');
            if(spare-- > 0) str.push_back(' ');
        }
        cout << str << endl;

        return str;
    }

    string LeftAlign(int begin, int end, int sum)
    {
        string str;
        for(int j = begin; j < end; j++)
        {
            str = str + words[j];
            if(j == end-1) break;
            str.push_back(' ');
        }
        int extraSpace = maxWidth - str.size();
        for(int i = 0; i < extraSpace; i++)
        {
            str.push_back(' ');
        }

        return str;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        this->words = words;
        this->maxWidth = maxWidth;

        vector<string> ret;

        int start = 0;
        int sum = words[0].size();

        for(int i = 1; i < words.size(); i++)
        {
            int add = words[i].size() + 1;

            if(i == words.size()-1)
            {
                if(sum + add <= maxWidth)
                {
                    ret.push_back(LeftAlign(start, i+1, sum + add));
                }
                else
                {
                    ret.push_back(CenterAlign(start, i, sum));
                    ret.push_back(LeftAlign(i, i+1, words.size()));
                }
            }

            else if( sum + add > maxWidth )
            {
                ret.push_back(CenterAlign(start, i, sum));
                start = i;
                sum = words[i].size();
            }
            else
            {
                sum+= add;
            }
        }

        if(start == 0) ret.push_back(LeftAlign(start, start+1, words[start].size()));
        return ret;
    }
};
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> directories;

        istringstream iss(path);
        string buffer;

        while(getline(iss, buffer, '/'))
        {
            // cout << "captured: " << buffer << "<" << endl;

            if(buffer == "") continue;
            if(buffer == ".") continue;
            if(buffer == "..")
            {
                if(directories.size()) directories.pop_back();
            }
            else 
            {
                directories.push_back(buffer);
            }
        }

        string ret;
        for(auto s : directories)
            ret += "/" + s;

        if(!ret.size()) return "/";
        else return ret;
    }
};
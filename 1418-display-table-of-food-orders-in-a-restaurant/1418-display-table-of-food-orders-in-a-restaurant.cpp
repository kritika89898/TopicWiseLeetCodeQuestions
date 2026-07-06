class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> ans;
        set<string> food;
        map<int,map<string,int>>mp;
        for(auto& o:orders){
            int tn = stoi(o[1]);
            string f = o[2];
            food.insert(f);
            mp[tn][f]++;
        }
        vector<string> table;
        table.push_back("Table");
        for(auto& f:food){
            table.push_back(f);
        }
        ans.push_back(table);
        for (auto &[table, cnt] : mp) {
            vector<string> row;
            row.push_back(to_string(table));

            for (auto &food : food)
                row.push_back(to_string(cnt[food]));

            ans.push_back(row);
        }

        return ans;
    }
};
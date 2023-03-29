class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> indexMap;
        vector<string> result;
        int indexSum=__INT_MAX__;
        for(int i=0;i<list1.size();i++)
        {
            indexMap[list1[i]]=i;
        }
        for(int j=0;j<list2.size();j++)
        {
            if(j>indexSum)break;
            if(indexMap.count(list2[j])>0)
            {
                int k = indexMap[list2[j]];
                if(j+k<indexSum)
                {
                    result.clear();
                    result.push_back(list2[j]);
                    indexSum=j+k;                    
                }
                else if(j+k==indexSum)
                {
                    result.push_back(list2[j]);
                }
            }
        }
        return result;
    }
};
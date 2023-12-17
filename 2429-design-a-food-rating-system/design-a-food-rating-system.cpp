class FoodRatings {
public:
    unordered_map<string,string>cus;
    unordered_map<string,set<pair<int,string>>>food;
    unordered_map<string,int>rat;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            string foo=foods[i];
            string c=cuisines[i];
            int r=ratings[i];
            food[c].insert({-r,foo});
            cus[foo]=c;
            rat[foo]=r;
        }
    }
    
    void changeRating(string fod, int newRating) {
        string c=cus[fod];
        int ol=rat[fod];
        food[c].erase({-ol,fod});
        food[c].insert({-newRating,fod});
        rat[fod]=newRating;
    }
    
    string highestRated(string cuisine) {
     return begin(food[cuisine])->second;   
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
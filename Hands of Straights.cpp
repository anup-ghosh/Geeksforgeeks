bool isStraightHand(int n, int gsz, vector<int> &hand) {
        if(n%gsz!=0) return false;
        sort(hand.begin(),hand.end());
        multimap<int,int> mp;
        for(int i=0;i<hand.size();i++){
            auto it=mp.find(hand[i]-1);
            if(it!=mp.end()){
                int tp=it->second;
                mp.erase(it);
                if(tp+1<gsz) mp.insert({hand[i],tp+1});
            }
            else{
                if(1<gsz) mp.insert({hand[i],1});
            }
        }
        if(mp.size()==0) return true;
        return false;
    }
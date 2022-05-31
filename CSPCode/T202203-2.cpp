#include<bits/stdc++.h>
using namespace std;
/*
*
*/
int goOutNum,askNum,timeWait;
vector<pair<int,int> > activities;
vector<int> asktimes;
int main(){
    cin>>goOutNum>>askNum>>timeWait;
    // Cin goout info
    for(int i=0;i<goOutNum;i++){
        pair<int,int> act;
        cin>>act.first>>act.second;
        activities.push_back(act);
    }
    // cin asktimes
    for(int i=0;i<askNum;i++){
        // 做核算的时间
        int testTime; 
        cin >> testTime;
        // 
        int start = testTime + timeWait;
        int end;
        int ans = 0;
        
        for(int j=0;j<activities.size();j++){
            end = testTime + timeWait + activities[j].second;
            if(activities[j].first >= start && activities[j].first <= end)
                ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;

}
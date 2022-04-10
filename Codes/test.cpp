#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        // 经典的 最长回文子串

        // 分段
        // 先从中间开始，如果不是回文的则分成两段进行递归
        int n = s.size();
        if(n==1)
            return s;
        if(n%2 == 0){
            // 偶数长度
            int mid1 = (n-1)/2;
            int mid2 = n/2;
            int maxres = 1;
            int resmid = findpartEven(0,n-1,mid1,mid2,&maxres,s);
            // 然后找到对应的字符串
            string ans = s.substr(resmid-maxres/2,maxres);
            return ans;
        }
        else{
            // 开始时奇数
            int mid = n/2;
            int maxres = 1;
            int resmid = findpartOdd(0,n-1,mid,&maxres,s);
            // 根据mid 和 res 找到字符串返回
            string ans = s.substr(resmid-maxres/2,maxres);
            return ans;
        }
       
    }
    // 找一部分的  长度为奇数
    int findpartOdd(int left,int right,int mid,int *maxres,string s){
         // 没必要再找了
        if(*maxres >= right - left + 1)
            return mid;
        int temp_res = 1;
        int resmid = mid;
        int n = right - left;
        for(int i=1;i<=n/2;i++){
            if( s[mid-i] == s[mid+i]){
                temp_res += 2;
                *maxres = max(*maxres,temp_res);
            }
            else{
                // 不相等 也是拆成两个偶数数的
                *maxres = max(*maxres,temp_res);
                //if(n==2) return mid;
                int newoddmid1 = (mid + left) / 2;
                int newoddmid2 = (mid + left) / 2 + 1;
                int res1mid = findpartEven(left,mid,newoddmid1,newoddmid2,maxres,s);
                if(temp_res < *maxres){
                    resmid = res1mid;
                    temp_res = *maxres;
                }
                newoddmid1 = (right + mid) / 2;
                newoddmid2 = (right + mid) / 2 + 1;
                int res2mid = findpartEven(mid,right,newoddmid1,newoddmid2,maxres,s);
                if(temp_res < *maxres){
                    resmid = res2mid;
                    temp_res = *maxres;
                }
                return resmid;
            }
        }
        return resmid;
    }
    // 找一部分的长度为偶数
    int findpartEven(int left,int right,int mid1,int mid2,int *maxres,string s){
        // 没必要再找了
        if(*maxres >= right - left + 1)
            return mid2;
        int temp_res = 0;
        int resmid = mid2;
        int n = right - left;
        for(int i=0;i<=n/2;i++){
            if( s[mid1-i] == s[mid2+i]){
                temp_res += 2;
                *maxres = max(*maxres,temp_res);
            }
            else{
                // 不相等 拆成两个奇数的
                *maxres = max(*maxres,temp_res);
                int newevenmid = (mid2 + left) / 2;
                int res1mid = findpartOdd(left,mid2,newevenmid,maxres,s);
                if(temp_res < *maxres){
                    resmid = res1mid;
                    temp_res = *maxres;
                }
                newevenmid = (right + mid1) / 2;
                int res2mid = findpartOdd(mid1,right,newevenmid,maxres,s);
                if(temp_res < *maxres){
                    resmid = res2mid;
                    temp_res = *maxres;
                }
                return resmid;
            }
        }
        return resmid;
    }
};
int main()
{
    Solution s;
    s.longestPalindrome("abb");
    return 0;
}
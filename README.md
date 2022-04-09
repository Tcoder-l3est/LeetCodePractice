# LeetCodePractice

### T34 在排序数组中查找元素的第一个和最后一个位置

![image-20220127145958824](https://vvtorres.oss-cn-beijing.aliyuncs.com/image-20220127145958824.png)

解答





---

### T74 搜索二维矩阵

![image-20220205222523251](https://vvtorres.oss-cn-beijing.aliyuncs.com/image-20220205222523251.png)



![image-20220205222534894](https://vvtorres.oss-cn-beijing.aliyuncs.com/image-20220205222534894.png)

题解

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 思路是先扫描最后一个数 如果小于 就扫描这一行 没有就false
        int m = matrix.size();
        for(int i=0;i<m;i++){
            int n = matrix[i].size();
            if(matrix[i][n-1] >= target){
                // 扫描这一行
                for(int j=0;j<n;j++){
                    if(matrix[i][j]==target)
                        return true;
                }
                return false;
            }
        }
        return false;
    }
};
```

---

### T33 搜索旋转排序数组

![image-20220205223156976](https://vvtorres.oss-cn-beijing.aliyuncs.com/image-20220205223156976.png)

**要求设计一个Olog(n)复杂度的搜索方法**

**题解**

**logn 可以用二分查找 然后怎么用呢？ 必须有序 怎么有序？->拆成两段有序数组就行了**

引出另外一个题目 如下**T153 寻找旋转排序数组中的最小值**

先利用这个思路 找出最小值 ，就找到从哪进行旋转了 然后 Nums[0] 和 MIn 分别是两端的起点，如果target < Nums[0] 就后段二分搜索 反之前段

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 先找Min的位置
        int index = 0;//默认位置
        int n = nums.size();
        int left = 0;int right = n-1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right])
                right = mid;
            else
                left = mid + 1;
        }
        index = left;// 这是最小值的位置
        if(target < nums[0]){
            // 后半段二分
            int low = index;
            int high = n-1;
            while(low < high){
                int mid = low + (high - low) / 2;
                if(nums[mid] < target){
                    // 比target小 说明还得往右
                    low = mid + 1;
                }else if(nums[mid] > target){
                    high = mid;
                }else{
                    // 相等
                    return mid;
                }
            }
            if(nums[low]==target)
                return low;
            else
                return -1;

        }else if(target > nums[0]){
            // 反之 前段
            int low = 0;
            int high = index-1;
            if(index == 0){
                high = n-1;
            }
            while(low < high){
                int mid = low + (high - low) / 2;
                if(nums[mid] < target){
                    // 比target小 说明还得往右
                    low = mid + 1;
                }else if(nums[mid] > target){
                    high = mid;
                }else{
                    // 相等
                    return mid;
                }
            }
            // 没找到
            if(nums[low]==target)
                return low;
            else
                return -1;
        }else{
            return 0;
        }
    }
};
```

 **另一个解法:**

![image-20220206010104832](https://gitee.com/zzy9/cloudimage/raw/master/image-20220206010104832.png)

---

### T153 寻找旋转排序数组中的最小值

**题目：**

![image-20220206001104642](https://vvtorres.oss-cn-beijing.aliyuncs.com/image-20220206001104642.png)

**题解**

![image-20220206002534755](https://vvtorres.oss-cn-beijing.aliyuncs.com/image-20220206002534755.png)

```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        // 所谓的旋转类似于 看作一个循环数组 然后转一下
        int n = nums.size();
        // 仍然可以用二分查找 只不过对于不同情况做不同处理
        int left=0; int right = n-1;
        // 第一种情况: 中值 < 右侧---说明中间现在是在最小值的右侧
        // 第二:  mid>right  ------- 说明右在最小值右边，  中在最小值左边
        // End: 当朝朝的区间长度不为1
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right]){
                // 说明中点 在最小值右边
                right = mid;
            }else
                left = mid + 1;
        }
        return nums[left];
    }
};
```





---

### T162 寻找峰值

**题目**

对于所有有效的 `i` 都有 `nums[i] != nums[i + 1]`

![image-20220206232950456](https://vvtorres.oss-cn-beijing.aliyuncs.com/image-20220206232950456.png)

**题解**

```c++
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 1 2 3 1
        // 沿着递增方向找 一定能找到最大值
        int left = 0;int right = nums.size()-1;
        while(left < right){
            int mid = left + (right - left) / 2 ;
            if(nums[mid + 1] >= nums[mid]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};
```

---

### T82 删除排序链表中的重复元素 ii

> 双指针

**题目**

![image-20220206234043695](https://vvtorres.oss-cn-beijing.aliyuncs.com/image-20220206234043695.png)

---

2022.2.25 Let's Go on!

### T537. 复数乘法

> ![image-20220225210318670](https://vvtorres.oss-cn-beijing.aliyuncs.com/image-20220225210318670.png)**注意 此题使用了 atoi函数**

**题解**

没啥好说的

我就是用了字符串处理的思想

```c++
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        // 输入" Real1 + abstract1 * i" 按照 + 来分割字符串即可
        int Real1,abstract1,Real2,abstract2;
        string temp1,temp2;
        int flag = 0;
        // 处理num1
        for(auto c : num1){
            if(flag == 1){
                if(c!='i'){
                    temp2+=c;
                }
            } 
            if(c != '+'&&flag == 0){
                temp1+= c;
            }
            else
                flag = 1;
        }
                Real1 = atoi(temp1.c_str());
        abstract1 = atoi(temp2.c_str());
        
        flag = 0;
        temp1 = "";temp2 = "";
        // 处理num2
        for(auto c : num2){
            if(flag == 1){
                if(c!='i'){
                    temp2+=c;
                }
            } 
            if(c != '+'&&flag == 0){
                temp1+= c;
            }
            else
                flag = 1;
        }
        Real2 = atoi(temp1.c_str());
        abstract2 = atoi(temp2.c_str());

        // 进行乘法
        int res1 = Real1*Real2 - abstract1 * abstract2;
        int res2 = Real1*abstract2 + Real2 * abstract1;
        string rez1 = to_string(res1);
        string rez2 = to_string(res2);
        //0+2i
        string result = rez1 + "+" + rez2 + "i";
        return result;
    }
};
```

**更好的方法**

![image-20220225211343222](https://vvtorres.oss-cn-beijing.aliyuncs.com/image-20220225211343222.png)

使用了**sscanf** 以及 **sprintf**

string 的输入 比如第一行就是把string a 按照引号的格式 输出到后面的地址中

最后sprintf 就是反过来了 后面的作为%d 然后输出到"a" 

---

### T2016 增量元素之间的差值

![image-20220226203045091](https://vvtorres.oss-cn-beijing.aliyuncs.com/image-20220226203045091.png)

**题解**

```c++
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // 7 1 5 4
        // 对应有多少种差值呢？
        // i = 0---n-1   j = 1 --- n
        // N的范围1000 O(n^2) 完全可以AC 但是能优化吗？
        // nums[2] - 
        int n = nums.size();

        //int Deltas[1005]; // 表示 最大差值
        //vector Deltas(n,0);
        // DP的思想吧 用一个pos 来记录 最小被减数 即维护一个前缀最小值
        // DP的思想了

        // Deltas[i] = max(Deltas[i-1],nums[i]-nums[pos]);
        // 必须是后面的 大于 前面的才能相减
        int premin = nums[0];
        int ans = -1;
        //Deltas[1] = nums[1] - nums[0];// 开始的最大插值认为是  -00
        for(int i=1;i<=n-1;i++){
            // 可以减 说明后面的大
            if(nums[i] > premin){
                ans = max(ans,nums[i] - premin);
            }
            else{// 后面小 需要更新premin
               premin = nums[i];
            }
        }
        return ans;
    }
};
```

### T553 最优除法

给定一组正整数，相邻的整数之间将会进行浮点除法操作。例如， [2,3,4] -> 2 / 3 / 4 。

但是，你可以在任意位置添加任意数目的括号，来改变算数的优先级。你需要找出怎么添加括号，才能得到最大的结果，并且返回相应的字符串格式的表达式。你的表达式不应该含有冗余的括号。

**题解**

数学用脑子想：

```c++
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        // 数学方法（分母最小 分子最大）所以分母使劲除法 分子不除
        string ans = to_string(nums[0]);
        if(nums.size() == 1){
            return ans;
        }
        else if(nums.size() == 2){
            ans += "/" + to_string(nums[1]);
            return ans;
        }
        ans += "/(";
        for(int i=1;i<nums.size() - 1;i++){
            string temp = to_string(nums[i]);
            ans =ans +  temp + "/";
        }
        ans += to_string(nums[nums.size()-1]) + ")";
        return ans;
    }
};
```

区间DP



---

> 保研前的关键刷题了 💪加油啊
>
> 1. 每日三题
> 2. 先刷LeetCode Hot 100
> 3. 再刷CCF T2 卡70%  再刷 T4 . 

---

## Hot 100 系列

> 2022.4.9

### T2 两数相加

**KeyWord: 链表、中等**

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 双指针吗
        ListNode* scanNodeL1 = l1;
        ListNode* scanNodeL2 = l2;
        // 先单独处理头
        int addFromBefore = 0; // 前一位的进位
        int sum = scanNodeL1->val + scanNodeL2->val + addFromBefore;
        if(sum >= 10){
            addFromBefore = 1;
            sum = sum - 10;
        }
        // 返回的头指针
        ListNode* resHeadNode = new ListNode(sum);
        ListNode* LastinsertNode = resHeadNode; // 链表末尾
        scanNodeL1 = scanNodeL1->next;
        scanNodeL2 = scanNodeL2->next;
        // 从头开始，类似于全加器
        while(scanNodeL1 != nullptr && scanNodeL2 != nullptr){
            sum = scanNodeL1->val + scanNodeL2->val + addFromBefore;
            if(sum < 10)
                addFromBefore = 0;
            if(sum >= 10){
                // 12    1    2
                addFromBefore = 1;
                sum = sum - 10;
            }
            ListNode* newnode = new ListNode(sum);
            LastinsertNode->next = newnode;
            LastinsertNode = newnode;
            scanNodeL1 = scanNodeL1->next;
            scanNodeL2 = scanNodeL2->next;
        }
        // 然后单独处理剩余的   999 + 11 = 9+1   9+1+1  9+1  =  0  1  0  1 = 1010
        while(scanNodeL1 != nullptr){
            // 还有剩余 则直接复制构造然后insert
            sum = scanNodeL1->val +  addFromBefore;
            if(sum < 10)
                addFromBefore = 0;
            if(sum >= 10){
                addFromBefore = 1;
                sum = sum - 10;
            }
            ListNode* newnode = new ListNode(sum);
            LastinsertNode->next = newnode;
            LastinsertNode = newnode;
            scanNodeL1 = scanNodeL1->next;
        }
        while(scanNodeL2 != nullptr){
            // 还有剩余 则直接复制构造然后insert
            sum = scanNodeL2->val +  addFromBefore;
            if(sum < 10)
                addFromBefore = 0;
            if(sum >= 10){
                addFromBefore = 1;
                sum = sum - 10;
            }
            ListNode* newnode = new ListNode(sum);
            LastinsertNode->next = newnode;
            LastinsertNode = newnode;
            scanNodeL2 = scanNodeL2->next;
            
        }
        if(addFromBefore != 0){
            // 进位
            ListNode* newnode = new ListNode(1);
            LastinsertNode->next = newnode;
        }

        return resHeadNode;
    }
};
```

---

### T3 无重复字符的最长字串

**keyword: 滑动窗口**

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 不含重复字符 的  最长  字串
        // O(n^2) = 25 * 10^8 也许可以
        // 试试DP呢
        // int n = s.size();
        // dp[i] 表示到 i位置   的最长字串的长度
        // 从i-1 到 i 新来一个char c, 如果
        // dp[i] = max(dp[i-1],)
        // vector<int> dp(n,0);

        // ------------------- 瞥了一眼题解 思路错了 用滑动窗口 ----------------
        // if(s == ""){
        //     return 0;
        // }
        // int n = s.size();
        // vector<int> dp(n,1);
        // // 滑动窗口忘了  c了 又看错题了 又重复字符就行 不是字符串。。。
        // // 假设用一个map 26 每次新加入 判断
        // vector<int> ctb(128,0);
        // ctb[s[0]] = 1;
        // for(int i=1;i<n;i++){
        //     // 看出现了吗
        //     int c = s[i];
        //     if(ctb[c] == 0){
        //         // 没出现过
        //         dp[i] = dp[i-1] + 1;
        //         ctb[c] = 1;
        //     }
        //     else{
        //         // 出现过了
        //         dp[i] = 1;
        //         // vector fill 0
                
        //         fill(ctb.begin(),ctb.end(),0);
        //         ctb[s[i]] = 1;
        //     }
        // }
        // return *max_element(dp.begin(),dp.end());


        // ------------------- 瞥了一眼题解 思路错了 用滑动窗口 ----------------
        int n = s.size();
        // 滑动窗口
        int left = 0;
        int ans = 0;
        // 记录每个字符的 最右位置
        vector<int> Table(128,0);
        for(int right =0;right < n;right++){
            // 更新左边界
            // 如果有重复的 则左边界
            // 没有重复 调整右边界

            // 如果 右边新进来的字符是重复的，则左边前进，
            // 前进到的位置就是重复字符的前一次出现的后一个位置
            left = max(left,Table[s[right]]);
            Table[s[right]] = right + 1;
            ans = max(ans, right - left + 1);

            
        }
        return ans;
    }
};
```

---


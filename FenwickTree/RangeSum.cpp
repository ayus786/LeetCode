// Leetcode 307 - Range Sum Query Mutable
class FenwickTree{
    public:
        vector<int> BIT;
        FenwickTree(){
        }
        FenwickTree(vector<int> nums){
            int n=nums.size();
            BIT.assign(n+1,0);
            for(int i=1; i<=n; i++){
                updateBIT(nums[i-1],i);
            }
        }
        void updateBIT(int nums,int idx){
            while(idx<BIT.size()){
                BIT[idx]+=nums;
                idx = getNext(idx);
            }
        }
        int getParent(int idx){
            return (idx-(idx&-idx));
        }
        int getSum(int idx){
            idx+=1;
            int sum=0;
            while(idx>0){
                sum+=BIT[idx];
                idx = getParent(idx);
            }
            return sum;
        }
        int getNext(int idx){
            return idx+(idx&-idx);
        }
    };
    class NumArray {
        FenwickTree f;
        vector<int> arr;
    public:
        NumArray(vector<int>& nums) : f(nums), arr(nums) {}
        
        void update(int index, int val) {
            int diff = val - arr[index];
            arr[index] = val;
            f.updateBIT(diff, index + 1);  // 1-based
        }
        
        int sumRange(int left, int right) {
            return f.getSum(right)-f.getSum(left-1);
        }
    };
    
    /**
     * Your NumArray object will be instantiated and called as such:
     * NumArray* obj = new NumArray(nums);
     * obj->update(index,val);
     * int param_2 = obj->sumRange(left,right);
     */
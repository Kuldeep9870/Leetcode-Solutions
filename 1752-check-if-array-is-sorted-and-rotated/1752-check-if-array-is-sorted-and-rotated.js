/**
 * @param {number[]} nums
 * @return {boolean}
 */
var check = function(nums) {
    let n=nums.length;
    let ans=0;
    for(let i=0;i<n-1;i++){
        if(nums[i]>=nums[i+1]){
            ans++;
        }
    }
    if(nums[0]<nums[n-1])
        ans++;

    if(ans<=1)
        return true;

    return false;
};
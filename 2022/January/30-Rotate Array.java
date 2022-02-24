class Solution {
    public void rotate(int[] nums, int k) {
        int[] rotateArr = new int[nums.length];
        for(int i=0;i<nums.length;i++) {
            rotateArr[(i+k)%nums.length] = nums[i];
        }
        for(int i=0;i<nums.length;i++) {
            nums[i] = rotateArr[i];
        }
    }
}

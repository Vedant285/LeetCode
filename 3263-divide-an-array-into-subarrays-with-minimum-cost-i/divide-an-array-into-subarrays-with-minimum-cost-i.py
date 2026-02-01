class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        cnt1 = nums[0]
        temp = nums[1:]
        temp.sort()
        return cnt1 + temp[0] + temp[1]
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        store = set() 
        di = {}
        n = len(nums)
        for i in range(n):
            com = target - nums[i] 
            if com in di :
                return [di[com] , i]
            di[nums[i]] = i 

        return []


        
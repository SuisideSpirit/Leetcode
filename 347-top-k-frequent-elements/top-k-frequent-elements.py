class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        dih = {} 
        for i in range(len(nums)):
            if nums[i] in dih :
                dih[nums[i]] += 1
            else :
                dih[nums[i]] = 1 
        
        sorted_items = sorted(dih.items(), key=lambda x: x[1], reverse=True)

        return [sorted_items[x][0] for x in range(k)]
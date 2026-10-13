class Solution(object):
    def containsDuplicate(self, nums):
        d = {} 
        for i in nums:
            if i in d :
                return True
            else :
                d[i] = 1

        return False

        """
        :type nums: List[int]
        :rtype: bool
        """
        
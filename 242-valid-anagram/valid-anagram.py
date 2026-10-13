class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        arr1 = [0] * 26 
        arr2 = [0] * 26 
        for i in s :
            arr1[ord(i) - ord('a')] += 1 
        for i in t :
            arr2[ord(i) - ord('a')] += 1 

        for i in range(0,26):
            if arr1[i] != arr2[i]:
                return False 

        return True 
        
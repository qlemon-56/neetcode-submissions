class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        
        uniqueNums = list(set(nums))
        if len(uniqueNums) == len(nums):
            return False
        else: 
            return True
        
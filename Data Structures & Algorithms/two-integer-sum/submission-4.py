class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        for i in enumerate(nums):
            for x in enumerate(nums):
                if i[0] == x[0]:

                    continue

                if i[1]+x[1] == target:
                    
                    return [i[0], x[0]]


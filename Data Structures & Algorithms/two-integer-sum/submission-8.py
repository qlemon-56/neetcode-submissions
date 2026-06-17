class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        indices = {}
            
        for n, m in enumerate(nums):
            
            indices[m] = n

        for i, j in enumerate(nums):

            if target - j in indices.keys():
                if i != indices[target-j]:
                    return [i , indices[target-j]]

                

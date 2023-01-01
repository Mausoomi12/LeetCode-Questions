class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # List to store results
        result = []
        # Dictionary to store the difference and its index
        index_map = {}
        # Loop for each element
        for i, n in enumerate(nums):
        # Difference which needs to be checked
           difference = target - n
           if difference in index_map:
              result.append(i)
              result.append(index_map[difference])
              break
           else:
              index_map[n] = i
        return result
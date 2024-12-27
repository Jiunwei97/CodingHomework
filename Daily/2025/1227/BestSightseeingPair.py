from typing import List

class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        max_score = 0
        max_ai_plus_i = values[0]  # Tracks the maximum A[i] + i seen so far

        for j in range(1, len(values)):
            # Calculate the score for the current pair (i, j)
            max_score = max(max_score, max_ai_plus_i + values[j] - j)
            
            # Update max_ai_plus_i
            max_ai_plus_i = max(max_ai_plus_i, values[j] + j)
        
        return max_score
    
# Create an instance of the Solution class
solution = Solution()

# Input list
values = [8, 1, 5, 2, 6]

# Call the method and print the result
result = solution.maxScoreSightseeingPair(values)
print(result)  # Output: 11

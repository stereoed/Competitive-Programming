class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        max_sum = float('-inf')
        def dfs(root):
            if not root:
                return float('-inf')
            left_max = dfs(root.left)
            right_max = dfs(root.right)
            curr_val = root.val
            curr_res = max(curr_val, left_max + curr_val, right_max + curr_val)
            curr_max = max(curr_res, left_max + right_max + curr_val)
            nonlocal max_sum
            max_sum = max(max_sum, curr_max)
            return curr_res
        dfs(root)
        return max_sum
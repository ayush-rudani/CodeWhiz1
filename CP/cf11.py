for _ in range(int(input())):
    s = [ord(x)-96 for x in input()]
    cost = abs(s[0]-s[-1])
    l, r = sorted([s[0], s[-1]])
    path = [i for i, x in enumerate(s) if l <= x <= r]
    del path[0]
    del path[-1]
    if s[0] < s[-1]:
        path.sort(key=lambda i: s[i])
    else:
        path.sort(key=lambda i: s[i], reverse=True)
    print(cost, len(path)+2)
    print(1, *[i+1 for i in path], len(s))


class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        cnt = 0
        for x in data:
            if cnt == 0:
                if x >> 5 == 0b110:
                    cnt = 1
                elif x >> 4 == 0b1110:
                    cnt = 2
                elif x >> 3 == 0b11110:
                    cnt = 3
                elif x >> 7:
                    return False
            else:
                if x >> 6 != 0b10:
                    return False
                cnt -= 1
        return cnt == 0


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def pseudoPalindromicPaths(self, root: Optional[TreeNode], cnt=0) -> int:
        if not root:
            return 0
        cnt ^= 1 << (root.val)
        res = self.pseudoPalindromicPaths(
            root.left, cnt) + self.pesudoPalindromicPaths(root.right, cnt)
        if (not root.left) and (not root.right) and ((cnt & (cnt-1)) == 0):
            res += 1
        return res

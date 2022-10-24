import chunk


class Solution:
    def romanToInt(self, s: str) -> int:
        # Using Monotonic Stack
        vm = {'I': 1, 'V': 5, 'X': 10, 'L': 50,
              'C': 100, 'D': 500, 'M': 1000}
        stk = []
        for i in range(len(s)):
            val = vm[s[i]]
            if not stk or stk[-1] >= val:
                stk.append(val)
            else:
                pre = stk.pop()
                stk.append(val-pre)

        return sum(stk)


for _ in range(int(input())):
    n = int(input())
    s = input()
    i = 0
    cnt = 0
    while i < n:
        if s[i] in "aeiou":
            cnt = 0
        else:
            cnt += 1
        if cnt == 4:
            break
        i += 1
    if cnt == 4:
        print("NO")
    else:
        print("YES")


class Solution:
    def movesToStamp(self, s, t):
        n, m, t, s, res = len(t), len(s), list(t), list(s), []

        def check(i):
            changed = False
            for j in range(m):
                if t[i+j] == '?':
                    continue  # already replaced
                if t[i+j] != s[j]:
                    return False  # mismatch
                changed = True
            if changed:
                t[i:i+m] = ['?']*m
                res.append(i)
            return changed

        changed = True
        while changed:
            for i in range(m-m+1):
                changed |= check(i)
        return res[::-1] if t == ['?']*n else []


# cook your dish here
for _ in range(int(input())):
    n, d = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    ans = 0
    for i in range(n-1, 1, -1):
        if (arr[i]-arr[i-1]):
            ans += arr[i]+arr[i-1]
            i -= 2
    print(ans)


class Solution2:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next is None:
            return None
        slow, fast = head, head.next.next
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        slow.next = slow.next.next
        return head


class Solution:
    def maxChunksToSorted(self, arr):
        chunks = 0
        min_index_for_chunk_end = arr[0]
        for i in range(len(arr)):
            min_index_for_chunk_end = max(min_index_for_chunk_end, arr[i])
            if min_index_for_chunk_end == i:
                chunks += 1
                
        return chunks

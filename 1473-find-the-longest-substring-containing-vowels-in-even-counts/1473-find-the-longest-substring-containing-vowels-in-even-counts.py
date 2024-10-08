class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        vow=[-1]*26
        vow[0]=0
        vow[ord('e')-ord('a')]=1
        vow[ord('i')-ord('a')]=2
        vow[ord('o')-ord('a')]=3
        vow[ord('u')-ord('a')]=4
        n=len(s)
        first_seen=[-1]*32
        first_seen[0]=0
        curr=0
        Len=0
        for i in range(n):
            x=vow[ord(s[i])-ord('a')]
            if x!=-1: curr^=(1<<x)
            if first_seen[curr]==-1: first_seen[curr]=i+1
            Len=max(Len, i+1-first_seen[curr])
        return Len
        
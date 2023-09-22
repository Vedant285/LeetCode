class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        a=0
        if len(s)>len(t):
            return False
        if len(s)==0:
            return True
        for i in range (0,len(t)):
            if s[a]==t[i]:
                a+=1
            if a==len(s):
                return True
        return a==len(s)
        
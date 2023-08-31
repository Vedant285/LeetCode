class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        startend=[0]*(n+1)
        for i in range(len(ranges)):
            a=max(0,i-ranges[i])
            b=min(n,i+ranges[i])
            startend[a]=max(startend[a],b)
        curr=0
        start=0
        end=0
        for i in range(n+1):
            if(i>end):
                return -1
            if(i>curr):
                start+=1
                curr=end
            end=max(end,startend[i])
        return start;
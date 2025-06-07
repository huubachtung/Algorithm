#Lexicographically Minimum String After Removing Stars
class Solution:
    def clearStars(self, s: str) -> str:
        n=len(s)

        ans = list(s)

        buckets = [[]for _ in range(26)]
        for i,c in enumerate(s):
            if c == '*':
                #delete *
                ans[i]=''
                #find and delete the smallest non'*' character to its left
                for j in range(26):
                    #find if bucket[j] not a blank
                    if buckets[j]:
                        idx = buckets[j].pop()
                        ans[idx] = ''
                        break
            else:
                #append index of c
                buckets[ord(c)-ord('a')].append(i)
        return "".join(ans)
    

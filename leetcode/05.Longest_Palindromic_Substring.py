# %%
import numpy as np
# %%

def pal(s: str) -> str:
        if len(s) <= 2:
            try: 
                if s[1] != s[0]:
                    return s[1]
                else:
                    return s
            except (IndexError, TypeError):
                return s
        
        dp = np.eye(len(s), dtype=int )
        mxi = 0; mxj = 0; keys = []

        # for i in range(0, len(s)-1):
        #     if s[i+1] == s[i]:
        #         dp[i][i+1] = 1
                
        #         keys.append([i, i+1])
        #         if mx==0: mx=2
        # print(dp)
        diff = 0; mxi=0; mxj=0;
        for i in range(1, len(s)):
            for j in range(i, len(s)):
        
                if s[j-i] == s[j] and dp[j-i+1][j-1] == 1:
                    dp[j-i][j] = 1
                    
        
        zq = np.where(dp>0 );print(dp)
        for i in range(len(zq[0])):
            # print(zq[0][i],  ,abs(zq[0][i] - zq[1][i]))
            if abs(zq[0][i] - zq[1][i])>diff:
                mxi = zq[0][i]
                mxj = zq[1][i]
                diff = abs(zq[0][i] - zq[1][i])

                # print(zq[0][i], zq[1][i])
        print(mxi, mxj)
        if diff != 0:
            return s[mxi:mxj+1]
        else:
            return ""
        # if mx != 0:
        #     return s[keys[-1][0]:keys[-1][1]+1] 
        # else:
        #     return s[0]
# %%

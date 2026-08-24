class Solution:
    def minimumString(self, a: str, b: str, c: str) -> str:
        def checkSubArray(a, b):
            if len(a) < len(b):
                return checkSubArray(b,a )
            k = len(b)
            for i in range(0, len(a) - k + 1):
                if a[i:i+k] == b:
                    return a
            return ""
        def func(a, b):
            if checkSubArray(a, b) != "":
                return checkSubArray(a, b)
            x = min(len(a), len(b))
            y, z = "", ""
            res = a + b
            for i in range(0, x):
                y =  a[-1*(i + 1)] + y
                z += b[i]
                if y == z:
                    res = a[:-1*(i + 1)] + y + b[i+1:]
            return res
        ls = []
        ls.append(func(func(a,b), c))
        ls.append(func(func(a,c), b))
        ls.append(func(func(b,a), c))
        ls.append(func(func(b,c), a))
        ls.append(func(func(c,a), b))
        ls.append(func(func(c,b), a))

        mn = min([len(x) for x in ls])
        res = []
        for x in ls:
            if len(x) == mn:
                res.append(x)
        res.sort()
        
        return res[0]
                    
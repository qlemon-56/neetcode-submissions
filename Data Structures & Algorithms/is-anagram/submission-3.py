class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        listA = {}
        listB = {}

        for i in s:
            if i in listA:
                listA[i]+=1
            else:
                listA.update({i:1})

        for i in t:
            if i in listB:
                listB[i]+=1
            else:
                listB.update({i:1})

        if len(listA) == len(listB):

            for n in listA:
                if n not in listB:
                    return False
                elif not (listA[n] == listB[n]):
                    return False
        else:
            return False
        return True

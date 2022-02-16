from debugpy import trace_this_thread

memo={}

def canConstruct(target,wordBank):
    if target=="": return True
    if target in memo: return memo[target]
    
    for i in wordBank:
        if target.find(i)==0:
            if canConstruct(target.replace(i,'',1),wordBank): 
                memo[target]=True
                return True
    
    memo[target]=False
    return False

print(canConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"]),len(memo)); 
memo={}
print(canConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"]),len(memo)); 
memo={}
print(canConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"]),len(memo));
memo={}
print(canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",[
  "e",
  "ее"
  "еее"
  "eeee"
  "eeeee"
  "eeeeee"
]),len(memo)); 
memo={}

def countConstruct(target, wordBank):
    if target=='': return 1
    if target in memo: return memo[target]

    totalCount=0

    for i in wordBank:
        if target.find(i)==0:
            totalCount+=countConstruct(target.replace(i,'',1),wordBank)
    
    memo[target]=totalCount
    return totalCount

print(countConstruct('purple',['purp','p','ur','le','purpl']),len(memo))
memo={}
print(countConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"]),len(memo)); 
memo={}
print(countConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"]),len(memo)); 
memo={}
print(countConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"]),len(memo));
memo={}
print(countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",[
  "e",
  "ее"
  "еее"
  "eeee"
  "eeeee"
  "eeeeee"
]),len(memo)); 

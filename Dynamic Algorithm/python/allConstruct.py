# a=[['a','bh','gfh'],
#     ['q','wer']
# ]
# a=[['GH']+i for i in a]
# b=[]+a
# print(a)
# print(b)

memo={}

def allConstruct(target,wordBank):
    if target=="": return [[]]
    if target in memo: return memo[target]

    allWay=[]

    for i in wordBank:
        if target.find(i)==0:
            re=allConstruct(target.replace(i,'',1),wordBank)
            re=[[i]+j for j in re]
            allWay+=re

    memo[target]=allWay
    return allWay

print(allConstruct('purple',['purp','p','ur','le','purpl']))
memo={}
print(allConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd","ef","c"])); 
memo={}
print(allConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])); 
memo={}
print(allConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"]));
memo={}
print(allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",[
  "e",
  "ее"
  "еее"
  "eeee"
  "eeeee"
  "eeeeee"
])); 


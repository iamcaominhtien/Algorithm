def allConstruct(target,wordBank):
    memo=[[] for i in range(len(target)+1)]
    memo[0]=[[]]

    for i in range(len(memo)):
        if memo[i]!=None:
            for word in wordBank:
                if word==target[i:i+len(word)]:
                    temp=[j+[word] for j in memo[i]]
                    memo[i+len(word)]+=temp
                    # print(word,len(memo[i]),len(memo[i+len(word)]))

    return memo[-1]

print(allConstruct('purple',['purp','p','ur','le','purpl']))
print(allConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd","ef","c"])); # true
print(allConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])); # false
print(allConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"])); # true
# print(allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
#     "e",
#     "ee",
#     "еее",
#     "eeee"
#     "eeeee",
#     "eеееее",
# ])); # false
print(allConstruct("aaaaaaaaaaz", ["a", "aa' *aaa", "aaaa", "aaaaa"]))
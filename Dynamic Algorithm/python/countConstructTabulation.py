def countConstruct(target,wordBank):
    memo=[0 for i in range(len(target)+1)]
    memo[0]=1

    for i in range(len(memo)):
        if memo[i]:
            for word in wordBank:
                if word==target[i:i+len(word)]:
                    memo[i+len(word)]+=memo[i]

    return memo[-1]

print(countConstruct('purple',['purp','p','ur','le','purpl']))
print(countConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"])); # true
print(countConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])); # false
print(countConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"])); # true
print(countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
    "e",
    "ee",
    "еее",
    "eeee"
    "eeeee",
    "eеееее",
])); # false

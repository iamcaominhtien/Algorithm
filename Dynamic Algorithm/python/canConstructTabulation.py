def canConstruct(target,wordBank):
    memo=[False for i in range(len(target)+1)]
    memo[0]=True

    for i in range(len(memo)):
        if memo[i]:
            for word in wordBank:
                if word==target[i:i+len(word)]:
                    memo[i+len(word)]=True

    return memo[-1]

print(canConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"])); # true
print(canConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])); # false
print(canConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"])); # true
print(canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
    "e",
    "ee",
    "еее",
    "eeee"
    "eeeee",
    "eеееее",
])); # false

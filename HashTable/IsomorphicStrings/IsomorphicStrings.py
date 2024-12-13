def isIsomorphic(s: str, t: str) -> bool:
    # Dictionaries to store mappings
    mapStoT = {}
    mapTtoS = {}

    for charS, charT in zip(s, t):
        # Check the mapping from s -> t
        if charS in mapStoT:
            if mapStoT[charS] != charT:
                return False
        # Check the mapping from t -> s
        if charT in mapTtoS:
            if mapTtoS[charT] != charS:
                return False
        
        # Create the mappings
        mapStoT[charS] = charT
        mapTtoS[charT] = charS

    return True

# Example Usage
s = "egg"
t = "add"
print(isIsomorphic(s, t))  # Output: True

s = "foo"
t = "bar"
print(isIsomorphic(s, t))  # Output: False

s = "paper"
t = "title"
print(isIsomorphic(s, t))  # Output: True

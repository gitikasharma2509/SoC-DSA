class hashing:
    # we can use m=2**64-1 for better result
    m = int(1e9) + 9
    b = 9973
    _pow = [1]

    def __init__(self, st: str):
        while len(self._pow) <= len(st):
            self._pow.append((self._pow[-1] * self.b) % self.m)

        self.phash = [0 for i in range(len(st) + 1)]
        for i in range(len(st)):
            self.phash[i + 1] = (
                (self.phash[i] * self.b) % self.m + ord(st[i])
            ) % self.m

    def get_hash(self, start: int, end: int):
        raw_v = self.phash[end+1] - self.phash[start ] * self._pow[end - start + 1]
        return raw_v % self.m


# String comparing
small_str = str(input("Small String...."))
big_str = str(input("Big String...."))
freq_small = [0 for i in range(0, 27)]
freq_big = [0 for i in range(0, 27)]
hs = hashing(big_str)
for i in range(len(small_str)):
    freq_small[ord(small_str[i]) - ord("a")] = freq_small[ord(small_str[i]) - ord("a")] + 1
    freq_big[ord(big_str[i]) - ord("a")] = freq_big[ord(big_str[i]) - ord("a")] + 1

good = set({})
for i in range(len(small_str) - 1, len(big_str)):
    if i >= len(small_str):
        freq_big[ord(big_str[i]) - ord("a")] = freq_big[ord(big_str[i]) - ord("a")] + 1
        freq_big[ord(big_str[i - len(small_str)]) - ord("a")] = (
            freq_big[ord(big_str[i - len(small_str)]) - ord("a")] - 1
        )
    matc =True
    for k in range(0,27):
        if not (freq_big[k]==freq_small[k]):
            matc=False
            break
    if matc:
        good.add(hs.get_hash(i+1-len(small_str),i))    

print(len(good))        
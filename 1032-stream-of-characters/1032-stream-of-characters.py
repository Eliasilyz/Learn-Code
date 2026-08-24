class StreamChecker:

    def __init__(self, words: List[str]):
        self.streams = []
        self.word_trie = {}
        for word in words:
            curr_trie = self.word_trie
            for i in reversed(range(len(word))):
                curr_char = word[i]
                if curr_char not in curr_trie:
                    curr_trie[curr_char] = {}
                curr_trie = curr_trie[curr_char]
            curr_trie["#"] = True

    def query(self, letter: str) -> bool:
        self.streams.append(letter)
        curr_trie = self.word_trie
        for i in reversed(range(len(self.streams))):
            curr_char = self.streams[i]
            if curr_char not in curr_trie:
                return False
            curr_trie = curr_trie[curr_char]
            if "#" in curr_trie:
                return True
        return False
            
        
        


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
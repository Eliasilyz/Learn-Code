class Solution:

    
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        
        # In this first block, the words are split into different sentences
        # just taking into account the number of characters, not the spaces
        current_size = 0
        sentences = [[]]
        sentence_lengths = [0]
        
        
        for word in words:
            
            word_len = len(word)
        
            if sentence_lengths[-1] + len(sentences[-1]) + word_len <= maxWidth:
                sentences[-1].append(word)
                sentence_lengths[-1] += word_len
            else:
                print(sentences[-1])
                sentences.append([word])
                sentence_lengths.append(word_len)
        
        
        # In this block, the spaces are added in a equilibrate way
        for sentence_index, sentence in enumerate(sentences):
            
            space_number = maxWidth - sentence_lengths[sentence_index]
            
            if len(sentence) > 1 and sentence_index != len(sentences) - 1:
                spaces_by_hole = space_number // (len(sentence) - 1)
                spaces_remaining = space_number % (len(sentence) - 1)
                
                for word_index in range(len(sentence) - 1):
                    
                    if spaces_remaining > 0:
                        sentence[word_index] += ' '*(spaces_by_hole + 1)
                        spaces_remaining -= 1
                    else:
                        sentence[word_index] += ' '*(spaces_by_hole)
            
            else:
                
                spaces_remaining = space_number - len(sentence) + 1
                if len(sentence) > 1:
                    sentences[sentence_index] = [' '.join(sentence)]
                sentences[sentence_index][-1] += ' '*spaces_remaining

        
        # All the lists are joined
        for sentence_index in range(len(sentences)):
            sentences[sentence_index] = ''.join(sentences[sentence_index])
            
        return sentences
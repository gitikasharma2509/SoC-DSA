def solve_censoring():
    para = input("Enter paragraph: ")
    word = input("Enter word to remove: ")
    
    l = len(word)
    m = int(1e9) + 9
    b = 9973
    
    # 1. Precompute the powers of 'b' up to the max possible length
    pow_b = [1] * (len(para) + 1)
    for i in range(1, len(para) + 1):
        pow_b[i] = (pow_b[i-1] * b) % m
        
    # 2. Calculate the hash of the target word ONCE
    target_hash = 0
    for char in word:
        target_hash = (target_hash * b + ord(char)) % m
        
    # 3. Setup our Stack and a dynamic list to hold the stack's prefix hashes
    stack = []
    stack_hashes = [0] 
    
    # 4. Process the paragraph character by character
    for char in para:
        stack.append(char)
        
        # Dynamically calculate the hash of the stack as it grows
        new_hash = (stack_hashes[-1] * b + ord(char)) % m
        stack_hashes.append(new_hash)
        
        # If our stack is at least as long as the word, check the end!
        if len(stack) >= l:
            # Get the hash of just the last 'l' characters using our standard formula
            # Formula: Hash(end) - Hash(start) * Base^(length)
            end = len(stack)
            start = len(stack) - l
            
            sub_hash = (stack_hashes[end] - stack_hashes[start] * pow_b[l]) % m
            
            # Ensure it's positive (Python modulo usually handles this, but it's good practice)
            sub_hash = (sub_hash + m) % m 
            
            if sub_hash == target_hash:
                # Double-check to prevent extremely rare hash collisions
                if "".join(stack[-l:]) == word:
                    # MATCH! Delete the last 'l' characters from our stack and hashes
                    del stack[-l:]
                    del stack_hashes[-l:]
                    
    # Join the surviving characters back into a string
    print("".join(stack))

solve_censoring()
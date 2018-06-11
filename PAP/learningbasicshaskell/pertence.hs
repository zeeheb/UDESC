pertence :: [Int] -> Int -> Bool
pertence [] _ = False

pertence (aHead:aTail) n | (aHead == n) = True
                         | otherwise = pertence aTail n

complistas :: [Int] -> [Int] ->  Bool
complistas [] [] = True
complistas [] _ = False
complistas _ [] = False
complistas(aHead:aTail) (bHead:bTail) | (aHead == bHead) = complistas aTail bTail
                                      | otherwise = False

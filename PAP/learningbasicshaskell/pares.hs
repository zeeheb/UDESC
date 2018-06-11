pares :: [Int] -> Bool
pares [] = True
pares (aHead:aTail) | ( mod aHead 2 == 1) = False
                    | otherwise = pares aTail

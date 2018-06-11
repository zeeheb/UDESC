getmenor :: [Int] -> Int
getmenor [aHead] = aHead
getmenor (aHead:aTail) | (aHead < getmenor aTail ) = aHead
                       | otherwise = getmenor aTail

removemenor :: [Int] -> [Int]
removemenor [] = []
removemenor (aHead:aTail) | (aHead == (getmenor(aHead:aTail ))) = aTail
                          | otherwise = (aHead:removemenor aTail)

auxordena :: [Int] -> [Int] -> [Int]
auxordena listaordenada [] = listaordenada
auxordena listaordenada (aHead:aTail) =  auxordena (listaordenada++[getmenor(aHead:aTail)])  (removemenor (aHead:aTail))

ordena :: [Int] -> [Int]
ordena [] = []
ordena lista = auxordena [] lista

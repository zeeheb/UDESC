-- [t] lista generica
-- ++ é um operador de concatenão entre duas listas

invlista :: [t] -> [t]
invlista [] = []

invlista (aHead:aTail) = invlista aTail ++ [aHead]

'root' expression(-> X) print(x)

'nonterm' expression(-> INT)
    
    'rule' expression(-> X): exrp2(-> X)
    'role' expression (-> X+Y): expression(-> X) expression(-> Y) "+"
    'role' expression (-> X-Y): expression(-> X) expression(-> Y) "-"
    'role' expression (-> X*Y): expression(-> X) expression(-> Y) "*"
    'role' expression (-> X/Y): expression(-> X) expression(-> Y) "/"
   
 'nonterm' expr2(-> INT)
   
    'rule' expr2(-> X): Number(-> X) 
    'rule' expr2(-> -X): "-" expr2(-> X)
    'rule' expr2(-> X): "+" expr2(-> X)
    'rule' expr2(-> X): "(" expr2(-> X) ")"
    
 'token' Number(-> INT)

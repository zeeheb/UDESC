
func :: (Int, Int) -> (Int,Int) -> (Int, Int)
func (a,b) (c,d) = (a+c, b+d)




nomes :: (String, Int, String)
nomes = ("oi", 22, "haha")

select_name(x,_,_) = x
select_age(_,y,_) = y
select_country(_,_,z) = z

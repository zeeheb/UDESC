type nome = String
type idade = Int
type pais = String
type Pessoa = (nome, idade, pais)


pessoa :: Pessoa
pessoa = ("eu", 20, "br")

retornaNome :: Pessoa -> nome
retornaNome(n, i, p)  = 

From LF Require Export Poly.

(** * Métodos Formais - Lista de Exercícios 2 *)


(** Informalmente podemos dizer que o seguinte teorema estabelece a 
    comutatividade da função [fold] em relação a concatenação ([++]), 
    prove este teorema: *)
 
Theorem app_comm_fold :forall {X Y} (f: X->Y->Y) l1 l2 b,
  fold f (l1 ++ l2) b = fold f l1 (fold f l2 b).
Proof.
  intros. induction l1.
  - unfold fold. simpl. reflexivity. 
  - simpl. rewrite <- IHl1. simpl. reflexivity. Qed. 

(** Como visto no módulo [Poly.v], muitas funções sobre listas podem ser 
    implementadas usando a função [fold], por exemplo, a função 
    que retorna o número de elementos de uma listas pode ser implementada 
    como: *)

Definition fold_length {X : Type} (l : list X) : nat :=
  fold (fun _ n => S n) l 0.

(** Prove que [fold_length] retorna ao número de elementos de uma lista.
    Para facilitar essa prova demostre o lema [fold_length_head]. Dica:
    as vezes a tática [reflexivty] aplica uma simplificação mais agressiva 
    que a tática [simpl], isso seŕá util na prova desse lema. *) 

Lemma fold_length_head : forall X (h : X) (t : list X),
  fold_length (h::t) = S (fold_length t).
Proof. intros. reflexivity. Qed.
 
Theorem fold_length_correct : forall X (l : list X),
  fold_length l = length l.
Proof. intros. induction l.
  - unfold fold_length. simpl. reflexivity.
  - simpl. rewrite <- IHl. unfold fold_length. simpl. reflexivity. Qed.

(** Também é possível definir a função [map] por meio da função [fold],
    faça essa definição: *)

Definition fold_map {X Y: Type} (f: X -> Y) (l: list X) : list Y := fold (fun x l' => f x :: l') l[]. 


Example test_fold_map : fold_map (mult 2) [1; 2; 3] = [2; 4; 6].
Proof. reflexivity. Qed.

(** Prove que [fold_map] tem um comportamento identico a [map], defina lemas 
    auxiliares se necessário: *)

Theorem fold_map_correct : forall X Y (f: X -> Y) (l: list X),
  fold_map f l = map f l.
Proof.  
  intros. induction l.
  - unfold fold_map. simpl. reflexivity.
  - simpl. rewrite <- IHl. unfold fold_map. simpl. reflexivity. Qed. 

(** Podemos imaginar que a função [fold] coloca uma operação binária entre
    cada elemento de uma lista, por exemplo, [fold plus [1; 2; 3] 0] é igual 
    (1+(2+(3+0))). Da forma que foi declarada a função [fold] a operação 
    binária é executada da direita para esquerda. Declare uma função [foldl]
    que aplique a operação da esquerda para direita: *)

Fixpoint foldl {X Y: Type} (f: Y->X->Y) (b: Y) (l: list X) : Y. 
Admitted.


(** Exemplo: [foldl minus 10 [1; 2; 3]] igual (((10-1)-2)-3). *)

Example test_foldl : foldl minus 10 [1; 2; 3] = 4.
Proof. Admitted.





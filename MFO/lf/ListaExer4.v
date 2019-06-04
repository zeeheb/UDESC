From LF Require Export Logic.

(* José Eduardo Brandão *)


Theorem or_distributes_over_and : forall P Q R : Prop,
  P \/ (Q /\ R) <-> (P \/ Q) /\ (P \/ R).
Proof.
  intros. split.
  - intro H. split. destruct H as [ H1 | H2 ].
    +  left. apply H1.
    + destruct H2. right. apply H.
    + destruct H. left. apply H. destruct H. right. apply H0.
  - intro H. destruct H. destruct H. 
    + left. apply H.
    + destruct H0 as [H3 | H4]. left. apply H3. right. split. apply H. apply H4. Qed.
         

Theorem dist_exists_and : forall (X:Type) (P Q : X -> Prop),
  (exists x, P x /\ Q x) -> (exists x, P x) /\ (exists x, Q x).
Proof.
  intros X P Q. split.
  - destruct H as [HX H]. exists HX. destruct H. apply H.
  - destruct H as [HX H]. exists HX. destruct H. apply H0. Qed.


Check proj1.
Check proj2.

Lemma In_map_iff :
  forall (A B : Type) (f : A -> B) (l : list A) (y : B),
    In y (map f l) <->
    exists x, f x = y /\ In x l.
Proof.
   intros A B f l y. split.
  induction l as [| h t].
  - simpl. contradiction. 
  - simpl. intros [H | H].
    + exists h. split. apply H. left. reflexivity.
    + apply IHt in H. destruct H as [w [F I]]. exists w. split. apply F. right. apply I.
  - intros [w [F I]]. rewrite <- F. apply In_map. apply I. Qed.

Lemma In_app_iff : forall A l l' (a:A),
  In a (l++l') <-> In a l \/ In a l'.
Proof.
  intros. split.
  - induction l as [|h t].
    + simpl. intro. right. apply H.
    + simpl. intros [H | H]. left. left. apply H. apply IHt in H. destruct H.
         left. right. apply H. right. apply H. 
  - induction l as [|h t].
    + intros [H | H]. inversion H. simpl. apply H.
    + intros [H | H]. simpl. inversion H.
        left. apply H0. right. apply IHt. left. apply H0.
       simpl. right. apply IHt. right. apply H. Qed.

(* Inspirado na função [In], defina uma função [All] que é válida quando
uma proposição [P] é válida para todos elementos de uma lista [l]: *) 

Fixpoint All {T : Type} (P : T -> Prop) (l : list T) : Prop :=
  match l with 
  | [] => True
  | h :: t => P h /\ All P t
  end.


Lemma All_In :
  forall T (P : T -> Prop) (l : list T),
    (forall x, In x l -> P x) <->
    All P l.
Proof.
  intros. split.
  - induction l as [|h t].
    + reflexivity.
    + intros. simpl. split. apply H. simpl. left. reflexivity. apply IHt. intros. apply H. simpl. right. apply H0.
  - induction l as [|h t].
    + intros. inversion H0.
    + intros. simpl in H0. simpl in H. destruct H as [PH APT]. destruct H0 as [HX | IXT]. rewrite <- HX. apply PH.
      apply IHt. apply APT. apply IXT. Qed.

  

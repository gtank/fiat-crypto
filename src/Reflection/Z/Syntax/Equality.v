Require Import Coq.ZArith.ZArith.
Require Import Crypto.Reflection.Syntax.
Require Import Crypto.Reflection.Equality.
Require Import Crypto.Reflection.Z.Syntax.
Require Import Crypto.Util.Decidable.
Require Import Crypto.Util.PartiallyReifiedProp.
Require Import Crypto.Util.HProp.

Global Instance dec_eq_base_type : DecidableRel (@eq base_type)
  := base_type_eq_dec.
Global Instance dec_eq_flat_type : DecidableRel (@eq (flat_type base_type)) := _.
Global Instance dec_eq_type : DecidableRel (@eq (type base_type)) := _.

Definition base_type_eq_semidec_transparent (t1 t2 : base_type)
  : option (t1 = t2)
  := Some (match t1, t2 return t1 = t2 with
           | TZ, TZ => eq_refl
           end).
Lemma base_type_eq_semidec_is_dec t1 t2 : base_type_eq_semidec_transparent t1 t2 = None -> t1 <> t2.
Proof.
  unfold base_type_eq_semidec_transparent; congruence.
Qed.

Definition op_beq_hetero {t1 tR t1' tR'} (f : op t1 tR) (g : op t1' tR') : reified_Prop
  := match f, g return bool with
     | OpConst v, OpConst v' => Z.eqb v v'
     | OpConst _, _ => false
     | Add, Add => true
     | Add, _ => false
     | Sub, Sub => true
     | Sub, _ => false
     | Mul, Mul => true
     | Mul, _ => false
     | Shl, Shl => true
     | Shl, _ => false
     | Shr, Shr => true
     | Shr, _ => false
     | Land, Land => true
     | Land, _ => false
     | Lor, Lor => true
     | Lor, _ => false
     | Neg n, Neg m => Z.eqb n m
     | Neg _, _ => false
     | Cmovne, Cmovne => true
     | Cmovne, _ => false
     | Cmovle, Cmovle => true
     | Cmovle, _ => false
     end.

Definition op_beq t1 tR (f g : op t1 tR) : reified_Prop
  := Eval cbv [op_beq_hetero] in op_beq_hetero f g.

Definition op_beq_hetero_type_eq {t1 tR t1' tR'} f g : to_prop (@op_beq_hetero t1 tR t1' tR' f g) -> t1 = t1' /\ tR = tR'.
Proof.
  destruct f, g; simpl; try solve [ repeat constructor | intros [] ].
Defined.

Definition op_beq_hetero_type_eqs {t1 tR t1' tR'} f g : to_prop (@op_beq_hetero t1 tR t1' tR' f g) -> t1 = t1'
  := fun H => let (p, q) := @op_beq_hetero_type_eq t1 tR t1' tR' f g H in p.
Definition op_beq_hetero_type_eqd {t1 tR t1' tR'} f g : to_prop (@op_beq_hetero t1 tR t1' tR' f g) -> tR = tR'
  := fun H => let (p, q) := @op_beq_hetero_type_eq t1 tR t1' tR' f g H in q.

Definition op_beq_hetero_eq {t1 tR t1' tR'} f g
  : forall pf : to_prop (@op_beq_hetero t1 tR t1' tR' f g),
    eq_rect
      _ (fun src => op src tR')
      (eq_rect _ (fun dst => op t1 dst) f _ (op_beq_hetero_type_eqd f g pf))
      _ (op_beq_hetero_type_eqs f g pf)
    = g.
Proof.
  destruct f, g; simpl; try solve [ reflexivity | intros [] ];
    unfold op_beq_hetero; simpl;
      repeat match goal with
             | [ |- context[to_prop (reified_Prop_of_bool ?x)] ]
               => destruct (Sumbool.sumbool_of_bool x) as [P|P]
             | [ H : NatUtil.nat_beq _ _ = true |- _ ]
               => apply NatUtil.internal_nat_dec_bl in H
             | [ H : Z.eqb _ _ = true |- _ ]
               => apply Z.eqb_eq in H
             | _ => progress subst
             | _ => reflexivity
             | [ H : ?x = false |- context[reified_Prop_of_bool ?x] ]
               => rewrite H
             | _ => progress simpl @to_prop
             | _ => tauto
             end.
Qed.

Lemma op_beq_bl : forall t1 tR x y, to_prop (op_beq t1 tR x y) -> x = y.
Proof.
  intros ?? f g H.
  pose proof (op_beq_hetero_eq f g H) as H'.
  generalize dependent (op_beq_hetero_type_eqd f g H).
  generalize dependent (op_beq_hetero_type_eqs f g H).
  intros; eliminate_hprop_eq; simpl in *; assumption.
Qed.
Require Import Crypto.Arithmetic.PrimeFieldTheorems.
Require Import Crypto.Specific.solinas64_2e130m5_3limbs.Synthesis.

(* TODO : change this to field once field isomorphism happens *)
Definition sub :
  { sub : feBW_tight -> feBW_tight -> feBW_loose
  | forall a b, phiBW_loose (sub a b) = F.sub (phiBW_tight a) (phiBW_tight b) }.
Proof.
  Set Ltac Profiling.
  Time synthesize_sub ().
  Show Ltac Profile.
Time Defined.

Print Assumptions sub.

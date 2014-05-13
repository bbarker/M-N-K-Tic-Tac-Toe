(*
** M-N-K Tic-Tac-Toe
*)

(* ****** ****** *)
//
#include
"share/atspre_define.hats"
#include
"share/atspre_staload.hats"
//
(* ****** ****** *)


staload "./game.sats"

(* ****** ****** *)


implement 
main0 (argc, argv) = 
{
//
// Initialize game board and state.
//
val () = gameSetup()
//
// Start the game!
// 
//val () = gameLoop()

} (* end of [main0] *)

(* ****** ****** *)

(* end of [main.dats] *)

(*
** The M-N-K-game
*)

(* ****** ****** *)
//
#include
"share/atspre_staload.hats"
//
(* ****** ****** *)

staload UN = "prelude/SATS/unsafe.sats"

(* ****** ****** *)

staload "./game.sats"

(* ****** ****** *)

#define PLAYER1 1
#define PLAYER2 2

(* ****** ****** *)
//
extern
fun fprint_the_board (FILEref): void
implement
fprint_the_board (out) =
  fprint_board (out, game_conf_get_board())
(* ****** ****** *)
//
extern
fun fprint_winning_message (out: FILEref, player_id: int): void
implement
fprint_winning_message (out, player_id) = 
let
  val () = fprint_the_board (out)
  val () = fprint_newline (out)
  val () = fprintln! (out, "Player", player_id, " is the winner!")
in
  // nothing
end
//
(* ****** ****** *)
//
extern
fun the_board_mark_at
  (player_id: int, i: int, j: int): bool
extern
fun the_board_check_at
  (player_id: int, i: int, j: int): bool
//
(* ****** ****** *)

implement
the_board_mark_at
  (player_id, i, j) = let
//
val board = game_conf_get_board ()
//
in
  board_mark_at (board, player_id, i, j)
end // end of [the_board_mark_at]

implement
the_board_check_at
  (player_id, i, j) = let
//
val board = game_conf_get_board ()
//
in
  board_check_at (board, i, j)
end // end of [the_board_check_at]

(* ****** ****** *)

extern
fun player_move (): (int, int)

(* ****** ****** *)

implement
player_move () = let
//
val inp = stdin_ref
val line = fileref_get_line_string (inp)
var line2: string = $UN.strptr2string (line)
val i = string_get_int (line2)
val j = string_get_int (line2)
val () = strptr_free (line)
//
in
  (i, j)
end // end of [player_move]

(* ****** ****** *)

implement
game_mainloop () = let
//
val out = stdout_ref
val () = fprintln! (out, "M-N-K-game starts")
//

//  **************

val inp = stdin_ref
val out = stdout_ref
//
val () = (
  fprint_the_board (out); fprint_newline (out)
) (* end of [val] *)
//
val player_id = game_conf_get_player_id ()
val () = $extfcall(void, "fprintf", "Player%d's turn: ", player_id)
val () = fileref_flush (out)
val (i, j) = player_move ()
val error = the_board_mark_at (player_id, i, j)
val isWinner = the_board_check_at (player_id, i, j)
//
in if isWinner 
then 
  fprint_winning_message (out, player_id)  
else 
(
  game_conf_next_player_turn();
  game_mainloop ()
)
end (* end of [game_mainloop] *)

(* ****** ****** *)

(* end of [game_mainloop.dats] *)

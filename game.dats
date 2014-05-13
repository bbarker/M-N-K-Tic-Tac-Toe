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

typedef board_element_array =
  [mn,m,n:nat | m > 2 && n > 2 && mn == m*n] array(board_element, mn)
assume board_abstype = board_element_array

(* ****** ****** *)

typedef direction_int_pair = 
@{
, dx = int
, dy = int
}
assume direction_abstype = direction_int_pair

(* ****** ****** *)

typedef board_idx_point = 
@{
, x = board_idx
, y = board_idx
}
assume board_point_abstype = board_idx_point

(* ****** ****** *)

typedef board_conf_simple =
@{
, m = board_idx
, n = board_idx
, k = board_idx
, cursor = board_point
, num_players = int
, player_turn = int
}
assume board_conf_abstype = board_conf_simple 

(* ****** ****** *)


local

(* var pos: pos_struct *)
(* val () = pos.pos_ntot := 0 *)
(* val () = pos.pos_nrow := 0 *)
(* val () = pos.pos_ncol := 0 *)
(* val posref = ref_make_viewptr{pos_struct}(view@pos | addr@pos) *)

in (*in-of-local*)

(* ****** ****** *)


implement
gameSetup():void = {
val () = fprint(GAMETEXT_OUT_BUF,

"Welcome to M-N-K-Tic-tac-toe\n\n
Please use the W-A-S-D keys (followed by ENTER) to move the cursor.\n
To mark a square, press the 'T' key (followed by ENTER).\n\n")

val () =  fprint(GAMETEXT_OUT_BUF, 
  "How many columns (three or more)?\n>>")
val m_in(* :board_idx *) = char2i(flushAndGetChar(stdin_ref))

val () = fprint(GAMETEXT_OUT_BUF, 
  "How many rows (three or more)?\n>>")
val n_in(* :board_idx *) = char2i(flushAndGetChar(stdin_ref))

val min_m_n(* :board_idx *) = min(m_in, n_in)
val max_m_n(* :board_idx *) = max(m_in, n_in)


val () = $extfcall (void, "fprintf", GAMETEXT_OUT_BUF,
  "How many in a row to win (from %u to %u)?\n>>", 3 (*type?*), max_m_n)
val k_in = char2i(flushAndGetChar(stdin_ref))
 
val () = $extfcall(void, "fprint", GAMETEXT_OUT_BUF, 
  "How many players (up to %d)?\n>>", PLAYER_MAX) 
val num_players_in = flushAndGetChar(stdin_ref)

} (* end of [gameSetup] *)

end // end of [local]

(* ****** ****** *)

(* end of [game.dats] *)

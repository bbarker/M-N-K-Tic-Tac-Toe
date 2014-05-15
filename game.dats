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


local

//var board: board_type
var board_conf: board_conf_type?

//
// Get user input and configure board
//
val () = boardSetup(board_conf)

//These should be redundant, but even with, doesn't work
//val () = assertloc(board_conf.m > 2)
//val () = assertloc(board_conf.n > 2)

val mn_i = board_conf.m * board_conf.n

prval mnGt0pf = m_times_n_Gt0(board_conf.m, board_conf.n, mn_i)

val mn = i2sz(mn_i)


val (board_pf, board_pfgc | board_p) = array_ptr_alloc<board_element> (mn)

val () = array_initize_elt<board_element>(
  !board_p, mn, TILE_EMPTY
)

// Refactor: board_conf_r -> board_conf, board_conf -> board_conf_data
val board_conf_r = ref_make_viewptr{board_conf_type}(view@board_conf | addr@board_conf)

in (*in-of-local*)

(* ****** ****** *)


implement
boardSetup(
  board_conf
):void = {
//
val () = fprint(GAMETEXT_OUT_BUF,

"Welcome to M-N-K-Tic-tac-toe\n\n
Please use the W-A-S-D keys (followed by ENTER) to move the cursor.\n
To mark a square, press the 'T' key (followed by ENTER).\n\n")

val () =  fprint(GAMETEXT_OUT_BUF, 
  "How many columns (three or more)?\n>>")
val m_in(* :board_idx *) = char2i(flushAndGetChar(stdin_ref))
val m_in = ckastloc_gintGte (m_in, 2)

val () = fprint(GAMETEXT_OUT_BUF, 
  "How many rows (three or more)?\n>>")
val n_in(* :board_idx *) = char2i(flushAndGetChar(stdin_ref))
val n_in = ckastloc_gintGte (n_in, 2)

val min_m_n(* :board_idx *) = min(m_in, n_in)
val max_m_n(* :board_idx *) = max(m_in, n_in)


val () = $extfcall (void, "fprintf", GAMETEXT_OUT_BUF,
  "How many in a row to win (from %u to %u)?\n>>", 3 (*type?*), max_m_n)
val k_in = char2i(flushAndGetChar(stdin_ref))
val k_in = ckastloc_gintGte (k_in, 2)
 
val () = $extfcall(void, "fprint", GAMETEXT_OUT_BUF, 
  "How many players (up to %d)?\n>>", PLAYER_MAX) 
val num_players_in = char2i(flushAndGetChar(stdin_ref))


//Refactor to a fun:
// assign reasonable defaults
val () = board_conf.m := m_in
val () = board_conf.n := n_in
val () = board_conf.k := k_in
val () = board_conf.cursor := @{x = 0, y = 0}
val () = board_conf.num_players := num_players_in
val () = board_conf.player_turn := 0
//

} (* end of [gameSetup] *)



end // end of [local]

(* ****** ****** *)

(* end of [game.dats] *)

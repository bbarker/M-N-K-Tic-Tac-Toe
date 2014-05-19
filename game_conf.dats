(*
** The M-N-K-game
*)

#define NUM_PLAYERS 2 //temporary

(* ****** ****** *)

#define
ATS_PACKNAME "M_N_K_game"

(* ****** ****** *)

#include "share/atspre_staload.hats"

(* ****** ****** *)

staload UN = "prelude/SATS/unsafe.sats"

(* ****** ****** *)

staload "./game.sats"

(* ****** ****** *)

implement
fprint_conf (out) =
{
  val M = game_conf_get_m ()
  val N = game_conf_get_n ()
  val K = game_conf_get_k ()
  val () = fprintln! (out, "M-N-K is ", M, "-", N, "-", K)
}
 
(* ****** ****** *)

staload M = {
//
typedef T = int
//
fun
initize (x: &T? >> T): void = x := 0
//
#include "share/atspre_define.hats"
#include "{$LIBATSHWXI}/globals/HATS/globvar.hats"
//
} (* end of [staload] *)

(* ****** ****** *)

implement
game_conf_get_m () = $M.get ()
implement
game_conf_set_m (m) = $M.set (m)

(* ****** ****** *)

staload N = {
//
typedef T = int
//
fun
initize (x: &T? >> T): void = x := 0
//
#include "share/atspre_define.hats"
#include "{$LIBATSHWXI}/globals/HATS/globvar.hats"
//
} (* end of [staload] *)

(* ****** ****** *)

implement
game_conf_get_n () = $N.get ()
implement
game_conf_set_n (n) = $N.set (n)

(* ****** ****** *)

staload K = {
//
typedef T = int
//
fun
initize (x: &T? >> T): void = x := 0
//
#include "share/atspre_define.hats"
#include "{$LIBATSHWXI}/globals/HATS/globvar.hats"
//
} (* end of [staload] *)

(* ****** ****** *)

implement
game_conf_get_k () = $K.get ()
implement
game_conf_set_k (k) = $K.set (k)

(* ****** ****** *)

staload
BOARD = {
//
typedef T = ptr
//
fun
initize (x: &T? >> _): void = x := the_null_ptr
//
#include "share/atspre_define.hats"
#include "{$LIBATSHWXI}/globals/HATS/globvar.hats"
//
} (* end of [staload] *)

(* ****** ****** *)

implement
game_conf_get_board () = $UN.cast{board}($BOARD.get())
implement
game_conf_set_board (x) = $BOARD.set($UN.cast{ptr}(x))

(* ****** ****** *)

staload PLAYER = {
//
typedef T = int
//
fun
initize (x: &T? >> T): void = x := 1
//
#include "share/atspre_define.hats"
#include "{$LIBATSHWXI}/globals/HATS/globvar.hats"
//
} (* end of [staload] *)


(* ****** ****** *)

implement
game_conf_get_player_id () = $PLAYER.get ()
implement
game_conf_next_player_turn () =
let
 val next_player = 1 + (game_conf_get_player_id () mod NUM_PLAYERS)
in
  $PLAYER.set (next_player)
end

(* ****** ****** *)

staload CURSOR = {
//
#include "./game_types.hats"
#include "./game_board_types.hats"
//
typedef T = board_point
//
val test: board_point = '(0, 0)
fun
initize (x: &T? >> T): void = x := test
//
#include "share/atspre_define.hats"
#include "{$LIBATSHWXI}/globals/HATS/globvar.hats"
//
} (* end of [staload] *)


(* ****** ****** *)

implement
game_conf_get_cursor () = $PLAYER.get ()
implement
game_conf_set_cursor (cursor) = $PLAYER.set (cursor)

(* ****** ****** *)


(* end of [game_conf.dats] *)

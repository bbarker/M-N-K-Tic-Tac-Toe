

#define INIT     0
#define INTRO    1
#define MENU     2
#define GAME     3
#define SHUTDOWN 4


// Some tile definitions
#define CURSOR_ON_EMPTY '?'
#define CURSOR_ON_TAKEN '!'
#define TILE_EMPTY      ' '
#define BORDER_VERTICAL '|'
#define ENDROW          '\n'
//
#define PLAYER_SYMBOLS  "XO+@"
#define PLAYER_MAX      4


// Controls
#define KEY_BUFFER stdin
#define KEY_UP     'w'
#define KEY_DOWN   's'
#define KEY_LEFT   'a'
#define KEY_RIGHT  'd'
#define KEY_MARK   't'

// Other game definitions
#define GAMETEXT_OUT_BUF    stdout_ref
#define NUM_SCORE_LINES     4

// Error values
#define UNKNOWN_ERROR ~100


(* ** Game types ** *)

typedef board_element = char

abst@ype board_abstype = ptr
typedef board_type = board_abstype
(* typedef board_type = *)
(*   [mn,m,n:nat | m > 2 && n > 2 && mn == m*n] array(board_element, mn) *)


typedef board_idx = int //unsigned short int

(* ****** ****** *)

abst@ype direction_abstype = ptr
typedef direction = direction_abstype

(* ****** ****** *)

abst@ype board_point_abstype = ptr
typedef board_point = board_point_abstype

(* ****** ****** *)

abst@ype board_conf_abstype = ptr
typedef board_conf_type = board_conf_abstype

(* ****** ****** *)


(* ** Game functions ** *)
//
// Initialize the game board and state.
//
fun gameSetup (): void
//
// main game loop 
//
fun gameLoop {mn,m,n:nat} (
  game_state:int, board_conf:board_conf_type, board:board_type 
): int
//
// Print current board
//
fun printBoard {mn:nat} (
  board_conf:board_conf_type, board:board_type
):void
//
// Check to see if there is a winner.
//
fun isWinner {mn:nat} (
  board_conf:board_conf_type, board:board_type
):bool





(* ** Utility functions ** *)
//
// Input buffer flush and get character using 
// only C-standard functions.
//
fun flushAndGetChar(
  input_buffer:FILEref
): char

(* end of [game.sats] *)
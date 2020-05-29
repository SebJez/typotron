
#ifndef KEY_LUT_LITERAL_H
#define KEY_LUT_LITERAL_H

namespace typotron{

const char key_literal_lut[] PROGMEM = {   
//    NORMAL  SHIFT   CODE    KB2+SHIFT
'n' , //000  N
',' , //001  ,       ?
'-' , //002  -       /               o/
'\0', //003
'\0', //004  margin right
'x' , //005  X
'v' , //006  V
'\0' , //007  last word

'b' , //010  B
'm' , //011  M
'.' , //012  .       .
'\0', //013
'\0', //014
'z' , //015  Z
'c' , //016  C
'\x7F' , //017  DEL             del word

'g' , //020  G
'l' , //021  L
';' , //022  ;       ;
'\0' , //023  tab +           tab-
'\0', //024
'\0' , //025  margin left
'd' , //026  D
'j' , //027  J

'f' , //030  F
'k' , //031  K
'\0' , //032  ij      *
'\0' , //033  up
'a' , //034  A
'\0' , //035  CAPS
's' , //036  S
'h', //037  H

'w' , //040  W
'y' , //041  Y
'i' , //042  I
'\0' , //043  down
'p' , //044  P
'\xA8' , //045  umlaut  ^
'\t' , //046  TAB
'r' , //047  R

'e' , //050  E
'u' , //051  U
'o' , //052  O
'\0', //053
'\n' , //054  ENTER
'+', //055  +       =
'q' , //056  Q
't' , //057  T

'1' , //060  1       f               |
'5' , //061  5       %       p10     degree
'7' , //062  7       &               <
'\b' , //063  BS              autortrn
'9' , //064  9       (       dec.tab 
'\xBD' , //065  1/2     !       hyphen
' ' , //066  SPACE
'3' , //067  3       Ł       i1 1/2  `

'\0' , //070  margin ignore   KB1<>2
'4' , //071  4       $       i2
'6' , //072  6       _       p12
'\r' , //073  CR
'8' , //074  8       '       indent  >
'\xBE' , //075  3/4     1/4     center
'0' , //076  0       )       undrlne
'2' , //077  2       "       i1      '/

 'N', //100  N
 '?', //101  ,       ?
 '/', //102  -       /               o/
 '\0', //103
 '\0', //104  margin right
 'X', //105  X
 'V', //106  V
 '\0', //107  last word

 'B', //110  B
 'M', //111  M
 '.', //112  .       .
 '\0', //113
 '\0', //114
 'Z', //115  Z
 'C', //116  C
 '\0', //117  DEL             del word

 'G', //120  G
 'L', //121  L
 ':', //122  ;       ;
 '\0', //123  tab +           tab-
'\0', //124
 '\0', //125  margin left
'D' , //126  D
'J' , //127  J

'F' , //130  F
'K' , //131  K
'*' , //132  ij      *
'\0' , //133  up
'A' , //134  A
'\0' , //135  CAPS
'S' , //136  S
'H' , //137  H

'W' , //140  W
'Y' , //141  Y
'I' , //142  I
'\0' , //143  down
'P' , //144  P
'^' , //145  umlaut  ^
'\0' , //146  TAB
'R' , //147  R

'E' , //150  E
'U' , //151  U
'O' , //152  O
'\0', //153
'\0' , //154  ENTER
'=' , //155  +       =
'Q' , //156  Q
'T' , //157  T

'\x83', //160  1       F               |           ***
'%', //161  5       %       p10     degree
'&', //162  7       &               <
'\0', //163  BS              autortrn
'(' , //164  9       (       dec.tab 
'!' , //165  1/2     !       hyphen
'\0', //166  SPACE
'\xA3' , //167  3       Ł       i1 1/2  `

'\0' , //170  margin ignore   KB1<>2
'$' , //171  4       $       i2
'_' , //172  6       _       p12
'\0' , //173  CR
'\'' , //174  8       '       indent  >
'\xBC' , //175  3/4     1/4     center
')' , //176  0       )       undrlne
'"' , //177  2       "       i1      '/

'\x10' , //200  N
'\0' , //201  ,       ?
'\0' , //202  -       /               o/
'\0', //203
'\0' , //204  margin right
'\x18' , //205  X
'\x16' , //206  V
'\0' , //207  last word

'\x02' , //210  B
'\x0D' , //211  M
'\0' , //212  .       .
'\0', //213
'\0', //214
'\x1A' , //215  Z
'\x03' , //216  C
'\0' , //217  DEL             del word

'\x07' , //220  G
'\x0C' , //221  L
'\0' , //222  ;       ;
'\0' , //223  tab +           tab-
'\0', //224
'\0' , //225  margin left
'\x04' , //226  D
'\x0A' , //227  J

'\x06' , //230  F
'\x0B' , //231  K
'\0' , //232  ij      *
'\0' , //233  up
'\x01' , //234  A
'\0' , //235  CAPS
'\x13' , //236  S
'\x08' , //237  H

'\x17' , //240  W
'\x19' , //241  Y
'\x09' , //242  I
'\0' , //243  down
'\x10' , //244  P
'\0' , //245  umlaut  ^
'\0' , //246  TAB
'\x12' , //247  R

'\x05' , //250  E
'\x15' , //251  U
'\x0F' , //252  O
'\0', //253
'\0' , //254  ENTER
'\0' , //255  +       =
'\x11' , //256  Q
'\x14' , //257  T

'|' , //260  1       F               |
'\0' , //261  5       %       p10     degree
'<' , //262  7       &               <
'\0' , //263  BS              autortrn
'\0' , //264  9       (       dec.tab 
'\0' , //265  1/2     !       hyphen
'\0' , //266  SPACE
'`' , //267  3       Ł       i1 1/2  `

'\0' , //270  margin ignore   KB1<>2
'\0' , //271  4       $       i2
'\0' , //272  6       _       p12
'\0' , //273  CR
'>' , //274  8       '       indent  >
'\0' , //275  3/4     1/4     center
'\0' , //276  0       )       undrlne
'\xB4' , //277  2       "       i1      '/

 '\0' , //300  N
 '\0', //301  ,       ?
 '\0', //302  -       /               o/
 '\0', //303
 '\0', //304  margin right
 '\0', //305  X
 '\0', //306  V
 '\0', //307  last word

 '\0', //310  B
 '\0', //311  M
 '\0', //312  .       .
 '\0', //313
 '\0', //314
 '\0', //315  Z
 '\0', //316  C
 '\0', //317  DEL             del word
 
 '\0', //320  G
 '\0', //321  L
 '\0', //322  ;       ;
 '\0', //323  tab +           tab-
 '\0', //324
 '\0', //325  margin left
 '\0', //326  D
 '\0', //327  J
 
 '\0', //330  F
 '\0', //331  K
 '\0', //332  ij      *
 '\0', //333  up
 '\0', //334  A
 '\0', //335  CAPS
 '\0', //336  S
 '\0', //337  H
 
 '\0', //340  W
 '\0', //341  Y
 '\0', //342  I
 '\0', //343  down
 '\0', //344  P
 '\0', //345  umlaut  ^
 '\0', //346  TAB
 '\0', //347  R
 
 '\0', //350  E
 '\0', //351  U
 '\0', //352  O
 '\0', //353
 '\0', //354  ENTER
 '\0', //355  +       =
 '\0', //356  Q
 '\0', //357  T

 '\0', //360  1       F               |
 '\0', //361  5       %       p10     degree
 '\0', //362  7       &               <
 '\0', //363  BS              autortrn
 '\0', //364  9       (       dec.tab 
 '\0', //365  1/2     !       hyphen
 '\0', //366  SPACE
 '\0', //367  3       Ł       i1 1/2  `
 
 '\0', //370  margin ignore   KB1<>2
 '\0', //371  4       $       i2
 '\0', //372  6       _       p12
 '\0', //373  CR
 '\0', //374  8       '       indent  >
 '\0', //375  3/4     1/4     center
 '\0', //376  0       )       undrlne
 '\0'  //377  2       "       i1      '/
 };

inline char keyToAsciiLiteral(byte key) {return pgm_read_byte_near(key_literal_lut+key);}
}//namespace
#endif
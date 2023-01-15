
COMANDI:

   94  cd /
   95  ls
   96  cd /home/
   97  ls
   98  cd 
   99  pwd
  100  clear
  101  ls
  102  ls /home/so2223/lecture_examples/20220929/
  103  ls /home/so2223/lecture_examples/20220928/
  104  ls lecture_examples/20220928/
  105  man man
  106  man -k fork
  107  man ls
  108  man man
  109  ls .
  110  ls -l .
  111  ls -la .
  112  clear
  113  echo $PATH
  114  ls 
  115  cat 
  116  cat > /tmp/out
  117  cat < /tmp/out
  118  cat < /tmp/out > /tmp/out_2
  119  cat /tmp/out
  120  cat /tmp/nonesiste > /tmp/out
  121  ls | sort -r
  122  clear
  123  ls | sort -r
  124  cd /tmp/
  125  ls -l out*
  126  echo ciao
  127  echo ciao > out
  128  diff out out_2 
  129  echo Ciao > out
  130  diff out out_2 
  131  od -cx out
  132  od -cx out_2 
  133  man ascii
  134  cp out out_3
  135  diff out out_3
  136  mv out_3 out_4
  137  mkdir mydir
  138  cp out out_2 out_4 mydir
  139  cd mydir/
  140  ls
  141  ls -l
  142  mkdir altronome
  143  rmdir altronome/
  144  cd ..
  145  rmdir mydir/
  146  rm -rf mydir/
  147  yes
  148  yes > /dev/null
  149  bg
  150  top
  151  ps -ax | grep "yes"
  152  kill 453269
  153  ps -ax | grep "yes"
  154  history
  155  history > comandi_20220929



COMANDI_C:

  149  vi hw.c
  150  gcc hw.c
  151  gcc -S hw.c
  152  ls
  153  rm hw.s
  154  gcc -c hw.c
  155  ls
  156  rm hw.o
  157  gcc -E hw.c 
  158  rm a.out 
  159  gcc -c hw.c
  160  ls
  161  gcc hw.o
  162  ls
  163  gcc -o hw hw.o
  164  rm a.out 
  165  ls
  166  ./hw
  167  rm hw.o
  168  vi hw.c
  169  gcc hw.c
  170  ./a.out 
  171  gcc -c hw.c
  172  nm hw.c 
  173  nm hw.o
  174  vi hw.c
  175  gcc -c hw.c
  176  nm hw.o
  177  gcc hw.o
  178  nm a.out
  179  gcc -static hw.o
  180  nm a.out
  181  nm a.out | grep printf
  182  ls
  183  man printf
  184  man 3 printf
  185  vi hw.c 
  186  cp hw.c hw2.c
  187  vi hw2.c
  188  gcc hw2.c 
  189  vi hw2.c
  190  man 3 printf
  191  man 2 write
  192  cp hw2.c hw3.c
  193  vi hw3.c 
  194  gcc hw3.c
  195  vi hw3.c 
  196  gcc hw3.c
  197  ./a.out 
  198  rm ./a.out 
  199  gcc hw3.c
  200  ./a.out 
  201  vi hw3.c 
  202  vi rargc.c
  203  gcc rargc.c 
  204  ./a.out 
  205  echo $?
  206  ./a.out 1 2 3 4
  207  echo $?
  208  gcc -c rargc.c 
  209  ld rargc.o
  210  ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crti.o -lc rargc.o /usr/lib/x86_64-linux-gnu/crtn.o
  211  ./a.out 1 2 3
  212  vi crts0.s
  213  vi /usr/include/x86_64-linux-gnu/asm/unistd_64.h 
  214  as -o crts0.o crts0.s 
  215  ld crts0.o rargc.o 
  216  ./a.out 1 2 3 4
  217  echo $?
  218  vi crts0.s
  219  ls
  220  vi crts0.s
  221  cp hw3.c hw4.c
  222  vi hw4.c
  223  vi /usr/include/x86_64-linux-gnu/asm/unistd_64.h 
  224  vi hw4.c
  225  gcc hw4.c
  226  vi hw4.c
  227  gcc hw4.c
  228  ./a.out 
  229  vi hw4.c
  230  gcc -c hw4.c
  231  nm hw4.o
  232  ld hw4.o
  233  cp hw4.c hw5.c
  234  vi hw5.c 
  235  gcc -c hw5.c
  236  ld hw5.o
  237  ls
  238  rm a.out 
  239  ld hw5.o
  240  ./a.out 
  241  echo %?
  242  ./a.out 
  243  echo $?
  244  vi hw5.c 
  245  vi noSO.c
  246  fg
  247  gcc noSO.c 
  248  ./a.out 
  249  vi noSO.c
	...
	per compilare noSO per avr atmega168
	 $ avr-gcc -mmcu=atmega168 -Os -o noSO noSO.c
# l'eseguibile ottenurto non e' per intel:
  $  file noSO
# generiamo il file .hex (perchÃ© l'utility di trasferimento lo vuole cosÃ¬)
  $ avr-objcopy -O ihex noSO noSO.hex
# ... carichiamo il file sul microcontrollore atmega168
        $ avrdude -p m168 -c stk500v2 -P /dev/ttyUSB0 -U flash:w:noSO.hex
# (occorre il chip, il programmatore ed u circuito quale quello descirtto qui:
# http://tuxgraphics.org/electronics/200904/avr-c-programming.shtml

# il led lampeggia. potere del software.

(un log di una lezione simile lo trovate in:
 https://so.v2.cs.unibo.it/wiki/index.php/Esperimenti_2021_settembre_30
 )

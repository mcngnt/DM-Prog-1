.ORIG x3000



INIT_TAB ; Initializing the memory (1,2)

LD R0 mem_size ; R0 : number of cells needing to be initialized
LEA R1 mem
ADD R1 R1 #1 ; R1 : current address where I write + 1

LOOP_START
STR R1 R1 #-1 ; R1 - 1 <- R1
ADD R1 R1 #1
ADD R0 R0 #-1
BRz END_LOOP_START
BR LOOP_START

END_LOOP_START
STR R0 R1 #-1 ; I put 0 in the last memory block (because here R0 = 0)

HALT



LIST_LENGTH ; Calculating the lenght of the list (3)

AND R0 R0 #0 ; R0 : list length
LEA R1 mem

SEARCH_LOOP
ADD R0 R0 #1
LDR R1 R1 #0 ; I access the next element of the list
BRz END_SEARCH
BR SEARCH_LOOP

END_SEARCH ; Result is now in R0
HALT



mem .BLKW #100 ; memory declaration
mem_size .FILL #99 ; size of the memory - 1

.END
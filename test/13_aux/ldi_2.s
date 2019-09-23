.name "tester"
.comment "test ldi"


ldi 3, %4, r3
st r3, 57

#will do nothing if r is <= 0 or > REG_NUM

;  0a e4 00 03 00 04 03 03 70 03 00 39
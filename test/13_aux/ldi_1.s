.name "tester"
.comment "test ldi"


ldi %4, %4, r3
st r3, 57

#will do nothing if r is <= 0 or > REG_NUM

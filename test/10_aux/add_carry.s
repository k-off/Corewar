.name "tester"
.comment "test add"


add r2, r3, r4
zjmp %0

#will do nothing if r is <= 0 or > REG_NUM
#will modify carry if the result of add is 0

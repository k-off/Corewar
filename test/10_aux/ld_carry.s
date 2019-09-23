.name "tester"
.comment "test ld"

ld %0, r2
zjmp %0

#will do nothing if r is <= 0 or > REG_NUM thus won't modify the carry
#if the load value is 0, carry will become 1 and activate the zjmp

.name "tester"
.comment "test add"


ld %100, r1
ld %100, r2
add r1, r17, r3
st r3, 45

#will do nothing if r is <= 0 or > REG_NUM

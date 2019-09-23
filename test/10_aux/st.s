.name "tester"
.comment "test st"

ld %100, r3
st r3, r4
st r4, 53

#will do nothing if r is <= 0 or > REG_NUM
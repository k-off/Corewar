.name "tester"
.comment "test reg after fork"

#this test proof that reg belong to each process instead of each player"

ld %42991616, r2
ld %25862, r3
ld %225286, r5
ld %100, r6
st r6, 56
st r5, 49
st r3, 66
st r2, 58
st r6, 96
st r5, 89
fork %37

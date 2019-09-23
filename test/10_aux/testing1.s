.name "tester"
.comment "test fork"

ld %1, r3
fork %100
st r3, 100
st r1, 99

#this will created the same process at the same place

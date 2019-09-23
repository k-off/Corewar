.name "tester"
.comment "test process behavior"


# ld %748, r2
# st r2, 58
# ld %1, r3
# st r3, 59

ld %1, r2
ld %57672447, r3
ld %180, r4

# st r2, -75 #03 70 02 ff f6
fork %90
st r4, 89
st r3, 83

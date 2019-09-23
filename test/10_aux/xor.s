.name "test"
.comment "xor test"

ld %100, r3
ld %50, r4
xor r3, r4, r5
st r5, 45


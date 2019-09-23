.name "eval"
.comment "eval comment"

ld %20, r5
st r5, 100
zjmp %100
ld %0, r6
zjmp %13
live %-2
live %-2
fork %50
ld %10, r6

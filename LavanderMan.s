.name "LavAnDerMaN"
.comment "HUH POTATO?"

start:
zjmp %:jmp
jmp:
zjmp %:jmp
load:
ld %0, r9
ld %57674359, r10
ld %922788095, r11
#for close placement
ld %57674241, r12
ld %1, r4
ld %0, r2
fork %:beforefork
beforefork:
st r1, 6
live %5
fork %:afterfork1
st r1, 6
live %5
fork %:afterfork1
st r1, 6
live %5
fork %:afterfork2
st r1, 6
live %5
fork %:middlefork
st r1, 6
live %5

ld %0, r9
zjmp %-500

middlefork:
st r1, 6
live %5
fork %:middlefork
st r1, 6
live %5
fork %:middlefork
st r1, 6
live %5
fork %:afterfork1
st r1, 6
live %5
fork %:afterfork2
st r1, 6
live %5
fork %:afterfork2
st r1, 6
live %5
fork %:afterfork2
st r1, 6
live %5
fork %:afterfork2
st r1, 6
live %5
fork %:afterfork2
st r1, 6
live %5
fork %:afterfork2
st r1, 6
live %5
fork %:afterfork2
st r1, 6
live %5
fork %:middle
st r1, 6
live %5
fork %:middle
st r1, 6
live %5

middle:
st r1, 6
live %5
zjmp %:middle

afterfork2:
st r1, 6
live %5
st r1, 6
live %5
zjmp %:afterfork2

afterfork1:
st r4, 510
st r1, 509
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r1, 6
live %5
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r12, 511
st r4, 511
st r1, 510
zjmp %300

afterfork2:
st r1, 6
live %5
zjmp %512




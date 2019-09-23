.name "maak me niet kwaad"
.comment "maak me niet kwaad"

ld 516, r5
st r5, 516
live %-1
ld %0, r5
zjmp %515
ldi %-514, %-2, r6
sti r6, %512, %7
live %-42
live %-42
fork %520

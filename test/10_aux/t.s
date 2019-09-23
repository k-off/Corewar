.name "tester"
.comment "test aff"


ld %2147483647, r2
st r2, 62 
# live %-1
# ld 3, r2
# st r2, 100
# add r2, r3, r5
# sub r2, r3, r4
# and r2, %3, r4
# or r2, 3, r4
# xor r2, 3, r4
# zjmp %1
# ldi %4, %4, r4
# ldi r2, %4, r3
# sti r5, %4, %53
# sti r6, 5, %57
# fork %1000
# lld 3, r3
# lldi 13, %4, r3
# lfork %4005
# live %-1
# live %-2
# aff r2

# ldi %0, %0, r2
# zjmp %0

.name "tester"
.comment "this test proof that the carry belong to each process"

#the first process carry is modified to 1 so it will success in zjmp
#the second process inherit the parent process which is still 0 and fail in zjmp

ld %9, r5
ld %65535, r6
st r6, 56
st r5, 49
fork %15
add r2, r3, r4

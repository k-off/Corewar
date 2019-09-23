.name "tester"
.comment "test ldi"


ldi 1, %256, r4
st r4, 57

#i believe this is a bug, 
#ldi 1, %255, r4 have this hex 0a e4 00 01 00 ff 04
#this makes id 1 have the value of 0xe4000100 or 3825205504
#(3825205504 + 255) % 512 = 511
#this makes the address as 511 or -1
#the result showed by st is 0x000ae400 which is the correct value from PC -1

#but if we change the code to this
#ldi 1, %256, r4 will have thie hex 0a e4 00 01 01 00 04
#this makes id 1 have the value of 0xe4000101 or 3825205505
#(3825205505 + 256) % 512 = 1
#by right, the result will be 0xe4000101 base of PC +1
#but the result showed by st is always 0x0
#this bug is only found when the 1st param is from 0xe4000101 - 0xe40001fc
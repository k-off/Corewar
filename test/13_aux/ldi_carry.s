.name "tester"
.comment "test ldi"


ldi %100, %100, r4
zjmp %0

#this should save 0x0 into r4 and it should modify the carry,
#but r_corewar does not modify it and i find no way to modify it
#and make it work in r_corewar


.name "zork"
.comment "just a basic living prog"

l2:
sti r99,%:live,%1 adfa
and r1,%0,r1
live:   live %1
zjmp %:live

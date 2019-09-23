.name "tester"
.comment "test lldi carry"


lldi	100, %100, r3
st r3, 57
zjmp %65535

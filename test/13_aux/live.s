.name "tester"
.comment "test live"

live %-1

#it wont do anything if the 1st param value is non existant player id
#ex : live %-5 the is no player with id no 5, so live wont report that player as alive
#even if a process do live with an invalid player no 5, this process won't die
#the VM treated that this process have did the call of live 
#which satisfied the rule of "process at least call alive once"
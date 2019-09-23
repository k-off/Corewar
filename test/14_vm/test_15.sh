RED="\033[0;31m";
GREEN="\033[32m";
HIGH="\033[1m";
EOC="\033[0m";

run_test() {
for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
do

CYCLE=$((1535 * $i))
CYCLE_OUR=$(($CYCLE))
if [ "$4" ]
then
	if [ "$i" -lt "2" ]
	then
	echo "${HIGH}FOUR COMPETITORS: $1 ${RED}VS${EOC}${HIGH} $2 ${RED}VS${EOC}${HIGH} $3 ${RED}VS${EOC}${HIGH} $4${EOC}"
	fi
../original_corewar $1 $2 $3 $4 "-d" $CYCLE  | grep "0x0" > "$ORIG"
../../corewar $1 $2 $3 $4 "-dump" $CYCLE_OUR | grep "0x0" > "$OUR"
elif [ "$3" ]
then
	if [ "$i" -lt "2" ]
	then
	echo "${HIGH}THREE COMPETITORS: $1 ${RED}VS${EOC}${HIGH} $2 ${RED}VS${EOC}${HIGH} $3${EOC}"
	fi
../original_corewar $1 $2 $3 "-d" $CYCLE  | grep "0x0" > "$ORIG"
../../corewar $1 $2 $3 "-dump" $CYCLE_OUR | grep "0x0" > "$OUR"
elif [ "$2" ]
then
	if [ "$i" -lt "2" ]
	then
	echo "${HIGH}TWO COMPETITORS: $1 ${RED}VS${EOC}${HIGH} $2${EOC}"
	fi
../original_corewar $1 $2 "-d" $CYCLE  | grep "0x0" > "$ORIG"
../../corewar $1 $2 "-dump" $CYCLE_OUR | grep "0x0" > "$OUR"
else
echo "${RED}EXIT: LESS THAN TWO COMPETITORS${EOC}"
exit
fi

RES=$(diff "$ORIG" "$OUR" | wc -c)
RES2=$(cmp -l "$ORIG" "$OUR" | wc -c)

if [ $RES -gt '1' ] || [ $RES2 -gt '1' ]
then
echo "${RED}NOT IDENTICAL:\tCYCLE $CYCLE${EOC}"
count=$(($count + 1))
else
echo "${GREEN}IDENTICAL:\tCYCLE $CYCLE${EOC}"
fi
rm -f "$ORIG" "$OUR"

done

echo
}

count=0
echo "${HIGH}\nMULTIPLAYER TEST - DUMP COMPARISON (cmp -l function + diff function 10 checks per file)${EOC}\n"

OUR="our_dump"
ORIG="original_dump"

#cp ../8_good/26_helltrain*orig.cor 26_helltrain_orig.cor
#cp ../8_good/35_Douceur_power*orig.cor 35_Douceur_power_orig.cor
#cp ../8_good/16_slider2*orig.cor 16_slider2_orig.cor

HELL=../8_good/26_helltrain*orig.cor
TOTO=../8_good/22_toto*orig.cor
SLDR=../8_good/16_slider2*orig.cor
FLTR=../8_good/58_fluttershy*orig.cor

run_test "$HELL" "$TOTO" "$SLDR" "$FLTR";
run_test "$HELL" "$TOTO" "$SLDR";
run_test "$HELL" "$FLTR" "$SLDR";
run_test "$HELL" "$TOTO";
run_test "$HELL" "$SLDR";
run_test "$HELL" "$FLTR";
run_test "$FLTR" "$SLDR";
run_test "$TOTO" "$SLDR";

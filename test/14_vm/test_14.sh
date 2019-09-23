RED="\033[0;31m";
GREEN="\033[32m";
HIGH="\033[1m";
EOC="\033[0m";
count=0
echo "${HIGH}\nVIRTUAL MACHINE TEST - DUMP COMPARISON (cmp -l function + diff function 10 checks per file)${EOC}\n"

OUR="our_dump"
ORIG="original_dump"
for file in ../8_good/*orig.cor
do

DST=$(echo $file | cut -d '/' -f 3)
cp "$file" "$DST"
echo "${HIGH}TESTING $DST${EOC}"

for i in 1 2 3 4 5 6 7 8 9 10
do

CYCLE=$((1535 * $i))
CYCLE_OUR=$(($CYCLE))

../original_corewar "$DST" "-d" $CYCLE  | grep "0x0" > "$ORIG"
../../corewar "$DST" "-dump" $CYCLE_OUR | grep "0x0" > "$OUR"
RES=$(diff "$ORIG" "$OUR" | wc -c)
RES2=$(cmp -l "$ORIG" "$OUR" | wc -c)
if [ $RES -gt '1' ] || [ $RES2 -gt '1' ]
then
echo "${RED}not identical:\tcycle $CYCLE, file '$DST'${EOC}"
count=$(($count + 1))
else
echo "${GREEN}identical:\tcycle $CYCLE, file '$DST'${EOC}"
fi
rm -f "$ORIG" "$OUR"

done

rm -f "$DST"

done

for file in ../10_aux/*orig.cor
do

DST=$(echo $file | cut -d '/' -f 3)
cp "$file" "$DST"

for i in 1
do

CYCLE=$((1535 * $i))
CYCLE_OUR=$(($CYCLE))

../original_corewar "$DST" "-d" $CYCLE  | grep "0x0" > "$ORIG"
../../corewar "$DST" "-dump" $CYCLE_OUR | grep "0x0" > "$OUR"
RES=$(diff "$ORIG" "$OUR" | wc -c)
RES2=$(cmp -l "$ORIG" "$OUR" | wc -c)
if [ $RES -gt '1' ] || [ $RES2 -gt '1' ]
then
echo "${RED}not identical:\tcycle $CYCLE, file '$DST'${EOC}"
count=$(($count + 1))
else
echo "${GREEN}identical:\tcycle $CYCLE, file '$DST'${EOC}"
fi
rm -f "$ORIG" "$OUR"

done

rm -f "$DST"

done

for file in ../11_aux/*orig.cor
do

DST=$(echo $file | cut -d '/' -f 3)
cp "$file" "$DST"

for i in 1
do

CYCLE=$((1535 * $i))
CYCLE_OUR=$(($CYCLE))

../original_corewar "$DST" "-d" $CYCLE  | grep "0x0" > "$ORIG"
../../corewar "$DST" "-dump" $CYCLE_OUR | grep "0x0" > "$OUR"
RES=$(diff "$ORIG" "$OUR" | wc -c)
RES2=$(cmp -l "$ORIG" "$OUR" | wc -c)
if [ $RES -gt '1' ] || [ $RES2 -gt '1' ]
then
echo "${RED}not identical:\tcycle $CYCLE, file '$DST'${EOC}"
count=$(($count + 1))
else
echo "${GREEN}identical:\tcycle $CYCLE, file '$DST'${EOC}"
fi
rm -f "$ORIG" "$OUR"

done

rm -f "$DST"

done


for file in ../12_aux/*orig.cor
do

DST=$(echo $file | cut -d '/' -f 3)
cp "$file" "$DST"

for i in 1
do

CYCLE=$((1535 * $i))
CYCLE_OUR=$(($CYCLE))

../original_corewar "$DST" "-d" $CYCLE  | grep "0x0" > "$ORIG"
../../corewar "$DST" "-dump" $CYCLE_OUR | grep "0x0" > "$OUR"
RES=$(diff "$ORIG" "$OUR" | wc -c)
RES2=$(cmp -l "$ORIG" "$OUR" | wc -c)
if [ $RES -gt '1' ] || [ $RES2 -gt '1' ]
then
echo "${RED}not identical:\tcycle $CYCLE, file '$DST'${EOC}"
count=$(($count + 1))
else
echo "${GREEN}identical:\tcycle $CYCLE, file '$DST'${EOC}"
fi
rm -f "$ORIG" "$OUR"

done

rm -f "$DST"

done

for file in ../13_aux/*orig.cor
do

DST=$(echo $file | cut -d '/' -f 3)
cp "$file" "$DST"

for i in 1
do

CYCLE=$((1535 * $i))
CYCLE_OUR=$(($CYCLE))

../original_corewar "$DST" "-d" $CYCLE  | grep "0x0" > "$ORIG"
../../corewar "$DST" "-dump" $CYCLE_OUR | grep "0x0" > "$OUR"
RES=$(diff "$ORIG" "$OUR" | wc -c)
RES2=$(cmp -l "$ORIG" "$OUR" | wc -c)
if [ $RES -gt '1' ] || [ $RES2 -gt '1' ]
then
echo "${RED}not identical:\tcycle $CYCLE, file '$DST'${EOC}"
count=$(($count + 1))
else
echo "${GREEN}identical:\tcycle $CYCLE, file '$DST'${EOC}"
fi
rm -f "$ORIG" "$OUR"

done

rm -f "$DST"

done

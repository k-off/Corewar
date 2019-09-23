RED="\033[0;31m";
GREEN="\033[32m";
HIGH="\033[1m";
EOC="\033[0m";

echo "${HIGH}\nDISASSEMBLER TEST (cmp -l function + diff function)${EOC}\n"

echo "${HIGH}\tBad files${EOC}"
../../dasm ../../tests_assembler

../../dasm ../../dasm

../../dasm ""

echo "${HIGH}\tGood files${EOC}"
for file in *.s
do

ORIGCOR="$(echo $file | cut -d . -f 1).cor"
NEWCOR="$(echo $file | cut -d . -f 1)_dasm.cor"
NEWS="$(echo $file | cut -d . -f 1)_dasm.s"

RES=$(../original_asm "$file" | wc -c)
cp "$ORIGCOR" "$NEWCOR"

RES=$(../../dasm "$NEWCOR" | wc -c)
rm -f "$NEWCOR"

RES=$(../original_asm "$NEWS" | wc -c)

RES=$(diff "$ORIGCOR" "$NEWCOR" | wc -c)
RES2=$(cmp -l "$ORIGCOR" "$NEWCOR" | wc -c)
if [ $RES -gt '1' ] || [ $RES2 -gt '1' ]
then
echo "${RED}not identical:\t'$ORIGCOR' and '$NEWCOR'${EOC}"
else
echo "${GREEN}identical:\t'$ORIGCOR' and '$NEWCOR'${EOC}"
fi
done

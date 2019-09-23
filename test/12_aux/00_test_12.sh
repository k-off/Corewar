RED="\033[0;31m";
GREEN="\033[32m";
HIGH="\033[1m";
EOC="\033[0m";

echo "${HIGH}\nAUX-12 TEST (cmp -l function + diff function)${EOC}\n"

for file in *.s
do

NAME="$(echo $file | cut -d . -f 1)"
COR="$(echo $file | cut -d . -f 1).cor"
OUR="$NAME our.cor"
RES=$(../../asm "$file" | wc -c)
mv "$COR" "$OUR"
ORIG="$NAME orig.cor"
RES=$(../original_asm "$file" | wc -c)
mv "$COR" "$ORIG"
RES=$(diff "$OUR" "$ORIG" | wc -c)
RES2=$(cmp -l "$OUR" "$ORIG" | wc -c)
if [ $RES -gt '1' ] || [ $RES2 -gt '1' ]
then
echo "${RED}not identical:\t'$OUR' and '$ORIG'${EOC}"
else
echo "${GREEN}identical:\t'$OUR' and '$ORIG'${EOC}"
fi
done

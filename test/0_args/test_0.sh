RED="\033[0;31m";
GREEN="\033[32m";
HIGH="\033[1m";
EOC="\033[0m";

echo "${HIGH}\nBAD NO ARGUMENTS TEST${EOC}\n"

for file in *.s
do
RES=$(../../asm "$file" | wc -c)
	if [ $RES -gt '4' ]
	then
		echo "${RED}not passed\t$file${EOC}"
	else
		echo "${GREEN}passed\t\t$file${EOC}"
	fi
done

RES=$(ls -la | grep ".cor" | wc -l)
if [ $RES -gt '0' ]
then
echo "${RED}NO ARGUMENTS SET NOT PASSED - .COR FILES HAVE BEEN CREATED${EOC}"
else
echo "${GREEN}NO ARGUMENTS SET - NO .COR FILES HAVE BEEN CREATED\n${EOC}"
fi

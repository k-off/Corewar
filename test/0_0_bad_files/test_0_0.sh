RED="\033[0;31m";
GREEN="\033[32m";
HIGH="\033[1m";
EOC="\033[0m";

echo "${HIGH}\nBAD FILES TEST${EOC}\n"

chmod 000 02_no_rights.s

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

file="98_directory"
RES=$(../../asm "$file" | wc -c)
if [ $RES -gt '4' ]
then
	echo "${RED}not passed\t$file${EOC}"
else
	echo "${GREEN}passed\t\t$file${EOC}"
fi

file="99_non_existent.s"
RES=$(../../asm "$file" | wc -c)
if [ $RES -gt '4' ]
then
echo "${RED}not passed\t$file${EOC}"
else
echo "${GREEN}passed\t\t$file${EOC}"
fi

RES=$(ls -la | grep ".cor" | wc -l)
if [ $RES -gt '0' ]
then
	echo "${RED}BAD FILES SET NOT PASSED - .COR FILES HAVE BEEN CREATED${EOC}"
else
	echo "${GREEN}BAD FILES SET PASSED\n${EOC}"
fi

chmod 644 02_no_rights.s

#!/bin/sh

# usage: sh test.sh

#======COLORS======#

EOC="\033[0m";
GREEN="\033[32m";
YELLOW="\033[33m";
RED="\033[0;31m";
BLUE="\033[0;36m";
HIGH="\033[1m";

#===PRELIMINARIES==#

preliminaries () {

ATR1=$(cat -e ../author | wc -l | tr -d ' ')
ATR2=$(cat -e ../author | wc -c | tr -d ' ')
if [ $ATR1 -lt '3' ] || [ $ATR2 -lt '6' ]
then
echo "${RED}Author-file\tfailed${EOC}"
else
echo "${GREEN}Author-file\tpassed${EOC}"
fi

NRM1=$(norminette ../asmf ../dasmf ../vm | grep 'Error' | wc -l | tr -d ' ')
if [ $NRM1 -gt '0' ]
then
echo "${RED}Norminette\tfailed${EOC}"
norminette ../asmf ../dasmf ../vm > norminette_output
else
echo "${GREEN}Norminette\tpassed${EOC}"
fi

MK0=$(make -C ../ fclean)
MK1=$(make -C ../ | grep "Nothing" | wc -l | tr -d ' ')
MK2=$(make -C ../ | grep "Nothing" | wc -l | tr -d ' ')
MK3=$(make -C ../ clean | grep "Nothing" | wc -l | tr -d ' ')
MK4=$(make -C ../ | grep "Nothing" | wc -l | tr -d ' ')
MK5=$(make -C ../ fclean | grep "Nothing" | wc -l | tr -d ' ')
MK6=$(make -C ../ | grep "Nothing" | wc -l | tr -d ' ')
if [ $MK1 -eq '0' ] && [ $MK2 -eq '1' ] && [ $MK4 -eq '1' ] && [ $MK6 -eq '0' ]
then
echo "${GREEN}Makefile\tpassed${EOC}"
else
echo "${RED}Makefile\tfailed${EOC}"
fi
MK0=$(make -C ../ clean)

sleep 1s

LM=$(ls -l ../ | grep " corewar\b" | cut -d ' ' -f 13 | wc -c | tr -d ' ')
if [ $LM -ne '8' ]
then
echo "${RED}corewar\t\tnot found${EOC}"
else
echo "${GREEN}corewar\t\tfound${EOC}"
fi

LM=$(ls -l ../ | grep " asm\b" | cut -d ' ' -f 14 | wc -c | tr -d ' ')
if [ $LM -ne '4' ]
then
echo "${RED}assembler\tnot found${EOC}"
else
echo "${GREEN}assembler\tfound${EOC}"
fi

sleep 1s

}

bad_input () {

cd 0_0_bad_files
sh test_0_0.sh
sleep 1s
cd ../0_args
sh test_0.sh
sleep 1s
cd ../1_args
sh test_1.sh
sleep 1s
cd ../2_args
sh test_2.sh
sleep 1s
cd ../3_args
sh test_3.sh
sleep 1s
cd ../4_args
sh test_4.sh
sleep 1s
cd ../5_bad_instructions
sh test_5.sh
sleep 1s
cd ../6_bad_labels
sh test_6.sh
sleep 1s
cd ../7_other
sh test_7.sh
sleep 1s
cd ..
}

choose () {
if [ $(echo $1 | wc -c | tr -d ' ') -lt 2 ]
then
echo "${HIGH}usage:\ttest.sh flag${EOC}"
echo "${HIGH}flags:\t-norm${EOC}\t- preliminary requierements test"
echo "\t${HIGH}-bad${EOC}\t- bad input test"
echo "\t${HIGH}-good${EOC}\t- good input test"
echo "\t${HIGH}-dasm${EOC}\t- disassembler test"
echo "\t${HIGH}-clean${EOC}\t- clean .cor and .DS_store from all directories"
echo "\t${HIGH}-all${EOC}\t- all tests"
elif [ $(echo $1 | wc -c | tr -d ' ') -gt 2 ]
then
echo $1
if [ "$1" == "-norm" ] || [ $1 == "-all" ]
then
preliminaries
fi
if [ "$1" == "-bad" ] || [ $1 == "-all" ]
then
bad_input
fi
if [ "$1" == "-good" ] || [ $1 == "-all" ]
then
cd 8_good
sh test_8.sh
cd ../10_aux
sh 00_test_10.sh
cd ../11_aux
sh 00_test_11.sh
cd ../12_aux
sh 00_test_12.sh
cd ../13_aux
sh 00_test_13.sh
cd ..
fi
if [ "$1" == "-dasm" ] || [ $1 == "-all" ]
then
cd 9_dasm
sh test_9.sh
cd ..
fi
if [ "$1" == "-vm" ] || [ $1 == "-all" ]
then
cd 14_vm
sh test_14.sh
sh test_15.sh
cd ..
fi
if [ "$1" == "-clean" ]
then
cd ..
make fclean
find . -name \*.cor -type f -delete
find . -name \.DS_Store -type f -delete
find . -name \norminette_output -type f -delete
find . -name \*_dasm.s -type f -delete
cd test
fi
fi
}

choose $1

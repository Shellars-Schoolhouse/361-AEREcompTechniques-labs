#!/bin/bash

#this is the kirckhoff solve, need to make sure i watched video correctly

FILE=$1 #Take in the input file name
MaxNode=0 #nodes start from 1 so 0 can be tested as error condition

IFS=$'\n' #Internal Field Seperator (IFS)
ARRAY_OF_LOOPS=(`grep L $1`)


#Use a C-style for loop...
for (( i =0; i < ${#ARRAY_OF_LOOPS[@]}; i++ ))
do 
	LINE="${ARRAY_OF_LOOPS[$i]}"

	if [[ "$LINE" =~ [L],([0-9,\s]+) ]]

	then 
		echo "HERE! Got a loop ${BASH_REMATCH[1]}"
		IFS=',' read -ra NODES <<< "${BASH_REMATCH[1]}"
		ARRAY_OF_LOOPS[$i]="" #empty this out to replace it
		for (( j = 1; j < ${#NODES[@]}; j++ ))
		do 
			ARRAY_OF_LOOPS[$i]+=" ${NODES[(($j-1))]},${NODES[$j]}"
		done  
		ARRAY_OF_LOOPS[$i]+=" ${NODES[-1]},${NODES[0]}"
	else 
		#default: print an error
		echo "Could not parse this line: ${LINE}"
		echo "Expecting line of the form (V|R),int,int,int OR L,int,int,int..."
	fi
done 

while read LINE
do 
	#echo "Here is the whole line: $LINE"
	case $LINE in 

		[VR],[0-9]*,[0-9]*,[0-9]*)
			[[ "$LINE" =~ ([VR]),([0-9]*),([0-9]*),([0-9]*) ]] #rematch with memory
			echo "Got a ${BASH_REMATCH[1]}-type edge from ${BASH_REMATCH[2]} to ${BASH_REMATCH[3]} of value ${BASH_REMATCH[4]}"

			if [ "${BASH_REMATCH[1]}" = R ]
			then
				EQN["${BASH_REMATCH[2]}"]+="-1i_${BASH_REMATCH[2]}${BASH_REMATCH[3]} " #negative direction
				EQN["${BASH_REMATCH[3]}"]+=" 1i_${BASH_REMATCH[2]}${BASH_REMATCH[3]} " #positive direction
			fi

		
			##fill in voltage equations
			##add in part to find/replace loops by copying loop from above
			##add it outside of the if statement so that we get the voltage link too
			for (( i = 0; i < ${#ARRAY_OF_LOOPS[@]}; i++ ))
			do
				LINE="${ARRAY_OF_LOOPS[$i]}"
				A=`echo \$LINE | sed s/${BASH_REMATCH[2]},${BASH_REMATCH[3]}/${BASH_REMATCH[4]}i_${BASH_REMATCH[2]}${BASH_REMATCH[3]}/`
				B=`echo \$A | sed s/${BASH_REMATCH[3]},${BASH_REMATCH[2]}/-${BASH_REMATCH[4]}i_${BASH_REMATCH[2]}${BASH_REMATCH[3]}/` #need -i_23
				ARRAY_OF_LOOPS[$i]="$B"
			done 

			#set the MaxNode
			if [ ${BASH_REMATCH[2]}   -gt $MaxNode ]
			then 
				MaxNode=${BASH_REMATCH[2]}
				#echo "Upping MaxNode to 1st: ${BASH_REMATCH[2]}"
			fi 
			if [ ${BASH_REMATCH[3]}   -gt $MaxNode ]
			then 
				MaxNode=${BASH_REMATCH[3]}
				#echo "Upping MaxNode to 2nd: ${BASH_REMATCH[3]}"
			fi

			connect+="i_${BASH_REMATCH[2]}${BASH_REMATCH[3]} "

			;;


		[L],[,0-9\s]* )
			
			;;

		"#"*)
			echo "Houston, we have a comment!"
			;;
		
		*)
			echo "Could not parse this line: $LINE";
			echo "Expecting line of the form: (V|R), int,int,int OR L,int,int,int..."
			;;
	esac

done < $FILE



echo ""
for EQUATION in $(seq 1 $MaxNode)
do 
		echo "EQN[$EQUATION] = ${EQN[$EQUATION]}" >> step2.txt
done 

for(( i=0; i < ${#ARRAY_OF_LOOPS[@]}; i++ ))
do
	echo "EQN[$((1 + $i + $MaxNode))] = ${ARRAY_OF_LOOPS[$i]}" >>step2.txt
done 

echo ""
echo "Varibales - ${connect[*]}" >> variables.txt

./kirchhoff step2.txt variables.txt
make halfclean

#echo "${ARRAY_OF_LOOPS[*]}"
		
# [[ "$LINE" =- [L], ([0-9,\s]+) ]] #rematch with memory
# echo "Got a loop through ${BASH_REMATCH[1]}"
# ;;  





		
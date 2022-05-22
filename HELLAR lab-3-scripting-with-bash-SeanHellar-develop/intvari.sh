#!/bin/bash

# Variance of a sample set is:
# Sum of the squares of the difference from the mean, divided by the number of samples
# Sum( x_i - mu )^2 / N


echo "Integer Variance Calculator"

#data had to be in an array so for loop could work
sed 's/\s\+/\n/g' samples.dat > rawdata.dat
mapfile -t array < rawdata.dat

if [[ ${#array[@]} -lt 2 ]]
then
    echo "Not enough samples!"
    exit
else
    echo "I recieved ${#array[@]} samples."
fi

mean=0
a=0  
for ((i=0;i<=${#array[@]};i++))
do
    ((a+=${array[i]})) 
done

#N= 999 
((mean =$a/${#array[@]}))
#Divide by number of smaples ))
echo "The integer mean value is: $mean"


vari=0
b=0
for ((j=0;j<=${#array[@]};j++))
do
    ((b+=(${array[j]}-$mean)**2)) 
    # Now compute the variance
done
((vari=$b/${#array[@]}))
echo "The integer standard deviation is: $vari"

#well that just sucked

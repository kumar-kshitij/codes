echo "Enter 3 numbers :"
read a
read b
read c

D=$((b*b - 4*a*c))

echo -n "Roots of ${a}x^2 + ${b}x + $c are"

if((D < 0))
then
	echo " imaginary."
else
	echo -n " real and"
	alpha=`echo "(-($b)+sqrt($D))/(2*$a)"|bc`
	beta=`echo "(-($b)-sqrt($D))/(2*$a)"|bc`
	if((D == 0))
	then
		echo " equal : $alpha"
	else
		echo " distinct : $alpha, $beta"
	fi
fi

echo "Enter two Numbers";
read a;
read b;
ch=0;
while [ $ch -le 4 ]
do
	echo "Enter Choice";
	read ch;
	case $ch in
		1)echo "Addition"
			sum=`expr $a + $b`
			echo $sum;;
		2)echo "Subtraction"
			sum=`expr $a - $b`
			echo $sum;;
		3)echo "Multiplication"
			sum=`expr $a \* $b`
			echo $sum;;
		4)echo "Division"
			sum=`expr $a / $b`
			echo $sum;;
		*)echo "Invalid Choice";;
	esac
done


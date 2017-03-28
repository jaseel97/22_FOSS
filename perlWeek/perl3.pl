#!/usr/bin/perl
# perl program to read an array and print sum of elements
# perl program to find factorial of a number
# program to find largest of three numbers
# perl program to perform linear search
print "Enter the elements. ctrl+d to stop entering values\n";
@a = <STDIN>;
chop (@a);
$l = @a ;
$sum = 0 ;
while ($i < $l){
#	print "test : $a[$i]\n";
	$sum += $a[$i];
	$i = $i + 1;
}
print "SUM : $sum\n";

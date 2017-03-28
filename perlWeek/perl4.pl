#!/usr/bin/perl
# factorial
print "Enter number\n";
$n = <STDIN> ;
chop $n ;
$n1 = $n;
$f=1;
while ($n1 >= 1){
	$f*=$n1;
	$n1 = $n1-1;
}
print "Factorial($n) : $f\n";	

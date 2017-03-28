#!/usr/bin/perl
# largest of 3
print "Enter the 3 numbers\n";
$a=<STDIN>,$b=<STDIN>,$c=<STDIN>;
chomp $a;
chomp $b;
chomp $c;
if ($a >= $b && $a >= $c ) {
	$l =$a;
}
elsif ($b >= $a && $b >= $c ) {
	$l = $b;
}
else{
	$l = $c;
}
print "Largest : $l\n";

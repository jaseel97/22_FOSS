#!/usr/bin/perl
# linear search
print "Enter the elements. Press ctrl+d to stop input\n";
@a = <STDIN>;
print "Enter search key\n";
$k = <STDIN>;
chop $k;
while ($a[$i] ne ""){
	if ($f = $k == $a[$i]){
		print "$k at position ".($i+1)."\n";
		last;	
	}
	$i++;
}
unless ($f){
	print "Search Failed\n";
}

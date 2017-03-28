#!/usr/bin/perl
%hash = (1,"stormCall", 2 ,"unrelentingForce");
@v = values %hash;
@k = keys %hash;
print "Values : $hash{1},$hash{2}\n";
print "Keys   : $k[0],$k[1]\n";
print "Added 3 => Oohdaviing\n";
$hash{3}="Oohdaviing";
@v = values %hash;
@k = keys %hash;
print "Values : @v\n";
print "Keys : @k\n";
print "Deleted stormCall\n";
delete $hash{1};
@v = values %hash;
@k = keys %hash;
print "Values : @v\n";
print "Keys : @k\n";

$s = @v;
print "Final Size : $s\n"; 

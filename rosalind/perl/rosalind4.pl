#!/usr/bin/perl
use warnings;

print "months:";
my $months = <STDIN>;
chomp($months);
print "rabbit litter pairs produced:";
my $k = <STDIN>;
chomp($k);

my $f_n1 = 1;
my $f_n2 = 1;
my $n = 3;
while($n<=$months){
	$f_n = $f_n1 + $k*$f_n2;
	$f_n2 = $f_n1;
	$f_n1 = $f_n;
	$n=$n+1;
}
print $f_n, "\n";
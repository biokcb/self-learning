#!/usr/bin/perl
use warnings;
use Algorithm::Permute;

print "Enter the number:";
my $numba = <STDIN>;
my @numbas = 1..$numba;

my $p_iterator = Algorithm::Permute->new ( \@numbas );

while (my @perm = $p_iterator->next){
	push(@array, "@numbas");
	}
	$iters = @array;
	print "\n$iters\n"
	
#!/usr/bin/perl
use warnings;

chomp(@sequences = <STDIN>);

@seq1 = split("", $sequences[0]);
@seq2 = split("", $sequences[1]);

$tot_mismatch=0;

for($i=0; defined($seq1[$i]); $i++){
	if ($seq1[$i] eq $seq2[$i]){
	$match_plus = 0;
	} else {
	$match_plus = 1;
	}
	$tot_mismatch = $tot_mismatch + $match_plus;	
}

print "\n$tot_mismatch\n\n";
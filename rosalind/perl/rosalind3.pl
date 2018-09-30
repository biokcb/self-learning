#!/usr/bin/perl

print "\nsequence:";
my $seq = <STDIN>;

$seq=reverse($seq);
$seq=~tr/ATCG/TAGC/;
print $seq, "\n";